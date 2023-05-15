#pragma once

#include "../pre_compiled_header.hpp"

#include "../concepts.hpp"
#include "vector.hpp"

namespace Tobot::Math {

    /// @brief A 2D vector class
    /// @tparam T The type of the vector
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Vector2D : Vector<T> {

        public:
            Vector2D(T x, T y);
            Vector2D(Vector2D & vec);
            Vector2D(Vector2D && vec);
            Vector2D(Vector2D const & vec);
            Vector2D(Vector2D const && vec);
            Vector2D(std::initializer_list<T> list);
            auto operator=(Vector2D<T> const & vec) -> Vector2D<T> &;
            auto operator=(Vector2D<T> && vec) -> Vector2D<T> &;

            /// @brief Addition operator for two vectors
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector2D<T> The sum of the two vectors
            friend inline auto operator+(Vector2D<T> lVec, Vector2D<T> const & rVec) -> Vector2D<T> {
                return Vector2D(lVec.x + rVec.x, lVec.y + rVec.y);
            }

            /// @brief Subtraction operator for two vectors
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector2D<T> The difference of the two vectors
            friend inline auto operator-(Vector2D<T> lVec, Vector2D<T> const & rVec) -> Vector2D<T> {
                return Vector2D(lVec.x - rVec.x, lVec.y - rVec.y);
            }

            /// @brief Multiplication operator for a vector and a scalar
            /// @param scalar The scalar to multiply the vector by
            /// @param vec The vector to multiply the scalar by
            /// @return Vector2D<T> The product of the vector and the scalar
            friend inline auto operator*(T const scalar, Vector2D<T> vec) -> Vector2D<T> {
                return Vector2D(vec.x * scalar, vec.y * scalar);
            }

            /// @brief Multiplication operator for a vector and a scalar
            /// @param vec The vector to multiply the scalar by
            /// @param scalar The scalar to multiply the vector by
            /// @return Vector2D<T> The product of the vector and the scalar
            friend inline auto operator*(Vector2D<T> vec, T const scalar) -> Vector2D<T> {
                return Vector2D(vec.x * scalar, vec.y * scalar);
            }

            /// @brief Division operator for a vector and a scalar
            /// @param scalar The scalar to divide the vector by
            /// @param vec The vector to divide the scalar by
            /// @return Vector2D<T> The quotient of the vector and the scalar
            friend inline auto operator/(T const scalar, Vector2D<T> vec) -> Vector2D<T> {
                return Vector2D(vec.x / scalar, vec.y / scalar);
            }

            /// @brief Division operator for a vector and a scalar
            /// @param vec The vector to divide the scalar by
            /// @param scalar The scalar to divide the vector by
            /// @return Vector2D<T> The quotient of the vector and the scalar
            friend inline auto operator/(Vector2D<T> vec, T const scalar) -> Vector2D<T> {
                return Vector2D(vec.x / scalar, vec.y / scalar);
            }

            auto operator+=(Vector2D<T> const & vec) -> Vector2D<T> &;

            auto operator-=(Vector2D<T> const & vec) -> Vector2D<T> &;

            auto operator*=(T const scalar) -> Vector2D<T> &;

            auto operator/=(T const scalar) -> Vector2D<T> &;

            auto operator()(std::size_t i) -> T &;

            auto operator()(std::size_t i) const -> T;

            auto operator[](std::size_t i) -> T &;

            auto operator[](std::size_t i) const -> T;

            auto operator==(Vector2D<T> const & vec) const -> bool;

            auto operator!=(Vector2D<T> const & vec) const -> bool;

            /// @brief Appends the vector to the output stream
            /// @param os The output stream to append to
            /// @param vec The vector to append
            /// @return std::ostream The output stream with the vector appended
            friend auto operator<<(std::ostream & os, Vector2D<T> const & vec) -> std::ostream {
                os << "(" << vec.x << ", " << vec.y << ")";
            }

            inline auto magnitude() -> T;

            inline auto normalize() -> void;

            inline auto getSize() -> std::size_t;

            inline auto dot(Vector2D<T> const & vec) -> T;

            auto cross(Vector2D<T> const & vec) -> Vector2D<T>;

            auto setX(T x) -> void;

            auto setY(T y) -> void;

            auto getX() const -> T;

            auto getY() const -> T;

        private:
            T x;
            T y;
    };

