#pragma once

#include "pre_compiled_header.h"

#include "concepts.h"
#include "point2D.h"

namespace Tobot::Math {
    /// @brief Models a linear slope or gradient in 2D space
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Gradient2D {
        public:
            Gradient2D(T m_slope, T m_yIntercept);
            Gradient2D(Gradient2D<T> const & gradient);
            Gradient2D(Gradient2D<T> && gradient) noexcept;
            ~Gradient2D();
            bool operator==(Gradient2D<T> const & gradient) const;
            bool operator!=(Gradient2D<T> const & gradient) const;
            T at(T x) const;
            T & getSlope();
            const T & getSlope() const;
            T & getYIntercept();
            const T & getYIntercept() const;
            bool intersects(Gradient2D<T> const & intersection) const;
            bool intersects(Point2D<T> & intersection) const;
            Point2D<T> * intersection(Gradient2D<T> const & gradient) const;

        private:
            // The slope of the gradient
            T m_slope;
            // The y-intercept of the gradient
            T m_yIntercept;
    };

    /// @brief Default constructor
    /// @tparam T The type of the gradient
    /// @param m_slope The slope of the gradient
    /// @param m_yIntercept The y-intercept of the gradient
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    Gradient2D<T>::Gradient2D(T m_slope, T m_yIntercept) {
        this->m_slope = m_slope;
        this->m_yIntercept = m_yIntercept;
    }

    /// @brief Copy constructor
    /// @tparam T The type of the gradient
    /// @param gradient The gradient to copy
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    Gradient2D<T>::Gradient2D(Gradient2D<T> const & gradient) {
        this->m_slope = gradient.m_slope;
        this->m_yIntercept = gradient.m_yIntercept;
    }

    /// @brief Move constructor
    /// @tparam T The type of the gradient
    /// @param gradient The gradient to move
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    Gradient2D<T>::Gradient2D(Gradient2D<T> && gradient) noexcept {
        this->m_slope = std::move(gradient.m_slope);
        this->m_yIntercept = std::move(gradient.m_yIntercept);
    }

    /// @brief Destructor
    /// @tparam T The type of the gradient
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    Gradient2D<T>::~Gradient2D() {
    }

    /// @brief Gets the y-intercept of the gradient
    /// @tparam T The type of the gradient
    /// @param x The x coordinate
    /// @return The y coordinate
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    T Gradient2D<T>::at(T x) const {
        return m_slope * x + m_yIntercept;
    }

    /// @brief Equality operator
    /// @tparam T The type of the gradient
    /// @param gradient The gradient to compare to
    /// @return True if the gradients are equal, false otherwise
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    bool Gradient2D<T>::operator==(Gradient2D<T> const & gradient) const {
        return this->m_slope == gradient.m_slope && this->m_yIntercept == gradient.m_yIntercept;
    }

    /// @brief Inequality operator
    /// @tparam T The type of the gradient
    /// @param gradient The gradient to compare to
    /// @return True if the gradients are not equal, false otherwise
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    bool Gradient2D<T>::operator!=(Gradient2D<T> const & gradient) const {
        return !(*this == gradient);
    }

    /// @brief Gets the slope of the gradient
    /// @tparam T The type of the gradient
    /// @return The slope of the gradient
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    T & Gradient2D<T>::getSlope() {
        return m_slope;
    }

    /// @brief Gets the slope of the gradient
    /// @tparam T The type of the gradient
    /// @return The slope of the gradient
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    const T & Gradient2D<T>::getSlope() const {
        return m_slope;
    }

    /// @brief Gets the y-intercept of the gradient
    /// @tparam T The type of the gradient
    /// @return The y-intercept of the gradient
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    T & Gradient2D<T>::getYIntercept() {
        return m_yIntercept;
    }

    /// @brief Gets the y-intercept of the gradient
    /// @tparam T The type of the gradient
    /// @return The y-intercept of the gradient
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    const T & Gradient2D<T>::getYIntercept() const {
        return m_yIntercept;
    }

    /// @brief Determines if the gradient intersects the other gradient
    /// @tparam T The type of the gradient
    /// @param intersection The gradient to check for intersection
    /// @return true if the gradients intersect, false otherwise
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    bool Gradient2D<T>::intersects(Gradient2D<T> const & intersection) const {
        // If the slopes are equal, then the gradients are parallel and do not intersect
        return this->m_slope != intersection.m_slope;
    }

    /// @brief Determines if the gradient intersects the point
    /// @tparam T The type of the gradient
    /// @param intersection The point to check for intersection
    /// @return true if the gradient intersects the point, false otherwise
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    bool Gradient2D<T>::intersects(Point2D<T> & intersection) const {
        if (this->at(intersection.x) == intersection.y) {
            return true;
        }
        return false;
    }

    /// @brief Gets the point of intersection between the gradient and the other gradient
    /// @tparam T The type of the gradient
    /// @param gradient The gradient to check for intersection
    /// @return The point of intersection between the gradients, or a nullpointer, if the gradients do not intersect
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    Point2D<T> * Gradient2D<T>::intersection(Gradient2D<T> const & gradient) const {
        // If the gradients are parallel, then there is no intersection
        if (!this->intersects(gradient)) {
            return nullptr;
        }

        // Get the x coordinate of the intersection
        T x = (gradient.m_yIntercept - this->m_yIntercept) / (this->m_slope - gradient.m_slope);
        // Get the y coordinate of the intersection
        T y = this->at(x);

        return new Point2D<T>(x, y);
    }
} // namespace Tobot::Math
