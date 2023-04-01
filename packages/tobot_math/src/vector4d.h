#pragma once

#include "concepts.h"
#include "pre_compiled_header.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Vector4D {

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

            inline T Magnitude();

            inline void Normalize();
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
    inline T Vector4D<T>::Magnitude() {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    }

    template <typename T>
        requires Arithmetic<T>
    inline void Vector4D<T>::Normalize() {
        *this /= this->Magnitude();
    }

} // namespace Tobot::Math
