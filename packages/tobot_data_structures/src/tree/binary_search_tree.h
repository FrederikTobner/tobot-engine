/**
 * @file binary_search_tree.h
 * @brief File containing a abstract class for a binary search tree
 * @details A binary search tree is a binary tree where the value of each node is greater than the value of all nodes in
 * the left subtree and less than the value of all nodes in the right subtree. This class is used as a base class for
 * the RedBlackTree and the AVLTree implementations.
 */

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
            virtual void traverseInOrder(std::function<void(T)> callback) const = 0;
            virtual void traversePreOrder(std::function<void(T)> callback) const = 0;
            virtual void traversePostOrder(std::function<void(T)> callback) const = 0;
            virtual void clear() = 0;
            virtual std::size_t getSize() = 0;
    }; // class BinarySearchTree

    template <typename T>
    BinarySearchTree<T>::BinarySearchTree() {
    }
} // namespace Tobot::DataStructures::Tree