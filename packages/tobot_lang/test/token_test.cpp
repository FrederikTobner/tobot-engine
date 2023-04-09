#include <gtest/gtest.h>

#include "tobot_lang.h"

using namespace Tobot::Language;

enum TokenTypes {
    NUMBER,
    PLUS,
    MINUS,
    STAR,
    SLASH,
    LEFT_PAREN,
    RIGHT_PAREN,
    END_OF_FILE
};

/*
 * Tests whether the Token
 */
TEST(Token, CanBeCreated) {
    Token<TokenTypes> token(NUMBER, "1", 1, 1);
}