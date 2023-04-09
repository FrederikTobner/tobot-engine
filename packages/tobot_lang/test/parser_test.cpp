#include <gtest/gtest.h>

#include "tobot_lang.h"
#include <vector>

using namespace Tobot::Language;

enum TokenTypes {
    NUMBER,
    PLUS,
    MINUS,
    STAR,
    SLASH
};

enum parsingRules {
    EXPRESSION,
    TERM,
    FACTOR,
    NUMBER_RULE,
};

/*
 * Tests whether the Parser can be created
 */
TEST(Parser, CanBeCreated) {
    std::vector<Token<TokenTypes>> tokens = {{NUMBER, "123", 1, 1}};
    TokenSequenceParsingRule<TokenTypes, parsingRules> tokenSequenceRule(NUMBER_RULE, {NUMBER});
    // We need to use a pointer here because the vector will try to copy the object
    // Should we solved in the future
    ParsingRule<TokenTypes, parsingRules> * parsingRule = &tokenSequenceRule;
    std::vector<ParsingRule<TokenTypes, parsingRules> *> leParsingRules = {parsingRule};
    Parser<TokenTypes, parsingRules> parser(leParsingRules);
}
