#pragma once

#include "../pre_compiled_header.h"

#include "../concepts.h"
#include "vector.h"

namespace Tobot::Math {

    /// @brief A 4D vector class
    /// @tparam T The type of the vector
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Vector4D : Vector<T> {

        public:
            T x;
            T y;
            T z;
            T w;

            Vector4D(T x, T y, T z, T w);
            Vector4D(Vector4D & vec);
            Vector4D(std::initializer_list<T> list);
            Vector4D(Vector4D const && vec);
            Vector4D<T> & operator=(Vector4D<T> const & vec);
            Vector4D<T> & operator=(Vector4D<T> const && vec);

            /// @brief Adds two vectors together
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector4D<T> The sum of the two vectors
            friend inline auto operator+(Vector4D<T> lVec, Vector4D<T> const & rVec) -> Vector4D<T> {
                return Vector4D(lVec.x + rVec.x, lVec.y + rVec.y, lVec.z + rVec.z, lVec.w + rVec.w);
            }

            /// @brief Subtracts two vectors
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector4D<T> The difference of the two vectors
            friend inline auto operator-(Vector4D<T> lVec, Vector4D<T> const & rVec) -> Vector4D<T> {
                return Vector4D(lVec.x - rVec.x, lVec.y - rVec.y, lVec.z - rVec.z, lVec.w - rVec.w);
            }

            /// @brief Multiplies a vector by a scalar
            /// @param scalar The scalar to multiply the vector by
            /// @param vec The vector to multiply by the scalar
            /// @return Vector4D<T> The product of the vector and the scalar
            friend inline auto operator*(T const scalar, Vector4D<T> vec) -> Vector4D<T> {
                return Vector4D(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar);
            }

            /// @brief Multiplies a vector by a scalar
            /// @param vec The vector to multiply by the scalar
            /// @param scalar The scalar to multiply the vector by
            /// @return Vector4D<T> The product of the vector and the scalar
            friend inline auto operator*(Vector4D<T> vec, T const scalar) -> Vector4D<T> {
                return Vector4D(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar);
            }

            /// @brief Divides a vector by a scalar
            /// @param scalar The scalar to divide the vector by
            /// @param vec The vector to divide by the scalar
            /// @return Vector4D<T> The quotient of the vector and the scalar
            friend inline auto operator/(T const scalar, Vector4D<T> vec) -> Vector4D<T> {
                return Vector4D(vec.x / scalar, vec.y / scalar, vec.z /= scalar, vec.w / scalar);
            }

            /// @brief Divides a vector by a scalar
            /// @param vec The vector to divide by the scalar
            /// @param scalar The scalar to divide the vector by
            /// @return Vector4D<T> The quotient of the vector and the scalar
            friend inline auto operator/(Vector4D<T> vec, T const scalar) -> Vector4D<T> {
                return Vector4D(vec.x / scalar, vec.y / scalar, vec.z / scalar, vec.w / scalar);
            }

            auto operator+=(Vector4D<T> const & vec) -> Vector4D<T> &;

            auto operator-=(Vector4D<T> const & vec) -> Vector4D<T> &;

            auto operator*=(T const scalar) -> Vector4D<T> &;

            auto operator/=(T const scalar) -> Vector4D<T> &;

            auto operator()(std::size_t i) -> T &;

            auto operator()(std::size_t i) const -> T;

            auto operator[](std::size_t i) -> T &;

            auto operator[](std::size_t i) const -> T;

            inline auto operator==(Vector4D<T> const & vec) const -> bool;

            inline auto operator!=(Vector4D<T> const & vec) const -> bool;

            /// @brief Appends the vector to the output stream
            /// @param os The output stream
            /// @param vec The vector to append to the output stream
            /// @return std::ostream The output stream
            friend auto operator<<(std::ostream & os, Vector4D<T> const & vec) -> std::ostream & {
                os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
            }

            auto Magnitude() -> T;

            inline auto Normalize() -> void;

            inline auto GetSize() -> std::size_t;

            auto Dot(Vector4D<T> const & vec) -> T;
    };

