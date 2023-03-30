#pragma once

#include "concepts.h"
#include <exception>
#include <vector>

namespace Tobot::Math {
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    class Matrix;
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    using rowVector = Matrix<T, 1, n>;
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    using colVector = Matrix<T, m, 1>;
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    class Matrix {
        private:
            std::vector<std::vector<T>> m_matrix;
            std::size_t rows;
            std::size_t cols;

        public:
            explicit Matrix();
            explicit Matrix(const std::vector<T> matrixValue);

            std::size_t getRows() const;
            std::size_t getColoumns() const;
    };

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix() : rows(m), cols(n) {
        if (rows == 0 || cols == 0) {
            throw std::invalid_argument("received zero as argument");
        }

        m_matrix.resize(rows);
        for (auto & colData : m_matrix) {
            colData.resize(cols);
        }
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix(const std::vector<T> matrixValue) : rows(m), cols(n) {
        if (rows == 0 || cols == 0) {
            throw std::invalid_argument("received zero as argument");
        }

        if (matrixValue.empty()) {
            throw std::invalid_argument("Empty vector");
        }

        if (rows * cols != matrixValue.size()) {
            throw std::runtime_error("Total number of matrix values does not match with rows and coloumns provided");
        }

        m_matrix.resize(rows);
        for (auto & colData : m_matrix) {
            colData.resize(cols);
        }

        for (std::size_t i = 0; i < rows; i++) {
            m_matrix[i] = {matrixValue.begin() + (i * cols), matrixValue.begin() + ((i + 1) * cols)};
        }
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    std::size_t Matrix<T, m, n>::getRows() const {
        return this->rows;
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    std::size_t Matrix<T, m, n>::getColoumns() const {
        return this->cols;
    }
} // namespace Tobot::Math