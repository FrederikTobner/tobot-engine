#pragma once

#include "../concepts.hpp"
#include "../pre_compiled_header.hpp"

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

            virtual auto magnitude() -> T = 0;

            virtual auto normalize() -> void = 0;

            virtual auto getSize() -> std::size_t = 0;
    };

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector<T>::Vector() {
    }
} // namespace Tobot::Math
