#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"
#include "production_rule.h"

namespace Tobot::Language {

    typedef enum {
        ZERO_OR_MORE, // *
        ONE_OR_MORE,  // +
        ZERO_OR_ONE,  // ?
        EXACTLY,      // {n}
        AT_LEAST,     // {n, }
        BETWEEN       // {n, m}
    } RegexQuantifier;

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class QuantifiedProductionRule : public Tobot::Language::ProductionRule<T1, T2> {
        public:
            QuantifiedProductionRule(std::pair<ProductionRule<T1, T2>, RegexQuantifier> rule, T2 type);
            ~QuantifiedProductionRule();
            virtual auto apply(std::vector<Token<T1>> tokens, std::size_t & current) -> bool;
            virtual auto getType() -> T2;

        private:
            std::vector<std::pair<ProductionRule<T1, T2>, RegexQuantifier>> rule;
            auto applyZeroOrMore(std::vector<Token<T1>> tokens, std::size_t & current, ProductionRule<T1, T2> rule)
                -> bool;
            auto applyOneOrMore(std::vector<Token<T1>> tokens, std::size_t & current, ProductionRule<T1, T2> rule)
                -> bool;
            auto applyZeroOrOne(std::vector<Token<T1>> tokens, std::size_t & current, ProductionRule<T1, T2> rule)
                -> bool;
            auto applyExactly(std::vector<Token<T1>> tokens, std::size_t & current, ProductionRule<T1, T2> rule,
                              std::size_t count) -> bool;
            auto applyAtLeast(std::vector<Token<T1>> tokens, std::size_t & current, ProductionRule<T1, T2> rule,
                              std::size_t count) -> bool;
            auto applyBetween(std::vector<Token<T1>> tokens, std::size_t & current, ProductionRule<T1, T2> rule,
                              std::size_t min, std::size_t max) -> bool;
            T2 type;
    };

    /// @brief Creates a new quantified parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param rule The rule to apply
    /// @param type The type of the expression
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] QuantifiedProductionRule<T1, T2>::QuantifiedProductionRule(
        std::pair<ProductionRule<T1, T2>, RegexQuantifier> rule, T2 type) {
        this->rule = rule;
    }

    /// @brief Destroys a quantified parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    QuantifiedProductionRule<T1, T2>::~QuantifiedProductionRule() {
    }

    /// @brief Applies a quantified parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The current position in the linear sequence of tokens
    /// @param current The current token
    /// @return true if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto QuantifiedProductionRule<T1, T2>::apply(std::vector<Token<T1>> tokens, std::size_t & current)
        -> bool {
        switch (rule.second) {
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

    /// @brief Applies a quantified parsing rule zero or more times
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    /// @param tokens The tokens to parse
    /// @param current The current position in the linear sequence of tokens
    /// @param rule The rule to apply
    /// @return true if the rule was applied successfully, false otherwise
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto QuantifiedProductionRule<T1, T2>::applyZeroOrMore(std::vector<Token<T1>> tokens,
                                                                         std::size_t & current,
                                                                         ProductionRule<T1, T2> rule) -> bool {
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
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto QuantifiedProductionRule<T1, T2>::applyOneOrMore(std::vector<Token<T1>> tokens,
                                                                        std::size_t & current,
                                                                        ProductionRule<T1, T2> rule) -> bool {
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
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto QuantifiedProductionRule<T1, T2>::applyZeroOrOne(std::vector<Token<T1>> tokens,
                                                                        std::size_t & current,
                                                                        ProductionRule<T1, T2> rule) -> bool {
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
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto QuantifiedProductionRule<T1, T2>::applyExactly(std::vector<Token<T1>> tokens,
                                                                      std::size_t & current,
                                                                      ProductionRule<T1, T2> rule, std::size_t count)
        -> bool {
        std::size_t start = current;
        for (std::size_t i = 0; i < count; i++) {
            if (!rule.apply(tokens, current)) {
                if (i == 0) {
                    current = start;
                }
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
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto QuantifiedProductionRule<T1, T2>::applyAtLeast(std::vector<Token<T1>> tokens,
                                                                      std::size_t & current,
                                                                      ProductionRule<T1, T2> rule, std::size_t count)
        -> bool {
        std::size_t start = current;
        for (std::size_t i = 0; i < count; i++) {
            if (!rule.apply(tokens, current)) {
                if (i != 0) {
                    // Backtracking is required
                    current = start;
                }
                return false;
            }
            current++;
        }

        while (rule.apply(tokens, current)) {
            current++;
        }
        return true;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto QuantifiedProductionRule<T1, T2>::applyBetween(std::vector<Token<T1>> tokens,
                                                                      std::size_t & current,
                                                                      ProductionRule<T1, T2> rule, std::size_t min,
                                                                      std::size_t max) -> bool {
        std::size_t start = current;
        for (std::size_t i = 0; i < min; i++) {
            if (!rule.apply(tokens, current)) {
                if (i != 0) {
                    current = start;
                }
                return false;
            }
            current++;
        }
        for (std::size_t i = min; i < max + 1; i++) {
            if (!rule.apply(tokens, current)) {
                return true;
            }
            current++;
        }
        current = start;
        return false;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto QuantifiedProductionRule<T1, T2>::getType() -> T2 {
        return type;
    }

} // namespace Tobot::Language
