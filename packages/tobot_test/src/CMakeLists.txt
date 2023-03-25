set(TOBOT_TEST_SOURCE_FILES

"test_case.cpp"
"test_fixture.cpp"
"test_report.cpp"
"test_state.cpp"
"processors/test_report_processor.cpp"
"processors/console_test_report_processor.cpp"
"runners/simple_test_runner.cpp"
"runners/test_runner.cpp"
)
set(TOBOT_TEST_HEADER_FILES
"test_case.h"
"test_fixture.h"
"test_macros.h"
"test_report.h"
"test_state.h"
"include/tobot_test.h"
"processors/test_report_processor.h"
"processors/console_test_report_processor.h"
"runners/simple_test_runner.h"
"runners/test_runner.h"

)

add_library(tobot-test STATIC ${TOBOT_TEST_SOURCE_FILES} ${TOBOT_TEST_HEADER_FILES})

target_include_directories(tobot-test PUBLIC "${SOURCE_PATH_TEST}/src/")

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-test  PUBLIC pre_compiled_header.h pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-test  PUBLIC pre_compiled_header.h)
endif()