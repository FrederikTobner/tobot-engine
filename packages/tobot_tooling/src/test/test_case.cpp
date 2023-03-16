#include "test_case.h"

using namespace Tobot::Tooling::Test;

TestCase::TestCase(void (*test_function)(TestState * state), char const * testName) {
    this->testFunction = test_function;
    this->testName = testName;
}

TestCase::~TestCase() {
}