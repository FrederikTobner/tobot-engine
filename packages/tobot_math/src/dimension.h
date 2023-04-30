#pragma once

#include "concepts.h"

namespace Tobot::Math {
    template <typename T>
        requires Arithmetic<T>
    class Dimension {
        public:
            T width;
            T height;
            Dimension();
            Dimension(T width, T height);
            Dimension(Dimension<T> const & dim);
            Dimension(std::initializer_list<T> list);
            Dimension<T> & operator=(Dimension<T> const & dim) {
                width = dim.width;
                height = dim.height;
                return *this;
            }
            Dimension<T> & operator=(Dimension<T> const && dim) {
                width = dim.width;
                height = dim.height;
                return *this;
            }
            /// @brief Appends the dimension to the ostream
            friend std::ostream operator<<(std::ostream & os, Dimension<T> const & dim) {
                os << "(" << dim.width << ", " << dim.height << ")";
            }
            bool operator==(Dimension<T> const & dim) const;
            bool operator!=(Dimension<T> const & dim) const;
    };

    template <typename T>
        requires Arithmetic<T>
    [[nodiscard]] Dimension<T>::Dimension() {
        width = T();
        height = T();
    }

    template <typename T>
        requires Arithmetic<T>
    [[nodiscard]] Dimension<T>::Dimension(T width, T height) {
        this->width = width;
        this->height = height;
    }

    template <typename T>
        requires Arithmetic<T>
    [[nodiscard]] Dimension<T>::Dimension(Dimension<T> const & dim) {
        width = dim.width;
        height = dim.height;
    }

    template <typename T>
        requires Arithmetic<T>
    [[nodiscard]] Dimension<T>::Dimension(std::initializer_list<T> list) {
        if (list.size() != 2) {
            throw std::invalid_argument("The initializer list must have a size of 2");
        }
        width = list[0];
        height = list[1];
    }

    /// @brief Compares two dimensions for equality
    /// @tparam T The type of the dimensions
    /// @param dim The dimension to compare to
    /// @return true If the dimensions are equal
    template <typename T>
        requires Arithmetic<T>
    [[nodiscard]] bool Dimension<T>::operator==(Dimension<T> const & dim) const {
        return width == dim.width && height == dim.height;
    }

    /// @brief Compares two dimensions for inequality
    /// @tparam T The type of the dimensions
    /// @param dim The dimension to compare to
    /// @return true If the dimensions are not equal
    template <typename T>
        requires Arithmetic<T>
    [[nodiscard]] bool Dimension<T>::operator!=(Dimension<T> const & dim) const {
        return !(*this == dim);
    }
} // namespace Tobot::Math
