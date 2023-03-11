# include google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Set all test files
set(TEST_SOURCES math/vector2d_test.cpp main.cpp)

# Set needed tobot-engine header/sources
set(TEST_DEPS_HEADERS "${SOURCEPATH}/math/vector2d.h")

add_executable(${PROJECT_NAME}_TESTS ${TEST_DEPS_SOURCES} ${TEST_DEPS_HEADERS} ${TEST_SOURCES})

# Includes SourcePath of the compiler for shorter includes
target_include_directories(${PROJECT_NAME}_TESTS PUBLIC ${SOURCEPATH})

# Link google test
target_link_libraries(${PROJECT_NAME}_TESTS GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_TESTS)
