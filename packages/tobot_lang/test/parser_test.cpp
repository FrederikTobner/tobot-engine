#include <gtest/gtest.h>

#include "tobot_data_structures.h"
#include "tobot_lang.h"
#include <vector>

using namespace Tobot::Language;
using namespace Tobot::DataStructures::Tree;

TOBOT_ENUM(TokenTypes, NUMBER, PLUS, MINUS, STAR, SLASH)

TOBOT_ENUM(GrammarSymbols, EXPRESSION, TERM, FACTOR, NUMBER_RULE)
/*
 * Tests whether the Parser can be created
 */
TEST(Parser, CanBeCreated) {
    auto numberParsingRule = std::make_unique<TerminalProductionRule<TokenTypes::Enum, GrammarSymbols::Enum>>(
        GrammarSymbols::NUMBER_RULE, TokenTypes::NUMBER);
    auto leGrammar =
        std::make_unique<Tree<ProductionRule<TokenTypes::Enum, GrammarSymbols::Enum> *>>(numberParsingRule.get());
    Parser<TokenTypes::Enum, GrammarSymbols::Enum> parser(leGrammar.get());
}

/*
 * Tests whether the Parser can parse
 */
TEST(Parser, CanParseSingleToken) {
    auto numberParsingRule = std::make_unique<TerminalProductionRule<TokenTypes::Enum, GrammarSymbols::Enum>>(
        GrammarSymbols::NUMBER_RULE, TokenTypes::NUMBER);
    auto leGrammar =
        std::make_unique<Tree<ProductionRule<TokenTypes::Enum, GrammarSymbols::Enum> *>>(numberParsingRule.get());
    std::vector<Token<TokenTypes::Enum>> tokens = {{TokenTypes::NUMBER, "123", 1, 1}};
    Parser<TokenTypes::Enum, GrammarSymbols::Enum> parser(leGrammar.get());
    Tobot::DataStructures::Tree::Tree<std::pair<TokenTypes::Enum, GrammarSymbols::Enum>> tree = parser.parse(tokens);
}
