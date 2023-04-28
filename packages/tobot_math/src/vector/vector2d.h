#pragma once

#include "../pre_compiled_header.h"

#include "../concepts.h"
#include "vector.h"

namespace Tobot::Math {

    /// @brief A 2D vector class
    /// @tparam T The type of the vector
    template <typename T = float>
        requires ArithmeticFloatingPoint<T>
    class Vector2D : Vector<T> {

        public:
            T x;
            T y;

            Vector2D(T x, T y);
            Vector2D(Vector2D & vec);
            Vector2D(Vector2D && vec);
            Vector2D(std::initializer_list<T> list);
            Vector2D<T> & operator=(Vector2D<T> const & vec);
            Vector2D<T> & operator=(Vector2D<T> && vec);

            /// @brief Addition operator for two vectors
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector2D<T> The sum of the two vectors
            friend inline Vector2D<T> operator+(Vector2D<T> lVec, Vector2D<T> const & rVec) {
                return Vector2D(lVec.x + rVec.x, lVec.y + rVec.y);
            }

            /// @brief Subtraction operator for two vectors
            /// @param lVec The left vector
            /// @param rVec The right vector
            /// @return Vector2D<T> The difference of the two vectors
            friend inline Vector2D<T> operator-(Vector2D<T> lVec, Vector2D<T> const & rVec) {
                return Vector2D(lVec.x - rVec.x, lVec.y - rVec.y);
            }

            /// @brief Multiplication operator for a vector and a scalar
            /// @param scalar The scalar to multiply the vector by
            /// @param vec The vector to multiply the scalar by
            /// @return Vector2D<T> The product of the vector and the scalar
            friend inline Vector2D<T> operator*(T const scalar, Vector2D<T> vec) {
                return Vector2D(vec.x * scalar, vec.y * scalar);
            }

            /// @brief Multiplication operator for a vector and a scalar
            /// @param vec The vector to multiply the scalar by
            /// @param scalar The scalar to multiply the vector by
            /// @return Vector2D<T> The product of the vector and the scalar
            friend inline Vector2D<T> operator*(Vector2D<T> vec, T const scalar) {
                return Vector2D(vec.x * scalar, vec.y * scalar);
            }

            /// @brief Division operator for a vector and a scalar
            /// @param scalar The scalar to divide the vector by
            /// @param vec The vector to divide the scalar by
            /// @return Vector2D<T> The quotient of the vector and the scalar
            friend inline Vector2D<T> operator/(T const scalar, Vector2D<T> vec) {
                return Vector2D(vec.x / scalar, vec.y / scalar);
            }

            /// @brief Division operator for a vector and a scalar
            /// @param vec The vector to divide the scalar by
            /// @param scalar The scalar to divide the vector by
            /// @return Vector2D<T> The quotient of the vector and the scalar
            friend inline Vector2D<T> operator/(Vector2D<T> vec, T const scalar) {
                return Vector2D(vec.x / scalar, vec.y / scalar);
            }
            Vector2D<T> & operator+=(Vector2D<T> const & vec);

            Vector2D<T> & operator-=(Vector2D<T> const & vec);

            Vector2D<T> & operator*=(T const scalar);

            Vector2D<T> & operator/=(T const scalar);

            T & operator()(std::size_t i);

            T operator()(std::size_t i) const;

            T & operator[](std::size_t i);

            T operator[](std::size_t i) const;

            bool operator==(Vector2D<T> const & vec) const;

            bool operator!=(Vector2D<T> const & vec) const;

            /// @brief Appends the vector to the output stream
            /// @param os The output stream to append to
            /// @param vec The vector to append
            /// @return std::ostream The output stream with the vector appended
            friend std::ostream operator<<(std::ostream & os, Vector2D<T> const & vec) {
                os << "(" << vec.x << ", " << vec.y << ")";
            }

            inline T Magnitude();

            inline void Normalize();

            inline std::size_t GetSize();

            inline T Dot(Vector2D<T> const & vec);

            Vector2D<T> Cross(Vector2D<T> const & vec);
            ;
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
    Vector2D<T> & Vector2D<T>::operator=(Vector2D<T> const & vec) {
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
    Vector2D<T> & Vector2D<T>::operator=(Vector2D<T> && vec) {
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
    Vector2D<T> & Vector2D<T>::operator+=(Vector2D<T> const & vec) {
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
    Vector2D<T> & Vector2D<T>::operator-=(Vector2D<T> const & vec) {
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
    Vector2D<T> & Vector2D<T>::operator*=(T const scalar) {
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
    Vector2D<T> & Vector2D<T>::operator/=(T const scalar) {
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
    T & Vector2D<T>::operator()(std::size_t i) {
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
    T Vector2D<T>::operator()(std::size_t i) const {
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
    T & Vector2D<T>::operator[](std::size_t i) {
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
    T Vector2D<T>::operator[](std::size_t i) const {
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
    bool Vector2D<T>::operator==(Vector2D<T> const & vec) const {
        return this->x == vec.x && this->y == vec.y;
    }

    /// @brief Compares two vectors for inequality
    /// @tparam T The type stored in the vector
    /// @param vec The vector to compare to
    /// @return bool True if the vectors are not equal, false otherwise
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    bool Vector2D<T>::operator!=(Vector2D<T> const & vec) const {
        return this->x != vec.x || this->y != vec.y;
    }

    /// @brief Gets the dot product of two vectors
    /// @tparam T The type stored in the vector
    /// @param vec The vector to dot with
    /// @return T The dot product of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    T Vector2D<T>::Dot(Vector2D<T> const & vec) {
        return this->x * vec.x + this->y * vec.y;
    }

    /// @brief Gets the cross product of two vectors
    /// @tparam T The type stored in the vector
    /// @param vec The vector to cross with
    /// @return Vector2D<T> The cross product of the two vectors
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    Vector2D<T> Vector2D<T>::Cross(Vector2D<T> const & vec) {
        return Vector2D(0, this->x * vec.y - this->y * vec.x);
    }

    /// @brief Gets the magnitude of the vector
    /// @tparam T The type stored in the vector
    /// @return T The magnitude of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    inline T Vector2D<T>::Magnitude() {
        return sqrt(this->x * this->x + this->y * this->y);
    }

    /// @brief Normalizes the vector
    /// @tparam T The type stored in the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    inline void Vector2D<T>::Normalize() {
        *this /= this->Magnitude();
    }

    /// @brief Gets the size of the vector
    /// @tparam T The type stored in the vector
    /// @return std::size_t The size of the vector
    template <typename T>
        requires ArithmeticFloatingPoint<T>
    inline std::size_t Vector2D<T>::GetSize() {
        return 2;
    }
} // namespace Tobot::Math
