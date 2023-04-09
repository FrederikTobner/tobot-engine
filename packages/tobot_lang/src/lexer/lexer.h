#pragma once

#include "../pre_compiled_header.h"

#include "../token.h"
#include "tokenization_rule.h"

namespace Tobot::Language {
    template <typename T>
        requires std::is_enum_v<T>
    class Lexer {
        public:
            Lexer(std::string source, std::vector<TokenizationRule<T>> rules);
            ~Lexer();
            std::vector<Token<T>> tokenize();

        private:
            /// @brief Source code to tokenize
            std::string source;
            /// @brief Rules for tokenizing
            std::vector<TokenizationRule<T>> rules;
            /// @brief Current line
            std::size_t line = 1;
            /// @brief Current column
            std::size_t column = 1;
            /// @brief Start of the current lexeme
            std::size_t start = 0;
            /// @brief End of the current lexeme
            std::size_t end = 0;
            void skipWhitespace();
            void reportError(std::string message);
            bool isAtEnd();
    };

    template <typename T>
        requires std::is_enum_v<T>
    Lexer<T>::Lexer(std::string source, std::vector<TokenizationRule<T>> rules) {
        this->source = source;
        this->rules = rules;
    }

    template <typename T>
        requires std::is_enum_v<T>
    Lexer<T>::~Lexer() {
    }

    template <typename T>
        requires std::is_enum_v<T>
    std::vector<Token<T>> Lexer<T>::tokenize() {
        std::vector<Token<T>> tokens;
        std::string sourceStart = this->source;
        std::string lexeme;
        std::smatch match;
        while (!this->isAtEnd()) {
            // Skipping whitespaces between the tokens
            this->skipWhitespace();
            sourceStart = this->source.substr(start);
            for (TokenizationRule<T> rule : this->rules) {
                // Only match at the start of the string
                if (std::regex_search(sourceStart, match, rule.getPattern())) {
                    // The end of the current lexeme is the length of the match
                    this->end = this->start + match.length();
                    lexeme = this->source.substr(start, end - start);
                    // Adding the token
                    tokens.push_back(Token<T>(rule.getType(), lexeme, this->line, this->column));
                    // Setting the current start of the next lexeme to the end of the current lexeme
                    this->start = this->end;
                    // Increment column by the length of the match
                    this->column += match.length();
                    break;
                }
            }
            if (match.empty()) {
                this->reportError("Unexpected character '" + std::string(1, this->source[start]) + "' at line " +
                                  std::to_string(this->line) + ", column " + std::to_string(this->column));
                break;
            }
        }
        return tokens;
    }

    template <typename T>
        requires std::is_enum_v<T>
    void Lexer<T>::skipWhitespace() {
        while (!this->isAtEnd() && (this->source[this->start] == ' ' || this->source[this->start] == '\t' ||
                                    this->source[this->start] == '\n' || this->source[this->start] == '\r')) {
            if (this->source[this->start] == '\n' || this->source[this->start] == '\r') {
                // Increment line and reset column
                this->line++;
                this->column = 1;
            } else {
                // Increment column
                this->column++;
            }
            this->start++;
        }
    }

    template <typename T>
        requires std::is_enum_v<T>
    void Lexer<T>::reportError(std::string message) {
        std::cout << "Error: " << message << "at line " << this->line << ", column " << this->column << std::endl;
    }

    template <typename T>
        requires std::is_enum_v<T> bool
    Lexer<T>::isAtEnd() {
        return this->start >= this->source.length();
    }
} // namespace Tobot::Language