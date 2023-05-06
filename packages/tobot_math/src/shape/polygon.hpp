#pragma once

#include "../pre_compiled_header.hpp"

#include "../point2d.hpp"
#include "circle.hpp"

namespace Tobot::Math {
    /// @brief Models a Polygon in 2D space
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Polygon2D {
        public:
            /// @brief Default constructor
            Polygon2D() = default;

            /// @brief Constructor
            /// @param points Points of the polygon
            Polygon2D(std::vector<Point2D<T>> const & points);

            /// @brief Constructor
            /// @param points Points of the polygon
            Polygon2D(std::initializer_list<Point2D<T>> const & points);

            /// @brief Copy constructor
            /// @param polygon Polygon to copy
            Polygon2D(Polygon2D<T> const & polygon);

            /// @brief Move constructor
            /// @param polygon Polygon to move
            Polygon2D(Polygon2D<T> &&) noexcept;

            /// @brief Destructor
            ~Polygon2D() = default;

            /// @brief Copy assignment operator
            /// @param polygon Polygon to copy
            /// @return Reference to this
            auto operator=(Polygon2D<T> const &) -> Polygon2D<T> &;

            /// @brief Move assignment operator
            /// @param polygon Polygon to move
            /// @return Reference to this
            auto operator=(Polygon2D<T> &&) noexcept -> Polygon2D<T> &;

            /// @brief Equality operator
            /// @param polygon Polygon to compare
            /// @return True if equal, false otherwise
            auto operator==(Polygon2D<T> const &) const -> bool;

            /// @brief Inequality operator
            /// @param polygon Polygon to compare
            /// @return True if not equal, false otherwise
            auto operator!=(Polygon2D<T> const &) const -> bool;

            /// @brief Get the points of the polygon
            /// @return Points of the polygon
            auto getPoints() const -> std::vector<Point2D<T>>;

            /// @brief Get the number of points of the polygon
            /// @return Number of points of the polygon
            auto getNumberOfPoints() const -> std::size_t;

            /// @brief Get the area of the polygon
            /// @return Area of the polygon
            auto getArea() const -> T;

            /// @brief Get the perimeter of the polygon
            /// @return Perimeter of the polygon
            auto getPerimeter() const -> T;

            /// @brief Get the centroid of the polygon
            /// @return Centroid of the polygon
            auto getCentroid() const -> Point2D<T>;

            auto isConvex() const -> bool;

            friend auto operator<<(std::ostream & os, Polygon2D<T> const & polygon) -> std::ostream & {
                os << "Polygon2D(";
                for (const auto & point : polygon.points) {
                    os << point << ", ";
                }
                os << ")";
                return os;
            }

        private:
            std::vector<Point2D<T>> points;
    };

    /// @brief Constructor
    /// @param points Points of the polygon
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Polygon2D<T>::Polygon2D(std::vector<Point2D<T>> const & points) : points(points) {
    }

    /// @brief Constructor
    /// @param points Points of the polygon
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Polygon2D<T>::Polygon2D(std::initializer_list<Point2D<T>> const & points) : points(points) {
    }

    /// @brief Copy constructor
    /// @param polygon Polygon to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Polygon2D<T>::Polygon2D(Polygon2D<T> const & polygon) : points(polygon.points) {
    }

    /// @brief Move constructor
    /// @param polygon Polygon to move
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Polygon2D<T>::Polygon2D(Polygon2D<T> &&) noexcept : points(std::move(points)) {
    }

    /// @brief Copy assignment operator
    /// @param polygon Polygon to copy
    /// @return Reference to this
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Polygon2D<T>::operator=(Polygon2D<T> const & polygon) -> Polygon2D<T> & {
        points = polygon.points;
        return *this;
    }

    /// @brief Move assignment operator
    /// @param polygon Polygon to move
    /// @return Reference to this
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Polygon2D<T>::operator=(Polygon2D<T> && polygon) noexcept -> Polygon2D<T> & {
        points = std::move(polygon.points);
        return *this;
    }

    /// @brief Equality operator
    /// @param polygon Polygon to compare
    /// @return True if equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Polygon2D<T>::operator==(Polygon2D<T> const & polygon) const -> bool {
        return points == polygon.points;
    }

    /// @brief Inequality operator
    /// @param polygon Polygon to compare
    /// @return True if not equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Polygon2D<T>::operator!=(Polygon2D<T> const & polygon) const -> bool {
        return points != polygon.points;
    }

    /// @brief Get the points of the polygon
    /// @return Points of the polygon
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Polygon2D<T>::getPoints() const -> std::vector<Point2D<T>> {
        return points;
    }

    /// @brief Get the number of points of the polygon
    /// @return Number of points of the polygon
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Polygon2D<T>::getNumberOfPoints() const -> std::size_t {
        return points.size();
    }

    /// @brief Get the area of the polygon
    /// @return Area of the polygon
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Polygon2D<T>::getArea() const -> T {
        T area = 0;
        for (size_t i = 0; i < points.size(); i++) {
            size_t j = (i + 1) % points.size();
            area += points[i].getX() * points[j].getY() - points[j].getX() * points[i].getY();
        }
        return std::abs(area) / 2;
    }

    /// @brief Get the perimeter of the polygon
    /// @return Perimeter of the polygon
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Polygon2D<T>::getPerimeter() const -> T {
        T perimeter = 0;
        for (size_t i = 0; i < points.size(); i++) {
            size_t j = (i + 1) % points.size();
            perimeter += std::sqrt(std::pow(points[j].getX() - points[i].getX(), 2) +
                                   std::pow(points[j].getY() - points[i].getY(), 2));
        }
        return perimeter;
    }

    /// @brief Get the centroid of the polygon
    /// @return Centroid of the polygon
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Polygon2D<T>::getCentroid() const -> Point2D<T> {
        T area = getArea();
        T x = 0;
        T y = 0;
        for (size_t i = 0; i < points.size(); i++) {
            size_t j = (i + 1) % points.size();
            x += (points[i].getX() + points[j].getX()) *
                 (points[i].getX() * points[j].getY() - points[j].getX() * points[i].getY());
            y += (points[i].getY() + points[j].getY()) *
                 (points[i].getX() * points[j].getY() - points[j].getX() * points[i].getY());
        }
        return Point2D<T>(x / (6 * area), y / (6 * area));
    }

    /// @brief Check if the polygon is convex
    /// @return True if the polygon is convex, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Polygon2D<T>::isConvex() const -> bool {
        if (points.size() <= 3) {
            return true;
        }
        bool isPositive = false;
        for (size_t i = 0; i < points.size(); i++) {
            size_t j = (i + 1) % points.size();
            size_t k = (i + 2) % points.size();
            T z = (points[j].getX() - points[i].getX()) * (points[k].getY() - points[j].getY()) -
                  (points[j].getY() - points[i].getY()) * (points[k].getX() - points[j].getX());
            if (z < 0) {
                if (isPositive) {
                    return false;
                }
            } else if (z > 0) {
                if (!isPositive) {
                    isPositive = true;
                }
            }
        }
        return true;
    }

} // namespace Tobot::Math