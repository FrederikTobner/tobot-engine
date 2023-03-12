/**
 * @file tobot_test.h
 * @brief Contains test macro's
 */

#pragma once

namespace Tobot::Tooling::Test {
#define TOBOT_TEST(testsuiteName, testName, ...) void test_##testsuiteName##_##testName##(int * result)

#define ASSERT_TRUE(condition)                                                                   \
    if (!condition) {                                                                            \
        std::cout << "Assertion failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        *result = -1;                                                                            \
        return;                                                                                  \
    }

#define EXPECT_TRUE(condition)                                                               \
    if (!condition) {                                                                        \
        std::cout << "Check failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        *result = -1;                                                                        \
    }

#define ASSERT_EQUAL(a, b)                                                                       \
    if (a != b) {                                                                                \
        std::cout << "Assertion failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        *result = -1;                                                                            \
        return;                                                                                  \
    }
#define EXPECT_EQUAL(a, b)                                                                   \
    if (a != b) {                                                                            \
        std::cout << "Check failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        *result = -1;                                                                        \
    }
#define ASSERT_STREQUAL(a, b)                                                                    \
    if (strcmp(a, b)) {                                                                          \
        std::cout << "Assertion failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        *result = -1;                                                                            \
        return;                                                                                  \
    }
#define EXPECT_STREQUAL(a, b)                                                                \
    if (strcmp(a, b)) {                                                                      \
        std::cout << "Check failed at line " << __LINE__ << " in " << __FILE__ << std::endl; \
        *result = -1;                                                                        \
    }

} // namespace Tobot::Tooling::Test
