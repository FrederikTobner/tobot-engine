/**
 * @file test_runner.h
 * @brief File containing declarations regarding a TestRunner.
 */

#pragma once

#include "test_fixture.h"
#include "test_report_processor.h"

#include <iostream>
#include <queue>

namespace Tobot::Tooling::Test {
    class TestRunner {

        private:
            /// @brief Queue that stores the TestFixture's the runner will execute
            std::queue<TestFixture> fixtureQueue;
            /// @brief The testreportprocessor that handles the testreports
            TestReportProcessor & processor;

        public:
            /// @brief Constructor of the Testrunner class
            /// @param processor The testreportprocessor that handles the testreports
            TestRunner(TestReportProcessor & processor);
            /// Destructor of the TestRunner class
            ~TestRunner();
            /// @brief Adds a new TestFixture to the the runner
            /// @param fixture The fixture that is added
            void addFixture(TestFixture fixture);
            /// @brief Executes all the TestCase's that are stored in the TestFixture's that this TestRunner will
            /// execute
            void runAll();
            TestRunner & operator=(const TestRunner & rhs){};
    };

} // namespace Tobot::Tooling::Test
