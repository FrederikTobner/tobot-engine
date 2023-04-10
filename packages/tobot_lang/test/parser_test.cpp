#include <gtest/gtest.h>

#include "tobot_data_structures.h"
#include "tobot_lang.h"
#include <vector>

using namespace Tobot::Language;

// Different types of tokens
enum TokenTypes {
    NUMBER,
    PLUS,
    MINUS,
    STAR,
    SLASH
};

// Different types of parsing rules - producing an expression, term, factor or a number
enum ParsingRules {
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
    TerminalParsingRule<TokenTypes, ParsingRules> tokenSequenceRule(NUMBER_RULE, NUMBER);
    // We need to use a pointer here because the vector will try to copy the object
    // Should we solved in the future
    ParsingRule<TokenTypes, ParsingRules> * parsingRule = &tokenSequenceRule;
    std::vector<ParsingRule<TokenTypes, ParsingRules> *> leParsingRules = {parsingRule};
    Parser<TokenTypes, ParsingRules> parser(leParsingRules);
}

/*
 * Tests whether the Parser can parse a single token
 */
TEST(Parser, CanParseSingleToken) {
    std::vector<Token<TokenTypes>> tokens = {{NUMBER, "123", 1, 1}};
    TerminalParsingRule<TokenTypes, ParsingRules> tokenSequenceRule(NUMBER_RULE, NUMBER);
    // We need to use a pointer here because the vector will try to copy the object
    // Should we solved in the future
    ParsingRule<TokenTypes, ParsingRules> * parsingRule = &tokenSequenceRule;
    std::vector<ParsingRule<TokenTypes, ParsingRules> *> leParsingRules = {parsingRule};
    Parser<TokenTypes, ParsingRules> parser(leParsingRules);
    Tobot::DataStructures::Tree::Tree<std::pair<TokenTypes, ParsingRules>> tree = parser.parse(tokens);
}
