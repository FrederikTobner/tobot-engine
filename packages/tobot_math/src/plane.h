#pragma once

#include "pre_compiled_header.h"

#include "concepts.h"
#include "vector/vector3d.h"

namespace Tobot::Math {
    template <typename T = float>
        requires Arithmetic<T>
    class Plane {
        public:
            Plane();
            Plane(T a, T b, T c, T d);
            Plane(const Vector3D<T> & normal, T d);
            Plane(const Vector3D<T> & normal, const Vector3D<T> & point);
            Plane(const Vector3D<T> & point1, const Vector3D<T> & point2, const Vector3D<T> & point3);
            Plane(const Plane<T> & plane);
            Plane(Plane<T> && plane);
            Plane<T> & operator=(const Plane<T> & plane);
            Plane<T> & operator=(Plane<T> && plane);
            ~Plane();
            T & operator()(std::size_t i);
            T operator()(std::size_t i) const;
            T & operator[](std::size_t i);
            T operator[](std::size_t i) const;
            T Distance(const Vector3D<T> & point) const;
            Vector3D<T> GetNormal() const;
            bool operator==(const Plane<T> & plane) const;
            bool operator!=(const Plane<T> & plane) const;
            friend std::ostream & operator<<(std::ostream & os, const Plane<T> & plane) {
                os << "(" << plane.a << ", " << plane.b << ", " << plane.c << ", " << plane.d << ")";
                return os;
            }

        private:
            T a;
            T b;
            T c;
            T d;
    };

    /// @brief Default constructor
    /// @tparam T The type of the plane
    template <typename T>
        requires Arithmetic<T>
    Plane<T>::Plane() {
    }

    /// @brief Constructor
    /// @tparam T The type of the plane
    template <typename T>
        requires Arithmetic<T>
    Plane<T>::Plane(T a, T b, T c, T d) : a(a), b(b), c(c), d(d) {
    }

    /// @brief Constructor
    /// @tparam T The type of the plane
    template <typename T>
        requires Arithmetic<T>
    Plane<T>::Plane(const Vector3D<T> & normal, T d) : a(normal(0)), b(normal(1)), c(normal(2)), d(d) {
    }

    /// @brief Constructor
    /// @tparam T The type of the plane
    /// @param normal The normal of the plane
    /// @param point A point on the plane
    template <typename T>
        requires Arithmetic<T>
    Plane<T>::Plane(const Vector3D<T> & normal, const Vector3D<T> & point)
        : a(normal(0)), b(normal(1)), c(normal(2)), d(-normal.Dot(point)) {
    }

    /// @brief Constructor
    /// @tparam T The type of the plane
    /// @param point1 The first point on the plane
    /// @param point2 The second point on the plane
    /// @param point3 The third point on the plane
    template <typename T>
        requires Arithmetic<T>
    Plane<T>::Plane(const Vector3D<T> & point1, const Vector3D<T> & point2, const Vector3D<T> & point3) {
        Vector<T> normal = (point2 - point1).Cross(point3 - point1);
        normal.Normalize();
        a = normal(0);
        b = normal(1);
        c = normal(2);
        d = -normal.Dot(point1);
    }

    /// @brief Get the distance between the plane and a point
    /// @tparam T The type of the plane
    /// @param plane The plane
    template <typename T>
        requires Arithmetic<T>
    Plane<T>::Plane(const Plane<T> & plane) : a(plane.a), b(plane.b), c(plane.c), d(plane.d) {
    }

    /// @brief Get the distance between the plane and a point
    /// @tparam T The type of the plane
    /// @param plane The plane
    template <typename T>
        requires Arithmetic<T>
    Plane<T>::Plane(Plane<T> && plane) : a(plane.a), b(plane.b), c(plane.c), d(plane.d) {
    }

    /// @brief Get the distance between the plane and a point
    /// @tparam T The type of the plane
    /// @param plane The plane
    /// @return The distance between the plane and a point
    template <typename T>
        requires Arithmetic<T>
    Plane<T> & Plane<T>::operator=(const Plane<T> & plane) {
        a = plane.a;
        b = plane.b;
        c = plane.c;
        d = plane.d;
        return *this;
    }

    /// @brief Get the distance between the plane and a point
    /// @tparam T The type of the plane
    /// @param plane The plane
    /// @return The distance between the plane and a point
    template <typename T>
        requires Arithmetic<T>
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
        requires Arithmetic<T>
    Plane<T>::~Plane() {
    }

    /// @brief Gets a component of the plane
    /// @tparam T The type of the plane
    /// @param i The index of the component
    /// @return The component of the plane
    template <typename T>
        requires Arithmetic<T>
    T & Plane<T>::operator()(std::size_t i) {
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
        requires Arithmetic<T>
    T Plane<T>::operator()(std::size_t i) const {
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
        requires Arithmetic<T>
    T & Plane<T>::operator[](std::size_t i) {
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
        requires Arithmetic<T>
    T Plane<T>::operator[](std::size_t i) const {
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
        requires Arithmetic<T>
    T Plane<T>::Distance(const Vector3D<T> & point) const {
        return a * point(0) + b * point(1) + c * point(2) + d;
    }

    /// @brief Get the normal of the plane
    /// @tparam T The type of the plane
    /// @return The normal of the plane
    template <typename T>
        requires Arithmetic<T>
    Vector3D<T> Plane<T>::GetNormal() const {
        return Vector3D<T>(a, b, c);
    }

    /// @brief Get the distance between the plane and a point
    /// @tparam T The type of the plane
    /// @param plane The plane
    /// @return The distance between the plane and a point
    template <typename T>
        requires Arithmetic<T> bool
    Plane<T>::operator==(const Plane<T> & plane) const {
        return a == plane.a && b == plane.b && c == plane.c && d == plane.d;
    }

    /// @brief Get the distance between the plane and a point
    /// @tparam T The type of the plane
    /// @param plane The plane
    /// @return The distance between the plane and a point
    template <typename T>
        requires Arithmetic<T> bool
    Plane<T>::operator!=(const Plane<T> & plane) const {
        return a != plane.a || b != plane.b || c != plane.c || d != plane.d;
    }

} // namespace Tobot::Math