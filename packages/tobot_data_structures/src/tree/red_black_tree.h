#pragma once

#include "../pre_compiled_header.h"

#include "binary_search_tree.h"

namespace Tobot::DataStructures::Tree {

    /// @brief A RedBlackTree is a self-balancing binary search tree.
    /// @tparam T The type of the value stored in the tree
    /// @details It is a binary search tree with one extra bit of storage per node: its color, which can be either red
    /// or black. These colors are used to ensure the tree remains approximately balanced during insertions and
    /// deletions.
    template <typename T>
    class RedBlackTree : public BinarySearchTree<T> {
        public:
            /// @brief The node structure for the RedBlackTree class
            struct Node {
                    T value;
                    Node * left;
                    Node * right;
                    Node * parent;
                    bool isRed;
            };
            RedBlackTree();
            RedBlackTree(RedBlackTree<T> & tree);
            RedBlackTree(std::initializer_list<T> list);
            ~RedBlackTree();
            void insert(T value);
            void remove(T value);
            bool contains(T value);
            Node * search(T value);
            void print();
            void traverseInOrder(std::function<void(T)> callback);
            void traversePreOrder(std::function<void(T)> callback);
            void traversePostOrder(std::function<void(T)> callback);
            void clear();
            std::size_t getSize();
            friend std::ostream & operator<<(std::ostream & os, RedBlackTree<T> const & tree) {
                TraverseInOrder(tree.root, [&os](T value) { os << value << ", "; });
            }
            class iterator : public std::iterator<std::input_iterator_tag, T> {
                public:
                    iterator(Node * node, Node * nil) {
                        this->node = node;
                        this->nil = nil;
                    }
                    iterator & operator++() {
                        if (this->node->right != this->nil) {
                            this->node = this->node->right;
                            while (this->node->left != this->nil) {
                                this->node = this->node->left;
                            }
                        } else {
                            Node * parent = this->node->parent;
                            while (this->node == parent->right) {
                                this->node = parent;
                                parent = parent->parent;
                            }
                            if (this->node->right != parent) {
                                this->node = parent;
                            }
                        }
                        return *this;
                    }
                    iterator operator++(int) {
                        iterator tmp(*this);
                        operator++();
                        return tmp;
                    }
                    bool operator==(const iterator & rhs) {
                        return this->node == rhs.node;
                    }
                    bool operator!=(const iterator & rhs) {
                        return this->node != rhs.node;
                    }
                    T & operator*() {
                        return this->node->value;
                    }
                    T * operator->() {
                        return &this->node->value;
                    }

                private:
                    Node * node;
                    Node * nil;
            };
            iterator begin() {
                return iterator(getMinimum(this->root), this->nil);
            }
            iterator end() {
                return iterator(this->nil, this->nil);
            }

        private:
            Node * root;
            Node * nil;
            void leftRotate(Node * node);
            void rightRotate(Node * node);
            void insertFixup(Node * node);
            void deleteFixup(Node * node);
            void transplant(Node * u, Node * v);
            Node * getMinimum(Node * node);
            Node * getMaximum(Node * node);
            Node * successor(Node * node);
            Node * predecessor(Node * node);
            void print(Node * node);
            void traverseInOrder(Node * node, std::function<void(T)> callback);
            void traversePreOrder(Node * node, std::function<void(T)> callback);
            void traversePostOrder(Node * node, std::function<void(T)> callback);
            void clear(Node * node);
    };

    /// @brief Constructor for the RedBlackTree class
    /// @tparam T The type of the value stored in the tree
    template <typename T>
    RedBlackTree<T>::RedBlackTree() {
        this->nil = new Node;
        this->nil->left = nullptr;
        this->nil->right = nullptr;
        this->nil->parent = nullptr;
        this->nil->isRed = false;
        this->root = this->nil;
    }

    /// @brief Copy constructor for the RedBlackTree class
    /// @tparam T The type of the value stored in the tree
    /// @param tree The tree to copy
    template <typename T>
    RedBlackTree<T>::RedBlackTree(RedBlackTree<T> & tree) {
        this->nil = new Node;
        this->nil->left = nullptr;
        this->nil->right = nullptr;
        this->nil->parent = nullptr;
        this->nil->isRed = false;
        this->root = this->nil;
        tree.traverseInOrder([&](T value) { this->insert(value); });
    }

