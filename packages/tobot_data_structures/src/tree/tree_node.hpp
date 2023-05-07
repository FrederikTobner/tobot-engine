#pragma once

#include "../pre_compiled_header.hpp"

namespace Tobot::DataStructures::Tree {

    /// @brief Models the node of a tree data structure.
    /// @tparam T The type of the data stored in the node.
    template <typename T>
    class TreeNode {
        public:
            TreeNode(T data);
            TreeNode(T data, std::vector<TreeNode *> children);
            ~TreeNode();
            auto addChild(TreeNode<T> * child) -> void;
            auto addChildAt(TreeNode<T> * child, std::size_t index) -> void;
            auto getValue() -> T &;
            auto getValue() const -> T const &;
            auto setValue(T data) -> void;
            auto removeChild(TreeNode<T> * child) -> void;
            auto removeChildByIndex(std::size_t index) -> void;
            auto getChildren() -> std::vector<TreeNode<T> *> &;
            auto getChildren() const -> std::vector<TreeNode<T> *> const &;

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
    auto TreeNode<T>::addChild(TreeNode<T> * child) -> void {
        this->children.push_back(child);
    }

    template <typename T>
    auto TreeNode<T>::addChildAt(TreeNode<T> * child, std::size_t index) -> void {
        if (index < children.size()) {
            children.insert(children.begin() + index, child);
        }
    }

    template <typename T>
    auto TreeNode<T>::getValue() -> T & {
        return this->data;
    }

    template <typename T>
    auto TreeNode<T>::getValue() const -> T const & {
        return this->data;
    }

    template <typename T>
    auto TreeNode<T>::setValue(T data) -> void {
        this->data = data;
    }

    template <typename T>
    auto TreeNode<T>::removeChild(TreeNode<T> * child) -> void {
        for (int i = 0; i < children.size(); i++) {
            if (children[i] == child) {
                children.erase(children.begin() + i);
                return;
            }
        }
    }

    template <typename T>
    auto TreeNode<T>::removeChildByIndex(std::size_t index) -> void {
        if (index < children.size()) {
            children.erase(children.begin() + index);
        }
    }

    template <typename T>
    [[nodiscard]] auto TreeNode<T>::getChildren() -> std::vector<TreeNode<T> *> & {
        return this->children;
    }

    template <typename T>
    [[nodiscard]] auto TreeNode<T>::getChildren() const -> std::vector<TreeNode<T> *> const & {
        return this->children;
    }

} // namespace Tobot::DataStructures::Tree