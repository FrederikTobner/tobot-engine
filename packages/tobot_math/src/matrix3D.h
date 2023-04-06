#pragma once

#include "pre_compiled_header.h"

#include "point2D.h"

namespace Tobot::Math {
    /// @brief Models a 3x3 matrix
    class Matrix3D {

        public:
            struct Row;

            /// @brief Default constructor
            Matrix3D();

            /// @brief Constructor
            /// @param data Data to initialize the matrix with
            Matrix3D(float[3][3]);

            /// @brief Constructor
            /// @param data Data to initialize the matrix with
            Matrix3D(std::initializer_list<float> data);

            /// @brief Copy constructor
            /// @param matrix Matrix to copy
            Matrix3D(const Matrix3D &);

            /// @brief Move constructor
            /// @param matrix Matrix to move
            Matrix3D(Matrix3D &&) noexcept;

            //// @brief Destructor
            ~Matrix3D() = default;

            /// @brief Copy assignment operator
            /// @param matrix Matrix to copy
            /// @return Reference to this
            Matrix3D & operator=(const Matrix3D &);

            /// @brief Move assignment operator
            /// @param matrix Matrix to move
            /// @return Reference to this
            Matrix3D & operator=(Matrix3D && matrix) noexcept;

            /// @brief Addition operator
            /// @param matrix Matrix to add
            /// @return Result of addition
            Matrix3D operator+(const Matrix3D & matrix) const;

            /// @brief Subtraction operator
            /// @param matrix Matrix to subtract
            /// @return Result of subtraction
            Matrix3D operator-(const Matrix3D & matrix) const;

            /// @brief Multiplication operator
            /// @param matrix Matrix to multiply
            /// @return Result of multiplication
            Matrix3D operator*(const Matrix3D & matrix) const;

            /// @brief Multiplication operator
            /// @param matrix Matrix to multiply
            /// @return Result of multiplication
            Matrix3D operator*(const float & matrix) const;

            /// @brief Division operator
            /// @param matrix Matrix to divide
            /// @return Result of division
            Matrix3D operator/(const float & matrix) const;

            /// @brief Addition assignment operator
            /// @param matrix Matrix to add
            /// @return Reference to this
            Matrix3D & operator+=(const Matrix3D &);

            /// @brief Subtraction assignment operator
            /// @param angle Angle to subtract
            /// @return Reference to this
            Matrix3D & operator-=(const Matrix3D &);

            /// @brief Multiplication assignment operator
            /// @param matrix Matrix to multiply
            /// @return Reference to this
            Matrix3D & operator*=(const Matrix3D &);

            /// @brief Multiplication assignment operator
            /// @param scalar Scalar to multiply
            /// @return Reference to this
            Matrix3D & operator*=(const float &);

            /// @brief Division assignment operator
            /// @param scalar Scalar to divide
            /// @return Reference to this
            Matrix3D & operator/=(const float &);

            /// @brief Inversion operator
            /// @return Inverse of this matrix
            Matrix3D operator!() const;

            float operator()(const int & row, const int & column) const;

            float & operator()(const int & row, const int & column);

            Row operator[](std::size_t row) {
                return Row(*this, row);
            }

            /// @brief Calculates the determinant of the matrix
            /// @return Determinant of the matrix
            float determinant() const;

            /// Identity matrix
            Matrix3D identity();

            /// Rotatates the matrix by the given angle
            /// @param angle Angle to rotate by
            /// @return Rotated matrix
            Matrix3D rotation(const float & angle);

            /// Reflects the matrix by the given angle
            /// @param angle Angle to reflect by
            /// @return Reflected matrix
            Matrix3D reflection(const float & angle);

            /// Rotatates the matrix by the given angle around the given point
            /// @param angle Angle to rotate by
            /// @param point Point to rotate around
            /// @return Rotated matrix
            Matrix3D rotation(const float & angle, const Point2D & point);

            /// Scales the matrix by the given factors around the given point
            /// @param x X factor
            /// @param y Y factor
            /// @param point Point to scale around
            /// @return Scaled matrix
            Matrix3D scale(const float & x, const float & y, const Point2D & point);

            /// Translates the matrix by the given factors around the given point
            /// @param x X factor
            /// @param y Y factor
            /// @param point Point to translate around
            /// @return Translated matrix
            Matrix3D translation(const float & x, const float & y, const Point2D & point);

            /// Shears the matrix by the given factors around the given point
            /// @param x X factor
            /// @param y Y factor
            /// @param point Point to shear around
            /// @return Sheared matrix
            Matrix3D shear(const float & x, const float & y, const Point2D & point);

            /// @brief Models a row of a matrix
            /// @details This struct is used to access the elements of a row of a matrix
            class Matrix3D::Row {
                public:
                    Matrix3D & parent;
                    std::size_t row;
                    Row(Matrix3D & parent, std::size_t row) : parent(parent), row(row) {
                    }
                    float & operator[](std::size_t col) {
                        return parent(row, col);
                    }
            };

        private:
            float m_data[3][3];
    };
} // namespace Tobot::Math