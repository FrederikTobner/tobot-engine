#pragma once

#include "../pre_compiled_header.hpp"

#include "../concepts.hpp"
#include "vector.hpp"

namespace Tobot::Math {

    /// @brief A 3D vector class
    /// @tparam T The type of the vector
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Vector3D : Vector<T> {

        public:
            Vector3D(T x, T y, T z);
            Vector3D(Vector3D & vec);
            Vector3D(Vector3D && vec);
            Vector3D(std::initializer_list<T> list);
            auto operator=(Vector3D<T> const & vec) -> Vector3D<T> &;
            auto operator=(Vector3D<T> && vec) -> Vector3D<T> &;
            auto getX() const -> T;
            auto getY() const -> T;
            auto getZ() const -> T;

            /// @brief Calculates the sum of two vectors
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector3D<T> The sum of the two vectors
            friend inline auto operator+(Vector3D<T> lVec, Vector3D<T> const & rVec) -> Vector3D<T> {
                return Vector3D(lVec.x + rVec.x, lVec.y + rVec.y, lVec.z + rVec.z);
            }

            /// @brief Substracts two vectors
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector3D<T> The difference of the two vectors
            friend inline auto operator-(Vector3D<T> lVec, Vector3D<T> const & rVec) -> Vector3D<T> {
                return Vector3D(lVec.x - rVec.x, lVec.y - rVec.y, lVec.z - rVec.z);
            }

            /// @brief Calulates the product of a vector and a scalar
            /// @param scalar The scalar
            /// @param vec The vector
            /// @return Vector3D<T> The product of the vector and the scalar
            friend inline auto operator*(T const scalar, Vector3D<T> & vec) -> Vector3D<T> {
                return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
            }

            friend inline auto operator*(T const scalar, Vector3D<T> const vec) -> Vector3D<T> {
                return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
            }

            /// @brief Calulates the product of a vector and a scalar
            /// @param vec The vector
            /// @param scalar The scalar
            /// @return Vector3D<T> The product of the vector and the scalar
            friend inline auto operator*(Vector3D<T> vec, T const scalar) -> Vector3D<T> {
                return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
            }

            /// @brief Calculates the division of a vector and a scalar
            /// @param scalar The scalar
            /// @param vec The vector
            /// @return Vector3D<T> The division of the vector and the scalar
            friend inline auto operator/(T const scalar, Vector3D<T> & vec) -> Vector3D<T> {
                return Vector3D(vec.x / scalar, vec.y / scalar, vec.z / scalar);
            }

            friend inline auto operator/(T const scalar, Vector3D<T> const vec) -> Vector3D<T> {
                return Vector3D(vec.x / scalar, vec.y / scalar, vec.z / scalar);
            }

            /// @brief Calculates the division of a vector and a scalar
            /// @param vec The vector
            /// @param scalar The scalar
            /// @return Vector3D<T> The division of the vector and the scalar
            friend inline auto operator/(Vector3D<T> vec, T const scalar) -> Vector3D<T> {
                return Vector3D(vec.x / scalar, vec.y / scalar, vec.z / scalar);
            }

            auto operator+=(Vector3D<T> const & vec) -> Vector3D<T> &;

            auto operator-=(Vector3D<T> const & vec) -> Vector3D<T> &;

            auto operator*=(T const scalar) -> Vector3D<T> &;

            auto operator/=(T const scalar) -> Vector3D<T> &;

            auto operator()(std::size_t i) -> T &;

            auto operator()(std::size_t i) const -> T;

            auto operator[](std::size_t i) -> T &;

            auto operator[](std::size_t i) const -> T;

            auto operator==(Vector3D<T> const & vec) const -> bool;

            auto operator!=(Vector3D<T> const & vec) const -> bool;

            /// @brief Appends the vector to the output stream
            /// @param os The output stream
            /// @param vec The vector
            /// @return std::ostream The output stream
            friend auto operator<<(std::ostream & os, Vector3D<T> const & vec) -> std::ostream {
                os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
            }

            inline auto magnitude() -> T;

            inline auto normalize() -> void;

            inline auto getSize() -> std::size_t;

            auto dot(Vector3D<T> const & vec) -> T;

            auto cross(Vector3D<T> const & vec) -> Vector3D<T>;

        private:
            T x;
            T y;
            T z;
    };

