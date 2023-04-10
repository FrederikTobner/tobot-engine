#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"
#include "parsing_rule.h"

namespace Tobot::Language {
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class TerminalParsingRule : public Tobot::Language::ParsingRule<T1, T2> {
        public:
            TerminalParsingRule(T2 type, T1 tokenType);
            ~TerminalParsingRule();
            virtual bool apply(std::vector<Token<T1>> tokens, std::size_t & current);

        private:
            T2 type;
            T1 tokenType;
    };
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    TerminalParsingRule<T1, T2>::TerminalParsingRule(T2 type, T1 tokenType) {
        this->type = type;
        this->tokenType = tokenType;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    TerminalParsingRule<T1, T2>::~TerminalParsingRule() {
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2> bool
    TerminalParsingRule<T1, T2>::apply(std::vector<Token<T1>> tokens, std::size_t & current) {
        if (tokens[current].getType() == this->tokenType) {
            current++;
            return true;
        }
        return false;
    }
} // namespace Tobot::Language