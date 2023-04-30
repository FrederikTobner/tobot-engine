/**
 * @file binary_search_tree.h
 * @brief File containing a abstract class for a binary search tree
 * @details A binary search tree is a binary tree where the value of each node is greater than the value of all nodes in
 * the left subtree and less than the value of all nodes in the right subtree. This class is used as a base class for
 * the RedBlackTree and the AVLTree implementations.
 */

#pragma once

namespace Tobot::DataStructures::Tree {

    /// @brief Interface for a binary search tree
    /// @tparam T The type of the values stored in the tree
    template <typename T>
    struct BinarySearchTree {
            virtual auto insert(T value) -> void = 0;
            virtual auto remove(T value) -> void = 0;
            virtual auto contains(T value) -> bool = 0;
            virtual auto print() -> void = 0;
            virtual auto traverseInOrder(std::function<void(T)> callback) const -> void = 0;
            virtual auto traversePreOrder(std::function<void(T)> callback) const -> void = 0;
            virtual auto traversePostOrder(std::function<void(T)> callback) const -> void = 0;
            virtual auto clear() -> void = 0;
            virtual auto getSize() -> std::size_t = 0;
    }; // class BinarySearchTree
} // namespace Tobot::DataStructures::Tree