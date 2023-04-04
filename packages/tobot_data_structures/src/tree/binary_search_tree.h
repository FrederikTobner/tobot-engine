#pragma once

namespace Tobot::DataStructures::Tree {

    template <typename T>
    class BinarySearchTree {
        public:
            BinarySearchTree();
            virtual void Insert(T value) = 0;
            virtual void Delete(T value) = 0;
            virtual bool Contains(T value) = 0;
            virtual void Print() = 0;
            virtual void TraverseInOrder(std::function<void(T)> callback) = 0;
            virtual void TraversePreOrder(std::function<void(T)> callback) = 0;
            virtual void TraversePostOrder(std::function<void(T)> callback) = 0;
            virtual void Clear() = 0;
            virtual std::size_t GetSize() = 0;
    }; // class BinarySearchTree

    template <typename T>
    BinarySearchTree<T>::BinarySearchTree() {
    }
} // namespace Tobot::DataStructures::Tree