    /// Creates a RebBlackTree from a list of values
    /// @tparam T The type of the value stored in the tree
    /// @param list The list of values to create the tree from
    template <typename T>
    RedBlackTree<T>::RedBlackTree(std::initializer_list<T> list) {
        this->nil = new Node;
        this->nil->left = nullptr;
        this->nil->right = nullptr;
        this->nil->parent = nullptr;
        this->nil->isRed = false;
        this->root = this->nil;
        for (T value : list) {
            this->insert(value);
        }
    }

    /// @brief Destructor for the RedBlackTree class
    /// @tparam T The type of the value stored in the tree
    template <typename T>
    RedBlackTree<T>::~RedBlackTree() {
        delete this->nil;
    }

    /// @brief Left rotate the tree at specified node
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to rotate the tree at
    template <typename T>
    void RedBlackTree<T>::leftRotate(Node * node) {
        Node * y = node->right;
        node->right = y->left;
        if (y->left != this->nil) {
            y->left->parent = node;
        }
        y->parent = node->parent;
        if (node->parent == this->nil) {
            this->root = y;
        } else if (node == node->parent->left) {
            node->parent->left = y;
        } else {
            node->parent->right = y;
        }
        y->left = node;
        node->parent = y;
    }

    /// @brief  Right rotate the tree at the specified node
    /// @tparam T  The type of the value stored in the tree
    /// @param node  The node to rotate the tree at
    template <typename T>
    void RedBlackTree<T>::rightRotate(Node * node) {
        Node * y = node->left;
        node->left = y->right;
        if (y->right != this->nil) {
            y->right->parent = node;
        }
        y->parent = node->parent;
        if (node->parent == this->nil) {
            this->root = y;
        } else if (node == node->parent->right) {
            node->parent->right = y;
        } else {
            node->parent->left = y;
        }
        y->right = node;
        node->parent = y;
    }

