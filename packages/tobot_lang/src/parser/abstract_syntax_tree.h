#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"
#include "context/parsing_context.h"

namespace Tobot::Language {
    /// @brief Models an abstract syntax tree
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class AbstractSyntaxTree {

        public:
            template <typename T1, typename T2>
                requires std::is_enum_v<T1> && std::is_enum_v<T2>
            class AbstractSyntaxTreeNode;
            AbstractSyntaxTree();
            ~AbstractSyntaxTree();

            /// @brief Models a expression that
            /// @tparam T1 The type of the token type enum
            /// @tparam T2 The type of the expression type enum
            template <typename T1, typename T2>
                requires std::is_enum_v<T1> && std::is_enum_v<T2>
            class AbstractSyntaxTreeNode {

                public:
                    AbstractSyntaxTreeNode(T2 type, ParsingContext<T1, T2> context) {
                        this->type = type;
                        this->context = context;
                    }
                    ~AbstractSyntaxTreeNode() {
                    }
                    bool isLeaf() {
                        return this->children.size() == 0;
                    }

                private:
                    T2 type;
                    // Should contain a single annotated context later
                    ParsingContext<T1, T2> context;
            };

        private:
            AbstractSyntaxTreeNode<T1, T2> * root;
    };

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    AbstractSyntaxTree<T1, T2>::AbstractSyntaxTree() {
        this->root = nullptr;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    AbstractSyntaxTree<T1, T2>::~AbstractSyntaxTree() {
    }

} // namespace Tobot::Language