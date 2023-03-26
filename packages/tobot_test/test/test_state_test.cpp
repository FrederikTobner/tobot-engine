#include <gtest/gtest.h>

#include "tobot_test.h"

using namespace Tobot::Tooling::Test;

TBTT_TEST(testState, fails) {
    TBTT_ASSERT_TRUE(false);
}

TBTT_TEST(testState, passes) {
    TBTT_ASSERT_TRUE(true);
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