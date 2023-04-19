set(LANG_HEADER_FILES
"token.h"
"lexer/tokenization_rule.h"
"lexer/lexer.h"
"include/tobot_lang.h"
"parser/context/parsing_context.h"
"parser/context/complex_parsing_context.h"
"parser/context/simple_parsing_context.h"
"parser/rule/production_rule.h"
"parser/rule/quantified_production_rule.h"
"parser/rule/production_rule_sequence.h"
"parser/rule/terminal_production_rule.h"
)

add_library(tobot-lang INTERFACE)

target_sources(tobot-lang INTERFACE ${LANG_HEADER_FILES})

set_target_properties(tobot-lang PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(tobot-lang INTERFACE tobot-data-structures)

target_include_directories(tobot-lang INTERFACE "${SOURCE_PATH_DATA_STRUCTURES}/include")

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-lang INTERFACE pre_compiled_header.h pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-lang INTERFACE pre_compiled_header.h)
endif()