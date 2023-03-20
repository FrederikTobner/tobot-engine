/**
 * @file test_runner.cpp
 * @brief File containing definitions regarding a TestRunner.
 */

#include "test_runner.h"

#include "test_report.h"

#include "stdio.h"

using namespace Tobot::Tooling::Test;

TestRunner::TestRunner(TestReportProcessor & processor) : processor(processor) {
}

TestRunner::~TestRunner() {
}

void TestRunner::addFixture(TestFixture fixture) {
    this->fixtureQueue.push(fixture);
}

void TestRunner::runAll() {
    size_t testCount = this->fixtureQueue.size();
    while (!this->fixtureQueue.empty()) {
        this->fixtureQueue.front().runTestCases(this->processor);
        this->fixtureQueue.pop();
    }
}