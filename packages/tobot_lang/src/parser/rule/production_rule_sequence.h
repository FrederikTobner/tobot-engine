#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"
#include "production_rule.h"

namespace Tobot::Language {
    /// @brief Simplest parsing rule that matches a sequence of tokens
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class ProductionRuleSequence : public Tobot::Language::ProductionRule<T1, T2> {
        public:
            ProductionRuleSequence(T2 type, std::vector<ProductionRule<T1, T2> *> rules);
            ~ProductionRuleSequence();

            virtual bool apply(std::vector<Token<T1>> tokens, std::size_t & current);

        private:
            T2 type;
            std::vector<ProductionRule<T1, T2> *> rules;
    };

    /// @brief Creates a new token sequence parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    ProductionRuleSequence<T1, T2>::ProductionRuleSequence(T2 type, std::vector<ProductionRule<T1, T2> *> rules) {
        this->type = type;
        this->rules = rules;
    }

    /// @brief Destroys a token parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    ProductionRuleSequence<T1, T2>::~ProductionRuleSequence() {
    }

    /// @brief Applies the token parsing rule to a vector of tokens
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The vector of tokens to apply the rule to
    /// @param current The current index in the vector of tokens
    /// @return True if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    ProductionRuleSequence<T1, T2>::apply(std::vector<Token<T1>> tokens, std::size_t & current) {
        std::size_t start = current;
        for (auto rule : this->rules) {
            if (!rule->apply(tokens, current)) {
                // Backtracking if the rule failed
                current = start;
                return false;
            }
        }
        return true;
    }

} // namespace Tobot::Language