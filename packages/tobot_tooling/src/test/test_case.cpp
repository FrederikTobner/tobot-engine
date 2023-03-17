#include "test_case.h"

using namespace Tobot::Tooling::Test;

TestCase::TestCase(void (*test_function)(TestState * state), std::string const & testName) : testName(testName) {
    this->testFunction = test_function;
}

TestCase::~TestCase() {
}