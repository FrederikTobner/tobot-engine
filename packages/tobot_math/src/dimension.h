#pragma once

#include "concepts.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Dimension {
        public:
            T width;
            T height;

            Dimension(T width, T height);
    };
} // namespace Tobot::Math
