#pragma once

#include "../pre_compiled_header.h"

#include "../regex_quantifier.h"
#include "../token.h"
#include "parsing_rule.h"

namespace Tobot::Language {
    /// @brief Simplest parsing rule that matches a sequence of tokens
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class TokenSequenceParsingRule : public Tobot::Language::ParsingRule<T1, T2> {
        public:
            TokenSequenceParsingRule(T2 type, std::vector<T1> tokens);
            ~TokenSequenceParsingRule();

            virtual bool apply(std::vector<Token<T1>> tokens, std::size_t & current);
            operator ParsingRule<T1, T2>() {
                return *this;
            }

        private:
            T2 type;
            std::vector<T1> tokens;
    };

    /// @brief Creates a new token sequence parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    TokenSequenceParsingRule<T1, T2>::TokenSequenceParsingRule(T2 type, std::vector<T1> tokens) {
        this->type = type;
        this->tokens = tokens;
    }

    /// @brief Destroys a token parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    TokenSequenceParsingRule<T1, T2>::~TokenSequenceParsingRule() {
    }

    /// @brief Applies the token parsing rule to a vector of tokens
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The vector of tokens to apply the rule to
    /// @param current The current index in the vector of tokens
    /// @return True if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    TokenSequenceParsingRule<T1, T2>::apply(std::vector<Token<T1>> tokens, std::size_t & current) {
        if (current >= tokens.size()) {
            return false;
        }

        for (std::size_t i = 0; i < this->tokens.size(); i++) {
            if (current + i >= tokens.size()) {
                return false;
            }

            if (tokens[current + i].getType() != this->tokens[i]) {
                return false;
            }
        }
        current += this->tokens.size();
        return true;
    }

} // namespace Tobot::Language