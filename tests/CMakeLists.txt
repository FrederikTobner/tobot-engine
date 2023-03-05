enable_testing()

# Set all test files
set(TEST_SOURCES math/vector2d_test.cpp main.cpp)

# Set needed tobot-engine header/sources
set(TEST_DEPS_HEADERS "${SOURCEPATH}/math/vector2d.h")

add_executable(${PROJECT_NAME}_TESTS ${TEST_DEPS_SOURCES} ${TEST_DEPS_HEADERS} ${TEST_SOURCES})

# Includes SourcePath of the compiler for shorter includes and the config file
target_include_directories(${PROJECT_NAME}_TESTS PUBLIC ${SOURCEPATH} ${PROJECT_BINARY_DIR}/src)

# Link google test
target_link_libraries(${PROJECT_NAME}_TESTS GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_TESTS)