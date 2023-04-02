#pragma once

#include "pre_compiled_header.h"

namespace Tobot::DataStructures {

    template <typename T, std::size_t size>
    class Array {
        public:
            T data[size];

            Array();
            Array(Array & array);
            Array(T data[size]);
            Array(std::initializer_list<T> list);

            T & operator[](std::size_t index);
            T & operator[](std::size_t index) const;
            Array<T, size> & operator=(const Array<T, size> & array);
            bool operator==(const Array<T, size> & array) const;
            bool operator!=(const Array<T, size> & array) const;
            void ForEach(std::function<void(T &)> function);
            std::size_t getSize() const;
            /// @brief Appends the array to the ostream
            /// @param os The ostream to append the array to
            /// @param array The array to append to the ostream
            /// @return std::ostream& The ostream with the array appended
            friend std::ostream operator<<(std::ostream & os, const Array<T, size> & array) {
                os << "[";
                for (std::size_t i = 0; i < size; i++) {
                    os << array.data[i];
                    if (i < size - 1) {
                        os << ", ";
                    }
                }
                os << "]";
                return os;
            }

    }; // class Array

    /// @brief Construct a new Array object
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    template <typename T, std::size_t size>
    Array<T, size>::Array() {
        for (std::size_t i = 0; i < size; i++) {
            this->data[i] = T();
        }
    }

    /// @brief Construct a new Array object
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @param array The array to copy
    template <typename T, std::size_t size>
    Array<T, size>::Array(Array & array) {
        for (std::size_t i = 0; i < size; i++) {
            this->data[i] = array.data[i];
        }
    }

    /// @brief Construct a new Array object
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @param data The data to initialize the array with
    template <typename T, std::size_t size>
    Array<T, size>::Array(T data[size]) {
        for (std::size_t i = 0; i < size; i++) {
            this->data[i] = data[i];
        }
    }

    /// @brief Assigns the given array to this array
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @param list The list to assign to this array
    /// @return Array<T, size>& This array
    template <typename T, std::size_t size>
    Array<T, size>::Array(std::initializer_list<T> list) {
        if (list.size() != size) {
            throw std::invalid_argument("The size of the initializer list does not match the size of the array");
        }
        for (auto it = list.begin(); it != list.end(); it++) {
            this->data[it - list.begin()] = *it;
        }
    }

    /// @brief Access the element at the given index
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @param index The index of the element to access
    /// @return T& The element at the given index
    template <typename T, std::size_t size>
    T & Array<T, size>::operator[](std::size_t index) {
        return this->data[index];
    }

    /// @brief Access the element at the given index
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @param index The index of the element to access
    /// @return T& The element at the given index
    template <typename T, std::size_t size>
    T & Array<T, size>::operator[](std::size_t index) const {
        return this->data[index];
    }

    /// @brief Assigns the given array to this array
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @param array The array to assign to this array
    /// @return Array<T, size>& This array
    template <typename T, std::size_t size>
    Array<T, size> & Array<T, size>::operator=(const Array<T, size> & array) {
        for (std::size_t i = 0; i < size; i++) {
            this->data[i] = array.data[i];
        }
        return *this;
    }

    /// @brief Compares this array to the given array
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @param array The array to compare to this array
    /// @return true If the arrays are equal
    template <typename T, std::size_t size>
    bool Array<T, size>::operator==(const Array<T, size> & array) const {
        for (std::size_t i = 0; i < size; i++) {
            if (this->data[i] != array.data[i]) {
                return false;
            }
        }
        return true;
    }

    /// @brief Compares this array to the given array
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @param array The array to compare to this array
    /// @return true If the arrays are not equal
    template <typename T, std::size_t size>
    bool Array<T, size>::operator!=(const Array<T, size> & array) const {
        return !(*this == array);
    }

    /// @brief Calls the given function for each element of the array
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @param callback The function to call for each element of the array
    template <typename T, std::size_t size>
    void Array<T, size>::ForEach(std::function<void(T &)> callback) {
        for (std::size_t i = 0; i < size; i++) {
            callback(this->data[i]);
        }
    }

    /// @brief Get the size of the array
    /// @tparam T The type of the elements of the array
    /// @tparam size The size of the array
    /// @return std::size_t The size of the array
    template <typename T, std::size_t size>
    std::size_t Array<T, size>::getSize() const {
        return size;
    }

} // namespace Tobot::DataStructures