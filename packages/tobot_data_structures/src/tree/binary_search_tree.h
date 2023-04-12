#pragma once

namespace Tobot::DataStructures::Tree {

    template <typename T>
    class BinarySearchTree {
        public:
            BinarySearchTree();
            virtual void insert(T value) = 0;
            virtual void remove(T value) = 0;
            virtual bool contains(T value) = 0;
            virtual void print() = 0;
            virtual void traverseInOrder(std::function<void(T)> callback) = 0;
            virtual void traversePreOrder(std::function<void(T)> callback) = 0;
            virtual void traversePostOrder(std::function<void(T)> callback) = 0;
            virtual void clear() = 0;
            virtual std::size_t getSize() = 0;
    }; // class BinarySearchTree

    template <typename T>
    BinarySearchTree<T>::BinarySearchTree() {
    }
} // namespace Tobot::DataStructures::Tree