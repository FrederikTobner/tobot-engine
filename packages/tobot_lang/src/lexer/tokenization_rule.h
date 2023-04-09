#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"

namespace Tobot::Language {
    template <typename T>
        requires std::is_enum_v<T>
    class TokenizationRule {
        public:
            TokenizationRule(T type, std::string regex);
            ~TokenizationRule();
            T getType();
            std::regex getPattern();

        private:
            std::pair<T, std::regex> rule;
    };

    template <typename T>
        requires std::is_enum_v<T>
    TokenizationRule<T>::TokenizationRule(T type, std::string regex) {
        // We add a ^ to the regex to ensure that the lexer only matches from the beginning of the string
        this->rule = std::make_pair(type, std::regex('^' + regex));
    }

    template <typename T>
        requires std::is_enum_v<T>
    TokenizationRule<T>::~TokenizationRule() {
    }

    template <typename T>
        requires std::is_enum_v<T>
    T TokenizationRule<T>::getType() {
        return this->rule.first;
    }

    template <typename T>
        requires std::is_enum_v<T>
    std::regex TokenizationRule<T>::getPattern() {
        return this->rule.second;
    }
} // namespace Tobot::Language