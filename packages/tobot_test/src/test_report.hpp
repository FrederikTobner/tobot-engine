/**
 * @file test_report.h
 * @brief File containing declarations regarding a TestReport.
 */

#pragma once

#include "test_case.hpp"
#include "test_state.hpp"

namespace Tobot::Tooling::Test {
    class TestReport {
        public:
            /// @brief The test the report corresponds to
            TestCase & correspondingTest;
            /// @brief The TestState of the testcase
            TestState * state;
            /// @brief Creates a new testreport by executing the correspondingTest
            /// @param correspondingTest  The test the report corresponds to
            TestReport(TestCase & correspondingTest);
            /// Destructor of the TestReport class
            ~TestReport();
    };

} // namespace Tobot::Tooling::Test
