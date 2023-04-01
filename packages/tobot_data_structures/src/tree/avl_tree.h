#pragma once

namespace Tobot::DataStructures {

    template <typename T>
    class AVLTree {
        public:
            struct Node {
                    T value;
                    Node * left;
                    Node * right;
                    int height;
            };
            AVLTree();
            ~AVLTree();

            void Insert(T value);
            void Delete(T value);
            bool Contains(T value);
            Node * Search(T value);

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
    };

    template <typename T>
    AVLTree<T>::AVLTree() {
        root = nullptr;
    }

    template <typename T>
    AVLTree<T>::~AVLTree() {
    }

    template <typename T>
    void AVLTree<T>::Insert(T value) {
        root = Insert(root, value);
    }

    template <typename T>
    void AVLTree<T>::Delete(T value) {
        root = Delete(root, value);
    }

    template <typename T>
    bool AVLTree<T>::Contains(T value) {
        return Search(value) != nullptr;
    }

    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::Search(T value) {
        return Search(root, value);
    }

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

    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::RotateLeftRight(Node * node) {
        node->left = RotateLeft(node->left);
        return RotateRight(node);
    }

    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::RotateRightLeft(Node * node) {
        node->right = RotateRight(node->right);
        return RotateLeft(node);
    }

    template <typename T>
    int AVLTree<T>::GetHeight(Node * node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    template <typename T>
    int AVLTree<T>::GetBalance(Node * node) {
        if (node == nullptr) {
            return 0;
        }
        return GetHeight(node->left) - GetHeight(node->right);
    }

    template <typename T>
    typename AVLTree<T>::Node * AVLTree<T>::CreateNode(T value) {
        Node * node = new Node();
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return node;
    }

    template <typename T>
    void AVLTree<T>::DeleteNode(Node * node) {
        delete node;
    }

} // namespace Tobot::DataStructures