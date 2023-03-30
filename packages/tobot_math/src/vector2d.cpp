#include "vector2d.h"

using namespace Tobot::Math;

template <typename T>
    requires Arithmetic<T>
Vector2D<T>::Vector2D(T x, T y) : x(x), y(y) {
}

// Gotta go fast 🚀
template class Vector2D<int_fast8_t>;
template class Vector2D<int_fast16_t>;
template class Vector2D<int_fast32_t>;
template class Vector2D<int_fast64_t>;
template class Vector2D<float>;
template class Vector2D<double>;