#pragma once

#include "test_report_processor.h"

#include <mutex>

namespace Tobot::Tooling::Test {
    class ConsoleTestReportProcessor : public Tobot::Tooling::Test::TestReportProcessor {
        private:
            size_t passedTestCounter = 0;
            size_t executedTestCounter = 0;
            /// @brief for thread safety
            std::mutex m_mutex;

        public:
            ConsoleTestReportProcessor();
            ~ConsoleTestReportProcessor();
            virtual void handleTestReport(TestReport report, size_t totalNumberOfTests,
                                          char const * fixtureName) override;
            virtual void preHandleTestReport(TestCase test, size_t totalNumberOfTests,
                                             char const * fixtureName) override;
    };

} // namespace Tobot::Tooling::Test