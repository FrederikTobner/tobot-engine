/**
 * @file test_case.h
 * @brief File containing declarations regarding a TestCase.
 */

#pragma once

#include "test_state.hpp"
#include <string>

namespace Tobot::Tooling::Test {
    class TestCase {
        public:
            /// @brief The name of the testcase
            std::string testName;
            /// @brief Function pointer to the underlying test function
            void (*testFunction)(TestState * state);

            /// @brief Constructor of the TestCase class
            /// @param testFunction Function pointer to the underlying test function
            /// @param testName  The name of the testcase
            TestCase(void (*testFunction)(TestState * state), std::string testName);

            /// Destructor of the TestCase class
            ~TestCase();
    };

} // namespace Tobot::Tooling::Test