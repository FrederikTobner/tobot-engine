/**
 * @file test_macros.h
 * @brief File containing macros for creating and writing TestCase's.
 */

#pragma once

namespace Tobot::Tooling::Test {
#define TOBOT_TEST(testsuiteName, testName, ...)                                        \
    static_assert(sizeof(#testsuiteName) > 1, "The test suite name must not be empty"); \
    static_assert(sizeof(#testName) > 1, "The test name must not be empty");            \
    void tobot_##testsuiteName##_##testName##_test(Tobot::Tooling::Test::TestState * state)

#define TOBOT_ASSERT_TRUE(condition)                                                                                 \
    static_assert(sizeof(#condition) > 1, "A condition needs to be specified");                                      \
    if (!(condition)) {                                                                                              \
        std::cout << "Assertion \"" << #condition << "\" failed at line " << __LINE__ << " in " << __FILE__ << "\n"; \
        state->passed = false;                                                                                       \
        return;                                                                                                      \
    }

#define TOBOT_EXPECT_TRUE(condition)                                                                             \
    static_assert(sizeof(#condition) > 1, "A condition needs to be specified");                                  \
    if (!(condition)) {                                                                                          \
        std::cout << "Check \"" << #condition << "\" failed at line " << __LINE__ << " in " << __FILE__ << "\n"; \
        state->passed = false;                                                                                   \
    }

#define TOBOT_ASSERT_FALSE(condition)                                                                                \
    static_assert(sizeof(#condition) > 1, "A condition needs to be specified");                                      \
    if (condition) {                                                                                                 \
        std::cout << "Assertion \"" << #condition << "\" failed at line " << __LINE__ << " in " << __FILE__ << "\n"; \
        state->passed = false;                                                                                       \
        return;                                                                                                      \
    }

#define TOBOT_EXPECT_FALSE(condition)                                                                            \
    static_assert(sizeof(#condition) > 1, "A condition needs to be specified");                                  \
    if (condition) {                                                                                             \
        std::cout << "Check \"" << #condition << "\" failed at line " << __LINE__ << " in " << __FILE__ << "\n"; \
        state->passed = false;                                                                                   \
    }

#define TOBOT_ASSERT_EQUAL(a, b)                                                                                      \
    static_assert(sizeof(#a) > 1, "The first value needs to be specified");                                           \
    static_assert(sizeof(#b) > 1, "The second value needs to be specified");                                          \
    if ((a) != (b)) {                                                                                                 \
        std::cout << "Assertion \"" << a << " equals " << b << "\" failed at line " << __LINE__ << " in " << __FILE__ \
                  << "\n";                                                                                            \
        state->passed = false;                                                                                        \
        return;                                                                                                       \
    }

#define TOBOT_EXPECT_EQUAL(a, b)                                                                                  \
    static_assert(sizeof(#a) > 1, "The first value needs to be specified");                                       \
    static_assert(sizeof(#b) > 1, "The second value needs to be specified");                                      \
    if ((a) != (b)) {                                                                                             \
        std::cout << "Check \"" << a << " equals " << b << "\" failed at line " << __LINE__ << " in " << __FILE__ \
                  << "\n";                                                                                        \
        state->passed = false;                                                                                    \
    }

#define TOBOT_ASSERT_NOT_EQUAL(a, b)                                                                                \
    static_assert(sizeof(#a) > 1, "The first value needs to be specified");                                         \
    static_assert(sizeof(#b) > 1, "The second value needs to be specified");                                        \
    if ((a) == (b)) {                                                                                               \
        std::cout << "Assertion \"" << a << " is not equal to " << b << "\"  failed at line " << __LINE__ << " in " \
                  << __FILE__ << "\n";                                                                              \
        state->passed = false;                                                                                      \
        return;                                                                                                     \
    }

#define TOBOT_EXPECT_NOT_EQUAL(a, b)                                                                             \
    static_assert(sizeof(#a) > 1, "The first value needs to be specified");                                      \
    static_assert(sizeof(#b) > 1, "The second value needs to be specified");                                     \
    if ((a) == (b)) {                                                                                            \
        std::cout << "Check \"" << a << " is not equal to " << b << "\"   failed at line " << __LINE__ << " in " \
                  << __FILE__ << "\n";                                                                           \
        state->passed = false;                                                                                   \
    }

#define TOBOT_ASSERT_STR_EQUAL(a, b)                                                                        \
    static_assert(sizeof(#a) > 1, "The first value needs to be specified");                                 \
    static_assert(sizeof(#b) > 1, "The second value needs to be specified");                                \
    if (strcmp(a, b)) {                                                                                     \
        std::cout << "Assertion  \"" << a << " equals " << b << "\"  failed at line " << __LINE__ << " in " \
                  << __FILE__ << "\n";                                                                      \
        state->passed = false;                                                                              \
        return;                                                                                             \
    }

#define TOBOT_EXPECT_STR_EQUAL(a, b)                                                                                \
    static_assert(sizeof(#a) > 1, "The first value needs to be specified");                                         \
    static_assert(sizeof(#b) > 1, "The second value needs to be specified");                                        \
    if (strcmp(a, b)) {                                                                                             \
        std::cout << "Check  \"" << a << " equals " << b << "\"  failed at line " << __LINE__ << " in " << __FILE__ \
                  << "\n";                                                                                          \
        state->passed = false;                                                                                      \
    }

#define TOBOT_ASSERT_STR_NOT_EQUAL(a, b)                                                                           \
    static_assert(sizeof(#a) > 1, "The first value needs to be specified");                                        \
    static_assert(sizeof(#b) > 1, "The second value needs to be specified");                                       \
    if (!strcmp(a, b)) {                                                                                           \
        std::cout << "Assertion \"" << a << " is not equal to " << b << "\" failed at line " << __LINE__ << " in " \
                  << __FILE__ << "\n";                                                                             \
        state->passed = false;                                                                                     \
        return;                                                                                                    \
    }

#define TOBOT_EXPECT_STR_NOT_EQUAL(a, b)                                                                         \
    static_assert(sizeof(#a) > 1, "The first value needs to be specified");                                      \
    static_assert(sizeof(#b) > 1, "The second value needs to be specified");                                     \
    if (!strcmp(a, b)) {                                                                                         \
        std::cout << "Check  \"" << a << " is not equal to " << b << "\"  failed at line " << __LINE__ << " in " \
                  << __FILE__ << "\n";                                                                           \
        state->passed = false;                                                                                   \
    }

} // namespace Tobot::Tooling::Test
