#include "tobot_tooling.h"

TOBOT_TEST(example, first) {
    EXPECT_TRUE(false)
    ASSERT_TRUE(true)
    ASSERT_STREQUAL("test", "test")
}

int main(int argc, char const ** argv) {
    int result = 0;
    test_example_first(&result);
    if (result) {
        return -1;
    }
    return 0;
}
