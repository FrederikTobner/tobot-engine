#pragma once

#include "concepts.h"
#include <array>
#include <exception>
#include <vector>

namespace Tobot::Math {
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    class Matrix {
        private:
            std::size_t rowsCount;
            std::size_t columnsCount;
            std::array<std::array<T, n>, m> m_matrix;

        public:
            explicit Matrix();
            explicit Matrix(const std::vector<T> values);

            std::size_t getRows() const;
            std::size_t getColoumns() const;
    };

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix() : rowsCount(m), columnsCount(n) {
        if (rowsCount == 0 || columnsCount == 0) {
            throw std::invalid_argument("received zero as argument");
        }
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix(const std::vector<T> values) : rowsCount(m), columnsCount(n) {

        static_assert(m > 0 && n > 0);

        if (values.empty()) {
            throw std::invalid_argument("The provided vector is empty");
        }

        if (rowsCount * columnsCount != values.size()) {
            throw std::runtime_error("Total number of matrix values does not match with rows and coloumns provided");
        }
        for (size_t i = 0; i < columnsCount; i++) {
            for (size_t j = 0; j < rowsCount; j++) {
                this->m_matrix[i][j] = values[i * rowsCount + j];
            }
        }
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    std::size_t Matrix<T, m, n>::getRows() const {
        return this->rowsCount;
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    std::size_t Matrix<T, m, n>::getColoumns() const {
        return this->columnsCount;
    }
} // namespace Tobot::Math