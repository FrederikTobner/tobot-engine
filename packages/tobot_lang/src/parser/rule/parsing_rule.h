#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"

namespace Tobot::Language {
    /// @brief Models a parsing rule for a parser
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class ParsingRule {
        public:
            ParsingRule();
            virtual ~ParsingRule();
            virtual bool apply(std::vector<Token<T1>> tokens, std::size_t & current) = 0;
    };

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    ParsingRule<T1, T2>::ParsingRule() {
    }

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    ParsingRule<T1, T2>::~ParsingRule() {
    }

} // namespace Tobot::Language