#pragma once

#include "../pre_compiled_header.h"

namespace Tobot::DataStructures::Tree {

    /// @brief Models the node of a tree data structure.
    /// @tparam T The type of the data stored in the node.
    template <typename T>
    class TreeNode {
        public:
            TreeNode(T data);
            TreeNode(T data, std::vector<TreeNode *> children);
            ~TreeNode();
            void addChild(TreeNode<T> * child);
            void addChildAt(TreeNode<T> * child, std::size_t index);
            T & getValue();
            T const & getValue() const;
            void setValue(T data);
            void removeChild(TreeNode<T> * child);
            void removeChildByIndex(std::size_t index);
            std::vector<TreeNode<T> *> & getChildren();
            std::vector<TreeNode<T> *> const & getChildren() const;

        private:
            T data;
            std::vector<TreeNode *> children;
    };

    template <typename T>
    TreeNode<T>::TreeNode(T data) {
        this->data = data;
    }

    template <typename T>
    TreeNode<T>::TreeNode(T data, std::vector<TreeNode *> children) {
        this->data = data;
        this->children = children;
    }

    template <typename T>
    TreeNode<T>::~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }

    template <typename T>
    void TreeNode<T>::addChild(TreeNode<T> * child) {
        this->children.push_back(child);
    }

    template <typename T>
    void TreeNode<T>::addChildAt(TreeNode<T> * child, std::size_t index) {
        if (index < children.size()) {
            children.insert(children.begin() + index, child);
        }
    }

    template <typename T>
    T & TreeNode<T>::getValue() {
        return this->data;
    }

    template <typename T>
    T const & TreeNode<T>::getValue() const {
        return this->data;
    }

    template <typename T>
    void TreeNode<T>::setValue(T data) {
        this->data = data;
    }

    template <typename T>
    void TreeNode<T>::removeChild(TreeNode<T> * child) {
        for (int i = 0; i < children.size(); i++) {
            if (children[i] == child) {
                children.erase(children.begin() + i);
                return;
            }
        }
    }

    template <typename T>
    void TreeNode<T>::removeChildByIndex(std::size_t index) {
        if (index < children.size()) {
            children.erase(children.begin() + index);
        }
    }

    template <typename T>
    [[nodiscard]] std::vector<TreeNode<T> *> & TreeNode<T>::getChildren() {
        return this->children;
    }

    template <typename T>
    [[nodiscard]] std::vector<TreeNode<T> *> const & TreeNode<T>::getChildren() const {
        return this->children;
    }

} // namespace Tobot::DataStructures::Tree