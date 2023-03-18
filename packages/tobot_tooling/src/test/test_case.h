#pragma once

#include "test_state.h"
#include <string>

namespace Tobot::Tooling::Test {
    class TestCase {
        public:
            char const * testName;
            void (*testFunction)(TestState * state);
            TestCase(void (*test_function)(TestState * state), char const * testName);
            ~TestCase();
    };

} // namespace Tobot::Tooling::Test