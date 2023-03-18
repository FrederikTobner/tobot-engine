#pragma once

namespace Tobot::Tooling::Test {
#define TOBOT_TEST(testsuiteName, testName, ...) \
    void test_##testsuiteName##_##testName##(Tobot::Tooling::Test::TestState * state)

#define ASSERT_TRUE(condition)                                                                   \
    if (!(condition)) {                                                                          \
        std::cout << "Assertion failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                                   \
        return;                                                                                  \
    }

#define EXPECT_TRUE(condition)                                                               \
    if (!(condition)) {                                                                      \
        std::cout << "Check failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                               \
    }

#define ASSERT_FALSE(condition)                                                                  \
    if (condition) {                                                                             \
        std::cout << "Assertion failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                                   \
        return;                                                                                  \
    }

#define EXPECT_FALSE(condition)                                                              \
    if (condition) {                                                                         \
        std::cout << "Check failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                               \
    }

#define ASSERT_EQUAL(a, b)                                                                       \
    if ((a) != (b)) {                                                                            \
        std::cout << "Assertion failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                                   \
        return;                                                                                  \
    }

#define EXPECT_EQUAL(a, b)                                                                   \
    if ((a) != (b)) {                                                                        \
        std::cout << "Check failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                               \
    }

#define ASSERT_NOT_EQUAL(a, b)                                                                   \
    if ((a) == (b)) {                                                                            \
        std::cout << "Assertion failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                                   \
        return;                                                                                  \
    }

#define EXPECT_NOT_EQUAL(a, b)                                                               \
    if ((a) == (b)) {                                                                        \
        std::cout << "Check failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                               \
    }

#define ASSERT_STR_EQUAL(a, b)                                                                   \
    if (strcmp(a, b)) {                                                                          \
        std::cout << "Assertion failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                                   \
        return;                                                                                  \
    }

#define EXPECT_STR_EQUAL(a, b)                                                               \
    if (strcmp(a, b)) {                                                                      \
        std::cout << "Check failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                               \
    }

#define ASSERT_STR_NOT_EQUAL(a, b)                                                               \
    if (!strcmp(a, b)) {                                                                         \
        std::cout << "Assertion failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                                   \
        return;                                                                                  \
    }

#define EXPECT_STR_NOT_EQUAL(a, b)                                                           \
    if (!strcmp(a, b)) {                                                                     \
        std::cout << "Check failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                               \
    }

} // namespace Tobot::Tooling::Test
