#pragma once

#include "pre_compiled_header.h"

namespace Tobot::Math {
    /// @brief Models a point in 2D space
    class Point2D {

        public:
            /// @brief Default constructor
            Point2D() = default;

            /// @brief Constructor
            /// @param x X coordinate
            /// @param y Y coordinate
            Point2D(const float & x, const float & y);

            /// @brief Copy constructor
            /// @param point Point to copy
            Point2D(const Point2D & point);

            /// @brief Move constructor
            /// @param point Point to move
            Point2D(Point2D &&) noexcept;

            /// @brief Destructor
            ~Point2D() = default;

            /// @brief Copy assignment operator
            /// @param point Point to copy
            /// @return Reference to this
            Point2D & operator=(const Point2D &);

            /// @brief Move assignment operator
            /// @param point Point to move
            /// @return Reference to this
            Point2D & operator=(Point2D &&) noexcept;

            /// @brief Equality operator
            /// @param point Point to compare
            /// @return True if equal, false otherwise
            bool operator==(const Point2D &) const;

            /// @brief Inequality operator
            /// @param point Point to compare
            /// @return True if not equal, false otherwise
            bool operator!=(const Point2D &) const;

            /// @brief Less than operator
            /// @param point Point to compare
            /// @return True if less than, false otherwise
            float distance(const Point2D &) const;

            /// @brief Less than or equal operator
            /// @param point Point to compare
            /// @param epsilon Epsilon value
            /// @return True if less than or equal, false otherwise
            float distance(const float &, const float &) const;

            /// @brief Greater than operator
            /// @param point Point to compare
            /// @return True if greater than, false otherwise
            float distanceSquared(const Point2D &) const;

            /// @brief Greater than or equal operator
            /// @param point Point to compare
            /// @param epsilon Epsilon value
            /// @return True if greater than or equal, false otherwise
            float distanceSquared(const float &, const float &) const;

            /// @brief Cross product
            /// @return Cross product
            float x() const;

            /// @brief Cross product
            /// @return Cross product
            float y() const;

            /// @brief Set X coordinate
            /// @param x X coordinate
            void setX(const float &);

            /// @brief Set Y coordinate
            /// @param y Y coordinate
            void setY(const float &);

        private:
            /// @brief X coordinate
            float m_x;

            /// @brief Y coordinate
            float m_y;
    };
} // namespace Tobot::Math