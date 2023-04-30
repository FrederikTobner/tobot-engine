/**
 * @file test_fixture.h
 * @brief File containing definitions regarding a TestFixture.
 */

#include "test_fixture.h"

#include "pre_compiled_header.h"

using namespace Tobot::Tooling::Test;

TestFixture::TestFixture(std::string fixtureName) {
    this->fixtureName = fixtureName;
}

TestFixture::~TestFixture() {
}

auto TestFixture::addTestCase(TestCase testCase) -> void {
    this->testQueue.push(testCase);
}

auto TestFixture::addTestCases(std::vector<TestCase> const & cases) -> void {
    for (TestCase testCase : cases) {
        this->testQueue.push(testCase);
    }
}

auto TestFixture::runTestCases(TestReportProcessor & processor) -> void {
    size_t testCount = this->testQueue.size();
    while (!this->testQueue.empty()) {
        processor.preHandleTestReport(this->testQueue.front(), testCount, this->fixtureName);
        Tobot::Tooling::Test::TestReport testReport(this->testQueue.front());
        processor.handleTestReport(testReport, testCount, this->fixtureName);
        this->testQueue.pop();
    }
}