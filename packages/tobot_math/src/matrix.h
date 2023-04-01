#pragma once

#include "concepts.h"
#include "pre_compiled_header.h"

namespace Tobot::Math {
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    class Matrix {
        private:
            std::size_t rowsCount;
            std::size_t columnsCount;
            std::array<std::array<T, n>, m> m_matrix;

        public:
            Matrix();
            Matrix(const std::vector<T> values);

            inline T & operator()(std::size_t i, std::size_t j);
            inline T & operator()(std::size_t i, std::size_t j) const;
            inline std::array<T, n> & operator[](std::size_t i);
            inline std::array<T, n> & operator[](std::size_t i) const;

            inline std::size_t getRows() const;
            inline std::size_t getColoumns() const;
    };

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix() : rowsCount(m), columnsCount(n) {
        static_assert(m > 0 && n > 0);
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix(const std::vector<T> values) : rowsCount(m), columnsCount(n) {

        static_assert(m > 0 && n > 0);

        if (values.empty()) {
            throw std::invalid_argument("The provided vector is empty");
        }

        if (rowsCount * columnsCount != values.size()) {
            throw std::runtime_error("Total number of matrix values does not match the rows and coloumns provided");
        }
        for (std::size_t i = 0; i < columnsCount; i++) {
            for (std::size_t j = 0; j < rowsCount; j++) {
                this->m_matrix[i][j] = values[i * rowsCount + j];
            }
        }
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline T & Matrix<T, m, n>::operator()(std::size_t i, std::size_t j) {
        assert(i < m && j < n);
        return this->m_matrix[i][j];
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline T & Matrix<T, m, n>::operator()(std::size_t i, std::size_t j) const {
        assert(i < m && j < n);
        return this->m_matrix[i][j];
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline std::array<T, n> & Matrix<T, m, n>::operator[](std::size_t i) {
        assert(i < m);
        return this->m_matrix[i];
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline std::array<T, n> & Matrix<T, m, n>::operator[](std::size_t i) const {
        assert(i < m);
        return this->m_matrix[i];
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline std::size_t Matrix<T, m, n>::getRows() const {
        return this->rowsCount;
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline std::size_t Matrix<T, m, n>::getColoumns() const {
        return this->columnsCount;
    }
} // namespace Tobot::Math
