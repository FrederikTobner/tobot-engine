#include "tobot_test.hpp"

using namespace Tobot::Tooling::Test;

TOBOT_TEST(example, first) {
    TOBOT_EXPECT_TRUE(1 < 5);
    TOBOT_ASSERT_TRUE(true);
    TOBOT_ASSERT_STR_EQUAL("first", "first");
}

TOBOT_TEST(example, second) {
    TOBOT_EXPECT_TRUE(3 < 1);
    TOBOT_ASSERT_TRUE(1 == 1);
    TOBOT_ASSERT_STR_EQUAL("second", "second");
}

int main(int argc, char const ** argv) {
    ConsoleTestReportProcessor processor;
    SimpleTestRunner runner(processor);
    TestFixture exampleFixture("example");
    // To discover tests automatically we could use ctags or cscope
    TestCase firstTest(tobot_example_first_test, "first");
    TestCase secondTest(tobot_example_second_test, "second");
    exampleFixture.addTestCases({firstTest, secondTest});
    runner.addFixture(exampleFixture);
    runner.runAll();
    return 0;
}
