#pragma once

#include "test_report.h"
#include <string>

namespace Tobot::Tooling::Test {
    class TestReportProcessor {
        private:
        public:
            TestReportProcessor();
            virtual ~TestReportProcessor();
            virtual void handleTestReport(TestReport report, size_t totalNumberOfTests,
                                          std::string const & fixtureName) = 0;
            virtual void preHandleTestReport(TestCase test, size_t totalNumberOfTests,
                                             std::string const & fixtureName) = 0;
    };

} // namespace Tobot::Tooling::Test