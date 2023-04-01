#pragma once

#include "pre_compiled_header.h"

#include "concepts.h"
#include "vector.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Vector3D : Vector<T> {

        public:
            T x;
            T y;
            T z;

            Vector3D(T x, T y, T z);

            /// @brief Calculates the sum of two vectors
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector3D<T> The sum of the two vectors
            friend inline Vector3D<T> operator+(Vector3D<T> lVec, const Vector3D<T> & rVec) {
                return Vector3D(lVec.x + rVec.x, lVec.y + rVec.y, lVec.z + rVec.z);
            }

            /// @brief Substracts two vectors
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector3D<T> The difference of the two vectors
            friend inline Vector3D<T> operator-(Vector3D<T> lVec, const Vector3D<T> & rVec) {
                return Vector3D(lVec.x - rVec.x, lVec.y - rVec.y, lVec.z - rVec.z);
            }

            /// @brief Calulates the product of a vector and a scalar
            /// @param scalar The scalar
            /// @param vec The vector
            /// @return Vector3D<T> The product of the vector and the scalar
            friend inline Vector3D<T> operator*(const T scalar, Vector3D<T> vec) {
                return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
            }

            /// @brief Calulates the product of a vector and a scalar
            /// @param vec The vector
            /// @param scalar The scalar
            /// @return Vector3D<T> The product of the vector and the scalar
            friend inline Vector3D<T> operator*(Vector3D<T> vec, const T scalar) {
                return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
            }

            /// @brief Calculates the division of a vector and a scalar
            /// @param scalar The scalar
            /// @param vec The vector
            /// @return Vector3D<T> The division of the vector and the scalar
            friend inline Vector3D<T> operator/(const T scalar, Vector3D<T> vec) {
                return Vector3D(vec.x / scalar, vec.y / scalar, vec.z / scalar);
            }

            /// @brief Calculates the division of a vector and a scalar
            /// @param vec The vector
            /// @param scalar The scalar
            /// @return Vector3D<T> The division of the vector and the scalar
            friend inline Vector3D<T> operator/(Vector3D<T> vec, const T scalar) {
                return Vector3D(vec.x / scalar, vec.y / scalar, vec.z / scalar);
            }

            Vector3D<T> & operator+=(const Vector3D<T> & vec);

            Vector3D<T> & operator-=(const Vector3D<T> & vec);

            Vector3D<T> & operator*=(const T scalar);

            Vector3D<T> & operator/=(const T scalar);

            T & operator()(std::size_t i);

            T operator()(std::size_t i) const;

            T & operator[](std::size_t i);

            T operator[](std::size_t i) const;

            /// @brief Appends the vector to the output stream
            /// @param os The output stream
            /// @param vec The vector
            /// @return std::ostream The output stream
            friend std::ostream operator<<(std::ostream & os, const Vector3D<T> & vec) {
                os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
                return os;
            }

            inline T Magnitude();

            inline void Normalize();

            inline std::size_t GetSize();

            T Dot(const Vector3D<T> & vec);

            Vector3D<T> Cross(const Vector3D<T> & vec);

            Vector3D<T> FromAngle(T angle);
    };

    /// @brief Constructs a new Vector3D object
    /// @tparam T The type of the vector
    /// @param x The x component of the vector
    /// @param y The y component of the vector
    /// @param z The z component of the vector
    template <typename T>
        requires Arithmetic<T>
    Vector3D<T>::Vector3D(T x, T y, T z) : x(x), y(y), z(z) {
    }

    /// @brief Calculates the sum of two vectors and assigns the result to the left vector
    /// @tparam T The type of the vector
    /// @param vec The vector to add
    /// @return Vector3D<T> The sum of the two vectors
    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> & Vector3D<T>::operator+=(const Vector3D<T> & vec) {
        this->x += vec.x;
        this->y += vec.y;
        this->z += vec.z;
        return *this;
    }

    /// @brief Calculates the difference of two vectors and assigns the result to the left vector
    /// @tparam T The type of the vector
    /// @param vec The vector to substract
    /// @return Vector3D<T> The difference of the two vectors
    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> & Vector3D<T>::operator-=(const Vector3D<T> & vec) {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= vec.z;
        return *this;
    }

    /// @brief Calculates the product of a vector and a scalar and assigns the result to the vector
    /// @tparam T The type of the vector
    /// @param scalar The scalar
    /// @return Vector3D<T> The product of the vector and the scalar
    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> & Vector3D<T>::operator*=(const T scalar) {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    /// @brief Calculates the division of a vector and a scalar and assigns the result to the vector
    /// @tparam T The type of the vector
    /// @param scalar The scalar
    /// @return Vector3D<T> The division of the vector and the scalar
    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> & Vector3D<T>::operator/=(const T scalar) {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        return *this;
    }

    /// @brief Gets the component of the vector at the specified index
    /// @tparam T The type of the vector
    /// @param i The index of the component
    /// @return T& The component at the specified index
    template <typename T>
        requires Arithmetic<T>
    T & Vector3D<T>::operator()(std::size_t i) {
        assert(i < 3);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;

        default:
            // Unreachable
#if defined(COMPILER_MSVC)
            __assume(0);
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
            __builtin_unreachable();
#else // Compiler is Intel or unknown
            exit(70);
#endif;
        }
    }

    /// @brief Gets the component of the vector at the specified index
    /// @tparam T The type of the vector
    /// @param i The index of the component
    /// @return T The component at the specified index
    template <typename T>
        requires Arithmetic<T>
    T Vector3D<T>::operator()(std::size_t i) const {
        assert(i < 3);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;

        default:
            // Unreachable
#if defined(COMPILER_MSVC)
            __assume(0);
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
            __builtin_unreachable();
#else // Compiler is Intel or unknown
            exit(70);
#endif;
        }
    }

    /// @brief Gets the component of the vector at the specified index
    /// @tparam T The type of the vector
    /// @param i The index of the component
    /// @return T& The component at the specified index
    template <typename T>
        requires Arithmetic<T>
    T & Vector3D<T>::operator[](std::size_t i) {
        assert(i < 3);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;

        default:
            // Unreachable
#if defined(COMPILER_MSVC)
            __assume(0);
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
            __builtin_unreachable();
#else // Compiler is Intel or unknown
            exit(70);
#endif;
        }
    }

    /// @brief Gets the component of the vector at the specified index
    /// @tparam T The type of the vector
    /// @param i The index of the component
    /// @return T The component at the specified index
    template <typename T>
        requires Arithmetic<T>
    T Vector3D<T>::operator[](std::size_t i) const {
        assert(i < 3);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;

        default:
            // Unreachable
#if defined(COMPILER_MSVC)
            __assume(0);
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
            __builtin_unreachable();
#else // Compiler is Intel or unknown
            exit(70);
#endif;
        }
    }

    /// @brief Calculates the magnitude of the vector
    /// @tparam T The type of the vector
    /// @return T The magnitude of the vector
    template <typename T>
        requires Arithmetic<T>
    inline T Vector3D<T>::Magnitude() {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    /// @brief Normalizes the vector
    /// @tparam T The type of the vector
    template <typename T>
        requires Arithmetic<T>
    inline void Vector3D<T>::Normalize() {
        *this /= this->Magnitude();
    }

    /// @brief Gets the size of the vector
    /// @tparam T The type of the vector
    /// @return std::size_t The size of the vector
    template <typename T>
        requires Arithmetic<T>
    inline std::size_t Vector3D<T>::GetSize() {
        return 3;
    }

    /// @brief Calculates the dot product of two vectors
    /// @tparam T The type of the vector
    /// @param vec The vector to calculate the dot product with
    /// @return T The dot product of the two vectors
    template <typename T>
        requires Arithmetic<T>
    T Vector3D<T>::Dot(const Vector3D<T> & vec) {
        return this->x * vec.x + this->y * vec.y + this->z * vec.z;
    }

    /// @brief Calculates the cross product of two vectors
    /// @tparam T The type of the vector
    /// @param vec The vector to calculate the cross product with
    /// @return Vector3D<T> The cross product of the two vectors
    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> Vector3D<T>::Cross(const Vector3D<T> & vec) {
        return Vector3D<T>(this->y * vec.z - this->z * vec.y, this->z * vec.x - this->x * vec.z,
                           this->x * vec.y - this->y * vec.x);
    }
} // namespace Tobot::Math
