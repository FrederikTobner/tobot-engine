set(LANG_HEADER_FILES
"token.hpp"
"tokenization_rule.hpp"
"lexer.hpp"
"include/tobot_lang.hpp"
)

add_library(tobot-lang INTERFACE)

target_sources(tobot-lang INTERFACE ${LANG_HEADER_FILES})

set_target_properties(tobot-lang PROPERTIES LINKER_LANGUAGE CXX)

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-lang INTERFACE pre_compiled_header.hpp pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-lang INTERFACE pre_compiled_header.hpp)
endif()