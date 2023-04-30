/**
 * @file test_fixture.cpp
 * @brief File containing definitions regarding a TestFixture.
 */

#pragma once

#include "processors/test_report_processor.h"
#include "test_case.h"

#include "pre_compiled_header.h"

namespace Tobot::Tooling::Test {

    class TestFixture {
        private:
            /// @brief Queue that holds all the testcases that the testfixture contains
            std::queue<TestCase> testQueue;

            /// @brief The name of the fixture
            std::string fixtureName;

        public:
            /// @brief Constructor of the testfixture Class
            /// @param fixtureName The name of the testfixture
            TestFixture(std::string fixtureName);

            /// Destructor of the testfixture Class
            ~TestFixture();

            /// @brief Adds a new Testcase to the testfixture
            /// @param test The test that is added to the fixture
            auto addTestCase(TestCase test) -> void;

            /// @brief Adds multiple testcases to the testfixture
            /// @param cases The cases that are added to the fixture
            auto addTestCases(std::vector<TestCase> const & cases) -> void;

            /// @brief Executes all the tests in the fixture
            /// @param processor The TestReportProcessor that handles all the testreports of the executed testcases
            auto runTestCases(TestReportProcessor & processor) -> void;
    };
} // namespace Tobot::Tooling::Test