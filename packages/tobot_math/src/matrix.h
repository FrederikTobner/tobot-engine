#pragma once

#include "concepts.h"
#include "pre_compiled_header.h"

namespace Tobot::Math {
    template <typename T = float, std::size_t m = 3, std::size_t n = 3>
        requires Arithmetic<T>
    class Matrix {
        private:
            std::size_t rowsCount;
            std::size_t columnsCount;
            std::array<std::array<T, n>, m> m_matrix;

        public:
            Matrix();
            Matrix(const Matrix<T, m, n> & mat);
            Matrix(const std::vector<T> values);
            Matrix(const std::initializer_list<T> list);

            inline T & operator()(std::size_t i, std::size_t j);
            inline T & operator()(std::size_t i, std::size_t j) const;
            inline std::array<T, n> & operator[](std::size_t i);
            inline std::array<T, n> & operator[](std::size_t i) const;
            bool operator==(const Matrix<T, m, n> & mat) const;
            bool operator!=(const Matrix<T, m, n> & mat) const;

            /// @brief Appends the matrix to the ostream
            /// @param os The ostream to append the matrix to
            /// @param mat The matrix to append to the ostream
            /// @return std::ostream& The ostream with the matrix appended
            friend std::ostream operator<<(std::ostream & os, const Matrix<T, m, n> & mat) {
                for (std::size_t i = 0; i < mat.getRows(); i++) {
                    for (std::size_t j = 0; j < mat.getColoumns(); j++) {
                        os << mat(i, j) << " ";
                    }
                    os << std::endl;
                }
                return os;
            }

            inline std::size_t & getRows();
            inline std::size_t & getColoumns();
    };

    /// @brief Construct a new Matrix object
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix() : rowsCount(m), columnsCount(n) {
        static_assert(m > 0 && n > 0);
    }

    /// @brief Construct a new Matrix object
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param mat The matrix to copy
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix(const Matrix<T, m, n> & mat) : rowsCount(m), columnsCount(n) {
        static_assert(m > 0 && n > 0);
        m_matrix = mat.m_matrix;
    }

    /// @brief Construct a new Matrix object from a vector of values
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param values The vector of values to construct the matrix from
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

    /// @brief Construct a new Matrix object from a list of values
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param list The list of values to construct the matrix from
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix(std::initializer_list<T> list) : rowsCount(m), columnsCount(n) {

        static_assert(m > 0 && n > 0);
        if (list.size() == 0) {
            throw std::invalid_argument("The provided list is empty");
        }

        if (rowsCount * columnsCount != list.size()) {
            throw std::runtime_error("Total number of matrix values does not match the rows and coloumns provided");
        }
        auto it = list.begin();
        for (std::size_t i = 0; i < columnsCount; i++) {
            for (std::size_t j = 0; j < rowsCount; j++, std::advance(it, 1)) {
                this->m_matrix[i][j] = *it;
            }
        }
    }

    /// @brief Get a reference to the value at the specified row and coloumn
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param i The row index
    /// @param j The coloumn index
    /// @return T& The value at the specified row and coloumn
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline T & Matrix<T, m, n>::operator()(std::size_t i, std::size_t j) {
        assert(i < m && j < n);
        return this->m_matrix[i][j];
    }

    /// @brief Get a const reference to the value at the specified row and coloumn
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param i The row index
    /// @param j The coloumn index
    /// @return T& The value at the specified row and coloumn
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline T & Matrix<T, m, n>::operator()(std::size_t i, std::size_t j) const {
        assert(i < m && j < n);
        return this->m_matrix[i][j];
    }

    /// @brief Get the underlying array of the specified row
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param i The row index
    /// @return std::array<T, n>& The underlying array of the specified row
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline std::array<T, n> & Matrix<T, m, n>::operator[](std::size_t i) {
        assert(i < m);
        return this->m_matrix[i];
    }

    /// @brief Get the underlying array of the specified row
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param i The row index
    /// @return std::array<T, n>& The underlying array of the specified row
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline std::array<T, n> & Matrix<T, m, n>::operator[](std::size_t i) const {
        assert(i < m);
        return this->m_matrix[i];
    }

    /// Compares two matrices for equality
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param mat The matrix to compare to
    /// @return true If the matrices are equal
    /// @return false If the matrices are not equal
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline bool Matrix<T, m, n>::operator==(const Matrix<T, m, n> & mat) const {
        for (std::size_t i = 0; i < columnsCount; i++) {
            for (std::size_t j = 0; j < rowsCount; j++) {
                if (this->m_matrix[i][j] != mat.m_matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    /// Compares two matrices for inequality
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param mat The matrix to compare to
    /// @return true If the matrices are not equal
    /// @return false If the matrices are equal
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline bool Matrix<T, m, n>::operator!=(const Matrix<T, m, n> & mat) const {
        return !(*this == mat);
    }

    /// @brief Get the number of rows in the matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @return std::size_t The number of rows in the matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline std::size_t & Matrix<T, m, n>::getRows() {
        return this->rowsCount;
    }

    /// @brief Gets the number of coloumns in the matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @return std::size_t The number of coloumns in the matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline std::size_t & Matrix<T, m, n>::getColoumns() {
        return this->columnsCount;
    }
} // namespace Tobot::Math
