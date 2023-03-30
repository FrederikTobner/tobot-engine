#include "vector4d.h"

using namespace Tobot::Math;

template <typename T>
    requires Arithmetic<T>
Vector4D<T>::Vector4D(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {
}

template class Vector4D<short>;
template class Vector4D<int>;
template class Vector4D<long>;
template class Vector4D<long long>;
template class Vector4D<float>;
template class Vector4D<double>;
template class Vector4D<long double>;
