#pragma once

#include "../../pre_compiled_header.h"

#include "parsing_context.h"

namespace Tobot::Language {

    /// @brief Models the parsing context corresponding to a terminal production rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class SimpleParsingContext : public ParsingContext<T1, T2> {

        public:
            SimpleParsingContext(T2 type, std::vector<T1> tokens);
            ~SimpleParsingContext();

        private:
            T2 type;
            std::vector<T1> tokens;
    };

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    SimpleParsingContext<T1, T2>::SimpleParsingContext(T2 type, std::vector<T1> tokens) : ParsingContext<T1, T2>(type) {
        this->type = type;
        this->tokens = tokens;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    SimpleParsingContext<T1, T2>::~SimpleParsingContext() {
    }
} // namespace Tobot::Language