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
    void traverseInOrder(T1 * node, std::function<void(T2)> callback, T1 const * const nil) {
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
    void traversePreOrder(T1 * node, std::function<void(T2)> callback, T1 const * const nil) {
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
    void traversePostOrder(T1 * node, std::function<void(T2)> callback, T1 const * const nil) {
        if (node != nil) {
            traversePostOrder(node->left, callback, nil);
            traversePostOrder(node->right, callback, nil);
            callback(node->value);
        }
    }

    template <typename T1>
        requires IsBinarySearchTreeNode<T1> decltype(auto)
    getMinimum(T1 * node, T1 const * const nil) {
        while (node->left != nil) {
            node = node->left;
        }
        return node;
    }

    template <typename T1>
        requires IsBinarySearchTreeNode<T1> decltype(auto)
    getMaximum(T1 * node, T1 const * const nil) {
        while (node->right != nil) {
            node = node->right;
        }
        return node;
    }

} // namespace Tobot::DataStructures::Tree