    /// @brief Creates a new Vector4D object
    /// @tparam T The underlying type of the vector
    /// @param x The x component of the vector
    /// @param y The y component of the vector
    /// @param z The z component of the vector
    /// @param w The w component of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector4D<T>::Vector4D(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {
    }

    /// @brief Creates a new Vector4D object
    /// @tparam T The underlying type of the vector
    /// @param vec The vector to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector4D<T>::Vector4D(Vector4D<T> & vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) {
    }

    /// @brief Creates a new Vector4D object
    /// @tparam T The underlying type of the vector
    /// @param list The list of components for the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector4D<T>::Vector4D(std::initializer_list<T> list) {
        assert(list.size() == 4);
        std::size_t i = 0;
        for (auto it = list.begin(); it != list.end(); ++it) {
            switch (i) {
            case 0:
                this->x = *it;
                break;
            case 1:
                this->y = *it;
                break;
            case 2:
                this->z = *it;
                break;
            case 3:
                this->w = *it;
                break;
            }
            ++i;
        }
    }

    /// @brief Creates a new Vector4D object
    /// @tparam T The underlying type of the vector
    /// @param vec The vector to copy
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector4D<T>::Vector4D(Vector4D<T> const && vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) {
    }

    /// @brief Creates a new Vector4D object
    /// @tparam T The underlying type of the vector
    /// @param vec The vector to copy
    /// @return Vector4D<T> The copy of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector4D<T>::operator=(Vector4D<T> const & vec) -> Vector4D<T> & {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        this->w = vec.w;
        return *this;
    }

    /// @brief Creates a new Vector4D object
    /// @tparam T The underlying type of the vector
    /// @param vec The vector to copy
    /// @return Vector4D<T> The copy of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector4D<T>::operator=(Vector4D<T> const && vec) -> Vector4D<T> & {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        this->w = vec.w;
        return *this;
    }

    /// @brief Adds two vectors together
    /// @tparam T The underlying type of the vector
    /// @param vec The vector to add to this vector
    /// @return Vector4D<T> The sum of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector4D<T>::operator+=(Vector4D<T> const & vec) -> Vector4D<T> & {
        this->x += vec.x;
        this->y += vec.y;
        this->z += vec.z;
        this->w += vec.w;
        return *this;
    }

    /// @brief Subtracts two vectors
    /// @tparam T The underlying type of the vector
    /// @param vec The vector to subtract from this vector
    /// @return Vector4D<T> The difference of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector4D<T>::operator-=(Vector4D<T> const & vec) -> Vector4D<T> & {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= vec.z;
        this->w -= vec.w;
        return *this;
    }

    /// @brief Multiplies a vector by a scalar
    /// @tparam T The underlying type of the vector
    /// @param scalar The scalar to multiply the vector by
    /// @return Vector4D<T> The product of the vector and the scalar
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector4D<T>::operator*=(T const scalar) -> Vector4D<T> & {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        this->w *= scalar;
        return *this;
    }

    /// @brief Divides a vector by a scalar
    /// @tparam T The underlying type of the vector
    /// @param scalar The scalar to divide the vector by
    /// @return Vector4D<T> The quotient of the vector and the scalar
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    auto Vector4D<T>::operator/=(T const scalar) -> Vector4D<T> & {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        this->w /= scalar;
        return *this;
    }

    /// @brief Gets a value from the vector at the specified index
    /// @tparam T The underlying type of the vector
    /// @param i The index of the value to get
    /// @return T& The value at the specified index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector4D<T>::operator()(std::size_t i) -> T & {
        assert(i < 4);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        case 3:
            return this->w;

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

    /// @brief Gets a value from the vector at the specified index
    /// @tparam T The underlying type of the vector
    /// @param i The index of the value to get
    /// @return T The value at the specified index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector4D<T>::operator()(std::size_t i) const -> T {
        assert(4 > i);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        case 3:
            return this->w;

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

    /// @brief Gets a value from the vector at the specified index
    /// @tparam T The underlying type of the vector
    /// @param i The index of the value to get
    /// @return T& The value at the specified index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector4D<T>::operator[](std::size_t i) -> T & {
        assert(i < 4);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        case 3:
            return this->w;

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

    /// @brief Gets a value from the vector at the specified index
    /// @tparam T The underlying type of the vector
    /// @param i The index of the value to get
    /// @return T The value at the specified index
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector4D<T>::operator[](std::size_t i) const -> T {
        assert(i < 4);
        switch (i) {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        case 3:
            return this->w;

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

    /// Compare two vectors for equality
    /// @tparam T The underlying type of the vector
    /// @param vec The vector to compare against
    /// @return bool True if the vectors are equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] inline auto Vector4D<T>::operator==(Vector4D<T> const & vec) const -> bool {
        return this->x == vec.x && this->y == vec.y && this->z == vec.z && this->w == vec.w;
    }

    /// Compare two vectors for inequality
    /// @tparam T The underlying type of the vector
    /// @param vec The vector to compare against
    /// @return bool True if the vectors are not equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] inline auto Vector4D<T>::operator!=(Vector4D<T> const & vec) const -> bool {
        return this->x != vec.x || this->y != vec.y || this->z != vec.z || this->w != vec.w;
    }

    /// @brief Gets the magnitude of the vector
    /// @tparam T The underlying type of the vector
    /// @return T The magnitude of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector4D<T>::Magnitude() -> T {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    }

    /// @brief Normalizes the vector
    /// @tparam T The underlying type of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    inline auto Vector4D<T>::Normalize() -> void {
        *this /= this->Magnitude();
    }

    /// @brief Gets the size of the vector
    /// @tparam T The underlying type of the vector
    /// @return std::size_t The size of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] inline std::size_t Vector4D<T>::GetSize() {
        return 4;
    }

    /// @brief Gets the dot product of two vectors
    /// @tparam T The underlying type of the vector
    /// @param vec The vector to dot with
    /// @return T The dot product of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    [[nodiscard]] auto Vector4D<T>::Dot(Vector4D<T> const & vec) -> T {
        return this->x * vec.x + this->y * vec.y + this->z * vec.z + this->w * vec.w;
    }

} // namespace Tobot::Math
