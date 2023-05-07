#pragma once

#include "concepts.hpp"

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
            auto operator=(Dimension<T> const & dim) -> Dimension<T> &;
            auto operator=(Dimension<T> const && dim) -> Dimension<T> &;
            /// @brief Appends the dimension to the ostream
            friend auto operator<<(std::ostream & os, Dimension<T> const & dim) -> std::ostream {
                os << "(" << dim.width << ", " << dim.height << ")";
            }
            auto operator==(Dimension<T> const & dim) const -> bool;
            auto operator!=(Dimension<T> const & dim) const -> bool;
    };

    template <typename T>
        requires Arithmetic<T>
    Dimension<T>::Dimension() {
        width = T();
        height = T();
    }

    template <typename T>
        requires Arithmetic<T>
    Dimension<T>::Dimension(T width, T height) {
        this->width = width;
        this->height = height;
    }

    template <typename T>
        requires Arithmetic<T>
    Dimension<T>::Dimension(Dimension<T> const & dim) {
        width = dim.width;
        height = dim.height;
    }

    template <typename T>
        requires Arithmetic<T>
    Dimension<T>::Dimension(std::initializer_list<T> list) {
        if (list.size() != 2) {
            throw std::invalid_argument("The initializer list must have a size of 2");
        }
        width = list[0];
        height = list[1];
    }

    /// @brief Assigns the values of the dimension to the current dimension
    /// @tparam T The type of the dimensions
    /// @param dim The dimension to assign
    /// @return The current dimension
    template <typename T>
        requires Arithmetic<T>
    auto Dimension<T>::operator=(Dimension<T> const & dim) -> Dimension<T> & {
        width = dim.width;
        height = dim.height;
        return *this;
    }

    /// @brief Assigns the values of the dimension to the current dimension
    /// @tparam T The type of the dimensions
    /// @param dim The dimension to assign
    /// @return The current dimension
    template <typename T>
        requires Arithmetic<T>
    auto Dimension<T>::operator=(Dimension<T> const && dim) -> Dimension<T> & {
        width = dim.width;
        height = dim.height;
        return *this;
    }

    /// @brief Compares two dimensions for equality
    /// @tparam T The type of the dimensions
    /// @param dim The dimension to compare to
    /// @return true If the dimensions are equal
    template <typename T>
        requires Arithmetic<T>
    [[nodiscard]] auto Dimension<T>::operator==(Dimension<T> const & dim) const -> bool {
        return width == dim.width && height == dim.height;
    }

    /// @brief Compares two dimensions for inequality
    /// @tparam T The type of the dimensions
    /// @param dim The dimension to compare to
    /// @return true If the dimensions are not equal
    template <typename T>
        requires Arithmetic<T>
    [[nodiscard]] auto Dimension<T>::operator!=(Dimension<T> const & dim) const -> bool {
        return !(*this == dim);
    }
} // namespace Tobot::Math
