#pragma once

#include "pre_compiled_header.h"

namespace Tobot::DataStructures {

    template <typename T>
    class Queue {
        public:
            Queue();
            Queue(const Queue<T> & queue);
            ~Queue();
            bool operator==(const Queue<T> & queue) const;
            bool operator!=(const Queue<T> & queue) const;
            T & operator[](std::size_t index);
            const T & operator[](std::size_t index) const;
            /// @brief Appends the queue to the ostream
            /// @param os The ostream to append the queue to
            /// @param queue The queue to append to the ostream
            /// @return std::ostream& The ostream with the queue appended
            friend std::ostream operator<<(std::ostream & os, const Queue<T> & queue) {
                os << "[";
                for (std::size_t i = 0; i < queue.size; i++) {
                    os << queue.data[i];
                    if (i < queue.size - 1) {
                        os << ", ";
                    }
                }
                os << "]";
                return os;
            }
            std::size_t Size() const;
            std::size_t Capacity() const;
            T & Front();
            T & Back();
            const T & Front() const;
            const T & Back() const;
            T & At(std::size_t index);
            const T & At(std::size_t index) const;
            void Pop();
            void Clear();
            T Dequeue();
            void Enqueue(const T & element);

        private:
            // The elements of the queue
            T * data;
            // The size of the queue
            std::size_t size;
            // The capacity of the queue
            std::size_t capacity;

    }; // class Queue

    /// @brief Construct a new Queue object
    /// @tparam T The type of the elements of the queue
    template <typename T>
    Queue<T>::Queue() {
        this->data = new T[1];
        this->size = 0;
        this->capacity = 1;
    }

    /// @brief Construct a new Queue object
    /// @tparam T The type of the elements of the queue
    /// @param queue The queue to copy
    template <typename T>
    Queue<T>::Queue(const Queue<T> & queue) {
        this->data = new T[queue.capacity];
        this->size = queue.size;
        this->capacity = queue.capacity;
        for (std::size_t i = 0; i < this->size; i++) {
            this->data[i] = queue.data[i];
        }
    }

    /// @brief Destroy the Queue object
    /// @tparam T The type of the elements of the queue
    template <typename T>
    Queue<T>::~Queue() {
        delete[] this->data;
    }

    /// @brief Compares two queues
    /// @tparam T The type of the elements of the queue
    /// @param queue The queue to compare to
    /// @return true If the queues are equal
    /// @return false If the queues are not equal
    template <typename T>
    bool Queue<T>::operator==(const Queue<T> & queue) const {
        if (this->size != queue.size) {
            return false;
        }
        for (std::size_t i = 0; i < this->size; i++) {
            if (this->data[i] != queue.data[i]) {
                return false;
            }
        }
        return true;
    }

    /// @brief Compares two queues
    /// @tparam T The type of the elements of the queue
    /// @param queue The queue to compare to
    /// @return true If the queues are not equal
    /// @return false If the queues are equal
    template <typename T>
    bool Queue<T>::operator!=(const Queue<T> & queue) const {
        return !(*this == queue);
    }

    /// @brief Returns the size of the queue
    /// @tparam T The type of the elements of the queue
    /// @return std::size_t The size of the queue
    template <typename T>
    std::size_t Queue<T>::Size() const {
        return this->size;
    }

    /// @brief Returns the capacity of the queue
    /// @tparam T The type of the elements of the queue
    /// @return std::size_t The capacity of the queue
    template <typename T>
    std::size_t Queue<T>::Capacity() const {
        return this->capacity;
    }

    /// @brief Returns the first element of the queue
    /// @tparam T The type of the elements of the queue
    /// @return T& The first element of the queue
    template <typename T>
    T & Queue<T>::Front() {
        if (this->size == 0) {
            throw std::out_of_range("No elements in queue");
        }
        return this->data[0];
    }

    /// @brief Returns the last element of the queue
    /// @tparam T The type of the elements of the queue
    /// @return T& The last element of the queue
    template <typename T>
    T & Queue<T>::Back() {
        if (this->size == 0) {
            throw std::out_of_range("No elements in queue");
        }
        return this->data[this->size - 1];
    }

    /// @brief Returns the first element of the queue
    /// @tparam T The type of the elements of the queue
    /// @return const T& The first element of the queue
    template <typename T>
    const T & Queue<T>::Front() const {
        if (this->size == 0) {
            throw std::out_of_range("No elements in queue");
        }
        return this->data[0];
    }

    /// @brief Returns the last element of the queue
    /// @tparam T The type of the elements of the queue
    /// @return const T& The last element of the queue
    template <typename T>
    const T & Queue<T>::Back() const {
        if (this->size == 0) {
            throw std::out_of_range("No elements in queue");
        }
        return this->data[this->size - 1];
    }

    /// @brief Returns the element at the specified index
    /// @tparam T The type of the elements of the queue
    /// @param index The index of the element to return
    /// @return T& The element at the specified index
    template <typename T>
    T & Queue<T>::At(std::size_t index) {
        if (index >= this->size) {
            throw std::out_of_range("Index out of range");
        }
        return this->data[index];
    }

    /// @brief Returns the element at the specified index
    /// @tparam T The type of the elements of the queue
    /// @param index The index of the element to return
    /// @return const T& The element at the specified index
    template <typename T>
    const T & Queue<T>::At(std::size_t index) const {
        if (index >= this->size) {
            throw std::out_of_range("Index out of range");
        }
        return this->data[index];
    }

    /// @brief Returns the element at the specified index
    /// @tparam T The type of the elements of the queue
    /// @param index The index of the element to return
    /// @return T& The element at the specified index
    template <typename T>
    T & Queue<T>::operator[](std::size_t index) {
        if (index >= this->size) {
            throw std::out_of_range("Index out of range");
        }
        return this->data[index];
    }

    /// @brief Returns the element at the specified index
    /// @tparam T The type of the elements of the queue
    /// @param index The index of the element to return
    /// @return const T& The element at the specified index
    template <typename T>
    const T & Queue<T>::operator[](std::size_t index) const {
        if (index >= this->size) {
            throw std::out_of_range("Index out of range");
        }
        return this->data[index];
    }

    /// @brief Removes the first element of the queue
    /// @tparam T The type of the elements of the queue
    template <typename T>
    void Queue<T>::Pop() {
        if (this->size == 0) {
            return;
        }
        for (std::size_t i = 0; i < this->size - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->size--;
    }

    /// @brief Removes all elements from the queue
    /// @tparam T The type of the elements of the queue
    template <typename T>
    void Queue<T>::Clear() {
        this->size = 0;
    }

    /// @brief Adds an element to the end of the queue
    /// @tparam T The type of the elements of the queue
    /// @param element The element to add
    template <typename T>
    void Queue<T>::Enqueue(const T & element) {
        if (this->size == this->capacity) {
            this->capacity *= 2;
            T * newData = new T[this->capacity];
            for (std::size_t i = 0; i < this->size; i++) {
                newData[i] = this->data[i];
            }
            delete[] this->data;
            this->data = newData;
        }
        this->data[this->size] = element;
        this->size++;
    }

    /// @brief Removes the first element of the queue and returns it
    /// @return T& The first element of the queue
    template <typename T>
    T Queue<T>::Dequeue() {
        if (this->size == 0) {
            throw std::out_of_range("No elements in queue");
        }
        T element = this->data[0];
        this->Pop();
        return element;
    }

} // namespace Tobot::DataStructures