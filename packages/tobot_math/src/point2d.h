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
            Point2D(const T & x, const T & y);

            /// @brief Copy constructor
            /// @param point Point to copy
            Point2D(const Point2D<T> & point);

            /// @brief Move constructor
            /// @param point Point to move
            Point2D(Point2D<T> &&) noexcept;

            /// @brief Destructor
            ~Point2D() = default;

            /// @brief Copy assignment operator
            /// @param point Point to copy
            /// @return Reference to this
            Point2D<T> & operator=(const Point2D<T> &);

            /// @brief Move assignment operator
            /// @param point Point to move
            /// @return Reference to this
            Point2D<T> & operator=(Point2D<T> &&) noexcept;

            /// @brief Equality operator
            /// @param point Point to compare
            /// @return True if equal, false otherwise
            bool operator==(const Point2D<T> &) const;

            /// @brief Inequality operator
            /// @param point Point to compare
            /// @return True if not equal, false otherwise
            bool operator!=(const Point2D<T> &) const;

            /// @brief Less than operator
            /// @param point Point to compare
            /// @return True if less than, false otherwise
            T distance(const Point2D<T> &) const;

            /// @brief Less than or equal operator
            /// @param point Point to compare
            /// @param epsilon Epsilon value
            /// @return True if less than or equal, false otherwise
            T distance(const T &, const T &) const;

            /// @brief Greater than operator
            /// @param point Point to compare
            /// @return True if greater than, false otherwise
            T distanceSquared(const Point2D<T> &) const;

            /// @brief Greater than or equal operator
            /// @param point Point to compare
            /// @param epsilon Epsilon value
            /// @return True if greater than or equal, false otherwise
            T distanceSquared(const T &, const T &) const;

            /// @brief Cross product
            /// @return Cross product
            T x() const;

            /// @brief Cross product
            /// @return Cross product
            T y() const;

            /// @brief Set X coordinate
            /// @param x X coordinate
            void setX(const T &);

            /// @brief Set Y coordinate
            /// @param y Y coordinate
            void setY(const T &);

            friend std::ostream & operator<<(std::ostream & os, const Point2D<T> & point) {
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
    Point2D<T>::Point2D(const T & x, const T & y) {
        m_x = x;
        m_y = y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Point2D<T>::Point2D(const Point2D<T> & point) {
        m_x = point.m_x;
        m_y = point.m_y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Point2D<T>::Point2D(Point2D<T> && point) noexcept {
        m_x = point.m_x;
        m_y = point.m_y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Point2D<T> & Point2D<T>::operator=(const Point2D<T> & point) {
        m_x = point.m_x;
        m_y = point.m_y;
        return *this;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Point2D<T> & Point2D<T>::operator=(Point2D<T> && point) noexcept {
        m_x = point.m_x;
        m_y = point.m_y;
        return *this;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T> bool
    Point2D<T>::operator==(const Point2D<T> & point) const {
        return (m_x == point.m_x) && (m_y == point.m_y);
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T> bool
    Point2D<T>::operator!=(const Point2D<T> & point) const {
        return (m_x != point.m_x) || (m_y != point.m_y);
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Point2D<T>::x() const {
        return m_x;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Point2D<T>::y() const {
        return m_y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    void Point2D<T>::setX(const T & x) {
        m_x = x;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    void Point2D<T>::setY(const T & y) {
        m_y = y;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Point2D<T>::distance(const Point2D<T> & point) const {
        return sqrt(pow(m_x - point.m_x, 2) + pow(m_y - point.m_y, 2));
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Point2D<T>::distance(const T & x, const T & y) const {
        return sqrt(pow(m_x - x, 2) + pow(m_y - y, 2));
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Point2D<T>::distanceSquared(const Point2D<T> & point) const {
        return pow(m_x - point.m_x, 2) + pow(m_y - point.m_y, 2);
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Point2D<T>::distanceSquared(const T & x, const T & y) const {
        return pow(m_x - x, 2) + pow(m_y - y, 2);
    }
} // namespace Tobot::Math