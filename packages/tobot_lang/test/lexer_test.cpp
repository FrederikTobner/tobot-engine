#include <gtest/gtest.h>

#include "tobot_data_structures.h"
#include "tobot_lang.h"

using namespace Tobot::Language;

TOBOT_ENUM(Token_Type, NUMBER, PLUS, MINUS, STAR, SLASH, LEFT_PAREN, RIGHT_PAREN)

std::vector<TokenizationRule<Token_Type::Enum>> rules = {
    {Token_Type::NUMBER, "[0-9]+"},  {Token_Type::PLUS, "\\+"}, {Token_Type::MINUS, "-"},
    {Token_Type::STAR, "\\*"},       {Token_Type::SLASH, "/"},  {Token_Type::LEFT_PAREN, "\\("},
    {Token_Type::RIGHT_PAREN, "\\)"}};
/*
 * Tests whether the Lexer can be created
 */
TEST(Lexer, CanBeCreated) {
    Lexer<Token_Type::Enum> lexer(rules);
}

/*
 * Tests whether the Lexer can tokenize a single token
 */
TEST(Lexer, CanTokenizeSingleToken) {
    Lexer<Token_Type::Enum> lexer(rules);
    std::vector<Token<Token_Type::Enum>> tokens = lexer.tokenize("-");
    ASSERT_EQ(tokens.size(), 1);
    ASSERT_EQ(tokens[0].getType(), Token_Type::MINUS);
    ASSERT_EQ(tokens[0].getLexeme(), "-");
    ASSERT_EQ(tokens[0].getLine(), 1);
    ASSERT_EQ(tokens[0].getColumn(), 1);
}

/*
 * Tests whether the Lexer can tokenize multiple tokens
 */
TEST(Lexer, CanTokenizeMultipleTokens) {
    Lexer<Token_Type::Enum> lexer(rules);
    std::vector<Token<Token_Type::Enum>> tokens = lexer.tokenize("- 123");
    ASSERT_EQ(tokens.size(), 2);
    ASSERT_EQ(tokens[0].getType(), Token_Type::MINUS);
    ASSERT_EQ(tokens[0].getLexeme(), "-");
    ASSERT_EQ(tokens[0].getLine(), 1);
    ASSERT_EQ(tokens[0].getColumn(), 1);
    ASSERT_EQ(tokens[1].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[1].getLexeme(), "123");
    ASSERT_EQ(tokens[1].getLine(), 1);
    ASSERT_EQ(tokens[1].getColumn(), 3);
}

/*
 * Tests whether the Lexer can tokenize a complex expression
 */
TEST(Lexer, CanTokenizeComplexExpression) {
    Lexer<Token_Type::Enum> lexer(rules);
    std::vector<Token<Token_Type::Enum>> tokens = lexer.tokenize("1 + 2 * 3 - 4 / 5");
    ASSERT_EQ(tokens.size(), 9);
    ASSERT_EQ(tokens[0].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[0].getLexeme(), "1");
    ASSERT_EQ(tokens[0].getLine(), 1);
    ASSERT_EQ(tokens[0].getColumn(), 1);
    ASSERT_EQ(tokens[1].getType(), Token_Type::PLUS);
    ASSERT_EQ(tokens[1].getLexeme(), "+");
    ASSERT_EQ(tokens[1].getLine(), 1);
    ASSERT_EQ(tokens[1].getColumn(), 3);
    ASSERT_EQ(tokens[2].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[2].getLexeme(), "2");
    ASSERT_EQ(tokens[2].getLine(), 1);
    ASSERT_EQ(tokens[2].getColumn(), 5);
    ASSERT_EQ(tokens[3].getType(), Token_Type::STAR);
    ASSERT_EQ(tokens[3].getLexeme(), "*");
    ASSERT_EQ(tokens[3].getLine(), 1);
    ASSERT_EQ(tokens[3].getColumn(), 7);
    ASSERT_EQ(tokens[4].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[4].getLexeme(), "3");
    ASSERT_EQ(tokens[4].getLine(), 1);
    ASSERT_EQ(tokens[4].getColumn(), 9);
    ASSERT_EQ(tokens[5].getType(), Token_Type::MINUS);
    ASSERT_EQ(tokens[5].getLexeme(), "-");
    ASSERT_EQ(tokens[5].getLine(), 1);
    ASSERT_EQ(tokens[5].getColumn(), 11);
    ASSERT_EQ(tokens[6].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[6].getLexeme(), "4");
    ASSERT_EQ(tokens[6].getLine(), 1);
    ASSERT_EQ(tokens[6].getColumn(), 13);
    ASSERT_EQ(tokens[7].getType(), Token_Type::SLASH);
    ASSERT_EQ(tokens[7].getLexeme(), "/");
    ASSERT_EQ(tokens[7].getLine(), 1);
    ASSERT_EQ(tokens[7].getColumn(), 15);
    ASSERT_EQ(tokens[8].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[8].getLexeme(), "5");
    ASSERT_EQ(tokens[8].getLine(), 1);
    ASSERT_EQ(tokens[8].getColumn(), 17);
}

/*
 * Tests whether the Lexer can handle line breaks
 */
TEST(Lexer, CanHandleLineBreaks) {
    Lexer<Token_Type::Enum> lexer(rules);
    std::vector<Token<Token_Type::Enum>> tokens = lexer.tokenize("1 \n2");
    ASSERT_EQ(tokens.size(), 2);
    ASSERT_EQ(tokens[0].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[0].getLexeme(), "1");
    ASSERT_EQ(tokens[0].getLine(), 1);
    ASSERT_EQ(tokens[0].getColumn(), 1);
    ASSERT_EQ(tokens[1].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[1].getLexeme(), "2");
    ASSERT_EQ(tokens[1].getLine(), 2);
    ASSERT_EQ(tokens[1].getColumn(), 1);
}

/*
 * Tests whether the Lexer can handle multiple line breaks
 */
TEST(Lexer, CanHandleMultipleLineBreaks) {
    Lexer<Token_Type::Enum> lexer(rules);
    std::vector<Token<Token_Type::Enum>> tokens = lexer.tokenize("1 \n\n2");
    ASSERT_EQ(tokens.size(), 2);
    ASSERT_EQ(tokens[0].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[0].getLexeme(), "1");
    ASSERT_EQ(tokens[0].getLine(), 1);
    ASSERT_EQ(tokens[0].getColumn(), 1);
    ASSERT_EQ(tokens[1].getType(), Token_Type::NUMBER);
    ASSERT_EQ(tokens[1].getLexeme(), "2");
    ASSERT_EQ(tokens[1].getLine(), 3);
    ASSERT_EQ(tokens[1].getColumn(), 1);
}