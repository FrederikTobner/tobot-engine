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
            char const * fixtureName;

        public:
            /// @brief Constructor of the testfixture Class
            /// @param fixtureName The name of the testfixture
            TestFixture(char const * fixtureName);

            /// Destructor of the testfixture Class
            ~TestFixture();

            /// @brief Adds a new Testcase to the testfixture
            /// @param test The test that is added to the fixture
            void addTestCase(TestCase test);

            /// @brief Adds multiple testcases to the testfixture
            /// @param cases The cases that are added to the fixture
            void addTestCases(const std::vector<TestCase> & cases);

            /// @brief Executes all the tests in the fixture
            /// @param processor The TestReportProcessor that handles all the testreports of the executed testcases
            void runTestCases(TestReportProcessor & processor);
    };
} // namespace Tobot::Tooling::Test