#include "vector2d.h"

using namespace Tobot::Math;

template <typename T>
    requires Arithmetic<T>
Vector2D<T>::Vector2D(T x, T y) : x(x), y(y) {
}

template class Vector2D<int>;