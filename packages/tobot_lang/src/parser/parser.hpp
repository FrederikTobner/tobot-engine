#pragma once

#include "../pre_compiled_header.hpp"

#include "../token.hpp"
#include "rule/production_rule.hpp"
#include "rule/production_rule_sequence.hpp"
#include "rule/quantified_production_rule.hpp"

#include "tobot_data_structures.hpp"

using namespace Tobot::DataStructures::Tree;

namespace Tobot::Language {
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class Parser {
        public:
            Parser(Tree<ProductionRule<T1, T2> *> * grammer);
            ~Parser();
            auto parse(std::vector<Token<T1>> tokens) -> Tree<std::pair<T1, T2>>;

        private:
            /// @brief The grammer used for parsing
            // We need to use a pointer here because the vector will try to copy the object otherwise
            // Should be solved in the future
            Tree<ProductionRule<T1, T2> *> * grammer;
            void reportError(std::string message, std::size_t current, std::vector<Token<T1>> tokens);
    };

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    Parser<T1, T2>::Parser(Tree<ProductionRule<T1, T2> *> * grammer) {
        this->grammer = grammer;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    Parser<T1, T2>::~Parser() {
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto Parser<T1, T2>::parse(std::vector<Token<T1>> tokens) -> Tree<std::pair<T1, T2>> {
        std::size_t start, current, end;
        start = current = end = 0;
        Tree<std::pair<T1, T2>> * tree = nullptr;
        // The tree should be made up by parsing contexts not by the type of the token and the type of the expression
        if (this->grammer->getRoot()->getValue()->apply(tokens, current)) {
            tree = new Tree(new TreeNode<std::pair<T1, T2>>(
                std::make_pair(tokens[start].getType(), this->grammer->getRoot()->getValue()->getType())));
        } else {
            reportError("Could not parse token sequence", current, tokens);
        }
        return *tree;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    auto Parser<T1, T2>::reportError(std::string message, std::size_t current, std::vector<Token<T1>> tokens) -> void {
        std::cout << "Error: " << message << " at " << tokens[current].getLine() << ":" << tokens[current].getColumn()
                  << "\n";
    }

} // namespace Tobot::Language