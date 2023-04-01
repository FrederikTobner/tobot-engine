#pragma once

#include "pre_compiled_header.h"

#include "concepts.h"
#include "vector.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Vector2D : Vector<T> {

        public:
            T x;
            T y;

            Vector2D(T x, T y);

            friend inline Vector2D<T> operator+(Vector2D<T> lVec, const Vector2D<T> & rVec) {
                return Vector2D(lVec.x + rVec.x, lVec.y + rVec.y);
            }

            friend inline Vector2D<T> operator-(Vector2D<T> lVec, const Vector2D<T> & rVec) {
                return Vector2D(lVec.x - rVec.x, lVec.y - rVec.y);
            }

            friend inline Vector2D<T> operator*(const T scalar, Vector2D<T> vec) {
                return Vector2D(vec.x * scalar, vec.y * scalar);
            }

            friend inline Vector2D<T> operator*(Vector2D<T> vec, const T scalar) {
                return Vector2D(vec.x * scalar, vec.y * scalar);
            }

            friend inline Vector2D<T> operator/(const T scalar, Vector2D<T> vec) {
                return Vector2D(vec.x / scalar, vec.y / scalar);
            }

            friend inline Vector2D<T> operator/(Vector2D<T> vec, const T scalar) {
                return Vector2D(vec.x / scalar, vec.y / scalar);
            }
            Vector2D<T> & operator+=(const Vector2D<T> & vec);

            Vector2D<T> & operator-=(const Vector2D<T> & vec);

            Vector2D<T> & operator*=(const T scalar);

            Vector2D<T> & operator/=(const T scalar);

            T & operator()(std::size_t i);

            T operator()(std::size_t i) const;

            T & operator[](std::size_t i);

            T operator[](std::size_t i) const;

            inline T Magnitude();

            inline void Normalize();

            inline std::size_t GetSize();

            inline T Dot(const Vector2D<T> & vec);

            Vector2D<T> Cross(const Vector2D<T> & vec);

            Vector2D<T> FromAngle(T angle);
    };

    template <typename T>
        requires Arithmetic<T>
    Vector2D<T>::Vector2D(T x, T y) : x(x), y(y) {
    }

    template <typename T>
        requires Arithmetic<T>
    Vector2D<T> & Vector2D<T>::operator+=(const Vector2D<T> & vec) {
        this->x += vec.x;
        this->y += vec.y;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector2D<T> & Vector2D<T>::operator-=(const Vector2D<T> & vec) {
        this->x -= vec.x;
        this->y -= vec.y;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector2D<T> & Vector2D<T>::operator*=(const T scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector2D<T> & Vector2D<T>::operator/=(const T scalar) {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    template <typename T>
        requires Arithmetic<T>
    T & Vector2D<T>::operator()(std::size_t i) {
        assert(i < 2);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;

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
    T Vector2D<T>::operator()(std::size_t i) const {
        assert(i < 2);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;

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
    T & Vector2D<T>::operator[](std::size_t i) {
        assert(i < 2);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;

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
    T Vector2D<T>::operator[](std::size_t i) const {
        assert(i < 2);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;

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
    T Vector2D<T>::Dot(const Vector2D<T> & vec) {
        return this->x * vec.x + this->y * vec.y;
    }

    template <typename T>
        requires Arithmetic<T>
    Vector2D<T> Vector2D<T>::Cross(const Vector2D<T> & vec) {
        return Vector2D(0, this->x * vec.y - this->y * vec.x);
    }

    template <typename T>
        requires Arithmetic<T>
    inline T Vector2D<T>::Magnitude() {
        return sqrt(this->x * this->x + this->y * this->y);
    }

    template <typename T>
        requires Arithmetic<T>
    inline void Vector2D<T>::Normalize() {
        *this /= this->Magnitude();
    }

    template <typename T>
        requires Arithmetic<T>
    inline std::size_t Vector2D<T>::GetSize() {
        return 2;
    }
} // namespace Tobot::Math
