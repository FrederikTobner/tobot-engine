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
            T const getType();
            std::regex const getPattern();

        private:
            T type;
            std::regex pattern;
    };

    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] TokenizationRule<T>::TokenizationRule(T type, std::string regex) {
        this->type = type;
        this->pattern = std::regex("^" + regex);
    }

    template <typename T>
        requires std::is_enum_v<T>
    TokenizationRule<T>::~TokenizationRule() {
    }

    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] T const TokenizationRule<T>::getType() {
        return this->type;
    }

    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] std::regex const TokenizationRule<T>::getPattern() {
        return this->pattern;
    }
} // namespace Tobot::Language