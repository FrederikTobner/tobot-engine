#pragma once

#include "concepts.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Dimension {
        public:
            T width;
            T height;

            Dimension(T width, T height) : width(width), height(height) {
            }
            friend std::ostream operator<<(std::ostream & os, const Dimension<T> & dim) {
                os << "(" << dim.width << ", " << dim.height << ")";
                return os;
            }
    };
} // namespace Tobot::Math
