#pragma once

#include "../pre_compiled_header.hpp"

#include "../token.hpp"
#include "production_rule.hpp"

namespace Tobot::Language {
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class TerminalProductionRule : public Tobot::Language::ProductionRule<T1, T2> {
        public:
            TerminalProductionRule(T2 type, T1 tokenType);
            ~TerminalProductionRule();
            virtual auto apply(std::vector<Token<T1>> tokens, std::size_t & current) -> bool;
            virtual auto getType() -> T2;

        private:
            T2 type;
            T1 tokenType;
    };
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    TerminalProductionRule<T1, T2>::TerminalProductionRule(T2 type, T1 tokenType) {
        this->type = type;
        this->tokenType = tokenType;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    TerminalProductionRule<T1, T2>::~TerminalProductionRule() {
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto TerminalProductionRule<T1, T2>::apply(std::vector<Token<T1>> tokens, std::size_t & current)
        -> bool {
        if (tokens[current].getType() == this->tokenType) {
            current++;
            return true;
        }
        return false;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] auto TerminalProductionRule<T1, T2>::getType() -> T2 {
        return this->type;
    }

} // namespace Tobot::Language