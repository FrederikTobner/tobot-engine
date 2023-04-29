# tobot-lang

Tools for generating lexical analyzers and parsers for programming languages, markup languages, and other text formats - inspired by [ANTLR](https://www.antlr.org/).

## Overview

Tobot-lang processes a formal grammar definition and create a lexer and parser for the language. The created lexer and parser can be used to analyze and parse the input text according to the grammar definition.

The grammar of a language is modeled as a tree of parsing rule. A parsing rule is a rule that can be used to parse a sequence of tokens. A parsing rule can be a sequence of other rules, a logical OR and AND connection between a group of sub-rules, a quantified rule or a terminal parsing rule.

The result of the parsing process is a tree of parsing contexts. A parsing context contains the matched tokens and the parsing rule that matched them.

## Rules

* QuantifiedParsingRule - inspired by a regex quantifier
* ParsingRule - a rule that can be used to parse a sequence of tokens
* SequenceParsingRule - a rule that matches a sequence of other rules
* TerminalParsingRule - a terminal rule of the grammer, that only contains the matched tokens and no sub-rule. These rules are always the leafs of the parsing rule tree.

What is still needed:

* A rule to model a logical OR and AND connection between a group of sub-rules
* A specification how we will implement backtracking if a parsing rule partially matches the input
* A specification how the grammer definition will look like. This should probably be done in a seperate file that is used to create a pasring tree.
