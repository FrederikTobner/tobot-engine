#include <gtest/gtest.h>

#include "tobot_lang.hpp"

using namespace Tobot::Language;

// Different types of tokens
enum TokenTypes {
    NUMBER
};

/*
 * Tests whether a Token can be created
 */
TEST(Token, CanBeCreated) {
    Token<TokenTypes> token(NUMBER, "1", 1, 1);
}