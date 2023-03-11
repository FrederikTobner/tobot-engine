# include google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TOBOT_MATH_TESTS tobot-tooling_TESTS)

# Set all test files
set(TEST_SOURCES vector2d_test.cpp main.cpp)

# Set needed tobot-math header/sources
set(TEST_DEPS_SOURCES "${SOURCE_PATH_MATH}/vector2d.cpp")

set(TEST_DEPS_HEADERS "${SOURCE_PATH_MATH}/vector2d.h")

add_executable(${TOBOT_MATH_TESTS} ${TEST_DEPS_SOURCES} ${TEST_DEPS_HEADERS} ${TEST_SOURCES})

# Includes source path of the math library
target_include_directories(${TOBOT_MATH_TESTS} PUBLIC ${SOURCE_PATH_MATH})

# Link google test
target_link_libraries(${TOBOT_MATH_TESTS} GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${TOBOT_MATH_TESTS})
