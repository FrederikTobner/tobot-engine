# include google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TOBOT_TEST_TESTS tobot-test_TESTS)

# Set all test files
set(TEST_SOURCES test_state_test.cpp main.cpp)

add_executable(${TOBOT_TEST_TESTS} ${TEST_SOURCES})

# Includes source path of the math library
target_include_directories(${TOBOT_TEST_TESTS} PUBLIC "${SOURCE_PATH_TEST}/include")

# Link google test
target_link_libraries(${TOBOT_TEST_TESTS} GTest::gtest_main tobot-test)

include(GoogleTest)
gtest_discover_tests(${TOBOT_TEST_TESTS})
