#pragma once

#include "test_case.h"
#include "test_state.h"

namespace Tobot::Tooling::Test {
    class TestReport {
        public:
            TestCase & correspondingTest;
            TestState * state;
            TestReport(TestCase & correspondingTest);
            ~TestReport();
    };

} // namespace Tobot::Tooling::Test
