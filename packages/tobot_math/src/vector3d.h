#pragma once

#include "concepts.h"
#include "pre_compiled_header.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Vector3D {

        public:
            T x;
            T y;
            T z;

            Vector3D(T x, T y, T z);

            Vector3D<T> & operator+=(const Vector3D<T> & rhs) {
                this->x += rhs.x;
                this->y += rhs.y;
                this->z += rhs.z;
                return *this;
            }

            Vector3D<T> & operator-=(const Vector3D<T> & rhs) {
                this->x -= rhs.x;
                this->y -= rhs.y;
                this->z -= rhs.z;
                return *this;
            }

            friend Vector3D<T> operator+(Vector3D<T> lhs, const Vector3D<T> & rhs) {
                lhs += rhs;
                return lhs;
            }

            friend Vector3D<T> operator-(Vector3D<T> lhs, const Vector3D<T> & rhs) {
                lhs -= rhs;
                return lhs;
            }

            Vector3D<T> & operator*=(const Vector3D<T> & rhs) {
                this->x *= rhs.x;
                this->y *= rhs.y;
                this->z *= rhs.z;
                return *this;
            }

            Vector3D<T> & operator*=(const T rhs) {
                this->x *= rhs;
                this->y *= rhs;
                this->z *= rhs;
                return *this;
            }

            Vector3D<T> & operator/=(const Vector3D<T> & rhs) {
                this->x /= rhs.x;
                this->y /= rhs.y;
                this->z /= rhs.z;
                return *this;
            }

            Vector3D<T> & operator/=(const T rhs) {

                this->x /= rhs;
                this->y /= rhs;
                this->z /= rhs;
                return *this;
            }

            friend Vector3D<T> operator*(Vector3D<T> lhs, const Vector3D<T> & rhs) {
                lhs *= rhs;
                return lhs;
            }

            friend Vector3D<T> operator*(Vector3D<T> lhs, const T rhs) {
                lhs.x *= rhs;
                lhs.y *= rhs;
                lhs.z *= rhs;
                return lhs;
            }

            friend Vector3D<T> operator/(Vector3D<T> lhs, const Vector3D<T> & rhs) {
                lhs /= rhs;
                return lhs;
            }

            friend Vector3D<T> operator/(Vector3D<T> lhs, const T rhs) {
                lhs.x /= rhs;
                lhs.y /= rhs;
                lhs.z /= rhs;
                return lhs;
            }

            T Magnitude() {
                return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
            }

            void Normalize() {
                *this /= this->Magnitude();
            }
    };
} // namespace Tobot::Math
