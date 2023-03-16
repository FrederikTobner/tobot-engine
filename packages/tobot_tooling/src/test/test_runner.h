#pragma once

#include "test_fixture.h"
#include "test_report_processor.h"

#include <iostream>
#include <queue>

namespace Tobot::Tooling::Test {
    class TestRunner {

        private:
            std::queue<TestFixture> fixtureQueue;
            TestReportProcessor & processor;

        public:
            TestRunner(TestReportProcessor & processor);
            ~TestRunner();
            void addFixture(TestFixture fixture);
            void runAll();
            TestRunner & operator=(const TestRunner & rhs){};
    };

} // namespace Tobot::Tooling::Test
