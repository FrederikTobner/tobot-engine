#pragma once

#include "concepts.h"
#include "pre_compiled_header.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Vector2D {

        public:
            T x;
            T y;

            Vector2D(T x, T y) : x(x), y(y){};

            friend Vector2D<T> operator+(Vector2D<T> lVec, const Vector2D<T> & rVec) {
                return Vector2D(lVec.x + rVec.x, lVec.y + rVec.y);
            }

            friend Vector2D<T> operator-(Vector2D<T> lVec, const Vector2D<T> & rVec) {
                return Vector2D(lVec.x - rVec.x, lVec.y - rVec.y);
            }

            friend Vector2D<T> operator*(const T scalar, Vector2D<T> vec) {
                return Vector2D(vec.x * scalar, vec.y * scalar);
            }

            friend Vector2D<T> operator*(Vector2D<T> vec, const T scalar) {
                return Vector2D(vec.x * scalar, vec.y * scalar);
            }

            friend Vector2D<T> operator/(const T scalar, Vector2D<T> vec) {
                return Vector2D(vec.x / scalar, vec.y / scalar);
            }

            friend Vector2D<T> operator/(Vector2D<T> vec, const T scalar) {
                return Vector2D(vec.x / scalar, vec.y / scalar);
            }

            Vector2D<T> & operator+=(const Vector2D<T> & vec) {
                this->x += vec.x;
                this->y += vec.y;
                return *this;
            }

            Vector2D<T> & operator-=(const Vector2D<T> & vec) {
                this->x -= vec.x;
                this->y -= vec.y;
                return *this;
            }

            Vector2D<T> & operator*=(const T scalar) {
                this->x *= scalar;
                this->y *= scalar;
                return *this;
            }

            Vector2D<T> & operator/=(const T scalar) {
                this->x /= scalar;
                this->y /= scalar;
                return *this;
            }

            T Magnitude() {
                return sqrt(this->x * this->x + this->y * this->y);
            }

            void Normalize() {
                *this /= this->Magnitude();
            }
    };
} // namespace Tobot::Math
