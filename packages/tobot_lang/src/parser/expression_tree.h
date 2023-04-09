#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"

namespace Tobot::Language {
    /// @brief Models a expression that
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class AnnnotatedSyntaxTree {

        public:
            template <typename T1, typename T2>
                requires std::is_enum_v<T1> && std::is_enum_v<T2>
            class AnnnotatedSyntaxTreeNode;
            AnnnotatedSyntaxTree();
            AnnnotatedSyntaxTree(AnnnotatedSyntaxTreeNode<T1, T2> root);
            ~AnnnotatedSyntaxTree();

            /// @brief Models a expression that
            /// @tparam T1 The type of the token type enum
            /// @tparam T2 The type of the expression type enum
            template <typename T1, typename T2>
                requires std::is_enum_v<T1> && std::is_enum_v<T2>
            class AnnnotatedSyntaxTreeNode {

                public:
                    AnnnotatedSyntaxTreeNode(T2 type, std::vector<Token<T1>> tokens) {
                        this->type = type;
                        this->tokens = tokens;
                    }
                    AnnnotatedSyntaxTreeNode(T2 type, std::vector<AnnnotatedSyntaxTreeNode<T1, T2>> children)
                        : AnnnotatedSyntaxTreeNode(type, std::vector<Token<T1>>()) {
                        this->children = children;
                    }
                    ~AnnnotatedSyntaxTreeNode() {
                    }
                    bool isLeaf() {
                        return this->children.size() == 0;
                    }
                    void addChild(AnnnotatedSyntaxTreeNode<T1, T2> child) {
                        this->children.push_back(child);
                    }
                    void addToken(Token<T1> token) {
                        this->tokens.push_back(token);
                    }

                private:
                    T2 type;
                    std::vector<Token<T1>> tokens;
            };

        private:
            AnnnotatedSyntaxTreeNode<T1, T2> root;
    };

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    AnnnotatedSyntaxTree<T1, T2>::AnnnotatedSyntaxTree() {
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    AnnnotatedSyntaxTree<T1, T2>::AnnnotatedSyntaxTree(AnnnotatedSyntaxTreeNode<T1, T2> root) {
        this->root = root;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    AnnnotatedSyntaxTree<T1, T2>::~AnnnotatedSyntaxTree() {
    }

} // namespace Tobot::Language