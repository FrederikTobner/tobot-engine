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

            Rectangle2D(const Point2D<T> & center, const T & width, const T & height, const T & rotation);

            Rectangle2D(const Rectangle2D<T> & rectangle);

            Rectangle2D(Rectangle2D<T> &&) noexcept;

            ~Rectangle2D() = default;

            Rectangle2D<T> & operator=(const Rectangle2D<T> &);

            Rectangle2D<T> & operator=(Rectangle2D<T> &&) noexcept;

            bool operator==(const Rectangle2D<T> &) const;

            bool operator!=(const Rectangle2D<T> &) const;

            Point2D<T> getCenter() const;

            T getWidth() const;

            T getHeight() const;

            T getRotation() const;

            T getArea() const;

            T getPerimeter() const;

            bool contains(const Point2D<T> &) const;

        private:
            Point2D<T> center;
            T width;
            T height;
            T rotation;
    };

    /// @brief Models a Cicle in 2D space
    /// @tparam T Type of the rectangle
    /// @param center Center of the rectangle
    /// @param width Width of the rectangle
    /// @param height Height of the rectangle
    /// @param rotation Rotation of the rectangle
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Rectangle2D<T>::Rectangle2D(const Point2D<T> & center, const T & width, const T & height, const T & rotation)
        : center(center), width(width), height(height), rotation(rotation) {
    }

    /// @brief Copy constructor
    /// @tparam T Type of the rectangle
    /// @param rectangle Rectangle to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Rectangle2D<T>::Rectangle2D(const Rectangle2D<T> & rectangle)
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
    Rectangle2D<T> & Rectangle2D<T>::operator=(const Rectangle2D<T> & rectangle) {
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
        requires ArithmeticFloatingPoint<T> bool
    Rectangle2D<T>::operator==(const Rectangle2D<T> & rectangle) const {
        return center == rectangle.center && width == rectangle.width && height == rectangle.height &&
               rotation == rectangle.rotation;
    }

    /// @brief Inequality operator
    /// @tparam T Type of the rectangle
    /// @param rectangle Rectangle to compare to
    /// @return True if the two rectangles are not equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T> bool
    Rectangle2D<T>::operator!=(const Rectangle2D<T> & rectangle) const {
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
        requires ArithmeticFloatingPoint<T> bool
    Rectangle2D<T>::contains(const Point2D<T> & point) const {
        return rotation == 0.0
                   ? point.x() >= center.x() - width / 2 && point.x() <= center.x() + width / 2 &&
                         point.y() >= center.y() - height / 2 && point.y() <= center.y() + height / 2
                   : (point.x() - center.x()) * std::cos(rotation) - (point.y() - center.y()) * std::sin(rotation) <=
                             width / 2 &&
                         (point.x() - center.x()) * std::cos(rotation) -
                                 (point.y() - center.y()) * std::sin(rotation) >=
                             -width / 2 &&
                         (point.x() - center.x()) * std::sin(rotation) +
                                 (point.y() - center.y()) * std::cos(rotation) <=
                             height / 2 &&
                         (point.x() - center.x()) * std::sin(rotation) +
                                 (point.y() - center.y()) * std::cos(rotation) >=
                             -height / 2;
    }

} // namespace Tobot::Math