set(TOBOT_TOOLING_SOURCE_FILES
"logging/logger.cpp"
)

set(TOBOT_TOOLING_HEADER_FILES
"logging/logger.h"
"debug/tobot_asserts.h"
"test/tobot_test.h"
"include/tobot_tooling.h"
)

add_library(tobot-tooling ${TOBOT_TOOLING_SOURCE_FILES} ${TOBOT_TOOLING_HEADER_FILES})

target_include_directories(tobot-tooling PUBLIC "${PROJECT_SOURCE_DIR}/packages/tobot_tooling/src/")