#pragma once

#include "pre_compiled_header.h"

#include "concepts.h"

namespace Tobot::Math {
    /// @brief Models a point in 2D space
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Point2D {

        public:
            /// @brief Default constructor
            Point2D() = default;

            /// @brief Constructor
            /// @param x X coordinate
            /// @param y Y coordinate
            Point2D(T const & x, T const & y);

            /// @brief Copy constructor
            /// @param point Point to copy
            Point2D(Point2D<T> const & point);

            /// @brief Move constructor
            /// @param point Point to move
            Point2D(Point2D<T> &&) noexcept;

            /// @brief Destructor
            ~Point2D() = default;

            /// @brief Copy assignment operator
            /// @param point Point to copy
            /// @return Reference to this
            auto operator=(Point2D<T> const &) -> Point2D<T> &;

            /// @brief Move assignment operator
            /// @param point Point to move
            /// @return Reference to this
            auto operator=(Point2D<T> &&) noexcept -> Point2D<T> &;

            /// @brief Equality operator
            /// @param point Point to compare
            /// @return True if equal, false otherwise
            auto operator==(Point2D<T> const &) const -> bool;

            /// @brief Inequality operator
            /// @param point Point to compare
            /// @return True if not equal, false otherwise
            auto operator!=(Point2D<T> const &) const -> bool;

            /// @brief Less than operator
            /// @param point Point to compare
            /// @return True if less than, false otherwise
            auto distance(Point2D<T> const &) const -> T;

            /// @brief Less than or equal operator
            /// @param point Point to compare
            /// @param epsilon Epsilon value
            /// @return True if less than or equal, false otherwise
            auto distance(T const &, T const &) const -> T;

            /// @brief Greater than operator
            /// @param point Point to compare
            /// @return True if greater than, false otherwise
            auto distanceSquared(Point2D<T> const &) const -> T;

            /// @brief Greater than or equal operator
            /// @param point Point to compare
            /// @param epsilon Epsilon value
            /// @return True if greater than or equal, false otherwise
            auto distanceSquared(T const &, T const &) const -> T;

            /// @brief Cross product
            /// @return Cross product
            auto getX() const -> T;

            /// @brief Cross product
            /// @return Cross product
            auto getY() const -> T;

            /// @brief Set X coordinate
            /// @param x X coordinate
            auto setX(T const &) -> void;

            /// @brief Set Y coordinate
            /// @param y Y coordinate
            auto setY(T const &) -> void;

            friend auto operator<<(std::ostream & os, Point2D<T> const & point) -> std::ostream & {
                os << "Point2D(" << point.m_x << ", " << point.m_y << ")";
                return os;
            }

        private:
            /// @brief X coordinate
            T m_x;

            /// @brief Y coordinate
            T m_y;
    };

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Point2D<T>::Point2D(T const & x, T const & y) {
        m_x = x;
        m_y = y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Point2D<T>::Point2D(Point2D<T> const & point) {
        m_x = point.m_x;
        m_y = point.m_y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Point2D<T>::Point2D(Point2D<T> && point) noexcept {
        m_x = point.m_x;
        m_y = point.m_y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Point2D<T>::operator=(Point2D<T> const & point) -> Point2D<T> & {
        m_x = point.m_x;
        m_y = point.m_y;
        return *this;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Point2D<T>::operator=(Point2D<T> && point) noexcept -> Point2D<T> & {
        m_x = point.m_x;
        m_y = point.m_y;
        return *this;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Point2D<T>::operator==(Point2D<T> const & point) const -> bool {
        return (m_x == point.m_x) && (m_y == point.m_y);
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Point2D<T>::operator!=(Point2D<T> const & point) const -> bool {
        return (m_x != point.m_x) || (m_y != point.m_y);
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Point2D<T>::getX() const -> T {
        return m_x;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Point2D<T>::getY() const -> T {
        return m_y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Point2D<T>::setX(T const & x) -> void {
        m_x = x;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Point2D<T>::setY(T const & y) -> void {
        m_y = y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Point2D<T>::distance(Point2D<T> const & point) const -> T {
        return sqrt(pow(m_x - point.m_x, 2) + pow(m_y - point.m_y, 2));
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Point2D<T>::distance(T const & x, T const & y) const -> T {
        return sqrt(pow(m_x - x, 2) + pow(m_y - y, 2));
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Point2D<T>::distanceSquared(Point2D<T> const & point) const -> T {
        return pow(m_x - point.m_x, 2) + pow(m_y - point.m_y, 2);
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Point2D<T>::distanceSquared(T const & x, T const & y) const -> T {
        return pow(m_x - x, 2) + pow(m_y - y, 2);
    }
} // namespace Tobot::Math