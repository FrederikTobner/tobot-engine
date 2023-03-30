#include "vector3d.h"

using namespace Tobot::Math;

template <typename T>
    requires Arithmetic<T>
Vector3D<T>::Vector3D(T x, T y, T z) : x(x), y(y), z(z) {
}

template class Vector3D<short>;
template class Vector3D<int>;
template class Vector3D<long>;
template class Vector3D<long long>;
template class Vector3D<float>;
template class Vector3D<double>;
template class Vector3D<long double>;
