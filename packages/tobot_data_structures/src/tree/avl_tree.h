#pragma once

#include "../pre_compiled_header.h"

#include "tree.h"

namespace Tobot::DataStructures {

    template <typename T>
    class AVLTree : Tree<T> {
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

            void Insert(T value);
            void Delete(T value);
            bool Contains(T value);
            Node * Search(T value);
            void TraverseInOrder(std::function<void(T)> callback);
            void TraversePreOrder(std::function<void(T)> callback);
            void TraversePostOrder(std::function<void(T)> callback);
            void Print();
            void Clear();
            std::size_t GetSize();
            friend std::ostream & operator<<(std::ostream & os, AVLTree<T> & tree) {
                TraverseInOrder([&](T value) { os << value << ", "; });
            }

        private:
            Node * root;

            Node * Insert(Node * node, T value);
            Node * Delete(Node * node, T value);
            Node * Search(Node * node, T value);

            Node * RotateLeft(Node * node);
            Node * RotateRight(Node * node);
            Node * RotateLeftRight(Node * node);
            Node * RotateRightLeft(Node * node);

            int GetHeight(Node * node);
            int GetBalance(Node * node);

            Node * CreateNode(T value);
            void DeleteNode(Node * node);
            void TraverseInOrder(Node * node, std::function<void(T)> callback);
            void TraversePreOrder(Node * node, std::function<void(T)> callback);
            void TraversePostOrder(Node * node, std::function<void(T)> callback);
            void Print(Node * node, int level);
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
        tree.TraverseInOrder([&](T value) { this->Insert(value); });
    }

    /// @brief AVLTree constructor
    /// @tparam T The type of the value stored in the tree
    /// @param list The list of values to insert in the tree
    template <typename T>
    AVLTree<T>::AVLTree(std::initializer_list<T> list) {
        root = nullptr;
        for (T value : list) {
            Insert(value);
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
    void AVLTree<T>::Insert(T value) {
        root = Insert(root, value);
    }

    /// @brief Delete a value from the tree
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to delete from the tree
    template <typename T>
    void AVLTree<T>::Delete(T value) {
        root = Delete(root, value);
    }

    /// @brief Check if the tree contains a value
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to check if it is in the tree
    /// @return True if the tree contains the value, false otherwise
    template <typename T>
    bool AVLTree<T>::Contains(T value) {
        return Search(value) != nullptr;
    }

    /// @brief Search for a value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to search for in the tree
    /// @return A pointer to the node containing the value, nullptr if the value is not in the tree
    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::Search(T value) {
        return Search(root, value);
    }

    /// @brief Insert a value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to insert the value in
    /// @param value The value to insert in the tree
    /// @return A pointer to the node containing the value
    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::Insert(Node * node, T value) {
        if (node == nullptr) {
            return CreateNode(value);
        }
        if (value < node->value) {
            node->left = Insert(node->left, value);
        } else if (value > node->value) {
            node->right = Insert(node->right, value);
        } else {
            return node;
        }
        node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));
        int balance = GetBalance(node);
        if (balance > 1 && value < node->left->value) {
            return RotateRight(node);
        }
        if (balance < -1 && value > node->right->value) {
            return RotateLeft(node);
        }
        if (balance > 1 && value > node->left->value) {
            return RotateLeftRight(node);
        }
        if (balance < -1 && value < node->right->value) {
            return RotateRightLeft(node);
        }
        return node;
    }

