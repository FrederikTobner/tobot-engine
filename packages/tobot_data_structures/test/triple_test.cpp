#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the Pair can be created
 */
TEST(Triple, CanBeCreated) {
    Triple<int, int, int> triple(1, 2, 3);
}

/*
 * Tests whether the Pair can be created with different types
 */
TEST(Triple, CanBeCreatedWithDifferentTypes) {
    Triple<int, char, double> triple(1, 'a', 1.0);
}

/*
 * Tests the equality operator
 */
TEST(Triple, Equality) {
    Triple<int, int, int> first_triple(1, 2, 3);
    Triple<int, int, int> second_triple(1, 2, 3);
    ASSERT_TRUE(first_triple == second_triple);
}

/*
 * Tests the inequality operator
 */
TEST(Triple, Inequality) {
    Triple<int, int, int> first_triple(1, 2, 3);
    Triple<int, int, int> second_triple(1, 2, 4);
    ASSERT_TRUE(first_triple != second_triple);
}