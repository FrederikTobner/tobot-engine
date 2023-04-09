
namespace Tobot::Language {

    /// @brief Models a expression that
    /// @tparam T1 The type of the token type enum
    /// @tparam T2 The type of the expression type enum
    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    class Expression {

        public:
            Expression(T2 type);
            virtual ~Expression() = 0;

        private:
            T2 type;
    };

    template <typename T1, typename T2>
        requires std::is_enum_v<T1> && std::is_enum_v<T2>
    Expression<T1, T2>::Expression(T2 type) {
        this->type = type;
    }
} // namespace Tobot::Language