#pragma once

#include "../pre_compiled_header.hpp"

#include <queue>

#include "tree_node.hpp"

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
            auto getSize() const -> std::size_t;
            auto getDepth() const -> std::size_t;
            auto getRoot() -> TreeNode<T> *;
            auto visitParentsFirst(std::function<void(TreeNode<T> *)> callback) -> void;
            auto visitChildrenFirst(std::function<void(TreeNode<T> *)> callback) -> void;
            auto insertAt(TreeNode<T> * node, std::size_t depth, std::size_t width) -> void;
            auto insertAt(TreeNode<T> * node, std::size_t depth, std::size_t width, std::size_t index) -> void;
            auto getNodesAtDepth(std::size_t depth) -> std::vector<TreeNode<T> *>;

        private:
            // The root node of the tree
            TreeNode<T> * root;
            auto getSize(TreeNode<T> * node) const -> std::size_t;
            auto getDepth(TreeNode<T> * node) const -> std::size_t;
            auto visitParentsFirst(TreeNode<T> * node, std::function<void(TreeNode<T> *)> callback) -> void;
            auto visitChildrenFirst(TreeNode<T> * node, std::function<void(TreeNode<T> *)> callback) -> void;
            auto getNodesAtDepth(TreeNode<T> * node, std::size_t depth, std::vector<TreeNode<T> *> & nodes) -> void;
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
    [[nodiscard]] auto Tree<T>::getSize() const -> std::size_t {
        return getSize(this->root);
    }

    /// @brief Get the depth of the tree
    /// @tparam T The type of the data stored in the tree
    /// @return std::size_t The depth of the tree
    template <typename T>
    [[nodiscard]] auto Tree<T>::getDepth() const -> std::size_t {
        return getDepth(this->root);
    }

    /// @brief Visit the tree in a parents first order
    /// @tparam T The type of the data stored in the tree
    /// @param node The node to visit
    /// @return std::size_t The depth of the tree
    template <typename T>
    [[nodiscard]] auto Tree<T>::getSize(TreeNode<T> * node) const -> std::size_t {
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
    [[nodiscard]] auto Tree<T>::getDepth(TreeNode<T> * node) const -> std::size_t {
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
    [[nodiscard]] auto Tree<T>::getRoot() -> TreeNode<T> * {
        return this->root;
    }

    /// @brief Visit the tree in a parents first order
    /// @tparam T The type of the data stored in the tree
    /// @param callback The callback function to call on each node
    template <typename T>
    auto Tree<T>::visitParentsFirst(std::function<void(TreeNode<T> *)> callback) -> void {
        if (this->root) {
            this->visitParentsFirst(this->root, callback);
        }
    }

    /// @brief Visit the tree in a children first order
    /// @tparam T The type of the data stored in the tree
    /// @param callback The callback function to call on each node
    template <typename T>
    auto Tree<T>::visitChildrenFirst(std::function<void(TreeNode<T> *)> callback) -> void {
        if (this->root) {
            this->visitChildrenFirst(this->root, callback);
        }
    }

    /// @brief Visit the tree in a parents first order
    /// @tparam T The type of the data stored in the tree
    /// @param node The node to visit
    /// @param callback The callback function to call on each node
    template <typename T>
    auto Tree<T>::visitParentsFirst(TreeNode<T> * node, std::function<void(TreeNode<T> *)> callback) -> void {
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
    auto Tree<T>::visitChildrenFirst(TreeNode<T> * node, std::function<void(TreeNode<T> *)> callback) -> void {
        if (node) {
            for (std::size_t i = 0; i < node->children.size(); i++) {
                visitChildrenFirst(node->children[i], callback);
            }
            callback(node);
        }
    }

    template <typename T>
    auto Tree<T>::getNodesAtDepth(std::size_t depth) -> std::vector<TreeNode<T> *> {
        std::vector<TreeNode<T> *> nodes;
        if (this->root) {
            this->getNodesAtDepth(this->root, depth, nodes);
        }
        return nodes;
    }

    template <typename T>
    auto Tree<T>::getNodesAtDepth(TreeNode<T> * node, std::size_t depth, std::vector<TreeNode<T> *> & nodes) -> void {
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
    auto Tree<T>::insertAt(TreeNode<T> * node, std::size_t depth, std::size_t width) -> void {
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
    auto Tree<T>::insertAt(TreeNode<T> * node, std::size_t depth, std::size_t width, std::size_t index) -> void {
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