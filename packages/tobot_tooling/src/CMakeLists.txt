set(TOBOT_TOOLING_SOURCE_FILES
"logging/logger.cpp"
"test/test_case.cpp"
"test/test_fixture.cpp"
"test/test_report.cpp"
"test/test_report_processor.cpp"
"test/test_runner.cpp"
"test/console_test_report_processor.cpp"
"test/test_state.cpp"
)

set(TOBOT_TOOLING_HEADER_FILES
"logging/logger.h"
"debug/tobot_asserts.h"
"test/tobot_test.h"
"test/test_case.h"
"test/test_fixture.h"
"test/test_macros.h"
"test/test_report.h"
"test/test_report_processor.h"
"test/test_runner.h"
"test/console_test_report_processor.h"
"test/test_state.h"
"include/tobot_tooling.h"
)

add_library(tobot-tooling STATIC ${TOBOT_TOOLING_SOURCE_FILES} ${TOBOT_TOOLING_HEADER_FILES})

target_include_directories(tobot-tooling PUBLIC "${SOURCE_PATH_TOOLING}/src/")