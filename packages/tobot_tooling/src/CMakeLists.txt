set(TOBOT_TOOLING_SOURCE_FILES
"logger.cpp"
)

set(TOBOT_TOOLING_HEADER_FILES
"logger.h"
"tobot_asserts.h"
"include/tobot_tooling.h"
)

add_library(tobot-tooling ${TOBOT_TOOLING_SOURCE_FILES} ${TOBOT_TOOLING_HEADER_FILES})