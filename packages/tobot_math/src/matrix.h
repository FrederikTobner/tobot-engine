#pragma once

#include "concepts.h"
#include "pre_compiled_header.h"

namespace Tobot::Math {

    /// @brief Represents a matrix of type T with m rows and n coloumns
    /// @tparam T The type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    template <typename T = float, std::size_t m = 3, std::size_t n = 3>
        requires Arithmetic<T>
    class Matrix {

        public:
            // Represents a row of the matrix
            class Row;

            explicit Matrix();
            explicit Matrix(const Matrix<T, m, n> & mat);
            explicit Matrix(const std::vector<T> values);
            Matrix(const std::initializer_list<T> list);
            explicit Matrix(Matrix<T, m, n> && mat);
            Matrix(std::array<std::array<T, n>, m> values);
            ~Matrix();

            inline T & operator()(std::size_t i, std::size_t j);
            inline T & operator()(std::size_t i, std::size_t j) const;
            Row operator[](std::size_t row) {
                return Row(*this, row);
            }
            Row & operator[](std::size_t row) const {
                return Row(*this, row);
            }
            bool operator==(const Matrix<T, m, n> & mat) const;
            bool operator!=(const Matrix<T, m, n> & mat) const;
            Matrix<T, m, n> & operator=(const Matrix<T, m, n> & mat);
            Matrix<T, m, n> & operator=(Matrix<T, m, n> && mat);
            Matrix<T, m, n> & operator*(const T & scalar) const;
            Matrix<T, m, n> & operator+=(const Matrix<T, m, n> & mat);
            Matrix<T, m, n> & operator-=(const Matrix<T, m, n> & mat);
            Matrix<T, m, n> & operator*=(const T & scalar);
            Matrix<T, m, n> & operator*=(const Matrix<T, m, n> & mat);

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
            T determinant() const;
            T cofactor(std::size_t i, std::size_t j) const;
            T minor(std::size_t i, std::size_t j) const;
            Matrix<T, m, n> inverse();
            Matrix<T, m, n> transpose() const;
            Matrix<T, m, n> adjoint() const;
            Matrix<T, m, n> identity() const;
            /// Implementation of the matrix row
            class Row {
                public:
                    Matrix & parent;
                    std::size_t row;
                    Row(Matrix & parent, std::size_t row) : parent(parent), row(row) {
                    }
                    T & operator[](std::size_t col) {
                        return parent(row, col);
                    }
            };

        private:
            std::size_t rowsCount;
            std::size_t columnsCount;
            mutable std::array<std::array<T, n>, m> m_matrix;
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

    /// @brief Construct a new Matrix object
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param mat The matrix to move
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix(Matrix<T, m, n> && mat) : rowsCount(m), columnsCount(n) {
        static_assert(m > 0 && n > 0);
        m_matrix = std::move(mat.m_matrix);
    }

    /**
     * @brief Construct a new Matrix object
     *
     * @tparam T the type of value used to build the matrix
     * @tparam m the number of rows in the matrix
     * @tparam n the number of columns in the matrix
     * @param values the values for the matrix in row-major order
     */
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix(const std::vector<T> values) : rowsCount(m), columnsCount(n) {

        // check that the matrix invariants are satisfied
        static_assert(m > 0 && n > 0);
        // check that the values vector is not empty
        if (values.empty()) {
            throw std::invalid_argument("The provided vector is empty");
        }
        // check that the number of values is equal to rowsCount * columnsCount
        if (rowsCount * columnsCount != values.size()) {
            throw std::runtime_error("Total number of matrix values does not match the rows and coloumns provided");
        }
        // populate the matrix with the provided values
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

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::Matrix(std::array<std::array<T, n>, m> mat) : rowsCount(m), columnsCount(n) {
        static_assert(m > 0 && n > 0);
        m_matrix = mat;
    }

    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n>::~Matrix() {
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

    /// @brief Copy assignment operator
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param mat The matrix to copy
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n> & Matrix<T, m, n>::operator=(const Matrix<T, m, n> & mat) {
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                this->m_matrix[i][j] = mat[i][j];
            }
        }
        return *this;
    }

