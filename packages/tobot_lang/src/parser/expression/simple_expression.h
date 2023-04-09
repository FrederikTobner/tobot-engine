#include "pre_compiled_header.h"

#include "expression.h"

namespace Tobot::Language {

    /// @brief Models a expression that
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class SimpleExpression {

        public:
            SimpleExpression(T2 type, std::vector<T1> tokens);
            ~SimpleExpression();

        private:
            T2 type;
            std::vector<T1> tokens;
    };
} // namespace Tobot::Language