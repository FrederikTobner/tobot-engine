set(TOBOT_TOOLING_SOURCE_FILES
"logging/logger.cpp"
)

set(TOBOT_TOOLING_HEADER_FILES
"logging/logger.hpp"
"debug/tobot_asserts.hpp"
"include/tobot_tooling.hpp"
)

add_library(tobot-tooling STATIC ${TOBOT_TOOLING_SOURCE_FILES} ${TOBOT_TOOLING_HEADER_FILES})

target_link_libraries(tobot-tooling PUBLIC tobot-io)
target_include_directories(tobot-tooling PUBLIC "${SOURCE_PATH_TOOLING}" "${SOURCE_PATH_IO}/include")

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-tooling PUBLIC pre_compiled_header.hpp pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-tooling PUBLIC pre_compiled_header.hpp)
endif()