    /// @brief Delete a value from the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to delete the value from
    /// @param value The value to delete from the tree
    /// @return A pointer to the node containing the value
    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::Delete(Node * node, T value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->value) {
            node->left = Delete(node->left, value);
        } else if (value > node->value) {
            node->right = Delete(node->right, value);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                Node * temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                DeleteNode(temp);
            } else {
                Node * temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->value = temp->value;
                node->right = Delete(node->right, temp->value);
            }
        }
        if (node == nullptr) {
            return node;
        }
        node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));
        int balance = GetBalance(node);
        if (balance > 1 && GetBalance(node->left) >= 0) {
            return RotateRight(node);
        }
        if (balance > 1 && GetBalance(node->left) < 0) {
            return RotateLeftRight(node);
        }
        if (balance < -1 && GetBalance(node->right) <= 0) {
            return RotateLeft(node);
        }
        if (balance < -1 && GetBalance(node->right) > 0) {
            return RotateRightLeft(node);
        }
        return node;
    }

    /// @brief Search for a value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to search the value in
    /// @param value The value to search for in the tree
    /// @return A pointer to the node containing the value, nullptr if the value is not in the tree
    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::Search(Node * node, T value) {
        if (node == nullptr || node->value == value) {
            return node;
        }
        if (value < node->value) {
            return Search(node->left, value);
        }
        return Search(node->right, value);
    }

    /// @brief Rotate the tree to the left
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to rotate the tree around
    /// @return A pointer to the new root of the tree
    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::RotateLeft(Node * node) {
        Node * right = node->right;
        Node * right_left = right->left;
        right->left = node;
        node->right = right_left;
        node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
        right->height = std::max(GetHeight(right->left), GetHeight(right->right)) + 1;
        return right;
    }

    /// @brief Rotate the tree to the right
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to rotate the tree around
    /// @return A pointer to the new root of the tree
    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::RotateRight(Node * node) {
        Node * left = node->left;
        Node * left_right = left->right;
        left->right = node;
        node->left = left_right;
        node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
        left->height = std::max(GetHeight(left->left), GetHeight(left->right)) + 1;
        return left;
    }

    /// @brief Rotate the tree to the left and then to the right
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to rotate the tree around
    /// @return A pointer to the new root of the tree
    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::RotateLeftRight(Node * node) {
        node->left = RotateLeft(node->left);
        return RotateRight(node);
    }

    /// @brief Rotate the tree to the right and then to the left
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to rotate the tree around
    /// @return A pointer to the new root of the tree
    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::RotateRightLeft(Node * node) {
        node->right = RotateRight(node->right);
        return RotateLeft(node);
    }

    /// @brief Get the height of a node
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to get the height of
    /// @return The height of the node
    template <typename T>
    int AVLTree<T>::GetHeight(Node * node) {
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
    int AVLTree<T>::GetBalance(Node * node) {
        if (node == nullptr) {
            return 0;
        }
        return GetHeight(node->left) - GetHeight(node->right);
    }

    /// @brief Create a new node with the given value
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to store in the node
    /// @return A pointer to the new node
    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::CreateNode(T value) {
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
    void AVLTree<T>::DeleteNode(Node * node) {
        delete node;
    }

    /// Traverse the tree in order
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start the traversal from
    /// @param callback The callback to call for each node
    template <typename T>
    void AVLTree<T>::TraverseInOrder(Node * node, std::function<void(T)> callback) {
        if (node == nullptr) {
            return;
        }
        TraverseInOrder(node->left, callback);
        callback(node->value);
        TraverseInOrder(node->right, callback);
    }

    /// Traverse the tree in order
    ///  @tparam T The type of the value stored in the tree
    ///  @param callback The callback to call for each node
    template <typename T>
    void AVLTree<T>::TraverseInOrder(std::function<void(T)> callback) {
        TraverseInOrder(root, callback);
    }

    /// Traverse the tree in pre order
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start the traversal from
    /// @param callback The callback to call for each node
    template <typename T>
    void AVLTree<T>::TraversePreOrder(Node * node, std::function<void(T)> callback) {
        if (node == nullptr) {
            return;
        }
        callback(node->value);
        TraversePreOrder(node->left, callback);
        TraversePreOrder(node->right, callback);
    }

    /// Traverse the tree in pre order
    /// @tparam T The type of the value stored in the tree
    /// @param callback The callback to call for each node
    template <typename T>
    void AVLTree<T>::TraversePreOrder(std::function<void(T)> callback) {
        TraversePreOrder(root, callback);
    }

    /// Traverse the tree in post order
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start the traversal from
    /// @param callback The callback to call for each node
    template <typename T>
    void AVLTree<T>::TraversePostOrder(Node * node, std::function<void(T)> callback) {
        if (node == nullptr) {
            return;
        }
        TraversePostOrder(node->left, callback);
        TraversePostOrder(node->right, callback);
        callback(node->value);
    }

    /// Traverse the tree in post order
    /// @tparam T The type of the value stored in the tree
    /// @param callback The callback to call for each node
    template <typename T>
    void AVLTree<T>::TraversePostOrder(std::function<void(T)> callback) {
        TraversePostOrder(root, callback);
    }

    /// Prints the tree in a human readable format
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start the traversal from
    /// @param indent The current indentation level
    template <typename T>
    void AVLTree<T>::Print(Node * node, int indent) {
        if (node == nullptr) {
            return;
        }
        Print(node->right, indent + 1);
        for (int i = 0; i < indent; i++) {
            std::cout << "    ";
        }
        std::cout << node->value << std::endl;
        Print(node->left, indent + 1);
    }

    /// Prints the tree in a human readable format
    /// @tparam T The type of the value stored in the tree
    template <typename T>
    void AVLTree<T>::Print() {
        Print(root, 0);
    }

    /// Clears the tree
    /// @tparam T The type of the value stored in the tree
    template <typename T>
    void AVLTree<T>::Clear() {
        TraversePostOrder([this](T value) { DeleteNode(Search(value)); });
        root = nullptr;
    }

    /// @brief Get the number of nodes in the tree
    /// @tparam T The type of the value stored in the tree
    /// @return The number of nodes in the tree
    template <typename T>
    std::size_t AVLTree<T>::GetSize() {
        std::size_t size = 0;
        TraverseInOrder([&size](T value) { size++; });
        return size;
    }

} // namespace Tobot::DataStructures