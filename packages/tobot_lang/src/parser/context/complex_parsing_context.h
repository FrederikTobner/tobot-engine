#pragma once

#include "../../pre_compiled_header.h"

#include "parsing_context.h"

namespace Tobot::Language {

    /// @brief Models the parsing context corresponding to a non-terminal production rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class ComplexParsingContext : public ParsingContext<T1, T2> {

        public:
            ComplexParsingContext(T2 type, std::vector<T1> contexts);
            ~ComplexParsingContext();

        private:
            T2 type;
            std::vector<ParsingContext<T1, T2>> contexts;
    };

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] ComplexParsingContext<T1, T2>::ComplexParsingContext(T2 type, std::vector<T1> contexts)
        : ParsingContext<T1, T2>(type) {
        this->type = type;
        this->contexts = contexts;
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    ComplexParsingContext<T1, T2>::~ComplexParsingContext() {
    }
} // namespace Tobot::Language