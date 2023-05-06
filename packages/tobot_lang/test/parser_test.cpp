#include <gtest/gtest.h>

#include "tobot_data_structures.hpp"
#include "tobot_lang.hpp"
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
    // Having only the type and the rule that was applied is not enough - we need to know the value of the token as well
    // But not each node in the tree is a terminal node, so we can only add this information to the terminal nodes
    ASSERT_EQ(tree.getRoot()->getValue().first, TokenTypes::NUMBER);
    ASSERT_EQ(tree.getRoot()->getValue().second, GrammarSymbols::NUMBER_RULE);
}