    /// @brief Constructs a new Vector3D object
    /// @tparam T The type of the vector
    /// @param x The x component of the vector
    /// @param y The y component of the vector
    /// @param z The z component of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector3D<T>::Vector3D(T x, T y, T z) : x(x), y(y), z(z) {
    }

    /// @brief Constructs a new Vector3D object
    /// @tparam T The type of the vector
    /// @param vec The vector to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector3D<T>::Vector3D(Vector3D<T> & vec) : x(vec.x), y(vec.y), z(vec.z) {
    }

    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector3D<T>::Vector3D(Vector3D && vec) : x(vec.x), y(vec.y), z(vec.z) {
    }

    /// @brief Constructs a new Vector3D object
    /// @tparam T The type of the vector
    /// @param list The list of components of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector3D<T>::Vector3D(std::initializer_list<T> list) {
        if (list.size() != 3) {
            throw std::invalid_argument("The list must have exactly 3 elements");
        }
        this->x = *list.begin();
        this->y = *(list.begin() + 1);
        this->z = *(list.begin() + 2);
    }

    /// @brief Assigns the vector to the right vector
    /// @tparam T The type of the vector
    /// @param vec The vector to assign
    /// @return Vector3D<T> The assigned vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector3D<T>::operator=(Vector3D<T> const & vec) -> Vector3D<T> & {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        return *this;
    }

    /// @brief Assigns the vector to the right vector
    /// @tparam T  The type of the vector
    /// @param vec The vector to assign
    /// @return  Vector3D<T> The assigned vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector3D<T>::operator=(Vector3D<T> && vec) -> Vector3D<T> & {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        return *this;
    }

    /// @brief Calculates the sum of two vectors and assigns the result to the left vector
    /// @tparam T The type of the vector
    /// @param vec The vector to add
    /// @return Vector3D<T> The sum of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector3D<T>::operator+=(Vector3D<T> const & vec) -> Vector3D<T> & {
        this->x += vec.x;
        this->y += vec.y;
        this->z += vec.z;
        return *this;
    }

    /// @brief Calculates the difference of two vectors and assigns the result to the left vector
    /// @tparam T The type of the vector
    /// @param vec The vector to substract
    /// @return Vector3D<T> The difference of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector3D<T>::operator-=(Vector3D<T> const & vec) -> Vector3D<T> & {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= vec.z;
        return *this;
    }

    /// @brief Calculates the product of a vector and a scalar and assigns the result to the vector
    /// @tparam T The type of the vector
    /// @param scalar The scalar
    /// @return Vector3D<T> The product of the vector and the scalar
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector3D<T>::operator*=(T const scalar) -> Vector3D<T> & {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    /// @brief Calculates the division of a vector and a scalar and assigns the result to the vector
    /// @tparam T The type of the vector
    /// @param scalar The scalar
    /// @return Vector3D<T> The division of the vector and the scalar
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector3D<T>::operator/=(T const scalar) -> Vector3D<T> & {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        return *this;
    }

    /// @brief Gets the component of the vector at the specified index
    /// @tparam T The type of the vector
    /// @param i The index of the component
    /// @return T& The component at the specified index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::operator()(std::size_t i) -> T & {
        assert(i < 3);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;

        default:
            // Unreachable
#if defined(COMPILER_MSVC)
            __assume(0);
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
            __builtin_unreachable();
#else // Compiler is Intel or unknown
            exit(70);
#endif
        }
    }

    /// @brief Gets the component of the vector at the specified index
    /// @tparam T The type of the vector
    /// @param i The index of the component
    /// @return T The component at the specified index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::operator()(std::size_t i) const -> T {
        assert(i < 3);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;

        default:
            // Unreachable
#if defined(COMPILER_MSVC)
            __assume(0);
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
            __builtin_unreachable();
#else // Compiler is Intel or unknown
            exit(70);
#endif
        }
    }

    /// @brief Gets the component of the vector at the specified index
    /// @tparam T The type of the vector
    /// @param i The index of the component
    /// @return T& The component at the specified index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::operator[](std::size_t i) -> T & {
        assert(i < 3);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;

        default:
            // Unreachable
#if defined(COMPILER_MSVC)
            __assume(0);
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
            __builtin_unreachable();
#else // Compiler is Intel or unknown
            exit(70);
#endif
        }
    }

    /// @brief Gets the component of the vector at the specified index
    /// @tparam T The type of the vector
    /// @param i The index of the component
    /// @return T The component at the specified index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::operator[](std::size_t i) const -> T {
        assert(i < 3);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;

        default:
            // Unreachable
#if defined(COMPILER_MSVC)
            __assume(0);
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
            __builtin_unreachable();
#else // Compiler is Intel or unknown
            exit(70);
#endif
        }
    }

    /// Compares two vectors
    /// @tparam T The type of the vector
    /// @param vec The vector to compare
    /// @return bool True if the vectors are equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::operator==(Vector3D<T> const & vec) const -> bool {
        return this->x == vec.x && this->y == vec.y && this->z == vec.z;
    }

    /// Compares two vectors
    /// @tparam T The type of the vector
    /// @param vec The vector to compare
    /// @return bool True if the vectors are not equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::operator!=(Vector3D<T> const & vec) const -> bool {
        return this->x != vec.x || this->y != vec.y || this->z != vec.z;
    }

    /// @brief Calculates the magnitude of the vector
    /// @tparam T The type of the vector
    /// @return T The magnitude of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] inline auto Vector3D<T>::magnitude() -> T {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    /// @brief Normalizes the vector
    /// @tparam T The type of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    inline auto Vector3D<T>::normalize() -> void {
        *this /= this->magnitude();
    }

    /// @brief Gets the size of the vector
    /// @tparam T The type of the vector
    /// @return std::size_t The size of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    inline auto Vector3D<T>::getSize() -> std::size_t {
        return 3;
    }

    /// @brief Calculates the dot product of two vectors
    /// @tparam T The type of the vector
    /// @param vec The vector to calculate the dot product with
    /// @return T The dot product of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::dot(Vector3D<T> const & vec) -> T {
        return this->x * vec.x + this->y * vec.y + this->z * vec.z;
    }

    /// @brief Calculates the cross product of two vectors
    /// @tparam T The type of the vector
    /// @param vec The vector to calculate the cross product with
    /// @return Vector3D<T> The cross product of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::cross(Vector3D<T> const & vec) -> Vector3D<T> {
        return Vector3D<T>(this->y * vec.z - this->z * vec.y, this->z * vec.x - this->x * vec.z,
                           this->x * vec.y - this->y * vec.x);
    }

    /// @brief Gets the x component of the vector
    /// @tparam T The type of the vector
    /// @return The x component of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::getX() const -> T {
        return this->x;
    }

    /// @brief Gets the y component of the vector
    /// @tparam T The type of the vector
    /// @return The y component of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::getY() const -> T {
        return this->y;
    }

    /// @brief Gets the z component of the vector
    /// @tparam T The type of the vector
    /// @return The z component of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector3D<T>::getZ() const -> T {
        return this->z;
    }

} // namespace Tobot::Math
