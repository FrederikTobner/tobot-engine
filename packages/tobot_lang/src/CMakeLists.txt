set(DATA_STRUCTURES_HEADER_FILES
"token.h"
"lexer/tokenization_rule.h"
"lexer/lexer.h"
"include/tobot_lang.h"
"parser/expression/expression.h"
"parser/expression/complex_expression.h"
"parser/expression/simple_expression.h"
"parser/abstract_syntax_tree.h.h"
"parser/regex_quantifier.h"
"parser/rule/parsing_rule.h"
"parser/rule/quantified_parsing_rule.h"
"parser/rule/token_sequence_parsing_rule.h"
)

add_library(tobot-lang INTERFACE)

target_sources(tobot-lang INTERFACE ${DATA_STRUCTURES_HEADER_FILES})

set_target_properties(tobot-lang PROPERTIES LINKER_LANGUAGE CXX)

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-lang INTERFACE pre_compiled_header.h pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-lang INTERFACE pre_compiled_header.h)
endif()