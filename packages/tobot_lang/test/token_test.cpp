#include <gtest/gtest.h>

#include "tobot_lang.h"

using namespace Tobot::Language;

// Different types of tokens
enum TokenTypes {
    NUMBER
};

/*
 * Tests whether the Token
 */
TEST(Token, CanBeCreated) {
    Token<TokenTypes> token(NUMBER, "1", 1, 1);
}