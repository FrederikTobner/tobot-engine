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

            Vector3D(T x, T y, T z) : x(x), y(y), z(z){};

            friend Vector3D<T> operator+(Vector3D<T> lVec, const Vector3D<T> & rVec) {
                return Vector3D(lVec.x + rVec.x, lVec.y + rVec.y, lVec.z + rVec.z);
            }

            friend Vector3D<T> operator-(Vector3D<T> lVec, const Vector3D<T> & rVec) {
                return Vector3D(lVec.x - rVec.x, lVec.y - rVec.y, lVec.z - rVec.z);
            }

            friend Vector3D<T> operator*(const T scalar, Vector3D<T> vec) {
                return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
            }

            friend Vector3D<T> operator*(Vector3D<T> vec, const T scalar) {
                return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
            }

            friend Vector3D<T> operator/(const T scalar, Vector3D<T> vec) {
                return Vector3D(vec.x / scalar, vec.y / scalar, vec.z / scalar);
            }

            friend Vector3D<T> operator/(Vector3D<T> vec, const T scalar) {
                return Vector3D(vec.x / scalar, vec.y / scalar, vec.z / scalar);
            }

            Vector3D<T> & operator+=(const Vector3D<T> & vec) {
                this->x += vec.x;
                this->y += vec.y;
                this->z += vec.z;
                return *this;
            }

            Vector3D<T> & operator-=(const Vector3D<T> & vec) {
                this->x -= vec.x;
                this->y -= vec.y;
                this->z -= vec.z;
                return *this;
            }

            Vector3D<T> & operator*=(const T scalar) {
                this->x *= scalar;
                this->y *= scalar;
                this->z *= scalar;
                return *this;
            }

            Vector3D<T> & operator/=(const T scalar) {

                this->x /= scalar;
                this->y /= scalar;
                this->z /= scalar;
                return *this;
            }

            T Magnitude() {
                return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
            }

            void Normalize() {
                *this /= this->Magnitude();
            }
    };
} // namespace Tobot::Math
