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

void SimpleTestRunner::addFixture(TestFixture fixture) {
    this->fixtureQueue.push(fixture);
}

void SimpleTestRunner::runAll() {
    size_t testCount = this->fixtureQueue.size();
    while (!this->fixtureQueue.empty()) {
        this->fixtureQueue.front().runTestCases(this->processor);
        this->fixtureQueue.pop();
    }
}

SimpleTestRunner & SimpleTestRunner::operator=(SimpleTestRunner const & rhs) {
    this->fixtureQueue = rhs.fixtureQueue;
    this->processor = rhs.processor;
    return *this;
};