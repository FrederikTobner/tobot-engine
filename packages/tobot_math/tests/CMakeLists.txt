# include google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TOBOT_MATH_TESTS tobot-math-tests)

# Set all test files
set(TEST_SOURCES
"circle_test.cpp"
"gradient_test.cpp"
"main.cpp"
"matrix_test.cpp"
"plane_test.cpp"
"point2d_test.cpp"
"polygon_test.cpp"
"rectangle_test.cpp"
"triangle_test.cpp"
"vector2d_test.cpp"
"vector3d_test.cpp"
"vector4d_test.cpp"
)

add_executable(${TOBOT_MATH_TESTS} ${TEST_SOURCES})

# Includes source path of the math library
target_include_directories(${TOBOT_MATH_TESTS} PUBLIC ${SOURCE_PATH_MATH})

# Link google test
target_link_libraries(${TOBOT_MATH_TESTS} GTest::gtest_main tobot-math)

include(GoogleTest)
gtest_discover_tests(${TOBOT_MATH_TESTS})
