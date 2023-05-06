#pragma once

#include "../pre_compiled_header.hpp"

#include "../token.hpp"

namespace Tobot::Language {
    /// @brief Models a parsing rule for a parser
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class ProductionRule {
        public:
            ProductionRule();
            virtual ~ProductionRule();
            virtual auto apply(std::vector<Token<T1>> tokens, std::size_t & current) -> bool = 0;
            virtual auto getType() -> T2 = 0;
    };

    /// @brief Creates a new parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    [[nodiscard]] ProductionRule<T1, T2>::ProductionRule() {
    }

    /// @brief Destroys a parsing rule
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    ProductionRule<T1, T2>::~ProductionRule() {
    }

} // namespace Tobot::Language