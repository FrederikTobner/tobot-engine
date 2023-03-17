#pragma once

#include "test_case.h"
#include "test_report_processor.h"

#include <queue>
#include <vector>

namespace Tobot::Tooling::Test {

    class TestFixture {
        private:
            std::queue<TestCase> testQueue;
            std::string const & fixtureName;

        public:
            TestFixture(std::string const & fixtureName);
            ~TestFixture();
            void addTestCase(TestCase test);
            void addTestCases(const std::vector<TestCase> & cases);
            void runTestCases(TestReportProcessor & processor);
    };
} // namespace Tobot::Tooling::Test