    /// @brief Constructor for the Vector2D class
    /// @tparam T The type stored in the vector
    /// @param x The x component of the vector
    /// @param y The y component of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector2D<T>::Vector2D(T x, T y) : x(x), y(y) {
    }

    /// @brief Constructor for the Vector2D class
    /// @tparam T The type stored in the vector
    /// @param vec The vector to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector2D<T>::Vector2D(Vector2D & vec) : x(vec.x), y(vec.y) {
    }

    /// @brief Constructor for the Vector2D class
    /// @tparam T The type stored in the vector
    /// @param vec The vector to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector2D<T>::Vector2D(Vector2D && vec) : x(vec.x), y(vec.y) {
    }

    /// @brief Constructor for the Vector2D class
    /// @tparam T The type stored in the vector
    /// @param vec The vector to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector2D<T>::Vector2D(Vector2D const && vec) : x(vec.x), y(vec.y) {
    }

    /// @brief Constructor for the Vector2D class
    /// @tparam T The type stored in the vector
    /// @param vec The vector to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector2D<T>::Vector2D(Vector2D const & vec) : x(vec.x), y(vec.y) {
    }

    /// @brief Constructor for the Vector2D class
    /// @tparam T The type stored in the vector
    /// @param list The list of values to initialize the vector with
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector2D<T>::Vector2D(std::initializer_list<T> list) {
        if (list.size() != 2) {
            throw std::invalid_argument("Vector2D initializer list must have 2 elements");
        }
        this->x = *list.begin();
        this->y = *(list.begin() + 1);
    }

    /// @brief Assignment operator for the Vector2D class
    /// @tparam T The type stored in the vector
    /// @param vec The vector to copy
    /// @return Vector2D<T> The copied vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector2D<T>::operator=(Vector2D<T> const & vec) -> Vector2D<T> & {
        this->x = vec.x;
        this->y = vec.y;
        return *this;
    }

    /// @brief Assignment operator for the Vector2D class
    /// @tparam T The type stored in the vector
    /// @param vec The vector to copy
    /// @return Vector2D<T> The copied vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector2D<T>::operator=(Vector2D<T> && vec) -> Vector2D<T> & {
        this->x = vec.x;
        this->y = vec.y;
        return *this;
    }

    /// @brief Adds two vectors together and stores the result in the first vector
    /// @tparam T The type of the vector
    /// @param vec The vector to get the magnitude of
    /// @return T The magnitude of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector2D<T>::operator+=(Vector2D<T> const & vec) -> Vector2D<T> & {
        this->x += vec.x;
        this->y += vec.y;
        return *this;
    }

    /// @brief Calculates the difference of two vectors and stores the result in the first vector
    /// @tparam T The type stored in the vector
    /// @param vec The vector to subtract from
    /// @return Vector2D<T> The difference of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector2D<T>::operator-=(Vector2D<T> const & vec) -> Vector2D<T> & {
        this->x -= vec.x;
        this->y -= vec.y;
        return *this;
    }

    /// @brief Calculates the product of a vector and a scalar and stores the result in the vector
    /// @tparam T The type stored in the vector
    /// @param scalar The scalar to multiply the vector by
    /// @return Vector2D<T> The product of the vector and the scalar
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector2D<T>::operator*=(T const scalar) -> Vector2D<T> & {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    /// @brief Calculates the quotient of a vector and a scalar and stores the result in the vector
    /// @tparam T The type stored in the vector
    /// @param scalar The scalar to divide the vector by
    /// @return Vector2D<T> The quotient of the vector and the scalar
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector2D<T>::operator/=(T const scalar) -> Vector2D<T> & {
        T factor = 1.0 / scalar;
        this->x *= factor;
        this->y *= factor;
        return *this;
    }

    /// @brief Gets the magnitude of the vector
    /// @tparam T The type stored in the vector
    /// @param i The index of the component to get
    /// @return T& The component at the index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector2D<T>::operator()(std::size_t i) -> T & {
        assert(i < 2);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;

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

    /// @brief Gets the component of the vector at the index
    /// @tparam T The type stored in the vector
    /// @param i The index of the component to get
    /// @return T The component at the index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector2D<T>::operator()(std::size_t i) const -> T {
        assert(i < 2);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;

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

    /// @brief Gets the component of the vector at the index
    /// @tparam T The type stored in the vector
    /// @param i The index of the component to get
    /// @return T& The component at the index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector2D<T>::operator[](std::size_t i) -> T & {
        assert(i < 2);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;

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

    /// @brief Gets the component of the vector at the index
    /// @tparam T The type stored in the vector
    /// @param i The index of the component to get
    /// @return T The component at the index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector2D<T>::operator[](std::size_t i) const -> T {
        assert(i < 2);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;

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

    /// @brief Compares two vectors for equality
    /// @tparam T The type stored in the vector
    /// @param vec The vector to compare to
    /// @return bool True if the vectors are equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector2D<T>::operator==(Vector2D<T> const & vec) const -> bool {
        return this->x == vec.x && this->y == vec.y;
    }

    /// @brief Compares two vectors for inequality
    /// @tparam T The type stored in the vector
    /// @param vec The vector to compare to
    /// @return bool True if the vectors are not equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector2D<T>::operator!=(Vector2D<T> const & vec) const -> bool {
        return this->x != vec.x || this->y != vec.y;
    }

    /// @brief Gets the dot product of two vectors
    /// @tparam T The type stored in the vector
    /// @param vec The vector to dot with
    /// @return T The dot product of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector2D<T>::dot(Vector2D<T> const & vec) -> T {
        return this->x * vec.x + this->y * vec.y;
    }

    /// @brief Gets the cross product of two vectors
    /// @tparam T The type stored in the vector
    /// @param vec The vector to cross with
    /// @return Vector2D<T> The cross product of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector2D<T>::cross(Vector2D<T> const & vec) -> Vector2D<T> {
        return Vector2D(0, this->x * vec.y - this->y * vec.x);
    }

    /// @brief Gets the magnitude of the vector
    /// @tparam T The type stored in the vector
    /// @return T The magnitude of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] inline auto Vector2D<T>::magnitude() -> T {
        return sqrt(this->x * this->x + this->y * this->y);
    }

    /// @brief Normalizes the vector
    /// @tparam T The type stored in the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    inline auto Vector2D<T>::normalize() -> void {
        *this /= this->magnitude();
    }

    /// @brief Gets the size of the vector
    /// @tparam T The type stored in the vector
    /// @return std::size_t The size of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] inline auto Vector2D<T>::getSize() -> std::size_t {
        return 2;
    }

    /// @brief Gets the x component of the vector
    /// @tparam T The type stored in the vector
    /// @return T The x component of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] inline auto Vector2D<T>::getX() const -> T {
        return this->x;
    }

    /// @brief Gets the y component of the vector
    /// @tparam T The type stored in the vector
    /// @return T The y component of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] inline auto Vector2D<T>::getY() const -> T {
        return this->y;
    }

    /// @brief Sets the x component of the vector
    /// @tparam T The type stored in the vector
    /// @param x The new x component
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    inline auto Vector2D<T>::setX(T x) -> void {
        this->x = x;
    }

    /// @brief Sets the y component of the vector
    /// @tparam T The type stored in the vector
    /// @param y The new y component
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    inline auto Vector2D<T>::setY(T y) -> void {
        this->y = y;
    }
} // namespace Tobot::Math
