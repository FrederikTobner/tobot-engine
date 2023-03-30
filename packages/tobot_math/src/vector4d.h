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

            Vector4D<T> & operator+=(const Vector4D<T> & rhs) {
                this->x += rhs.x;
                this->y += rhs.y;
                this->z += rhs.z;
                this->w += rhs.w;
                return *this;
            }

            Vector4D<T> & operator-=(const Vector4D<T> & rhs) {
                this->x -= rhs.x;
                this->y -= rhs.y;
                this->z -= rhs.z;
                this->w -= rhs.w;
                return *this;
            }

            friend Vector4D<T> operator+(Vector4D<T> lhs, const Vector4D<T> & rhs) {
                lhs += rhs;
                return lhs;
            }

            friend Vector4D<T> operator-(Vector4D<T> lhs, const Vector4D<T> & rhs) {
                lhs -= rhs;
                return lhs;
            }

            Vector4D<T> & operator*=(const Vector4D<T> & rhs) {
                this->x *= rhs.x;
                this->y *= rhs.y;
                this->z *= rhs.z;
                this->w *= rhs.w;
                return *this;
            }

            Vector4D<T> & operator*=(const T rhs) {
                this->x *= rhs;
                this->y *= rhs;
                this->z *= rhs;
                this->w *= rhs;
                return *this;
            }

            Vector4D<T> & operator/=(const Vector4D<T> & rhs) {
                this->x /= rhs.x;
                this->y /= rhs.y;
                this->z /= rhs.z;
                this->w /= rhs.w;
                return *this;
            }

            Vector4D<T> & operator/=(const T rhs) {

                this->x /= rhs;
                this->y /= rhs;
                this->z /= rhs;
                this->w /= rhs;
                return *this;
            }

            friend Vector4D<T> operator*(Vector4D<T> lhs, const Vector4D<T> & rhs) {
                lhs *= rhs;
                return lhs;
            }

            friend Vector4D<T> operator*(Vector4D<T> lhs, const T rhs) {
                lhs.x *= rhs;
                lhs.y *= rhs;
                lhs.z *= rhs;
                lhs.w *= rhs;
                return lhs;
            }

            friend Vector4D<T> operator/(Vector4D<T> lhs, const Vector4D<T> & rhs) {
                lhs /= rhs;
                return lhs;
            }

            friend Vector4D<T> operator/(Vector4D<T> lhs, const T rhs) {
                lhs.x /= rhs;
                lhs.y /= rhs;
                lhs.z /= rhs;
                lhs.w /= rhs;
                return lhs;
            }

            T Magnitude() {
                return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
            }

            void Normalize() {
                *this /= this->Magnitude();
            }
    };
} // namespace Tobot::Math
