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
            QuantifiedParsingRule(std::vector<std::pair<ParsingRule<T1, T2>, RegexQuantifier>> rule, T2 type);
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

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    QuantifiedParsingRule<T1, T2>::QuantifiedParsingRule(
        std::vector<std::pair<ParsingRule<T1, T2>, RegexQuantifier>> rule, T2 type) {
        this->rule = rule;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    QuantifiedParsingRule<T1, T2>::~QuantifiedParsingRule() {
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::apply(std::vector<Token<T1>> tokens, std::size_t & current) {
        for (auto rule : this->rule) {
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
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applySingle(std::vector<Token<T1>> tokens, std::size_t & current,
                                               ParsingRule<T1, T2> rule) {
        return rule.apply(tokens, current);
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyZeroOrMore(std::vector<Token<T1>> tokens, std::size_t & current,
                                                   ParsingRule<T1, T2> rule) {
        while (rule.apply(tokens, current)) {
            current++;
        }
        return true;
    }

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

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyZeroOrOne(std::vector<Token<T1>> tokens, std::size_t & current,
                                                  ParsingRule<T1, T2> rule) {
        if (rule.apply(tokens, current)) {
            current++;
        }
        return true;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyExactly(std::vector<Token<T1>> tokens, std::size_t & current,
                                                ParsingRule<T1, T2> rule, std::size_t count) {
        for (std::size_t i = 0; i < count; i++) {
            if (!rule.apply(tokens, current)) {
                return false;
            }
            current++;
        }
        return true;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyAtLeast(std::vector<Token<T1>> tokens, std::size_t & current,
                                                ParsingRule<T1, T2> rule, std::size_t count) {
        for (std::size_t i = 0; i < count; i++) {
            if (!rule.apply(tokens, current)) {
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
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    QuantifiedParsingRule<T1, T2>::applyBetween(std::vector<Token<T1>> tokens, std::size_t & current,
                                                ParsingRule<T1, T2> rule, std::size_t min, std::size_t max) {
        for (std::size_t i = 0; i < min; i++) {
            if (!rule.apply(tokens, current)) {
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
        return false;
    }

} // namespace Tobot::Language
