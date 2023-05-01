#pragma once

#include "../concepts.h"
#include "../pre_compiled_header.h"

namespace Tobot::Math {
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    class Vector {

        public:
            Vector();
            virtual auto operator()(std::size_t i) const -> T = 0;

            virtual auto operator()(std::size_t i) -> T & = 0;

            virtual auto operator[](std::size_t i) const -> T = 0;

            virtual auto operator[](std::size_t i) -> T & = 0;

            virtual auto Magnitude() -> T = 0;

            virtual auto Normalize() -> void = 0;

            virtual auto GetSize() -> std::size_t = 0;
    };

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Vector<T>::Vector() {
    }
} // namespace Tobot::Math
