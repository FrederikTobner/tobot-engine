/**
 * @file avl_tree.h
 * @brief File containing a template implementation of a AVL Tree
 * @details A AVL Tree is a self balancing binary search tree. It is a binary search tree where the difference between
 * the height of the left and right subtree of a node is at most 1.
 * @see https://en.wikipedia.org/wiki/AVL_tree
 */

#pragma once

#include "../pre_compiled_header.hpp"

#include "binary_search_tree.hpp"

#include "binary_tree_algorithms.hpp"

namespace Tobot::DataStructures::Tree {

    /// @brief AVL Tree implementation
    /// @tparam T Type of the tree values
    template <typename T>
    class AVLTree : public BinarySearchTree<T> {
        public:
            struct Node {
                    T value;
                    Node * left;
                    Node * right;
                    int height;
            };
            AVLTree();
            AVLTree(AVLTree & tree);
            ~AVLTree();
            AVLTree(std::initializer_list<T> list);

            auto insert(T value) -> void;
            auto remove(T value) -> void;
            auto contains(T value) -> bool;
            auto search(T value) -> Node *;
            auto traverseInOrder(std::function<void(T)> callback) const -> void;
            auto traversePreOrder(std::function<void(T)> callback) const -> void;
            auto traversePostOrder(std::function<void(T)> callback) const -> void;
            auto print() -> void;
            auto clear() -> void;
            auto getMaximum() -> Node *;
            auto getMinimum() -> Node *;
            std::size_t getSize();
            friend std::ostream & operator<<(std::ostream & os, AVLTree<T> const & tree) {
                TraverseInOrder([&](T value) { os << value << ", "; });
            }

        private:
            Node * root;

            auto insert(Node * node, T value) -> Node *;
            auto remove(Node * node, T value) -> Node *;
            auto search(Node * node, T value) -> Node *;

            auto rotateLeft(Node * node) -> Node *;
            auto rotateRight(Node * node) -> Node *;
            auto rotateLeftRight(Node * node) -> Node *;
            auto rotateRightLeft(Node * node) -> Node *;

            auto getHeight(Node * node) -> int;
            auto getBalance(Node * node) -> int;

            auto createNode(T value) -> Node *;
            auto deleteNode(Node * node) -> void;
            auto print(Node * node, int level) -> void;
    };

    /// @brief AVLTree constructor
    /// @tparam T The type of the value stored in the tree
    template <typename T>
    AVLTree<T>::AVLTree() {
        root = nullptr;
    }

    /// @brief AVLTree copy constructor
    /// @tparam T The type of the value stored in the tree
    /// @param tree The tree to copy
    template <typename T>
    AVLTree<T>::AVLTree(AVLTree & tree) {
        root = nullptr;
        tree.traverseInOrder([&](T value) { this->insert(value); });
    }

    /// @brief AVLTree constructor
    /// @tparam T The type of the value stored in the tree
    /// @param list The list of values to insert in the tree
    template <typename T>
    AVLTree<T>::AVLTree(std::initializer_list<T> list) {
        root = nullptr;
        for (T value : list) {
            insert(value);
        }
    }

    /// @brief AVLTree destructor
    /// @tparam T The type of the value stored in the tree
    template <typename T>
    AVLTree<T>::~AVLTree() {
    }

    /// @brief Insert a value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to insert in the tree
    template <typename T>
    auto AVLTree<T>::insert(T value) -> void {
        root = insert(root, value);
    }

    /// @brief Delete a value from the tree
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to delete from the tree
    template <typename T>
    auto AVLTree<T>::remove(T value) -> void {
        root = remove(root, value);
    }

    /// @brief Check if the tree contains a value
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to check if it is in the tree
    /// @return True if the tree contains the value, false otherwise
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::contains(T value) -> bool {
        return Tobot::DataStructures::Tree::containsWithNullCheck(this->root, (Node *)nullptr, value);
    }

    /// @brief Search for a value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to search for in the tree
    /// @return A pointer to the node containing the value, nullptr if the value is not in the tree
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::search(T value) -> typename AVLTree<T>::Node * {
        return search(root, value);
    }

