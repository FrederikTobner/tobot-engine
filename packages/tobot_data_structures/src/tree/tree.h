#pragma once

#include "../pre_compiled_header.h"

#include <queue>

#include "tree_node.h"

namespace Tobot::DataStructures::Tree {

    /// @brief A simple unsorted tree with non-unique values
    /// @tparam T The type of the data stored in the tree
    template <typename T>
    class Tree {
        public:
            Tree();
            Tree(T data);
            Tree(TreeNode<T> * root);
            ~Tree();
            std::size_t getSize() const;
            std::size_t getDepth() const;
            TreeNode<T> * getRoot();
            void visitParentsFirst(std::function<void(TreeNode<T> *)> callback);
            void visitChildrenFirst(std::function<void(TreeNode<T> *)> callback);
            void insertAt(TreeNode<T> * node, std::size_t depth, std::size_t width);
            void insertAt(TreeNode<T> * node, std::size_t depth, std::size_t width, std::size_t index);
            std::vector<TreeNode<T> *> getNodesAtDepth(std::size_t depth);

        private:
            // The root node of the tree
            TreeNode<T> * root;
            std::size_t getSize(TreeNode<T> * node) const;
            std::size_t getDepth(TreeNode<T> * node) const;
            void visitParentsFirst(TreeNode<T> * node, std::function<void(TreeNode<T> *)> callback);
            void visitChildrenFirst(TreeNode<T> * node, std::function<void(TreeNode<T> *)> callback);
            void getNodesAtDepth(TreeNode<T> * node, std::size_t depth, std::vector<TreeNode<T> *> & nodes);
    };

    /// @brief Construct a new Tree object
    /// @tparam T The type of the data stored in the tree
    template <typename T>
    Tree<T>::Tree() {
        this->root = nullptr;
    }

    /// @brief Construct a new Tree object with a root node
    /// @tparam T The type of the data stored in the tree
    /// @param data The data to store in the root node
    template <typename T>
    Tree<T>::Tree(T data) {
        this->root = new TreeNode<T>(data);
    }

    /// @brief Construct a new Tree object with a root node
    /// @tparam T The type of the data stored in the tree
    /// @param root The root node of the tree
    template <typename T>
    Tree<T>::Tree(TreeNode<T> * root) {
        this->root = root;
    }

    /// @brief Destroy the Tree object
    /// @tparam T The type of the data stored in the tree
    template <typename T>
    Tree<T>::~Tree() {
        if (root) {
            delete root;
            root = nullptr;
        }
    }

    /// @brief Get the size of the tree
    /// @tparam T The type of the data stored in the tree
    /// @return std::size_t The size of the tree
    template <typename T>
    std::size_t Tree<T>::getSize() const {
        return getSize(this->root);
    }

    /// @brief Get the depth of the tree
    /// @tparam T The type of the data stored in the tree
    /// @return std::size_t The depth of the tree
    template <typename T>
    std::size_t Tree<T>::getDepth() const {
        return getDepth(this->root);
    }

    /// @brief Visit the tree in a parents first order
    /// @tparam T The type of the data stored in the tree
    /// @param node The node to visit
    /// @return std::size_t The depth of the tree
    template <typename T>
    std::size_t Tree<T>::getSize(TreeNode<T> * node) const {
        if (!node) {
            return 0;
        } else {
            std::size_t count = 1;
            for (std::size_t i = 0; i < node->children.size(); i++) {
                count += getSize(node->children[i]);
            }
            return count;
        }
    }

    /// @brief Get the depth of the tree
    /// @tparam T The type of the data stored in the tree
    /// @param node The node to get the depth of
    /// @return std::size_t The depth of the tree
    template <typename T>
    std::size_t Tree<T>::getDepth(TreeNode<T> * node) const {
        if (!node) {
            return 0;
        } else {
            std::size_t maxDepth = 0;
            for (std::size_t i = 0; i < node->children.size(); i++) {
                std::size_t childDepth = getDepth(node->children[i]);
                if (childDepth > maxDepth) {
                    maxDepth = childDepth;
                }
            }
            return maxDepth + 1;
        };
    }