    /// @brief Move assignment operator
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param mat The matrix to move
    /// @return Matrix<T, m, n> & A reference to the moved matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n> & Matrix<T, m, n>::operator=(Matrix<T, m, n> && mat) {
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                this->m_matrix[i][j] = std::move(mat[i][j]);
            }
        }
        return *this;
    }

    /// Multiplies the Matrix by a scalar
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param scalar The scalar to multiply by
    /// @return Matrix<T, m, n> The product of the matrix and the scalar
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n> & Matrix<T, m, n>::operator*(const T & scalar) const {
        Matrix<T, m, n> result;
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                result[i][j] = this->m_matrix[i][j] * scalar;
            }
        }
        return result;
    }

    /// @brief Add a matrix to this matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param mat The matrix to add
    /// @return Matrix<T, m, n> & A reference to the moved matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n> & Matrix<T, m, n>::operator+=(const Matrix<T, m, n> & mat) {
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                this->m_matrix[i][j] += mat[i][j];
            }
        }
        return *this;
    }

    /// Subtracts a matrix from this matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param mat The matrix to subtract
    /// @return Matrix<T, m, n> & A reference to the moved matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n> & Matrix<T, m, n>::operator-=(const Matrix<T, m, n> & mat) {
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                this->m_matrix[i][j] -= mat[i][j];
            }
        }
        return *this;
    }

    /// @brief Multiply this matrix by a scalar
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param scalar The scalar to multiply by
    /// @return Matrix<T, m, n> & A reference to the moved matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n> & Matrix<T, m, n>::operator*=(const T & scalar) {
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                this->m_matrix[i][j] *= scalar;
            }
        }
        return *this;
    }

    /// @brief Multiply this matrix by another matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param mat The matrix to multiply by
    /// @return Matrix<T, m, n> & A reference to the moved matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n> & Matrix<T, m, n>::operator*=(const Matrix<T, m, n> & mat) {
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                this->m_matrix[i][j] *= mat[i][j];
            }
        }
        return *this;
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

    /// Calculates the determinant of the matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @return T The determinant of the matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline T Matrix<T, m, n>::determinant() const {
        static_assert(m == n, "Matrix must be square");
        if constexpr (m == 1) {
            return this->m_matrix[0][0];
        } else if constexpr (m == 2) {
            return this->m_matrix[0][0] * this->m_matrix[1][1] - this->m_matrix[0][1] * this->m_matrix[1][0];
        } else {
            T det = 0;
            for (std::size_t i = 0; i < columnsCount; i++) {
                det += this->m_matrix[0][i] * this->cofactor(0, i);
            }
            return det;
        }
    }

    /// Calculates the cofactor of the matrix at the specified row and coloumn
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @param i The row index
    /// @param j The coloumn index
    /// @return T The cofactor of the matrix at the specified row and coloumn
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline T Matrix<T, m, n>::cofactor(std::size_t i, std::size_t j) const {
        static_assert(m == n, "Matrix must be square");
        assert(i < m && j < n);
        return std::pow(-1, i + j) * this->minor(i, j);
    }

    /**
     * Calculates the minor of the matrix at the specified row and column
     *
     * @tparam T The underlying type of the matrix
     * @tparam m The number of rows in the matrix
     * @tparam n The number of columns in the matrix
     * @param i The row index
     * @param j The column index
     *
     * @return T The minor of the matrix at the specified row and column
     */
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline T Matrix<T, m, n>::minor(std::size_t i, std::size_t j) const {
        static_assert(m == n, "Matrix must be square");
        assert(i < m && j < n);
        Matrix<T, m - 1, n - 1> minor;
        std::size_t minorRow = 0;
        std::size_t minorCol = 0;
        for (std::size_t row = 0; row < rowsCount; row++) {
            for (std::size_t col = 0; col < columnsCount; col++) {
                if (row != i && col != j) {
                    minor[minorRow][minorCol] = this->m_matrix[row][col];
                    minorCol++;
                    if (minorCol == minor.getColoumns()) {
                        minorCol = 0;
                        minorRow++;
                    }
                }
            }
        }
        return minor.determinant();
    }

    /// @brief Calculates the inverse of the matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @return Matrix<T, m, n> The inverse of the matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline Matrix<T, m, n> Matrix<T, m, n>::inverse() {
        static_assert(m == n, "Matrix must be square");
        std::array<std::array<T, n>, m> inverted;
        T det = this->determinant();
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                inverted[j][i] = this->cofactor(i, j) / det;
            }
        }
        return Matrix<T, m, n>(inverted);
    }

    /// @brief Calculates the transpose of the matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @return Matrix<T, m, n> The transpose of the matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline Matrix<T, m, n> Matrix<T, m, n>::transpose() const {
        Matrix<T, m, n> transpose;
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                transpose[j][i] = this->m_matrix[i][j];
            }
        }
        return transpose;
    }

    /// @brief Calculates the adjoint of the matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @return Matrix<T, m, n> The adjoint of the matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    inline Matrix<T, m, n> Matrix<T, m, n>::adjoint() const {
        static_assert(m == n, "Matrix must be square");
        Matrix<T, m, n> adjoint;
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                adjoint[i][j] = this->cofactor(i, j);
            }
        }
        return adjoint;
    }

    /// @brief Calculates the identity matrix of the same size as the matrix
    /// @tparam T The underlying type of the matrix
    /// @tparam m The number of rows in the matrix
    /// @tparam n The number of coloumns in the matrix
    /// @return Matrix<T, m, n> The identity matrix of the same size as the matrix
    template <typename T, std::size_t m, std::size_t n>
        requires Arithmetic<T>
    Matrix<T, m, n> Matrix<T, m, n>::identity() const {
        Matrix<T, m, n> identity(*this->m_matrix);
        for (std::size_t i = 0; i < rowsCount; i++) {
            for (std::size_t j = 0; j < columnsCount; j++) {
                identity[i][j] = (i == j) ? 1 : 0;
            }
        }
        return identity;
    }

} // namespace Tobot::Math
