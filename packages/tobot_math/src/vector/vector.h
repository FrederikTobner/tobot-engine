#pragma once

#include "concepts.h"
#include "pre_compiled_header.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Vector {

        public:
            Vector() {
            }
            virtual T & operator()(std::size_t i) = 0;

            virtual T operator()(std::size_t i) const = 0;

            virtual T & operator[](std::size_t i) = 0;

            virtual T operator[](std::size_t i) const = 0;

            virtual T Magnitude() = 0;

            virtual void Normalize() = 0;

            virtual std::size_t GetSize() = 0;
    };
} // namespace Tobot::Math
