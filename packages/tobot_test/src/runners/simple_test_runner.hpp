/**
 * @file test_runner.h
 * @brief File containing declarations regarding a TestRunner.
 */

#pragma once

#include "../processors/test_report_processor.hpp"
#include "test_runner.hpp"

#include "../pre_compiled_header.hpp"

namespace Tobot::Tooling::Test {
    class SimpleTestRunner : public Tobot::Tooling::Test::TestRunner {

        private:
            /// @brief Queue that stores the TestFixture's the runner will execute
            std::queue<TestFixture> fixtureQueue;
            /// @brief The testreportprocessor that handles the testreports
            TestReportProcessor & processor;

        public:
            /// @brief Constructor of the Testrunner class
            /// @param processor The testreportprocessor that handles the testreports
            SimpleTestRunner(TestReportProcessor & processor);
            /// Destructor of the TestRunner class
            ~SimpleTestRunner();
            /// @brief Copy assignment operator
            /// @param rhs The TestRunner that is copied
            /// @return A reference to the TestRunner that is copied
            auto operator=(SimpleTestRunner const & rhs) -> SimpleTestRunner &;
            /// @brief Adds a new TestFixture to the the runner
            /// @param fixture The fixture that is added
            virtual auto addFixture(TestFixture fixture) -> void;
            /// @brief Executes all the TestCase's that are stored in the TestFixture's that this TestRunner will
            /// execute
            virtual auto runAll() -> void;
    };

} // namespace Tobot::Tooling::Test
