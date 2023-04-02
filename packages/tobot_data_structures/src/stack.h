#pragma once

#include "pre_compiled_header.h"

namespace Tobot::DataStructures {

    template <typename T>
    class Stack {
        public:
            Stack();
            Stack(const Stack<T> & stack);
            ~Stack();
            bool operator==(const Stack<T> & stack) const;
            bool operator!=(const Stack<T> & stack) const;
            T & operator[](std::size_t index);
            T & operator[](std::size_t index) const;
            /// @brief Appends the stack to the ostream
            /// @param os The ostream to append the stack to
            /// @param stack The stack to append to the ostream
            /// @return std::ostream& The ostream with the stack appended
            friend std::ostream operator<<(std::ostream & os, const Stack<T> & stack) {
                for (std::size_t i = 0; i < stack.size; i++) {
                    os << stack.elements[i] << " ";
                }
                return os;
            }
            void Push(T value);
            T Pop();
            T Peek();
            bool IsEmpty();
            std::size_t GetSize();
            void Clear();

        private:
            T * elements;
            std::size_t size;
            std::size_t capacity;

    }; // class Stack

    /// @brief Construct a new Stack object
    /// @tparam T The type of the elements of the stack
    template <typename T>
    Stack<T>::Stack() {
        this->size = 0;
        this->capacity = 1;
        this->elements = new T[this->capacity];
    }

    /// @brief Construct a new Stack object
    /// @tparam T The type of the elements of the stack
    /// @param stack The stack to copy
    template <typename T>
    Stack<T>::Stack(const Stack<T> & stack) {
        this->size = stack.size;
        this->capacity = stack.capacity;
        this->elements = new T[this->capacity];
        for (std::size_t i = 0; i < this->size; i++) {
            this->elements[i] = stack.elements[i];
        }
    }

    /// @brief Destroy the Stack object
    /// @tparam T The type of the elements of the stack
    template <typename T>
    Stack<T>::~Stack() {
        delete[] this->elements;
    }

    /// @brief Checks if two stacks are equal
    /// @tparam T The type of the elements of the stack
    /// @param stack The stack to compare to
    /// @return true The stacks are equal
    /// @return false The stacks are not equal
    template <typename T>
    bool Stack<T>::operator==(const Stack<T> & stack) const {
        if (this->size != stack.size) {
            return false;
        }
        for (std::size_t i = 0; i < this->size; i++) {
            if (this->elements[i] != stack.elements[i]) {
                return false;
            }
        }
        return true;
    }

    /// @brief Checks if two stacks are not equal
    /// @tparam T The type of the elements of the stack
    /// @param stack The stack to compare to
    /// @return true The stacks are not equal
    /// @return false The stacks are equal
    template <typename T>
    bool Stack<T>::operator!=(const Stack<T> & stack) const {
        return !(*this == stack);
    }

    /// @brief Gets the element at the specified index
    /// @tparam T The type of the elements of the stack
    /// @param index The index of the element to get
    /// @return T& The element at the specified index
    template <typename T>
    T & Stack<T>::operator[](std::size_t index) {
        if (index >= this->size) {
            throw std::out_of_range("Index out of range");
        }
        return this->elements[index];
    }

    /// @brief Gets the element at the specified index
    /// @tparam T The type of the elements of the stack
    /// @param index The index of the element to get
    /// @return T& The element at the specified index
    template <typename T>
    T & Stack<T>::operator[](std::size_t index) const {
        if (index >= this->size) {
            throw std::out_of_range("Index out of range");
        }
        return this->elements[index];
    }

    /// @brief Pushes a value to the stack
    /// @tparam T The type of the elements of the stack
    /// @param value The value to push to the stack
    template <typename T>
    void Stack<T>::Push(T value) {
        if (this->size == this->capacity) {
            this->capacity *= 2;
            T * newElements = new T[this->capacity];
            for (std::size_t i = 0; i < this->size; i++) {
                newElements[i] = this->elements[i];
            }
            delete[] this->elements;
            this->elements = newElements;
        }
        this->elements[this->size] = value;
        this->size++;
    }

    /// @brief Pops a value from the stack
    /// @tparam T The type of the elements of the stack
    /// @return T The value popped from the stack
    template <typename T>
    T Stack<T>::Pop() {
        if (this->size == 0) {
            throw std::runtime_error("Stack is empty");
        }
        this->size--;
        T value = this->elements[this->size];
        if (this->size < this->capacity / 4) {
            this->capacity /= 2;
            T * newElements = new T[this->capacity];
            for (std::size_t i = 0; i < this->size; i++) {
                newElements[i] = this->elements[i];
            }
            delete[] this->elements;
            this->elements = newElements;
        }
        return value;
    }

    /// @brief Peeks at the top of the stack
    /// @tparam T The type of the elements of the stack
    /// @return T The value at the top of the stack
    template <typename T>
    T Stack<T>::Peek() {
        if (this->size == 0) {
            throw std::runtime_error("Stack is empty");
        }
        return this->elements[this->size - 1];
    }

    /// @brief Checks if the stack is empty
    /// @tparam T The type of the elements of the stack
    /// @return true The stack is empty
    /// @return false The stack is not empty
    template <typename T>
    bool Stack<T>::IsEmpty() {
        return this->size == 0;
    }

    /// @brief Gets the size of the stack
    /// @tparam T The type of the elements of the stack
    /// @return std::size_t The size of the stack
    template <typename T>
    std::size_t Stack<T>::GetSize() {
        return this->size;
    }

    /// @brief Clears the stack
    /// @tparam T The type of the elements of the stack
    template <typename T>
    void Stack<T>::Clear() {
        this->size = 0;
        this->capacity = 1;
        delete[] this->elements;
        this->elements = new T[this->capacity];
    }

} // namespace Tobot::DataStructures