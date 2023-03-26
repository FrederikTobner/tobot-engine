/**
 * @file test_case.cpp
 * @brief File containing definitions regarding a TestCase.
 */

#include "test_case.h"

using namespace Tobot::Tooling::Test;

TestCase::TestCase(void (*testFunction)(TestState * state), char const * testName) {
    this->testName = testName;
    this->testFunction = testFunction;
}

TestCase::~TestCase() {
}