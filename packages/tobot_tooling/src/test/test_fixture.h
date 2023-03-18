#pragma once

#include "test_case.h"
#include "test_report_processor.h"

#include <queue>
#include <vector>

namespace Tobot::Tooling::Test {

    class TestFixture {
        private:
            std::queue<TestCase> testQueue;
            char const * fixtureName;

        public:
            TestFixture(char const * fixtureName);
            ~TestFixture();
            void addTestCase(TestCase test);
            void addTestCases(const std::vector<TestCase> & cases);
            void runTestCases(TestReportProcessor & processor);
    };
} // namespace Tobot::Tooling::Test