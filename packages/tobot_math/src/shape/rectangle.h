#pragma once
#include "../pre_compiled_header.h"

#include "../point2d.h"

namespace Tobot::Math {
    /// @brief Models a Cicle in 2D space
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Rectangle2D {
        public:
            Rectangle2D() = default;

            Rectangle2D(T x, T y, T width, T height, T rotation);

            Rectangle2D(Point2D<T> const & center, T const & width, T const & height, T const & rotation);

            Rectangle2D(std::initializer_list<T> list);

            Rectangle2D(Rectangle2D<T> const & rectangle);

            Rectangle2D(Rectangle2D<T> &&) noexcept;

            ~Rectangle2D() = default;

            Rectangle2D<T> & operator=(Rectangle2D<T> const &);

            Rectangle2D<T> & operator=(Rectangle2D<T> &&) noexcept;

            bool operator==(Rectangle2D<T> const &) const;

            bool operator!=(Rectangle2D<T> const &) const;

            Point2D<T> getCenter() const;

            T getWidth() const;

            T getHeight() const;

            T getRotation() const;

            T getArea() const;

            T getPerimeter() const;

            bool contains(Point2D<T> const &) const;

            friend std::ostream & operator<<(std::ostream & os, Rectangle2D<T> const & rectangle) {
                os << "Rectangle2D(" << rectangle.center << ", " << rectangle.width << ", " << rectangle.height << ", "
                   << rectangle.rotation << ")";
                return os;
            }

        private:
            Point2D<T> center;
            T width;
            T height;
            T rotation;
    };

    /// @brief Constructor
    /// @tparam T Type of the rectangle
    /// @param x X coordinate of the center of the rectangle
    /// @param y Y coordinate of the center of the rectangle
    /// @param width Width of the rectangle
    /// @param height Height of the rectangle
    /// @param rotation Rotation of the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Rectangle2D<T>::Rectangle2D(T x, T y, T width, T height, T rotation)
        : center(x, y), width(width), height(height), rotation(rotation) {
    }

    /// @brief Constructor
    /// @tparam T Type of the rectangle
    /// @param list List of values to initialize the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Rectangle2D<T>::Rectangle2D(std::initializer_list<T> list) {
        if (list.size() != 5) {
            throw std::invalid_argument("Invalid number of arguments");
        }

        auto it = list.begin();
        center = Point2D<T>(*it, *(it + 1));
        width = *(it + 2);
        height = *(it + 3);
        rotation = *(it + 4);
    }

    /// @brief Models a Cicle in 2D space
    /// @tparam T Type of the rectangle
    /// @param center Center of the rectangle
    /// @param width Width of the rectangle
    /// @param height Height of the rectangle
    /// @param rotation Rotation of the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Rectangle2D<T>::Rectangle2D(Point2D<T> const & center, T const & width, T const & height, T const & rotation)
        : center(center), width(width), height(height), rotation(rotation) {
    }

    /// @brief Copy constructor
    /// @tparam T Type of the rectangle
    /// @param rectangle Rectangle to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Rectangle2D<T>::Rectangle2D(Rectangle2D<T> const & rectangle)
        : center(rectangle.center), width(rectangle.width), height(rectangle.height), rotation(rectangle.rotation) {
    }

    /// @brief Move constructor
    /// @tparam T Type of the rectangle
    /// @param rectangle Rectangle to move
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Rectangle2D<T>::Rectangle2D(Rectangle2D<T> && rectangle) noexcept
        : center(std::move(rectangle.center)), width(std::move(rectangle.width)), height(std::move(rectangle.height)),
          rotation(std::move(rectangle.rotation)) {
    }

    /// @brief Copy assignment operator
    /// @tparam T Type of the rectangle
    /// @param rectangle Rectangle to copy
    /// @return Reference to this
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Rectangle2D<T> & Rectangle2D<T>::operator=(Rectangle2D<T> const & rectangle) {
        center = rectangle.center;
        width = rectangle.width;
        height = rectangle.height;
        rotation = rectangle.rotation;
        return *this;
    }

    /// @brief Move assignment operator
    /// @tparam T Type of the rectangle
    /// @param rectangle Rectangle to move
    /// @return Reference to this
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Rectangle2D<T> & Rectangle2D<T>::operator=(Rectangle2D<T> && rectangle) noexcept {
        center = std::move(rectangle.center);
        width = std::move(rectangle.width);
        height = std::move(rectangle.height);
        rotation = std::move(rectangle.rotation);
        return *this;
    }

    /// @brief Equality operator
    /// @tparam T Type of the rectangle
    /// @param rectangle Rectangle to compare to
    /// @return True if the two rectangles are equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    bool Rectangle2D<T>::operator==(Rectangle2D<T> const & rectangle) const {
        return center == rectangle.center && width == rectangle.width && height == rectangle.height &&
               rotation == rectangle.rotation;
    }

    /// @brief Inequality operator
    /// @tparam T Type of the rectangle
    /// @param rectangle Rectangle to compare to
    /// @return True if the two rectangles are not equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    bool Rectangle2D<T>::operator!=(Rectangle2D<T> const & rectangle) const {
        return center != rectangle.center || width != rectangle.width || height != rectangle.height ||
               rotation != rectangle.rotation;
    }

    /// @brief Get the center of the rectangle
    /// @tparam T Type of the rectangle
    /// @return Center of the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Point2D<T> Rectangle2D<T>::getCenter() const {
        return center;
    }

    /// @brief Get the width of the rectangle
    /// @tparam T Type of the rectangle
    /// @return Width of the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Rectangle2D<T>::getWidth() const {
        return width;
    }

    /// @brief Get the height of the rectangle
    /// @tparam T Type of the rectangle
    /// @return Height of the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Rectangle2D<T>::getHeight() const {
        return height;
    }

    /// @brief Get the rotation of the rectangle
    /// @tparam T Type of the rectangle
    /// @return Rotation of the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Rectangle2D<T>::getRotation() const {
        return rotation;
    }

    /// @brief Get the area of the rectangle
    /// @tparam T Type of the rectangle
    /// @return Area of the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Rectangle2D<T>::getArea() const {
        return width * height;
    }

    /// @brief Get the perimeter of the rectangle
    /// @tparam T Type of the rectangle
    /// @return Perimeter of the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Rectangle2D<T>::getPerimeter() const {
        return 2 * (width + height);
    }

    /// @brief Check if a point is inside the rectangle
    /// @tparam T Type of the rectangle
    /// @param point Point to check
    /// @return True if the point is inside the rectangle, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    bool Rectangle2D<T>::contains(Point2D<T> const & point) const {
        return rotation == 0.0
                   ? point.getX() >= center.getX() - width / 2 && point.getX() <= center.getX() + width / 2 &&
                         point.getY() >= center.getY() - height / 2 && point.getY() <= center.getY() + height / 2
                   : (point.getX() - center.getX()) * std::cos(rotation) -
                                 (point.getY() - center.getY()) * std::sin(rotation) <=
                             width / 2 &&
                         (point.getX() - center.getX()) * std::cos(rotation) -
                                 (point.getY() - center.getY()) * std::sin(rotation) >=
                             -width / 2 &&
                         (point.getX() - center.getX()) * std::sin(rotation) +
                                 (point.getY() - center.getY()) * std::cos(rotation) <=
                             height / 2 &&
                         (point.getX() - center.getX()) * std::sin(rotation) +
                                 (point.getY() - center.getY()) * std::cos(rotation) >=
                             -height / 2;
    }

} // namespace Tobot::Math