#pragma once

#include "utilities/concepts.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Dimension {
        public:
            T width;
            T height;

            Dimension(T width, T height) : width(width), height(height) {
            }
    };
} // namespace Tobot::Math
