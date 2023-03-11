include(CheckIncludeFile)

# Checking dependecies
if(UNIX)
elseif(WIN32)
    # Check dependecies under windows
    CHECK_INCLUDE_FILE("windows.h" WINDOWS_AVAILABLE)
    if(NOT ${WINDOWS_AVAILABLE})
        message(FATAL_ERROR "windows.h is required to build the compiler under windows. \
\   \   Please make sure it is available to the compiler and try again after that")
    endif() # windows.h not available
endif()

set(TOBOT_TOOLING_SOURCE_FILES
"logging/logger.cpp"
)

set(TOBOT_TOOLING_HEADER_FILES
"logging/logger.h"
"debug/tobot_asserts.h"
"test/tobot_test.h"
"include/tobot_tooling.h"
)

add_library(tobot-tooling STATIC ${TOBOT_TOOLING_SOURCE_FILES} ${TOBOT_TOOLING_HEADER_FILES})

target_include_directories(tobot-tooling PUBLIC "${SOURCE_PATH_TOOLING}/src/")