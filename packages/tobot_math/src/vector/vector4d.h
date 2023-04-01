#pragma once

#include "pre_compiled_header.h"

#include "concepts.h"
#include "vector.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Vector4D : Vector<T> {

        public:
            T x;
            T y;
            T z;
            T w;

            Vector4D(T x, T y, T z, T w);

            friend inline Vector4D<T> operator+(Vector4D<T> lVec, const Vector4D<T> & rVec) {
                return Vector4D(lVec.x + rVec.x, lVec.y + rVec.y, lVec.z + rVec.z, lVec.w + rVec.w);
            }

            friend inline Vector4D<T> operator-(Vector4D<T> lVec, const Vector4D<T> & rVec) {
                return Vector4D(lVec.x - rVec.x, lVec.y - rVec.y, lVec.z - rVec.z, lVec.w - rVec.w);
            }

            friend inline Vector4D<T> operator*(const T scalar, Vector4D<T> vec) {
                return Vector4D(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar);
            }

            friend inline Vector4D<T> operator*(Vector4D<T> vec, const T scalar) {
                return Vector4D(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar);
            }

            friend inline Vector4D<T> operator/(const T scalar, Vector4D<T> vec) {
                return Vector4D(vec.x / scalar, vec.y / scalar, vec.z /= scalar, vec.w / scalar);
            }

            friend inline Vector4D<T> operator/(Vector4D<T> vec, const T scalar) {
                return Vector4D(vec.x / scalar, vec.y / scalar, vec.z / scalar, vec.w / scalar);
            }

            Vector4D<T> & operator+=(const Vector4D<T> & vec);

            Vector4D<T> & operator-=(const Vector4D<T> & vec);

            Vector4D<T> & operator*=(const T scalar);

            Vector4D<T> & operator/=(const T scalar);

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
    Vector4D<T>::Vector4D(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {
    }

    template <typename T>
        requires Arithmetic<T>
    Vector4D<T> & Vector4D<T>::operator+=(const Vector4D<T> & vec) {
        this->x += vec.x;
        this->y += vec.y;
        this->z += vec.z;
        this->w += vec.w;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector4D<T> & Vector4D<T>::operator-=(const Vector4D<T> & vec) {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= vec.z;
        this->w -= vec.w;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector4D<T> & Vector4D<T>::operator*=(const T scalar) {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        this->w *= scalar;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector4D<T> & Vector4D<T>::operator/=(const T scalar) {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        this->w /= scalar;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    T & Vector4D<T>::operator()(std::size_t i) {
        assert(i < 4);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        case 3:
            return this->w;

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
    T Vector4D<T>::operator()(std::size_t i) const {
        assert(i < 4);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        case 3:
            return this->w;

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
    T & Vector4D<T>::operator[](std::size_t i) {
        assert(i < 4);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        case 3:
            return this->w;

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
    T Vector4D<T>::operator[](std::size_t i) const {
        assert(i < 4);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        case 3:
            return this->w;

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
    inline T Vector4D<T>::Magnitude() {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    }

    template <typename T>
        requires Arithmetic<T>
    inline void Vector4D<T>::Normalize() {
        *this /= this->Magnitude();
    }

    template <typename T>
        requires Arithmetic<T>
    inline std::size_t Vector4D<T>::GetSize() {
        return 4;
    }

} // namespace Tobot::Math
