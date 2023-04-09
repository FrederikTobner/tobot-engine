#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"
#include "parsing_rule.h"
#include "regex_quantifier.h"

namespace Tobot::Language {
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class QuantifiedParsingRule : public Tobot::Language::ParsingRule<T1, T2> {
        public:
            QuantifiedParsingRule(std::pair<ParsingRule<T1, T2>, RegexQuantifier> rule, T2 type);
            ~QuantifiedParsingRule();
            virtual bool apply(std::vector<Token<T1>> tokens, std::size_t & current);
            operator ParsingRule<T1, T2>() {
                return *this;
            }

        private:
            std::vector<std::pair<ParsingRule<T1, T2>, RegexQuantifier>> rule;
            bool applySingle(std::vector<Token<T1>> tokens, std::size_t & current, ParsingRule<T1, T2> rule);
            bool applyZeroOrMore(std::vector<Token<T1>> tokens, std::size_t & current, ParsingRule<T1, T2> rule);
            bool applyOneOrMore(std::vector<Token<T1>> tokens, std::size_t & current, ParsingRule<T1, T2> rule);
            bool applyZeroOrOne(std::vector<Token<T1>> tokens, std::size_t & current, ParsingRule<T1, T2> rule);
            bool applyExactly(std::vector<Token<T1>> tokens, std::size_t & current, ParsingRule<T1, T2> rule,
                              std::size_t count);
            bool applyAtLeast(std::vector<Token<T1>> tokens, std::size_t & current, ParsingRule<T1, T2> rule,
                              std::size_t count);
            bool applyBetween(std::vector<Token<T1>> tokens, std::size_t & current, ParsingRule<T1, T2> rule,
                              std::size_t min, std::size_t max);
    };

    /// @brief Creates a new quantified parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param rule The rule to apply
    /// @param type The type of the expression
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    QuantifiedParsingRule<T1, T2>::QuantifiedParsingRule(std::pair<ParsingRule<T1, T2>, RegexQuantifier> rule,
                                                         T2 type) {
        this->rule = rule;
    }

    /// @brief Destroys a quantified parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    QuantifiedParsingRule<T1, T2>::~QuantifiedParsingRule() {
    }

    /// @brief Applies a quantified parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The current position in the linear sequence of tokens
    /// @param current The current token
    /// @return true if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::apply(std::vector<Token<T1>> tokens, std::size_t & current) {
        switch (rule.second) {
        case RegexQuantifier::NO_QUANTIFIER:
            return this->applySingle(tokens, current, rule.first);
        case RegexQuantifier::ZERO_OR_MORE:
            return this->applyZeroOrMore(tokens, current, rule.first);
        case RegexQuantifier::ONE_OR_MORE:
            return this->applyOneOrMore(tokens, current, rule.first);
        case RegexQuantifier::ZERO_OR_ONE:
            return this->applyZeroOrOne(tokens, current, rule.first);
        case RegexQuantifier::EXACTLY:
            return this->applyExactly(tokens, current, rule.first, rule.second.count);
        case RegexQuantifier::AT_LEAST:
            return this->applyAtLeast(tokens, current, rule.first, rule.second.count);
        case RegexQuantifier::BETWEEN:
            return this->applyBetween(tokens, current, rule.first, rule.second.min, rule.second.max);
        }
    }

    /// @brief Applies a quantified parsing rule exactly once
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The tokens to parse
    /// @param current The current position in the linear sequence of tokens
    /// @param rule The rule to apply
    /// @return true if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applySingle(std::vector<Token<T1>> tokens, std::size_t & current,
                                               ParsingRule<T1, T2> rule) {
        return rule.apply(tokens, current);
    }

    /// @brief Applies a quantified parsing rule zero or more times
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The tokens to parse
    /// @param current The current position in the linear sequence of tokens
    /// @param rule The rule to apply
    /// @return true if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyZeroOrMore(std::vector<Token<T1>> tokens, std::size_t & current,
                                                   ParsingRule<T1, T2> rule) {
        while (rule.apply(tokens, current)) {
            current++;
        }
        return true;
    }

    /// @brief Applies a quantified parsing rule one or more times
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The tokens to parse
    /// @param current The current position in the linear sequence of tokens
    /// @param rule The rule to apply
    /// @return true if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyOneOrMore(std::vector<Token<T1>> tokens, std::size_t & current,
                                                  ParsingRule<T1, T2> rule) {
        if (!rule.apply(tokens, current)) {
            return false;
        }
        current++;
        while (rule.apply(tokens, current)) {
            current++;
        }
        return true;
    }

    /// @brief Applies a quantified parsing rule zero or one times
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The tokens to parse
    /// @param current The current position in the linear sequence of tokens
    /// @param rule The rule to apply
    /// @return true if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyZeroOrOne(std::vector<Token<T1>> tokens, std::size_t & current,
                                                  ParsingRule<T1, T2> rule) {
        if (rule.apply(tokens, current)) {
            current++;
        }
        return true;
    }

    /// @brief Applies a quantified parsing rule between a minimum and maximum number of times
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The tokens to parse
    /// @param current The current position in the linear sequence of tokens
    /// @param rule The rule to apply
    /// @param count The number of times to apply the rule
    /// @return true if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyExactly(std::vector<Token<T1>> tokens, std::size_t & current,
                                                ParsingRule<T1, T2> rule, std::size_t count) {
        std::size_t currentCount = current;
        for (std::size_t i = 0; i < count; i++) {
            if (!rule.apply(tokens, current)) {
                return false;
            }
            current++;
        }
        return true;
    }

    /// @brief Applies a quantified parsing rule between a minimum and maximum number of times
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The tokens to parse
    /// @param current The current position in the linear sequence of tokens
    /// @param rule The rule to apply
    /// @param count The number of times to apply the rule
    /// @return true if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyAtLeast(std::vector<Token<T1>> tokens, std::size_t & current,
                                                ParsingRule<T1, T2> rule, std::size_t count) {
        std::size_t currentCount = current;
        for (std::size_t i = 0; i < count; i++) {
            if (!rule.apply(tokens, currentCount)) {
                return false;
            }
            currentCount++;
        }
        while (rule.apply(tokens, currentCount)) {
            currentCount++;
        }
        current = currentCount;
        return true;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyBetween(std::vector<Token<T1>> tokens, std::size_t & current,
                                                ParsingRule<T1, T2> rule, std::size_t min, std::size_t max) {
        std::size_t currentCount = current;
        for (std::size_t i = 0; i < min; i++) {
            if (!rule.apply(tokens, currentCount)) {
                return false;
            }
            currentCount++;
        }
        for (std::size_t i = min; i < max + 1; i++) {
            if (!rule.apply(tokens, currentCount)) {
                current = currentCount;
                return true;
            }
            currentCount++;
        }
        return false;
    }

} // namespace Tobot::Language
