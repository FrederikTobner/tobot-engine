#pragma once

namespace Tobot::Tooling::Test {
    #define TOBOT_TEST(testsuiteName, testName, ...) \
    void tobot_test##testsuiteName##_##testName##(int * result)    
    
    #define ASSERT_TRUE(condition) \
    if(!condition) {\
        std::cout << "Assertion failed";\
        *result = -1;\
        return;\
    }
    #define EXPECT_TRUE(condition) \
    if(!condition) \
        *result = -1;
}