set(TOBOT_IO_SOURCE_FILES
"console/console_style.cpp"
"guard/directory_guard.cpp"
"path/path_utils.cpp"
)

set(TOBOT_IO_HEADER_FILES
"console/console_style.hpp"
"guard/directory_guard.hpp"
"include/tobot_io.hpp"
"path/path_utils.hpp"
)

add_library(tobot-io STATIC ${TOBOT_IO_SOURCE_FILES} ${TOBOT_IO_HEADER_FILES})

target_include_directories(tobot-io PUBLIC "${SOURCE_PATH_TOOLING}/src/")

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-io  PUBLIC pre_compiled_header.hpp pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-io  PUBLIC pre_compiled_header.hpp)
endif()