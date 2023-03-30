#pragma once

#include "concepts.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Vector2D {

        public:
            T x;
            T y;

            Vector2D(T x, T y);

            Vector2D<T> & operator+=(const Vector2D<T> & rhs) {
                this->x += rhs.x;
                this->y += rhs.y;
                return *this;
            }

            Vector2D<T> & operator-=(const Vector2D<T> & rhs) {
                this->x -= rhs.x;
                this->y -= rhs.y;
                return *this;
            }

            friend Vector2D<T> operator+(Vector2D<T> lhs, const Vector2D<T> & rhs) {
                lhs += rhs;
                return lhs;
            }

            friend Vector2D<T> operator-(Vector2D<T> lhs, const Vector2D<T> & rhs) {
                lhs -= rhs;
                return lhs;
            }

            Vector2D<T> & operator*=(const Vector2D<T> & rhs) {
                this->x *= rhs.x;
                this->y *= rhs.y;
                return *this;
            }

            Vector2D<T> & operator*=(const T rhs) {
                this->x *= rhs;
                this->y *= rhs;
                return *this;
            }

            Vector2D<T> & operator/=(const Vector2D<T> & rhs) {
                this->x /= rhs.x;
                this->y /= rhs.y;
                return *this;
            }

            Vector2D<T> & operator/=(const T rhs) {

                this->x /= rhs;
                this->y /= rhs;
                return *this;
            }

            friend Vector2D<T> operator*(Vector2D<T> lhs, const Vector2D<T> & rhs) {
                lhs *= rhs;
                return lhs;
            }

            friend Vector2D<T> operator*(Vector2D<T> lhs, const T rhs) {
                lhs.x *= rhs;
                lhs.y *= rhs;
                return lhs;
            }

            friend Vector2D<T> operator/(Vector2D<T> lhs, const Vector2D<T> & rhs) {
                lhs /= rhs;
                return lhs;
            }

            friend Vector2D<T> operator/(Vector2D<T> lhs, const T rhs) {
                lhs.x /= rhs;
                lhs.y /= rhs;
                return lhs;
            }

            T Magnitude() {
                return sqrt(this->x * this->x + this->y * this->y);
            }

            void Normalize() {
                *this /= this->Magnitude();
            }
    };
} // namespace Tobot::Math
