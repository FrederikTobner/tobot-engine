# include google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TOBOT_DATA_STRUCTURES_TESTS tobot-data-structures_TESTS)

set(TOBOT_DATA_STRUCTURES_TEST_SOURCES 
"avl_tree_test.cpp"
"graph_test.cpp"
"main.cpp"
"red_black_tree_test.cpp"
"tree_test.cpp"
"tree_node_test.cpp"
)

# Set all test files
set(TEST_SOURCES ${TOBOT_DATA_STRUCTURES_TEST_SOURCES})

add_executable(${TOBOT_DATA_STRUCTURES_TESTS} ${TEST_SOURCES})

# Includes source path of the math library
target_include_directories(${TOBOT_DATA_STRUCTURES_TESTS} PUBLIC "${SOURCE_PATH_DATA_STRUCTURES}/include")

# Link google test
target_link_libraries(${TOBOT_DATA_STRUCTURES_TESTS} PUBLIC GTest::gtest_main tobot-data-structures)

include(GoogleTest)
gtest_discover_tests(${TOBOT_DATA_STRUCTURES_TESTS})
