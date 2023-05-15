# include google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TOBOT_LANG_TESTS tobot-lang-tests)

set(TOBOT_LANG_TEST_SOURCES
"lexer_test.cpp" 
"token_test.cpp"
)

add_executable(${TOBOT_LANG_TESTS} ${TOBOT_LANG_TEST_SOURCES})

# Includes source path of the math library
target_include_directories(${TOBOT_LANG_TESTS} PUBLIC ../src/include)

# Link google test
target_link_libraries(${TOBOT_LANG_TESTS} PUBLIC GTest::gtest_main tobot-lang)

include(GoogleTest)
gtest_discover_tests(${TOBOT_LANG_TESTS})
