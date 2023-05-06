#include <gtest/gtest.h>

#include "tobot_lang.hpp"

using namespace Tobot::Language;

// Different types of tokens
enum TokenTypes {
    NUMBER
};

// Different symbols in the grammar
enum GrammarSymbols {
    NUMBER_RULE
};

/*
 * Tests whether we can create a terminal production rule
 */
TEST(TerminalProductionRule, CanBeCreated) {
    TerminalProductionRule<TokenTypes, GrammarSymbols> rule(NUMBER_RULE, NUMBER);
}