    /// @brief Insert a value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to insert the value in
    /// @param value The value to insert in the tree
    /// @return A pointer to the node containing the value
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::insert(Node * node, T value) -> typename AVLTree<T>::Node * {
        if (node == nullptr) {
            return createNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        int balance = getBalance(node);
        if (balance > 1 && value < node->left->value) {
            return rotateRight(node);
        }
        if (balance < -1 && value > node->right->value) {
            return rotateLeft(node);
        }
        if (balance > 1 && value > node->left->value) {
            return rotateLeftRight(node);
        }
        if (balance < -1 && value < node->right->value) {
            return rotateRightLeft(node);
        }
        return node;
    }

    /// @brief Delete a value from the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to delete the value from
    /// @param value The value to delete from the tree
    /// @return A pointer to the node containing the value
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::remove(Node * node, T value) -> typename AVLTree<T>::Node * {
        if (node == nullptr) {
            return node;
        }
        if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value > node->value) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                Node * temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                deleteNode(temp);
            } else {
                Node * temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->value = temp->value;
                node->right = remove(node->right, temp->value);
            }
        }
        if (node == nullptr) {
            return node;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        int balance = getBalance(node);
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }
        if (balance > 1 && getBalance(node->left) < 0) {
            return rotateLeftRight(node);
        }
        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }
        if (balance < -1 && getBalance(node->right) > 0) {
            return rotateRightLeft(node);
        }
        return node;
    }

    /// @brief Search for a value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to search the value in
    /// @param value The value to search for in the tree
    /// @return A pointer to the node containing the value, nullptr if the value is not in the tree
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::search(Node * node, T value) -> typename AVLTree<T>::Node * {
        if (node == nullptr || node->value == value) {
            return node;
        }
        if (value < node->value) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

    /// @brief Rotate the tree to the left
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to rotate the tree around
    /// @return A pointer to the new root of the tree
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::rotateLeft(Node * node) -> typename AVLTree<T>::Node * {
        Node * right = node->right;
        Node * right_left = right->left;
        right->left = node;
        node->right = right_left;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        int rightleftHeight = getHeight(right->left);
        int rightrightHeight = getHeight(right->right);
        right->height = 1 + (rightleftHeight > rightrightHeight ? rightleftHeight : rightrightHeight);
        return right;
    }

    /// @brief Rotate the tree to the right
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to rotate the tree around
    /// @return A pointer to the new root of the tree
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::rotateRight(Node * node) -> typename AVLTree<T>::Node * {
        Node * left = node->left;
        Node * left_right = left->right;
        left->right = node;
        node->left = left_right;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        int leftleftHeight = getHeight(left->left);
        int leftrightHeight = getHeight(left->right);
        left->height = 1 + (leftleftHeight > leftrightHeight ? leftleftHeight : leftrightHeight);
        return left;
    }

    /// @brief Rotate the tree to the left and then to the right
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to rotate the tree around
    /// @return A pointer to the new root of the tree
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::rotateLeftRight(Node * node) -> typename AVLTree<T>::Node * {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    /// @brief Rotate the tree to the right and then to the left
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to rotate the tree around
    /// @return A pointer to the new root of the tree
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::rotateRightLeft(Node * node) -> typename AVLTree<T>::Node * {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    /// @brief Gets the minimum value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to get the minimum value from
    /// @return The minimum value in the tree
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::getMinimum() -> typename AVLTree<T>::Node * {
        Tobot::DataStructures::Tree::getMinimum(root, (Node *)nullptr);
    }

    /// @brief Gets the maximum value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to get the maximum value from
    /// @return The maximum value in the tree
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::getMaximum() -> typename AVLTree<T>::Node * {
        Tobot::DataStructures::Tree::getMaximum(root, (Node *)nullptr);
    }

    /// @brief Get the height of a node
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to get the height of
    /// @return The height of the node
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::getHeight(Node * node) -> int {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    /// @brief Get the balance of a node
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to get the balance of
    /// @return The balance of the node
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::getBalance(Node * node) -> int {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    /// @brief Create a new node with the given value
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to store in the node
    /// @return A pointer to the new node
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::createNode(T value) -> typename AVLTree<T>::Node * {
        Node * node = new Node();
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return node;
    }

    /// @brief Delete a node from the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to delete
    template <typename T>
    auto AVLTree<T>::deleteNode(Node * node) -> void {
        delete node;
    }

    /// Traverse the tree in order
    ///  @tparam T The type of the value stored in the tree
    ///  @param callback The callback to call for each node
    template <typename T>
    auto AVLTree<T>::traverseInOrder(std::function<void(T)> callback) const -> void {
        Tobot::DataStructures::Tree::traverseInOrder(root, callback, (Node *)nullptr);
    }

    /// Traverse the tree in pre order
    /// @tparam T The type of the value stored in the tree
    /// @param callback The callback to call for each node
    template <typename T>
    auto AVLTree<T>::traversePreOrder(std::function<void(T)> callback) const -> void {
        Tobot::DataStructures::Tree::traversePreOrder(root, callback, (Node *)nullptr);
    }

    /// Traverse the tree in post order
    /// @tparam T The type of the value stored in the tree
    /// @param callback The callback to call for each node
    template <typename T>
    auto AVLTree<T>::traversePostOrder(std::function<void(T)> callback) const -> void {
        Tobot::DataStructures::Tree::traversePostOrder(root, callback, (Node *)nullptr);
    }

    /// Prints the tree in a human readable format
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start the traversal from
    /// @param indent The current indentation level
    template <typename T>
    auto AVLTree<T>::print(Node * node, int indent) -> void {
        if (node == nullptr) {
            return;
        }
        print(node->right, indent + 1);
        for (int i = 0; i < indent; i++) {
            std::cout << "    ";
        }
        std::cout << node->value << std::endl;
        print(node->left, indent + 1);
    }

    /// Prints the tree in a human readable format
    /// @tparam T The type of the value stored in the tree
    template <typename T>
    void AVLTree<T>::print() {
        print(root, 0);
    }

    /// Clears the tree
    /// @tparam T The type of the value stored in the tree
    template <typename T>
    auto AVLTree<T>::clear() -> void {
        traversePostOrder([this](T value) { deleteNode(search(value)); });
        root = nullptr;
    }

    /// @brief Get the number of nodes in the tree
    /// @tparam T The type of the value stored in the tree
    /// @return The number of nodes in the tree
    template <typename T>
    [[nodiscard]] auto AVLTree<T>::getSize() -> std::size_t {
        std::size_t size = 0;
        traverseInOrder([&size](T value) { size++; });
        return size;
    }

} // namespace Tobot::DataStructures::Tree