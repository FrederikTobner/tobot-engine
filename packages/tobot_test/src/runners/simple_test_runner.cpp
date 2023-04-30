/**
 * @file test_runner.cpp
 * @brief File containing definitions regarding a TestRunner.
 */

#include "simple_test_runner.h"

#include "../test_report.h"

#include <iostream>
#include <stdio.h>

using namespace Tobot::Tooling::Test;

SimpleTestRunner::SimpleTestRunner(TestReportProcessor & processor) : processor(processor) {
}

SimpleTestRunner::~SimpleTestRunner() {
}

auto SimpleTestRunner::addFixture(TestFixture fixture) -> void {
    this->fixtureQueue.push(fixture);
}

auto SimpleTestRunner::runAll() -> void {
    size_t testCount = this->fixtureQueue.size();
    while (!this->fixtureQueue.empty()) {
        this->fixtureQueue.front().runTestCases(this->processor);
        this->fixtureQueue.pop();
    }
}

auto SimpleTestRunner::operator=(SimpleTestRunner const & rhs) -> SimpleTestRunner & {
    this->fixtureQueue = rhs.fixtureQueue;
    this->processor = rhs.processor;
    return *this;
};