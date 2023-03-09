#pragma once

#include "utilities/concepts.h"

namespace Tobot::Math
{
    template <typename T> requires Arithmetic<T>
    class Vector2D
    {

    public:
        T x;
        T y;

        Vector2D(T x, T y) : x(x), y(y) {}

        Vector2D<T> &operator+=(const Vector2D<T> &rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            return *this;
        }
        friend Vector2D<T> operator+(Vector2D<T> lhs, const Vector2D<T> &rhs)
        {
            lhs += rhs;
            return lhs;
        }

        Vector2D<T> &operator*=(const Vector2D<T> &rhs)
        {
            this->x *= rhs.x;
            this->y *= rhs.y;
            return *this;
        }

        friend Vector2D<T> operator*(Vector2D<T> lhs, const Vector2D<T> &rhs)
        {
            lhs *= rhs;
            return lhs;
        }
    };
} // namespace Tobot::Math
