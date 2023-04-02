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
            bool operator==(const Dimension<T> & dim) const;
            bool operator!=(const Dimension<T> & dim) const;
    };

    /// @brief Compares two dimensions for equality
    /// @tparam T The type of the dimensions
    /// @param dim The dimension to compare to
    /// @return true If the dimensions are equal
    template <typename T>
        requires Arithmetic<T> bool
    Dimension<T>::operator==(const Dimension<T> & dim) const {
        return width == dim.width && height == dim.height;
    }

    /// @brief Compares two dimensions for inequality
    /// @tparam T The type of the dimensions
    /// @param dim The dimension to compare to
    /// @return true If the dimensions are not equal
    template <typename T>
        requires Arithmetic<T> bool
    Dimension<T>::operator!=(const Dimension<T> & dim) const {
        return !(*this == dim);
    }
} // namespace Tobot::Math
