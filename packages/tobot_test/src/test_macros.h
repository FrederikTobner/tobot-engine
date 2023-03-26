/**
 * @file test_macros.h
 * @brief File containing macros for creating and writing TestCase's.
 */

#pragma once

namespace Tobot::Tooling::Test {
#define TBTT_TEST(testsuiteName, testName, ...) \
    void tobot_##testsuiteName##_##testName##_test(Tobot::Tooling::Test::TestState * state)

#define TBTT_ASSERT_TRUE(condition)                                                                         \
    if (!(condition)) {                                                                                     \
        std::cout << "Assertion \"" << #condition << "\" failed at line " << __LINE__ << " in " << __FILE__ \
                  << std::endl;                                                                             \
        state->passed = false;                                                                              \
        return;                                                                                             \
    }

#define TBTT_EXPECT_TRUE(condition)                                                                                   \
    if (!(condition)) {                                                                                               \
        std::cout << "Check \"" << #condition << "\" failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                                                        \
    }

#define TBTT_ASSERT_FALSE(condition)                                                                        \
    if (condition) {                                                                                        \
        std::cout << "Assertion \"" << #condition << "\" failed at line " << __LINE__ << " in " << __FILE__ \
                  << std::endl;                                                                             \
        state->passed = false;                                                                              \
        return;                                                                                             \
    }

#define TBTT_EXPECT_FALSE(condition)                                                                                  \
    if (condition) {                                                                                                  \
        std::cout << "Check \"" << #condition << "\" failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        state->passed = false;                                                                                        \
    }

#define TBTT_ASSERT_EQUAL(a, b)                                                                             \
    if ((a) != (b)) {                                                                                       \
        std::cout << "Assertion \"" << #a << " equals " << #b << "\" failed at line " << __LINE__ << " in " \
                  << __FILE__ << std::endl;                                                                 \
        state->passed = false;                                                                              \
        return;                                                                                             \
    }

#define TBTT_EXPECT_EQUAL(a, b)                                                                                     \
    if ((a) != (b)) {                                                                                               \
        std::cout << "Check \"" << #a << " equals " << #b << "\" failed at line " << __LINE__ << " in " << __FILE__ \
                  << std::endl;                                                                                     \
        state->passed = false;                                                                                      \
    }

#define TBTT_ASSERT_NOT_EQUAL(a, b)                                                                                   \
    if ((a) == (b)) {                                                                                                 \
        std::cout << "Assertion \"" << #a << " is not equal to " << #b << "\"  failed at line " << __LINE__ << " in " \
                  << __FILE__ << std::endl;                                                                           \
        state->passed = false;                                                                                        \
        return;                                                                                                       \
    }

#define TBTT_EXPECT_NOT_EQUAL(a, b)                                                                                \
    if ((a) == (b)) {                                                                                              \
        std::cout << "Check \"" << #a << " is not equal to " << #b << "\"   failed at line " << __LINE__ << " in " \
                  << __FILE__ << std::endl;                                                                        \
        state->passed = false;                                                                                     \
    }

#define TBTT_ASSERT_STR_EQUAL(a, b)                                                                         \
    if (strcmp(a, b)) {                                                                                     \
        std::cout << "Assertion  \"" << a << " equals " << b << "\"  failed at line " << __LINE__ << " in " \
                  << __FILE__ << std::endl;                                                                 \
        state->passed = false;                                                                              \
        return;                                                                                             \
    }

#define TBTT_EXPECT_STR_EQUAL(a, b)                                                                                 \
    if (strcmp(a, b)) {                                                                                             \
        std::cout << "Check  \"" << a << " equals " << b << "\"  failed at line " << __LINE__ << " in " << __FILE__ \
                  << std::endl;                                                                                     \
        state->passed = false;                                                                                      \
    }

#define TBTT_ASSERT_STR_NOT_EQUAL(a, b)                                                                            \
    if (!strcmp(a, b)) {                                                                                           \
        std::cout << "Assertion \"" << a << " is not equal to " << b << "\" failed at line " << __LINE__ << " in " \
                  << __FILE__ << std::endl;                                                                        \
        state->passed = false;                                                                                     \
        return;                                                                                                    \
    }

#define TBTT_EXPECT_STR_NOT_EQUAL(a, b)                                                                          \
    if (!strcmp(a, b)) {                                                                                         \
        std::cout << "Check  \"" << a << " is not equal to " << b << "\"  failed at line " << __LINE__ << " in " \
                  << __FILE__ << std::endl;                                                                      \
        state->passed = false;                                                                                   \
    }

} // namespace Tobot::Tooling::Test
