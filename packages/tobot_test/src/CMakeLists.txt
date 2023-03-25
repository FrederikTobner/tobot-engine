set(TOBOT_TEST_SOURCE_FILES
"test_case.cpp"
"test_fixture.cpp"
"test_report.cpp"
"test_report_processor.cpp"
"test_runner.cpp"
"console_test_report_processor.cpp"
"test_state.cpp"
)
set(TOBOT_TEST_HEADER_FILES
"test_case.h"
"test_fixture.h"
"test_macros.h"
"test_report.h"
"test_report_processor.h"
"test_runner.h"
"console_test_report_processor.h"
"test_state.h"
"./include/tobot_test.h"
)

add_library(tobot-test STATIC ${TOBOT_TEST_SOURCE_FILES} ${TOBOT_TEST_HEADER_FILES})

target_include_directories(tobot-test PUBLIC "${SOURCE_PATH_TEST}/src/")