    /// @brief Get the root node of the tree
    /// @tparam T The type of the data stored in the tree
    /// @return TreeNode<T> * The root node of the tree
    template <typename T>
    TreeNode<T> * Tree<T>::getRoot() {
        return this->root;
    }

    /// @brief Visit the tree in a parents first order
    /// @tparam T The type of the data stored in the tree
    /// @param callback The callback function to call on each node
    template <typename T>
    void Tree<T>::visitParentsFirst(std::function<void(TreeNode<T> *)> callback) {
        if (this->root) {
            this->visitParentsFirst(this->root, callback);
        }
    }

    /// @brief Visit the tree in a children first order
    /// @tparam T The type of the data stored in the tree
    /// @param callback The callback function to call on each node
    template <typename T>
    void Tree<T>::visitChildrenFirst(std::function<void(TreeNode<T> *)> callback) {
        if (this->root) {
            this->visitChildrenFirst(this->root, callback);
        }
    }

    /// @brief Visit the tree in a parents first order
    /// @tparam T The type of the data stored in the tree
    /// @param node The node to visit
    /// @param callback The callback function to call on each node
    template <typename T>
    void Tree<T>::visitParentsFirst(TreeNode<T> * node, std::function<void(TreeNode<T> *)> callback) {
        if (node) {
            callback(node);
            for (std::size_t i = 0; i < node->getChildren().size(); i++) {
                visitParentsFirst(node->getChildren()[i], callback);
            }
        }
    }

    /// @brief Visit the tree in a children first order
    /// @tparam T The type of the data stored in the tree
    /// @param node The node to visit
    /// @param callback The callback function to call on each node
    template <typename T>
    void Tree<T>::visitChildrenFirst(TreeNode<T> * node, std::function<void(TreeNode<T> *)> callback) {
        if (node) {
            for (std::size_t i = 0; i < node->children.size(); i++) {
                visitChildrenFirst(node->children[i], callback);
            }
            callback(node);
        }
    }

    template <typename T>
    std::vector<TreeNode<T> *> Tree<T>::getNodesAtDepth(std::size_t depth) {
        std::vector<TreeNode<T> *> nodes;
        if (this->root) {
            this->getNodesAtDepth(this->root, depth, nodes);
        }
        return nodes;
    }

    template <typename T>
    void Tree<T>::getNodesAtDepth(TreeNode<T> * node, std::size_t depth, std::vector<TreeNode<T> *> & nodes) {
        if (depth == 0) {
            nodes.push_back(node);
        } else {
            for (std::size_t i = 0; i < node->getChildren().size(); i++) {
                getNodesAtDepth(node->getChildren()[i], depth - 1, nodes);
            }
        }
    }

    /// @brief Insert a node at a specific depth and width
    /// @tparam T The type of the data stored in the tree
    /// @param node The node to insert
    /// @param depth The depth to insert the node at
    /// @param width The width to insert the node at
    template <typename T>
    void Tree<T>::insertAt(TreeNode<T> * node, std::size_t depth, std::size_t width) {
        if (depth == 0) {
            if (width == 0) {
                this->root.insertChild(node);
            }
        } else {
            std::vector<TreeNode<T> *> nodes = this->getNodesAtDepth(depth - 1);
            if (nodes.size() > width) {
                nodes[width]->insertChild(node);
            }
        }
    }

    /// @brief Insert a node at a specific depth and width
    /// @tparam T The type of the data stored in the tree
    /// @param node The node to insert
    /// @param depth The depth to insert the node at
    /// @param width The width to insert the node at
    template <typename T>
    void Tree<T>::insertAt(TreeNode<T> * node, std::size_t depth, std::size_t width, std::size_t index) {
        if (depth == 0) {
            if (width == 0) {
                this->root.insertChildAt(node, index);
            }
        } else {
            std::vector<TreeNode<T> *> nodes = this->getNodesAtDepth(depth - 1);
            if (nodes.size() > width) {
                nodes[width]->insertChildAt(node, index);
            }
        }
    }

} // namespace Tobot::DataStructures::Tree