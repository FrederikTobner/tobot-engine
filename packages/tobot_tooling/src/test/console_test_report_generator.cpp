#include "console_test_report_generator.h"

#include <stdio.h>

using namespace Tobot::Tooling::Test;

ConsoleTestReportGenerator::ConsoleTestReportGenerator() {
}

ConsoleTestReportGenerator::~ConsoleTestReportGenerator() {
}

void ConsoleTestReportGenerator::handle_test_report(TestReport report, size_t totalNumberOfTests) {
    std::scoped_lock lock(log_mutex);
    this->executedTestCounter++;
    if (report.state->passed) {
        printf("%zu/%zu Test #%zu: %s.%s Passed!\n", this->executedTestCounter, totalNumberOfTests, totalNumberOfTests,
               report.corresponding_test->testName, report.corresponding_test->groupName);
        this->passedTestCounter++;
    } else {
        fprintf(stderr, "%zu/%zu Test#%zu: %s.%s Failed!\n", this->executedTestCounter, totalNumberOfTests,
                totalNumberOfTests, report.corresponding_test->testName, report.corresponding_test->groupName);
    }
}

void ConsoleTestReportGenerator::handle_pre_test_report(Test test, size_t totalNumberOfTests) {
    std::scoped_lock lock(log_mutex);
    printf("Start %zu: %s.%s\n", this->executedTestCounter + 1, test.testName, test.groupName);
}