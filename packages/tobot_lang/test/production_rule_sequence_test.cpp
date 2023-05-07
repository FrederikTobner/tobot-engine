#include <gtest/gtest.h>

#include "tobot_lang.hpp"

using namespace Tobot::Language;

// Different types of tokens
enum TokenTypes {
    NUMBER,
    PLUS,
    MINUS,
    STAR,
};

// Different symbols in the grammar
enum GrammarSymbols {
    EXPRESSION,
    STAR_RULE,
    MINUS_RULE,
    NUMBER_RULE,
};

/*
 * Tests whether we can create a production rule sequence
 */
TEST(ProductionRuleSequence, CanBeCreated) {
    TerminalProductionRule<TokenTypes, GrammarSymbols> rule(NUMBER_RULE, NUMBER);
    TerminalProductionRule<TokenTypes, GrammarSymbols> rule2(STAR_RULE, STAR);
    TerminalProductionRule<TokenTypes, GrammarSymbols> rule3(MINUS_RULE, MINUS);
    ProductionRuleSequence<TokenTypes, GrammarSymbols> sequence(EXPRESSION, {&rule, &rule2, &rule3});
}