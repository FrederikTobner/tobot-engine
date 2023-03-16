#include "tobot_tooling.h"

using namespace Tobot::Tooling::Test;

TOBOT_TEST(example, first) {
    EXPECT_TRUE(1 < 5);
    ASSERT_TRUE(true);
    ASSERT_STREQUAL("first", "first");
}

TOBOT_TEST(example, second) {
    EXPECT_TRUE(3 > 1);
    ASSERT_TRUE(1 == 1);
    ASSERT_STREQUAL("second", "second");
}

int main(int argc, char const ** argv) {
    ConsoleTestReportProcessor processor;
    TestRunner runner(processor);
    TestFixture exampleFixture("example");
    TestCase firstTest(test_example_first, "first");
    TestCase secondTest(test_example_second, "second");
    exampleFixture.addTestCases({firstTest, secondTest});
    runner.addFixture(exampleFixture);
    runner.runAll();
    return 0;
}
