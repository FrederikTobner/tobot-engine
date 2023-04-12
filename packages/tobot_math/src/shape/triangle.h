#pragma once
#include "../pre_compiled_header.h"

#include "../point2d.h"

namespace Tobot::Math {
    /// @brief Models a Cicle in 2D space
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Triangle2D {
        public:
            /// @brief Default constructor
            Triangle2D() = default;

            /// @brief Constructor
            /// @param a First point
            /// @param b Second point
            /// @param c Third point
            Triangle2D(Point2D<T> const & a, Point2D<T> const & b, Point2D<T> const & c);

            /// @brief Copy constructor
            /// @param triangle Triangle2D to copy
            Triangle2D(Triangle2D<T> const & triangle);

            /// @brief Move constructor
            /// @param triangle Triangle2D to move
            Triangle2D(Triangle2D<T> &&) noexcept;

            /// @brief Destructor
            ~Triangle2D() = default;

            /// @brief Copy assignment operator
            /// @param triangle Triangle2D to copy
            /// @return Reference to this
            Triangle2D<T> & operator=(Triangle2D<T> const &);

            /// @brief Move assignment operator
            /// @param triangle Triangle2D to move
            /// @return Reference to this
            Triangle2D<T> & operator=(Triangle2D<T> &&) noexcept;

            /// @brief Equality operator
            /// @param triangle Triangle2D to compare
            /// @return True if equal, false otherwise
            bool operator==(Triangle2D<T> const &) const;

            /// @brief Inequality operator
            /// @param triangle Triangle2D to compare
            /// @return True if not equal, false otherwise
            bool operator!=(Triangle2D<T> const &) const;

            /// @brief Get the first point
            /// @return First point
            Point2D<T> getA() const;

            /// @brief Get the second point
            /// @return Second point
            Point2D<T> getB() const;

            /// @brief Get the third point
            /// @return Third point
            Point2D<T> getC() const;

            T getArea() const;

            T getPerimeter() const;

            T getAngleA() const;

            T getAngleB() const;

            T getAngleC() const;

            friend std::ostream & operator<<(std::ostream & os, Triangle2D<T> const & triangle) {
                os << "Triangle2D(" << triangle.m_a << ", " << triangle.m_b << ", " << triangle.m_c << ")";
                return os;
            }

        private:
            Point2D<T> m_a;
            Point2D<T> m_b;
            Point2D<T> m_c;
    };

    /// @brief Constructs a triangle
    /// @tparam T Type of the triangle
    /// @param a The first point
    /// @param b The second point
    /// @param c The third point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Triangle2D<T>::Triangle2D(Point2D<T> const & a, Point2D<T> const & b, Point2D<T> const & c)
        : m_a(a), m_b(b), m_c(c) {
    }

    /// @brief Copy constructor
    /// @tparam T Type of the triangle
    /// @param triangle Triangle2D to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Triangle2D<T>::Triangle2D(Triangle2D<T> const & triangle)
        : m_a(triangle.m_a), m_b(triangle.m_b), m_c(triangle.m_c) {
    }

    /// @brief Move constructor
    /// @tparam T Type of the triangle
    /// @param triangle Triangle2D to move
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Triangle2D<T>::Triangle2D(Triangle2D<T> && triangle) noexcept
        : m_a(std::move(triangle.m_a)), m_b(std::move(triangle.m_b)), m_c(std::move(triangle.m_c)) {
    }

    /// @brief Copy assignment operator
    /// @tparam T Type of the triangle
    /// @param triangle Triangle2D to copy
    /// @return Reference to this
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Triangle2D<T> & Triangle2D<T>::operator=(Triangle2D<T> const & triangle) {
        m_a = triangle.m_a;
        m_b = triangle.m_b;
        m_c = triangle.m_c;
        return *this;
    }

    /// @brief Move assignment operator
    /// @tparam T Type of the triangle
    /// @param triangle Triangle2D to move
    /// @return Reference to this
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Triangle2D<T> & Triangle2D<T>::operator=(Triangle2D<T> && triangle) noexcept {
        m_a = std::move(triangle.m_a);
        m_b = std::move(triangle.m_b);
        m_c = std::move(triangle.m_c);
        return *this;
    }

    /// @brief Equality operator
    /// @tparam T Type of the triangle
    /// @param triangle Triangle2D to compare
    /// @return True if equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T> bool
    Triangle2D<T>::operator==(Triangle2D<T> const & triangle) const {
        return m_a == triangle.m_a && m_b == triangle.m_b && m_c == triangle.m_c;
    }

    /// @brief Inequality operator
    /// @tparam T Type of the triangle
    /// @param triangle Triangle2D to compare
    /// @return True if not equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T> bool
    Triangle2D<T>::operator!=(Triangle2D<T> const & triangle) const {
        return !(*this == triangle);
    }

    /// @brief Get the first point
    /// @tparam T Type of the triangle
    /// @return First point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Point2D<T> Triangle2D<T>::getA() const {
        return m_a;
    }

    /// @brief Get the second point
    /// @tparam T Type of the triangle
    /// @return Second point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Point2D<T> Triangle2D<T>::getB() const {
        return m_b;
    }

    /// @brief Get the third point
    /// @tparam T Type of the triangle
    /// @return Third point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Point2D<T> Triangle2D<T>::getC() const {
        return m_c;
    }

    /// @brief Get the area of the triangle
    /// @tparam T Type of the triangle
    /// @return Area of the triangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Triangle2D<T>::getArea() const {
        return 0.5 * m_a.distance(m_b) * m_a.distance(m_c) * std::sin(getAngleA());
    }

    /// @brief Get the perimeter of the triangle
    /// @tparam T Type of the triangle
    /// @return Perimeter of the triangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Triangle2D<T>::getPerimeter() const {
        return m_a.distance(m_b) + m_b.distance(m_c) + m_c.distance(m_a);
    }

    /// @brief Get the angle A of the triangle
    /// @tparam T Type of the triangle
    /// @return Angle A of the triangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Triangle2D<T>::getAngleA() const {
        T a = m_b.distance(m_c);
        T b = m_c.distance(m_a);
        T c = m_a.distance(m_b);
        return std::acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / MATH_PI;
    }

    /// @brief Get the angle B of the triangle
    /// @tparam T Type of the triangle
    /// @return Angle B of the triangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Triangle2D<T>::getAngleB() const {
        T a = m_b.distance(m_c);
        T b = m_c.distance(m_a);
        T c = m_a.distance(m_b);
        return std::acos((c * c + a * a - b * b) / (2 * c * a)) * 180.0 / MATH_PI;
    }

    /// @brief Get the angle C of the triangle
    /// @tparam T Type of the triangle
    /// @return Angle C of the triangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Triangle2D<T>::getAngleC() const {
        T a = m_b.distance(m_c);
        T b = m_c.distance(m_a);
        T c = m_a.distance(m_b);
        return std::acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / MATH_PI;
    }

} // namespace Tobot::Math