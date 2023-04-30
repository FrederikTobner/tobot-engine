/**
 * @file console_test_report_processor.h
 * @brief File containing declarations regarding a ConsoleTestReportProcessor.
 */

#pragma once

#include "test_report_processor.h"

#include "../pre_compiled_header.h"

namespace Tobot::Tooling::Test {
    class ConsoleTestReportProcessor : public Tobot::Tooling::Test::TestReportProcessor {
        private:
            /// @brief The amount of testcases the testReportProcessor has already executed
            size_t passedTestCounter = 0;
            /// @brief The amount of testcases the testReportProcessor has already executed
            size_t executedTestCounter = 0;
            /// @brief for thread safety
            std::mutex m_mutex;

        public:
            /// @brief Constructor of the ConsoleTestReportProcessor class
            ConsoleTestReportProcessor();
            ///  Destructor of the ConsoleTestReportProcessor class
            ~ConsoleTestReportProcessor();
            /// @brief Handles an incoming TestReport from a TestCase
            /// @param report The report that is handled
            /// @param totalNumberOfTests The amount of tests that will be executed (REFACTOR!)
            /// @param fixtureName The name of the fixture the testcase belongs to
            virtual auto handleTestReport(TestReport report, size_t totalNumberOfTests, std::string const & fixtureName)
                -> void override;
            /// @brief Prehandles an incoming TestReport from a TestCase
            /// @param test The underlying TestCase
            /// @param totalNumberOfTests The amount of tests that will be executed (REFACTOR!)
            /// @param fixtureName The name of the fixture the testcase belongs to
            virtual auto preHandleTestReport(TestCase test, size_t totalNumberOfTests, std::string const & fixtureName)
                -> void override;
    };

} // namespace Tobot::Tooling::Test