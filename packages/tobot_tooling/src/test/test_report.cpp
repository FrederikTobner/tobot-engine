#include "test_report.h"

using namespace Tobot::Tooling::Test;

TestReport::TestReport(TestCase & correspondingTest) : correspondingTest(correspondingTest) {
    this->state = new TestState();
    this->correspondingTest.testFunction(state);
}

TestReport::~TestReport() {
}