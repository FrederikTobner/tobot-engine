#pragma once

#include "pre_compiled_header.h"

#include "concepts.h"
#include "vector/vector3d.h"

/// @brief A plane in 3D space.
namespace Tobot::Math {
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Plane {
        public:
            Plane();
            Plane(T a, T b, T c, T d);
            Plane(Vector3D<T> const & normal, T d);
            Plane(Vector3D<T> const & normal, Vector3D<T> const & point);
            Plane(Vector3D<T> const & point1, Vector3D<T> const & point2, Vector3D<T> const & point3);
            Plane(Plane<T> const & plane);
            Plane(Plane<T> && plane);
            Plane<T> & operator=(Plane<T> const & plane);
            Plane<T> & operator=(Plane<T> && plane);
            ~Plane();
            T & operator()(std::size_t i);
            T operator()(std::size_t i) const;
            T & operator[](std::size_t i);
            T operator[](std::size_t i) const;
            T distance(const Vector3D<T> & point) const;
            Vector3D<T> getNormal() const;
            bool operator==(Plane<T> const & plane) const;
            bool operator!=(Plane<T> const & plane) const;
            friend std::ostream & operator<<(std::ostream & os, Plane<T> const & plane) {
                os << "(" << plane.a << ", " << plane.b << ", " << plane.c << ", " << plane.d << ")";
                return os;
            }
            T getA() const;
            T getB() const;
            T getC() const;
            T getD() const;

        private:
            T a;
            T b;
            T c;
            T d;
    };

    /// @brief Default constructor
    /// @tparam T The type of the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Plane<T>::Plane() {
    }

    /// @brief Constructor
    /// @tparam T The type of the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Plane<T>::Plane(T a, T b, T c, T d) : a(a), b(b), c(c), d(d) {
    }

    /// @brief Constructor
    /// @tparam T The type of the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Plane<T>::Plane(Vector3D<T> const & normal, T d) : a(normal(0)), b(normal(1)), c(normal(2)), d(d) {
    }

    /// @brief Constructor
    /// @tparam T The type of the plane
    /// @param normal The normal of the plane
    /// @param point A point on the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Plane<T>::Plane(Vector3D<T> const & normal, Vector3D<T> const & point)
        : a(normal(0)), b(normal(1)), c(normal(2)), d(-normal.Dot(point)) {
    }

    /// @brief Constructor
    /// @tparam T The type of the plane
    /// @param point1 The first point on the plane
    /// @param point2 The second point on the plane
    /// @param point3 The third point on the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Plane<T>::Plane(Vector3D<T> const & point1, Vector3D<T> const & point2, Vector3D<T> const & point3) {
        Vector<T> normal = (point2 - point1).Cross(point3 - point1);
        normal.Normalize();
        a = normal(0);
        b = normal(1);
        c = normal(2);
        d = -normal.Dot(point1);
    }

    /// @brief Copy constructor
    /// @tparam T The type of the plane
    /// @param plane The plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Plane<T>::Plane(Plane<T> const & plane) : a(plane.a), b(plane.b), c(plane.c), d(plane.d) {
    }

    /// @brief Move constructor
    /// @tparam T The type of the plane
    /// @param plane The plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Plane<T>::Plane(Plane<T> && plane) : a(plane.a), b(plane.b), c(plane.c), d(plane.d) {
    }

    /// @brief Copy assignment operator
    /// @tparam T The type of the plane
    /// @param plane The plane
    /// @return The distance between the plane and a point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Plane<T> & Plane<T>::operator=(Plane<T> const & plane) {
        a = plane.a;
        b = plane.b;
        c = plane.c;
        d = plane.d;
        return *this;
    }

    /// @brief GMove assignment operator
    /// @tparam T The type of the plane
    /// @param plane The plane
    /// @return The distance between the plane and a point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Plane<T> & Plane<T>::operator=(Plane<T> && plane) {
        a = plane.a;
        b = plane.b;
        c = plane.c;
        d = plane.d;
        return *this;
    }

    /// @brief Destructor
    /// @tparam T The type of the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Plane<T>::~Plane() {
    }

    /// @brief Gets a component of the plane
    /// @tparam T The type of the plane
    /// @param i The index of the component
    /// @return The component of the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] T & Plane<T>::operator()(std::size_t i) {
        switch (i) {
        case 0:
            return a;
        case 1:
            return b;
        case 2:
            return c;
        case 3:
            return d;
        default:
            throw std::out_of_range("Plane index out of range.");
        }
    }

    /// @brief Gets a component of the plane
    /// @tparam T The type of the plane
    /// @param i The index of the component
    /// @return The component of the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] T Plane<T>::operator()(std::size_t i) const {
        switch (i) {
        case 0:
            return a;
        case 1:
            return b;
        case 2:
            return c;
        case 3:
            return d;
        default:
            throw std::out_of_range("Plane index out of range.");
        }
    }

    /// @brief Gets a component of the plane
    /// @tparam T The type of the plane
    /// @param i The index of the component
    /// @return The component of the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] T & Plane<T>::operator[](std::size_t i) {
        switch (i) {
        case 0:
            return a;
        case 1:
            return b;
        case 2:
            return c;
        case 3:
            return d;
        default:
            throw std::out_of_range("Plane index out of range.");
        }
    }

    /// @brief Gets a component of the plane
    /// @tparam T The type of the plane
    /// @param i The index of the component
    /// @return The component of the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] T Plane<T>::operator[](std::size_t i) const {
        switch (i) {
        case 0:
            return a;
        case 1:
            return b;
        case 2:
            return c;
        case 3:
            return d;
        default:
            throw std::out_of_range("Plane index out of range.");
        }
    }

    /// @brief Get the distance between the plane and a point
    /// @tparam T The type of the plane
    /// @param point The point
    /// @return The distance between the plane and a point
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] T Plane<T>::distance(Vector3D<T> const & point) const {
        return a * point(0) + b * point(1) + c * point(2) + d;
    }

    /// @brief Get the normal of the plane
    /// @tparam T The type of the plane
    /// @return The normal of the plane
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] Vector3D<T> Plane<T>::getNormal() const {
        return Vector3D<T>(a, b, c);
    }

    /// @brief Check if the plane is equal to another plane
    /// @tparam T The type of the plane
    /// @param plane The plane to check
    /// @return true if the plane is equal to another plane, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] bool Plane<T>::operator==(Plane<T> const & plane) const {
        return a == plane.a && b == plane.b && c == plane.c && d == plane.d;
    }

    /// @brief Check if the plane is not equal to another plane
    /// @tparam T The type of the plane
    /// @param plane The plane to check
    /// @return true if the plane is not equal to another plane, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] bool Plane<T>::operator!=(Plane<T> const & plane) const {
        return a != plane.a || b != plane.b || c != plane.c || d != plane.d;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] T Plane<T>::getA() const {
        return a;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] T Plane<T>::getB() const {
        return b;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] T Plane<T>::getC() const {
        return c;
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] T Plane<T>::getD() const {
        return d;
    }

} // namespace Tobot::Math