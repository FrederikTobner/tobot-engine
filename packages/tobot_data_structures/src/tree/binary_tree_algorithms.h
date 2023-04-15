/**
 * @file binary_tree_traversal.h
 * @brief File containing implementation of the behavoir that is used for traversing a binary search tree
 * @details This behaviour is used by the RedBlackTree and the AVLTree implementations.
 */

#pragma once

#include "../pre_compiled_header.h"

#include "../concepts.h"

namespace Tobot::DataStructures::Tree {

    /// @brief Traverses a binary tree in order
    /// @tparam T1 The type of the node
    /// @tparam T2 The type of the value stored in the node
    /// @param node The node to start traversing from
    /// @param callback The callback to call for each node
    /// @param nil The null representation of a node
    template <typename T1, typename T2>
        requires IsBinarySearchTreeNode<T1> && IsValueInBinarySearchTreeNode<T1, T2>
    auto traverseInOrder(T1 * node, std::function<void(T2)> callback, T1 const * const nil) -> void {
        if (node != nil) {
            traverseInOrder(node->left, callback, nil);
            callback(node->value);
            traverseInOrder(node->right, callback, nil);
        }
    }

    /// @brief Traverses a binary tree in pre order
    /// @tparam T1 The type of the node
    /// @tparam T2 The type of the value stored in the node
    /// @param node The node to start traversing from
    /// @param callback The callback to call for each node
    /// @param nil The null representation of a node
    template <typename T1, typename T2>
        requires IsBinarySearchTreeNode<T1> && IsValueInBinarySearchTreeNode<T1, T2>
    auto traversePreOrder(T1 * node, std::function<void(T2)> callback, T1 const * const nil) -> void {
        if (node != nil) {
            callback(node->value);
            traversePreOrder(node->left, callback, nil);
            traversePreOrder(node->right, callback, nil);
        }
    }

    /// @brief Traverses a binary tree in post order
    /// @tparam T1 The type of the node
    /// @tparam T2 The type of the value stored in the node
    /// @param node The node to start traversing from
    /// @param callback The callback to call for each node
    /// @param nil The null representation of a node
    template <typename T1, typename T2>
        requires IsBinarySearchTreeNode<T1> && IsValueInBinarySearchTreeNode<T1, T2>
    auto traversePostOrder(T1 * node, std::function<void(T2)> callback, T1 const * const nil) -> void {
        if (node != nil) {
            traversePostOrder(node->left, callback, nil);
            traversePostOrder(node->right, callback, nil);
            callback(node->value);
        }
    }

    /// @brief Gets the node with the minimum value in a binary search tree
    /// @tparam T1 The type of the node
    /// @param node The node to start searching from
    /// @param nil The null representation of a node
    /// @return The node with the minimum value
    template <typename T1>
        requires IsBinarySearchTreeNode<T1>
    auto getMinimum(T1 * node, T1 const * const nil) -> T1 * {
        while (node->left != nil) {
            node = node->left;
        }
        return node;
    }

    /// @brief Gets the node with the maximum value in a binary search tree
    /// @tparam T1 The type of the node
    /// @param node The node to start searching from
    /// @param nil The null representation of a node
    /// @return The node with the maximum value
    template <typename T1>
        requires IsBinarySearchTreeNode<T1>
    auto getMaximum(T1 * node, T1 const * const nil) -> T1 * {
        while (node->right != nil) {
            node = node->right;
        }
        return node;
    }

    /// @brief Checks if a value is contained in a binary search tree - with a null check
    /// @tparam T1 The type of the node
    /// @tparam T2 The type of the value stored in the node
    /// @param root The root of the tree
    /// @param nil The null representation of a node
    /// @param value The value to check for
    /// @return true if the value is contained in the tree, false otherwise
    template <typename T1, typename T2>
        requires IsBinarySearchTreeNode<T1> && IsValueInBinarySearchTreeNode<T1, T2>
    auto containsWithNullCheck(T1 * root, T1 const * const nil, T2 value) -> bool {
        T1 * x = root;
        while (x != nil && x->value != value) {
            if (value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        if (!x || x->value != value) {
            return false;
        }
        return x;
    }

    /// @brief Checks if a value is contained in a binary search tree - without a null check
    /// @tparam T1 The type of the node
    /// @tparam T2 The type of the value stored in the node
    /// @param root The root of the tree
    /// @param nil The null representation of a node
    /// @param value The value to check for
    /// @return true if the value is contained in the tree, false otherwise
    template <typename T1, typename T2>
        requires IsBinarySearchTreeNode<T1> && IsValueInBinarySearchTreeNode<T1, T2>
    auto containsWithoutNullCheck(T1 * root, T1 const * const nil, T2 value) -> bool {
        T1 * x = root;
        while (x != nil && x->value != value) {
            if (value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        if (x->value != value) {
            return false;
        }
        return x;
    }

} // namespace Tobot::DataStructures::Tree