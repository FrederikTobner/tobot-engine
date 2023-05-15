set(TOBOT_TOOLING_SOURCE_FILES
"logging/logger.cpp"
"console/console_style.cpp"
"guard/directory_guard.cpp"
"path/path_utils.cpp"
)

set(TOBOT_TOOLING_HEADER_FILES
"console/console_style.hpp"
"debug/tobot_asserts.hpp"
"include/tobot_tooling.hpp"
"logging/logger.hpp"
"guard/directory_guard.hpp"
"path/path_utils.hpp"
)

add_library(tobot-tooling STATIC ${TOBOT_TOOLING_SOURCE_FILES} ${TOBOT_TOOLING_HEADER_FILES})

target_include_directories(tobot-tooling PUBLIC ../../tobot_data_structures/src/include)

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-tooling PUBLIC pre_compiled_header.hpp pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-tooling PUBLIC pre_compiled_header.hpp)
endif()