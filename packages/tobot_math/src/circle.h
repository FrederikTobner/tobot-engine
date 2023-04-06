#pragma once

#include "pre_compiled_header.h"

#include "point2d.h"

namespace Tobot::Math {
    /// @brief Models a Cicle in 2D space
    class Circle {
        public:
            /// @brief Default constructor
            Circle() = default;

            /// @brief Constructor
            /// @param center Center of the circle
            /// @param radius Radius of the circle
            Circle(const Point2D & center, const float & radius);

            /// @brief Copy constructor
            /// @param circle Circle to copy
            Circle(const Circle & circle);

            /// @brief Move constructor
            /// @param circle Circle to move
            Circle(Circle &&) noexcept;

            /// @brief Destructor
            ~Circle() = default;

            /// @brief Copy assignment operator
            /// @param circle Circle to copy
            /// @return Reference to this
            Circle & operator=(const Circle &);

            /// @brief Move assignment operator
            /// @param circle Circle to move
            /// @return Reference to this
            Circle & operator=(Circle &&) noexcept;

            /// @brief Equality operator
            /// @param circle Circle to compare
            /// @return True if equal, false otherwise
            bool operator==(const Circle &) const;

            /// @brief Inequality operator
            /// @param circle Circle to compare
            /// @return True if not equal, false otherwise
            bool operator!=(const Circle &) const;

            /// @brief Less than operator
            /// @param circle Circle to compare
            /// @return True if less than, false otherwise
            bool operator<(const Circle &) const;

            /// @brief Greater than operator
            /// @param circle Circle to compare
            /// @return True if greater than, false otherwise
            bool operator>(const Circle &) const;

            /// @brief Less than or equal operator
            /// @param circle Circle to compare
            /// @return True if less than or equal, false otherwise
            bool operator<=(const Circle &) const;

            /// @brief Greater than or equal operator
            /// @param circle Circle to compare
            /// @return True if greater than or equal, false otherwise
            bool operator>=(const Circle &) const;

            /// @brief Get the center of the circle
            /// @return Center of the circle
            Point2D center() const;

            /// @brief Get the radius of the circle
            /// @return Radius of the circle
            float radius() const;

            /// @brief Set the center of the circle
            /// @param center Center of the circle
            void setCenter(const Point2D &);

            /// @brief Set the radius of the circle
            /// @param radius Radius of the circle
            void setRadius(const float &);

            /// @brief Get the area of the circle
            /// @return Area of the circle
            float getArea() const;

        private:
            Point2D m_center;
            float m_radius;
    };
} // namespace Tobot::Math
