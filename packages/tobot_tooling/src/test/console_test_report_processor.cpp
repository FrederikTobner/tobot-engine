#include "console_test_report_processor.h"

#include <stdio.h>

using namespace Tobot::Tooling::Test;

ConsoleTestReportProcessor::ConsoleTestReportProcessor() {
}

ConsoleTestReportProcessor::~ConsoleTestReportProcessor() {
    printf("\n%g%% tests passed, %zu tests failed of %zu\n",
           100.0 * this->passedTestCounter / this->executedTestCounter,
           this->executedTestCounter - this->passedTestCounter, this->executedTestCounter);
}

void ConsoleTestReportProcessor::handleTestReport(TestReport report, size_t totalNumberOfTests,
                                                  std::string const & fixtureName) {
    std::scoped_lock lock(m_mutex);
    this->executedTestCounter++;
    if (report.state->passed) {
        printf("%zu/%zu Test #%zu: %s.%s\t Passed ...\n", this->executedTestCounter, totalNumberOfTests,
               this->executedTestCounter, fixtureName.c_str(), report.correspondingTest.testName);
        this->passedTestCounter++;
    } else {
        printf("%zu/%zu Test#%zu: %s.%s\t Failed ...\n", this->executedTestCounter, totalNumberOfTests,
               this->executedTestCounter, fixtureName.c_str(), report.correspondingTest.testName);
    }
}

void ConsoleTestReportProcessor::preHandleTestReport(TestCase test, size_t totalNumberOfTests,
                                                     std::string const & fixtureName) {
    std::scoped_lock lock(m_mutex);
    printf("Start %zu: %s.%s\n", this->executedTestCounter + 1, fixtureName.c_str(), test.testName);
}