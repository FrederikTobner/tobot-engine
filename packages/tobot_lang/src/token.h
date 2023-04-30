#pragma once

#include "pre_compiled_header.h"

namespace Tobot::Language {
    template <typename T>
        requires std::is_enum_v<T>
    class Token {
        public:
            Token(T type, std::string lexeme, std::size_t line, std::size_t column);
            ~Token();
            auto getType() -> T const;
            auto getLexeme() -> std::string const;
            auto getLine() -> std::size_t const;
            auto getColumn() -> std::size_t const;

        private:
            T type;
            std::string lexeme;
            std::size_t line;
            std::size_t column;
    };

    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] Token<T>::Token(T type, std::string lexeme, std::size_t line, std::size_t column) {
        this->type = type;
        this->lexeme = lexeme;
        this->line = line;
        this->column = column;
    }

    template <typename T>
        requires std::is_enum_v<T>
    Token<T>::~Token() {
    }

    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] auto Token<T>::getType() -> T const {
        return this->type;
    }

    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] auto Token<T>::getLexeme() -> std::string const {
        return this->lexeme;
    }

    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] auto Token<T>::getLine() -> std::size_t const {
        return this->line;
    }

    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] auto Token<T>::getColumn() -> std::size_t const {
        return this->column;
    }
} // namespace Tobot::Language