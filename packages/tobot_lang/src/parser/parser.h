#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"
#include "expression_tree.h"
#include "rule/parsing_rule.h"
#include "rule/quantified_parsing_rule.h"
#include "rule/token_sequence_parsing_rule.h"

namespace Tobot::Language {
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class Parser {
        public:
            Parser(std::vector<ParsingRule<T1, T2> *> grammer);
            ~Parser();
            AnnnotatedSyntaxTree<T1, T2> parse(std::vector<Token<T1>> tokens);

        private:
            /// @brief The grammer used for parsing
            std::vector<ParsingRule<T1, T2> *> grammer;
            /// @brief The tokens to parse
            std::vector<Token<T1>> tokens;
            /// @brief The index of the first token in the expression
            std::size_t start;
            /// @brief The index of the last token in the expression
            std::size_t end;
            std::size_t current;
            void reportError(std::string message);
    };

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    Parser<T1, T2>::Parser(std::vector<ParsingRule<T1, T2> *> grammer) {
        this->grammer = grammer;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    Parser<T1, T2>::~Parser() {
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    AnnnotatedSyntaxTree<T1, T2> Parser<T1, T2>::parse(std::vector<Token<T1>> tokens) {
        start = current = 0;
        end = 0;
        AnnnotatedSyntaxTree<T1, T2> tree;
        while (current < tokens.size()) {
            start = current;
            for (auto rule : this->grammer) {
                if (rule->apply(tokens, current)) {

                    break;
                }
            }
            end = current;
            if (start == end) {
                reportError("No parsing rule matched the token at index " + std::to_string(start));
                break;
            }
        }
        return tree;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    void Parser<T1, T2>::reportError(std::string message) {
        std::cout << "Error: " << message << std::endl;
    }

} // namespace Tobot::Language