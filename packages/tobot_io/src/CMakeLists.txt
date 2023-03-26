set(TOBOT_IO_SOURCE_FILES
"guard/directory_guard.cpp"
"path/path_utils.cpp"
)

set(TOBOT_IO_HEADER_FILES
"guard/directory_guard.h"
"include/tobot_io.h"
"path/path_utils.h"
)

add_library(tobot-io STATIC ${TOBOT_IO_SOURCE_FILES} ${TOBOT_IO_HEADER_FILES})

target_include_directories(tobot-io PUBLIC "${SOURCE_PATH_TOOLING}/src/")

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-io  PUBLIC pre_compiled_header.h pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-io  PUBLIC pre_compiled_header.h)
endif()