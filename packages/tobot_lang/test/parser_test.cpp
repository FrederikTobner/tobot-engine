#include <gtest/gtest.h>

#include "tobot_data_structures.h"
#include "tobot_lang.h"
#include <vector>

using namespace Tobot::Language;
using namespace Tobot::DataStructures::Tree;

// Different types of tokens
enum TokenTypes {
    NUMBER,
    PLUS,
    MINUS,
    STAR,
    SLASH
};

// Different symbols in the grammar
enum GrammarSymbols {
    EXPRESSION,
    TERM,
    FACTOR,
    NUMBER_RULE,
};

/*
 * Tests whether the Parser can be created
 */
TEST(Parser, CanBeCreated) {
    std::unique_ptr<ProductionRule<TokenTypes, GrammarSymbols>> numberParsingRule =
        std::make_unique<TerminalProductionRule<TokenTypes, GrammarSymbols>>(NUMBER_RULE, NUMBER);
    std::unique_ptr<Tree<ProductionRule<TokenTypes, GrammarSymbols> *>> leGrammar =
        std::make_unique<Tree<ProductionRule<TokenTypes, GrammarSymbols> *>>(numberParsingRule.get());
    Parser<TokenTypes, GrammarSymbols> parser(leGrammar.get());
}

/*
 * Tests whether the Parser can parse
 */
TEST(Parser, CanParseSingleToken) {
    std::unique_ptr<ProductionRule<TokenTypes, GrammarSymbols>> numberParsingRule =
        std::make_unique<TerminalProductionRule<TokenTypes, GrammarSymbols>>(NUMBER_RULE, NUMBER);
    std::unique_ptr<Tree<ProductionRule<TokenTypes, GrammarSymbols> *>> leGrammar =
        std::make_unique<Tree<ProductionRule<TokenTypes, GrammarSymbols> *>>(numberParsingRule.get());
    std::vector<Token<TokenTypes>> tokens = {{NUMBER, "123", 1, 1}};
    Parser<TokenTypes, GrammarSymbols> parser(leGrammar.get());
    Tobot::DataStructures::Tree::Tree<std::pair<TokenTypes, GrammarSymbols>> tree = parser.parse(tokens);
}
