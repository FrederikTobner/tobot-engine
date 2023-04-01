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

            friend inline Vector3D<T> operator+(Vector3D<T> lVec, const Vector3D<T> & rVec) {
                return Vector3D(lVec.x + rVec.x, lVec.y + rVec.y, lVec.z + rVec.z);
            }

            friend inline Vector3D<T> operator-(Vector3D<T> lVec, const Vector3D<T> & rVec) {
                return Vector3D(lVec.x - rVec.x, lVec.y - rVec.y, lVec.z - rVec.z);
            }

            friend inline Vector3D<T> operator*(const T scalar, Vector3D<T> vec) {
                return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
            }

            friend inline Vector3D<T> operator*(Vector3D<T> vec, const T scalar) {
                return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
            }

            friend inline Vector3D<T> operator/(const T scalar, Vector3D<T> vec) {
                return Vector3D(vec.x / scalar, vec.y / scalar, vec.z / scalar);
            }

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

            inline T Magnitude();

            inline void Normalize();

            inline std::size_t GetSize();
    };

    template <typename T>
        requires Arithmetic<T>
    Vector3D<T>::Vector3D(T x, T y, T z) : x(x), y(y), z(z) {
    }

    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> & Vector3D<T>::operator+=(const Vector3D<T> & vec) {
        this->x += vec.x;
        this->y += vec.y;
        this->z += vec.z;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> & Vector3D<T>::operator-=(const Vector3D<T> & vec) {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= vec.z;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> & Vector3D<T>::operator*=(const T scalar) {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> & Vector3D<T>::operator/=(const T scalar) {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        return *this;
    }

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

    template <typename T>
        requires Arithmetic<T>
    inline T Vector3D<T>::Magnitude() {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    template <typename T>
        requires Arithmetic<T>
    inline void Vector3D<T>::Normalize() {
        *this /= this->Magnitude();
    }

    template <typename T>
        requires Arithmetic<T>
    inline std::size_t Vector3D<T>::GetSize() {
        return 3;
    }

} // namespace Tobot::Math
