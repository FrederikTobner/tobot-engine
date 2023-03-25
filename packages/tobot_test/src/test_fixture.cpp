/**
 * @file test_fixture.h
 * @brief File containing definitions regarding a TestFixture.
 */

#include "test_fixture.h"

#include "pre_compiled_header.h"

using namespace Tobot::Tooling::Test;

TestFixture::TestFixture(char const * fixtureName) {
    this->fixtureName = fixtureName;
}

TestFixture::~TestFixture() {
}

void TestFixture::addTestCase(TestCase testCase) {
    this->testQueue.push(testCase);
}

void TestFixture::addTestCases(const std::vector<TestCase> & cases) {
    for (TestCase testCase : cases) {
        this->testQueue.push(testCase);
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