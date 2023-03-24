/**
 * @file test_report_processor.h
 * @brief File containing declarations regarding a TestReportProcessor.
 */

#pragma once

#include "test_report.h"
#include <string>

namespace Tobot::Tooling::Test {
    class TestReportProcessor {
        private:
        public:
            /// The Constructor of the TestReportProcessor class
            TestReportProcessor();
            /// @brief Virtual Destructor of the TestReportProcessor
            virtual ~TestReportProcessor();
            /// @brief Handles an incoming TestReport from a TestCase
            /// @param report The report that is handled
            /// @param totalNumberOfTests The amount of tests that will be executed (REFACTOR!)
            /// @param fixtureName The name of the fixture the testcase belongs to
            virtual void handleTestReport(TestReport report, size_t totalNumberOfTests,
                                          std::string const & fixtureName) = 0;
            /// @brief Prehandles an incoming TestReport from a TestCase
            /// @param test The underlying TestCase
            /// @param totalNumberOfTests The amount of tests that will be executed (REFACTOR!)
            /// @param fixtureName The name of the fixture the testcase belongs to
            virtual void preHandleTestReport(TestCase test, size_t totalNumberOfTests,
                                             std::string const & fixtureName) = 0;
    };

} // namespace Tobot::Tooling::Test
