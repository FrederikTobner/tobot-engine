/**
 * @file test_state.h
 * @brief File containing declarations regarding a TestState.
 */

#pragma once

namespace Tobot::Tooling::Test {
    /// @brief Used to store the state of a test
    class TestState {
        public:
            /// @brief Constructor of the TestState class
            TestState();
            /// @brief Destructor of the TestState class
            ~TestState();
            /// @brief
            bool passed;
    };

} // namespace Tobot::Tooling::Test