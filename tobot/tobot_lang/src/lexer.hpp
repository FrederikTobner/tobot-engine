#pragma once

#include "../pre_compiled_header.hpp"

#include "../token.hpp"
#include "tokenization_rule.hpp"

namespace Tobot::Language {
    template <typename T>
        requires std::is_enum_v<T>
    class Lexer {
        public:
            Lexer(std::vector<TokenizationRule<T>> rules);
            ~Lexer();
            auto tokenize(std::string source) -> std::vector<Token<T>>;

        private:
            /// @brief Rules for tokenizing
            std::vector<TokenizationRule<T>> rules;
            auto skipWhitespace(std::string source, std::size_t & start, std::size_t & line, std::size_t & column)
                -> void;
            auto reportError(std::string message, std::size_t & line, std::size_t & column) -> void;
            auto isAtEnd(std::string source, std::size_t start) -> bool;
    };

    /// @brief Creates a new lexer
    /// @tparam T The type of the tokens
    /// @param source Source code to tokenize
    /// @param rules Rules for tokenizing
    template <typename T>
        requires std::is_enum_v<T>
    Lexer<T>::Lexer(std::vector<TokenizationRule<T>> rules) {
        this->rules = rules;
    }

    /// @brief Destroys the lexer
    /// @tparam T The type of the tokens
    template <typename T>
        requires std::is_enum_v<T>
    Lexer<T>::~Lexer() {
    }

    /// @brief Tokenizes the source code
    /// @tparam T The type of the tokens
    /// @return A vector of tokens
    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] auto Lexer<T>::tokenize(std::string source) -> std::vector<Token<T>> {
        std::size_t line = 1;
        std::size_t column = 1;
        std::size_t start = 0;
        std::size_t end = 0;
        std::vector<Token<T>> tokens;
        std::string sourceStart = source;
        std::string lexeme;
        std::smatch match;
        while (!this->isAtEnd(source, start)) {
            // Skipping whitespaces between the tokens
            this->skipWhitespace(source, start, line, column);
            sourceStart = source.substr(start);
            for (TokenizationRule<T> rule : this->rules) {
                // Only match at the start of the string
                if (std::regex_search(sourceStart, match, rule.getPattern())) {
                    // The end of the current lexeme is the length of the match
                    end = start + match.length();
                    lexeme = source.substr(start, end - start);
                    // Adding the token
                    tokens.push_back(Token<T>(rule.getType(), lexeme, line, column));
                    // Setting the current start of the next lexeme to the end of the current lexeme
                    start = end;
                    // Increment column by the length of the match
                    column += match.length();
                    break;
                }
            }
            if (match.empty()) {
                this->reportError("Unexpected character '" + std::string(1, source[start]), line, column);
                break;
            }
        }
        return tokens;
    }

    /// @brief Skips whitespaces in the source code
    /// @tparam T The type of the token type enum
    template <typename T>
        requires std::is_enum_v<T>
    auto Lexer<T>::skipWhitespace(std::string source, std::size_t & start, std::size_t & line, std::size_t & column)
        -> void {
        while (!this->isAtEnd(source, start)) {
            if (source[start] == '\n' || source[start] == '\r') {
                // Increment line and reset column
                line++;
                column = 1;
            } else if (source[start] == '\t') {
                // Increment column by 4
                column += 4;
            } else if (source[start] == ' ') {
                // Increment column
                column++;
            } else {
                // If the character is not a whitespace, stop skipping
                break;
            }
            start++;
        }
    }

    /// @brief Reports an error to the console
    /// @tparam T The type of the token type enum
    /// @param message The error message
    template <typename T>
        requires std::is_enum_v<T>
    auto Lexer<T>::reportError(std::string message, std::size_t & line, std::size_t & column) -> void {
        std::cout << "Error: " << message << "at line " << line << ", column " << column << std::endl;
    }

    /// @brief Checks if the lexer is at the end of the source code
    /// @tparam T The type of the token type enum
    /// @return true if the lexer is at the end of the source code, false otherwise
    template <typename T>
        requires std::is_enum_v<T>
    [[nodiscard]] auto Lexer<T>::isAtEnd(std::string source, std::size_t start) -> bool {
        return start >= source.length();
    }
} // namespace Tobot::Language