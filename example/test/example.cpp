#include "tobot_test.h"

using namespace Tobot::Tooling::Test;

TBTT_TEST(example, first) {
    TBTT_EXPECT_TRUE(1 < 5);
    TBTT_ASSERT_TRUE(true);
    TBTT_ASSERT_STR_EQUAL("first", "first");
}

TBTT_TEST(example, second) {
    TBTT_EXPECT_TRUE(3 < 1);
    TBTT_ASSERT_TRUE(1 == 1);
    TBTT_ASSERT_STR_EQUAL("second", "second");
}

int main(int argc, char const ** argv) {
    ConsoleTestReportProcessor processor;
    SimpleTestRunner runner(processor);
    TestFixture exampleFixture("example");
    TestCase firstTest(tobot_example_first_test, "first");
    TestCase secondTest(tobot_example_second_test, "second");
    exampleFixture.addTestCases({firstTest, secondTest});
    runner.addFixture(exampleFixture);
    runner.runAll();
    return 0;
}