    /// @brief Insert a new node into the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to insert into the tree
    template <typename T>
    void RedBlackTree<T>::insertFixup(Node * node) {
        while (node->parent->isRed) {
            if (node->parent == node->parent->parent->left) {
                Node * y = node->parent->parent->right;
                if (y->isRed) {
                    node->parent->isRed = false;
                    y->isRed = false;
                    node->parent->parent->isRed = true;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        this->leftRotate(node);
                    }
                    node->parent->isRed = false;
                    node->parent->parent->isRed = true;
                    this->rightRotate(node->parent->parent);
                }
            } else {
                Node * y = node->parent->parent->left;
                if (y->isRed) {
                    node->parent->isRed = false;
                    y->isRed = false;
                    node->parent->parent->isRed = true;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        this->rightRotate(node);
                    }
                    node->parent->isRed = false;
                    node->parent->parent->isRed = true;
                    this->leftRotate(node->parent->parent);
                }
            }
        }
        this->root->isRed = false;
    }

    /// @brief Delete a node from the tree
    /// @tparam T The type of the value stored in the tree
    /// @param value The value of the node to delete
    template <typename T>
    void RedBlackTree<T>::insert(T value) {
        Node * z = new Node;
        z->value = value;
        z->left = this->nil;
        z->right = this->nil;
        z->parent = this->nil;
        z->isRed = true;
        Node * y = this->nil;
        Node * x = this->root;
        while (x != this->nil) {
            y = x;
            if (z->value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == this->nil) {
            this->root = z;
        } else if (z->value < y->value) {
            y->left = z;
        } else {
            y->right = z;
        }
        this->insertFixup(z);
    }

    /// @brief Delete a node from the tree
    /// @tparam T The type of the value stored in the tree
    /// @param value The value of the node to delete
    template <typename T>
    void RedBlackTree<T>::remove(T value) {
        Node * z = this->root;
        while (z != this->nil && z->value != value) {
            if (value < z->value) {
                z = z->left;
            } else {
                z = z->right;
            }
        }
        if (z == this->nil) {
            return;
        }
        Node * y = z;
        Node * x;
        bool yOriginalColor = y->isRed;
        if (z->left == this->nil) {
            x = z->right;
            this->transplant(z, z->right);
        } else if (z->right == this->nil) {
            x = z->left;
            this->transplant(z, z->left);
        } else {
            y = this->getMinimum(z->right);
            yOriginalColor = y->isRed;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                this->transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            this->transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->isRed = z->isRed;
        }
        if (!yOriginalColor) {
            this->deleteFixup(x);
        }
        delete z;
    }

    /// @brief Check if the tree contains a node with the given value
    /// @tparam T The type of the value stored in the tree
    /// @param value The value to check for
    /// @return True if the tree contains a node with the given value, false otherwise
    template <typename T>
    bool RedBlackTree<T>::contains(T value) {
        Node * x = this->root;
        while (x != this->nil && x->value != value) {
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

    /// @brief Fix the tree after a node has been deleted
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start fixing the tree at
    template <typename T>
    void RedBlackTree<T>::deleteFixup(Node * node) {
        while (node != this->root && !node->isRed) {
            if (node == node->parent->left) {
                Node * w = node->parent->right;
                if (w->isRed) {
                    w->isRed = false;
                    node->parent->isRed = true;
                    this->leftRotate(node->parent);
                    w = node->parent->right;
                }
                if (!w->left->isRed && !w->right->isRed) {
                    w->isRed = true;
                    node = node->parent;
                } else {
                    if (!w->right->isRed) {
                        w->left->isRed = false;
                        w->isRed = true;
                        this->rightRotate(w);
                        w = node->parent->right;
                    }
                    w->isRed = node->parent->isRed;
                    node->parent->isRed = false;
                    w->right->isRed = false;
                    this->leftRotate(node->parent);
                    node = this->root;
                }
            } else {
                Node * w = node->parent->left;
                if (w->isRed) {
                    w->isRed = false;
                    node->parent->isRed = true;
                    this->rightRotate(node->parent);
                    w = node->parent->left;
                }
                if (!w->right->isRed && !w->left->isRed) {
                    w->isRed = true;
                    node = node->parent;
                } else {
                    if (!w->left->isRed) {
                        w->right->isRed = false;
                        w->isRed = true;
                        this->leftRotate(w);
                        w = node->parent->left;
                    }
                    w->isRed = node->parent->isRed;
                    node->parent->isRed = false;
                    w->left->isRed = false;
                    this->rightRotate(node->parent);
                    node = this->root;
                }
            }
        }
        node->isRed = false;
    }

    /// @brief Transplant one node for another
    /// @tparam T The type of the value stored in the tree
    /// @param value The value of the node to delete
    /// @return The node with the given value
    template <typename T>
    typename RedBlackTree<T>::Node * RedBlackTree<T>::search(T value) {
        Node * x = this->root;
        while (x != this->nil && x->value != value) {
            if (value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        if (x->value != value) {
            return nullptr;
        }
        return x;
    }

    /// @brief Transplant one node for another
    /// @tparam T The type of the value stored in the tree
    /// @param u The node to transplant
    /// @param v The node to transplant with
    template <typename T>
    void RedBlackTree<T>::transplant(Node * u, Node * v) {
        if (u->parent == this->nil) {
            this->root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    /// @brief Get the minimum value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start searching from
    /// @return The node with the minimum value
    template <typename T>
    typename RedBlackTree<T>::Node * RedBlackTree<T>::getMinimum(Node * node) {
        while (node->left != this->nil) {
            node = node->left;
        }
        return node;
    }

    /// @brief Get the maximum value in the tree
    /// @tparam T The type of the value stored in the tree
    /// @param x The node to start searching from
    /// @return The node with the maximum value
    template <typename T>
    typename RedBlackTree<T>::Node * RedBlackTree<T>::getMaximum(Node * node) {
        while (node->right != this->nil) {
            node = node->right;
        }
        return node;
    }

    /// @brief Get the successor of a node
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to get the successor of
    /// @return The successor of the given node
    template <typename T>
    typename RedBlackTree<T>::Node * RedBlackTree<T>::successor(Node * node) {
        if (node->right != this->nil) {
            return this->getMinimum(node->right);
        }
        Node * y = node->parent;
        while (y != this->nil && node == y->right) {
            node = y;
            y = y->parent;
        }
        return y;
    }

    /// @brief Get the predecessor of a node
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to get the predecessor of
    /// @return The predecessor of the given node
    template <typename T>
    typename RedBlackTree<T>::Node * RedBlackTree<T>::predecessor(Node * node) {
        if (node->left != this->nil) {
            return this->getMaximum(node->left);
        }
        Node * y = node->parent;
        while (y != this->nil && node == y->left) {
            node = y;
            y = y->parent;
        }
        return y;
    }

    /// @brief Print the tree to the console
    /// @tparam T The type of the value stored in the tree
    template <typename T>
    void RedBlackTree<T>::print() {
        this->print(this->root);
        std::cout << std::endl;
    }

    /// @brief Print the tree to the console
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start printing from
    template <typename T>
    void RedBlackTree<T>::print(Node * node) {
        if (node != this->nil) {
            this->print(node->left);
            std::cout << node->value << " ";
            this->print(node->right);
        }
    }

    /// Traverse the tree in order and call the given function on each node
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start traversing from
    /// @param callback The function to call on each node
    template <typename T>
    void RedBlackTree<T>::traverseInOrder(Node * node, std::function<void(T)> callback) {
        if (node != this->nil) {
            this->traverseInOrder(node->left, callback);
            callback(node->value);
            this->traverseInOrder(node->right, callback);
        }
    }

    /// Traverses the tree in order and calls the given function on each node
    /// @tparam T The type of the value stored in the tree
    /// @param callback The function to call on each node
    template <typename T>
    void RedBlackTree<T>::traverseInOrder(std::function<void(T)> callback) {
        this->traverseInOrder(this->root, callback);
    }

    /// Traverse the tree in pre order and call the given function on each node
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start traversing from
    /// @param callback The function to call on each node
    template <typename T>
    void RedBlackTree<T>::traversePreOrder(Node * node, std::function<void(T)> callback) {
        if (node != this->nil) {
            callback(node->value);
            this->traversePreOrder(node->left, callback);
            this->traversePreOrder(node->right, callback);
        }
    }

    /// Traverses the tree in pre order and calls the given function on each node
    /// @tparam T The type of the value stored in the tree
    /// @param callback The function to call on each node
    template <typename T>
    void RedBlackTree<T>::traversePreOrder(std::function<void(T)> callback) {
        this->traversePreOrder(this->root, callback);
    }

    /// Traverse the tree in post order and call the given function on each node
    /// @tparam T The type of the value stored in the tree
    /// @param node The node to start traversing from
    /// @param callback The function to call on each node
    template <typename T>
    void RedBlackTree<T>::traversePostOrder(Node * node, std::function<void(T)> callback) {
        if (node != this->nil) {
            this->traversePostOrder(node->left, callback);
            this->traversePostOrder(node->right, callback);
            callback(node->value);
        }
    }

    /// Traverses the tree in post order and calls the given function on each node
    /// @tparam T The type of the value stored in the tree
    /// @param callback The function to call on each node
    template <typename T>
    void RedBlackTree<T>::traversePostOrder(std::function<void(T)> callback) {
        this->traversePostOrder(this->root, callback);
    }

    /// Clears the tree
    ///  @tparam T The type of the value stored in the tree
    template <typename T>
    void RedBlackTree<T>::clear() {
        this->clear(this->root);
        this->root = this->nil;
    }

    /// Clears the tree
    ///  @tparam T The type of the value stored in the tree
    ///  @param node The node to start clearing from
    template <typename T>
    void RedBlackTree<T>::clear(Node * node) {
        if (node != this->nil) {
            this->clear(node->left);
            this->clear(node->right);
            delete node;
        }
    }

    /// Gets the amount of nodes in the tree
    /// @tparam T The type of the value stored in the tree
    /// @return The amount of nodes in the tree
    template <typename T>
    std::size_t RedBlackTree<T>::getSize() {
        std::size_t size = 0;
        traverseInOrder([&size](T value) { size++; });
        return size;
    }

} // namespace Tobot::DataStructures::Tree