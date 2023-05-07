#include <gtest/gtest.h>

#include "tobot_test.hpp"

using namespace Tobot::Tooling::Test;

TOBOT_TEST(testState, fails) {
    TOBOT_ASSERT_TRUE(false);
}

TOBOT_TEST(testState, passes) {
    TOBOT_ASSERT_TRUE(true);
}

TEST(testState, CanFail) {
    TestCase testCase(tobot_testState_fails_test, "fails");
    TestReport report(testCase);
    ASSERT_FALSE(report.state->passed);
}

TEST(testState, CanPass) {
    TestCase testCase(tobot_testState_passes_test, "passes");
    TestReport report(testCase);
    ASSERT_TRUE(report.state->passed);
}