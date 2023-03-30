#include "vector2d.h"

using namespace Tobot::Math;

template <typename T>
    requires Arithmetic<T>
Vector2D<T>::Vector2D(T x, T y) : x(x), y(y) {
}

template class Vector2D<short>;
template class Vector2D<int>;
template class Vector2D<long>;
template class Vector2D<long long>;
template class Vector2D<float>;
template class Vector2D<double>;
template class Vector2D<long double>;