#pragma once

#include "pre_compiled_header.h"

namespace Tobot::Language {
    template <typename T>
        requires std::is_enum_v<T>
    class Token {
        public:
            Token(T type, std::string lexeme, std::size_t line, std::size_t column);
            ~Token();
            T const getType();
            std::string const getLexeme();
            std::size_t const getLine();
            std::size_t const getColumn();

        private:
            T type;
            std::string lexeme;
            std::size_t line;
            std::size_t column;
    };

    template <typename T>
        requires std::is_enum_v<T>
    Token<T>::Token(T type, std::string lexeme, std::size_t line, std::size_t column) {
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
    T const Token<T>::getType() {
        return this->type;
    }

    template <typename T>
        requires std::is_enum_v<T>
    std::string const Token<T>::getLexeme() {
        return this->lexeme;
    }

    template <typename T>
        requires std::is_enum_v<T>
    std::size_t const Token<T>::getLine() {
        return this->line;
    }

    template <typename T>
        requires std::is_enum_v<T>
    std::size_t const Token<T>::getColumn() {
        return this->column;
    }
} // namespace Tobot::Language