#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"
#include "rule/production_rule.h"
#include "rule/production_rule_sequence.h"
#include "rule/quantified_production_rule.h"
#include "tobot_data_structures.h"

using namespace Tobot::DataStructures::Tree;

namespace Tobot::Language {
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class Parser {
        public:
            Parser(Tree<ProductionRule<T1, T2> *> * grammer);
            ~Parser();
            Tree<std::pair<T1, T2>> parse(std::vector<Token<T1>> tokens);

        private:
            /// @brief The grammer used for parsing
            // We need to use a pointer here because the vector will try to copy the object otherwise
            // Should be solved in the future
            Tree<ProductionRule<T1, T2> *> * grammer;
            /// @brief The index of the first token in the expression
            std::size_t start;
            /// @brief The index of the last token in the expression
            std::size_t end;
            /// @brief The index of the current position of the parser
            std::size_t current;
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
    Tree<std::pair<T1, T2>> Parser<T1, T2>::parse(std::vector<Token<T1>> tokens) {
        start = current = 0;
        end = 0;
        Tree<std::pair<T1, T2>> * tree = new Tree<std::pair<T1, T2>>();
        // TODO: Implement parsing
        return *tree;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    void Parser<T1, T2>::reportError(std::string message, std::size_t current, std::vector<Token<T1>> tokens) {
        std::cout << "Error: " << message << " at " << tokens[current].getLine() << ":" << tokens[current].getColumn()
                  << std::endl;
    }

} // namespace Tobot::Language