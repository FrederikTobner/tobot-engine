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
    std::unique_ptr<ProductionRule<TokenTypes::Value, GrammarSymbols::Value>> numberParsingRule =
        std::make_unique<TerminalProductionRule<TokenTypes::Value, GrammarSymbols::Value>>(GrammarSymbols::NUMBER_RULE,
                                                                                           TokenTypes::NUMBER);
    std::unique_ptr<Tree<ProductionRule<TokenTypes::Value, GrammarSymbols::Value> *>> leGrammar =
        std::make_unique<Tree<ProductionRule<TokenTypes::Value, GrammarSymbols::Value> *>>(numberParsingRule.get());
    Parser<TokenTypes::Value, GrammarSymbols::Value> parser(leGrammar.get());
}

/*
 * Tests whether the Parser can parse
 */
TEST(Parser, CanParseSingleToken) {
    std::unique_ptr<ProductionRule<TokenTypes::Value, GrammarSymbols::Value>> numberParsingRule =
        std::make_unique<TerminalProductionRule<TokenTypes::Value, GrammarSymbols::Value>>(GrammarSymbols::NUMBER_RULE,
                                                                                           TokenTypes::NUMBER);
    std::unique_ptr<Tree<ProductionRule<TokenTypes::Value, GrammarSymbols::Value> *>> leGrammar =
        std::make_unique<Tree<ProductionRule<TokenTypes::Value, GrammarSymbols::Value> *>>(numberParsingRule.get());
    std::vector<Token<TokenTypes::Value>> tokens = {{TokenTypes::NUMBER, "123", 1, 1}};
    Parser<TokenTypes::Value, GrammarSymbols::Value> parser(leGrammar.get());
    Tobot::DataStructures::Tree::Tree<std::pair<TokenTypes::Value, GrammarSymbols::Value>> tree = parser.parse(tokens);
}
