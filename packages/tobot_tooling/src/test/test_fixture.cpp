#include "test_fixture.h"

#include <stdarg.h>

using namespace Tobot::Tooling::Test;

TestFixture::TestFixture(std::string const & fixtureName) : fixtureName(fixtureName) {
}

TestFixture::~TestFixture() {
}

void TestFixture::addTestCase(TestCase testCase) {
    this->testQueue.push(testCase);
}

void TestFixture::addTestCases(const std::vector<TestCase> & cases) {
    for (size_t i = 0; i < cases.size(); ++i) {
        this->testQueue.push(cases[i]);
    }
}

void TestFixture::runTestCases(TestReportProcessor & processor) {
    size_t testCount = this->testQueue.size();
    while (!this->testQueue.empty()) {
        processor.preHandleTestReport(this->testQueue.front(), testCount, this->fixtureName);
        Tobot::Tooling::Test::TestReport testReport(this->testQueue.front());
        processor.handleTestReport(testReport, testCount, this->fixtureName);
        this->testQueue.pop();
    }
}