#pragma once

#include "../test_fixture.h"

namespace Tobot::Tooling::Test {
    class TestRunner {
        private:
        public:
            /// @brief Constructor of the Testrunner class
            /// @param processor The testreportprocessor that handles the testreports
            TestRunner();
            /// Destructor of the TestRunner class
            virtual ~TestRunner();
            /// @brief Adds a new TestFixture to the the runner
            /// @param fixture The fixture that is added
            virtual void addFixture(TestFixture fixture) = 0;
            /// @brief Executes all the TestCase's that are stored in the TestFixture's that this TestRunner will
            /// execute
            virtual void runAll() = 0;
    };
} // namespace Tobot::Tooling::Test