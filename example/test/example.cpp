#include "tobot_tooling.h"

TOBOT_TEST(example, first) {
    EXPECT_TRUE(false)
    ASSERT_TRUE(true)
}

int main(int argc, char const ** argv) {
    int result = 0;
    tobot_testexample_first(&result);
    if (result) {
        std::cerr << "Test failed" << std::endl;
    }
    return 0;
}
