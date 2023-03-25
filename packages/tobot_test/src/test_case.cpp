/**
 * @file test_case.cpp
 * @brief File containing definitions regarding a TestCase.
 */

#include "test_case.h"

using namespace Tobot::Tooling::Test;

TestCase::TestCase(void (*test_function)(TestState * state), char const * testName) {
    this->testName = testName;
    this->test_function = test_function;
}

TestCase::~TestCase() {
}