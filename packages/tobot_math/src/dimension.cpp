#include "dimension.h"

using namespace Tobot::Math;

template <typename T>
    requires Arithmetic<T>
Dimension<T>::Dimension(T width, T height) : width(width), height(height) {
}

template class Dimension<int>;
