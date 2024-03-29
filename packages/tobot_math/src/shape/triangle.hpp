#pragma once
#include "../pre_compiled_header.hpp"

#include "../point2d.hpp"

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
            auto operator=(Triangle2D<T> const &) -> Triangle2D<T> &;

            /// @brief Move assignment operator
            /// @param triangle Triangle2D to move
            /// @return Reference to this
            auto operator=(Triangle2D<T> &&) noexcept -> Triangle2D<T> &;

            /// @brief Equality operator
            /// @param triangle Triangle2D to compare
            /// @return True if equal, false otherwise
            auto operator==(Triangle2D<T> const &) const -> bool;

            /// @brief Inequality operator
            /// @param triangle Triangle2D to compare
            /// @return True if not equal, false otherwise
            auto operator!=(Triangle2D<T> const &) const -> bool;

            /// @brief Get the first point
            /// @return First point
            auto getA() const -> Point2D<T>;

            /// @brief Get the second point
            /// @return Second point
            auto getB() const -> Point2D<T>;

            /// @brief Get the third point
            /// @return Third point
            auto getC() const -> Point2D<T>;

            auto getArea() const -> T;

            auto getPerimeter() const -> T;

            auto getAngleA() const -> T;

            auto getAngleB() const -> T;

            auto getAngleC() const -> T;

            friend auto operator<<(std::ostream & os, Triangle2D<T> const & triangle) -> std::ostream & {
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
    auto Triangle2D<T>::operator=(Triangle2D<T> const & triangle) -> Triangle2D<T> & {
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
    auto Triangle2D<T>::operator=(Triangle2D<T> && triangle) noexcept -> Triangle2D<T> & {
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
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Triangle2D<T>::operator==(Triangle2D<T> const & triangle) const -> bool {
        return m_a == triangle.m_a && m_b == triangle.m_b && m_c == triangle.m_c;
    }

    /// @brief Inequality operator
    /// @tparam T Type of the triangle
    /// @param triangle Triangle2D to compare
    /// @return True if not equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Triangle2D<T>::operator!=(Triangle2D<T> const & triangle) const -> bool {
        return !(*this == triangle);
    }

    /// @brief Get the first point
    /// @tparam T Type of the triangle
    /// @return First point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Triangle2D<T>::getA() const -> Point2D<T> {
        return m_a;
    }

    /// @brief Get the second point
    /// @tparam T Type of the triangle
    /// @return Second point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Triangle2D<T>::getB() const -> Point2D<T> {
        return m_b;
    }

    /// @brief Get the third point
    /// @tparam T Type of the triangle
    /// @return Third point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Triangle2D<T>::getC() const -> Point2D<T> {
        return m_c;
    }

    /// @brief Get the area of the triangle
    /// @tparam T Type of the triangle
    /// @return Area of the triangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Triangle2D<T>::getArea() const -> T {
        return 0.5 * m_a.distance(m_b) * m_a.distance(m_c) * std::sin(getAngleA());
    }

    /// @brief Get the perimeter of the triangle
    /// @tparam T Type of the triangle
    /// @return Perimeter of the triangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Triangle2D<T>::getPerimeter() const -> T {
        return m_a.distance(m_b) + m_b.distance(m_c) + m_c.distance(m_a);
    }

    /// @brief Get the angle A of the triangle
    /// @tparam T Type of the triangle
    /// @return Angle A of the triangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Triangle2D<T>::getAngleA() const -> T {
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
    [[nodiscard]] auto Triangle2D<T>::getAngleB() const -> T {
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
    [[nodiscard]] auto Triangle2D<T>::getAngleC() const -> T {
        T a = m_b.distance(m_c);
        T b = m_c.distance(m_a);
        T c = m_a.distance(m_b);
        return std::acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / MATH_PI;
    }

} // namespace Tobot::Math