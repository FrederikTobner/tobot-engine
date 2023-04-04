#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the Pair can be created
 */
TEST(Quadruple, CanBeCreated) {
    Quadruple<int, int, int, int> quadruple(1, 2, 3, 4);
}

/*
 * Tests whether the Pair can be created with different types
 */
TEST(Quadruple, CanBeCreatedWithDifferentTypes) {
    Quadruple<int, char, double, bool> quadruple(1, 'a', 1.0, true);
}

/*
 * Tests the equality operator
 */
TEST(Quadruple, Equality) {
    Quadruple<int, int, int, int> first_quadruple(1, 2, 3, 4);
    Quadruple<int, int, int, int> second_quadruple(1, 2, 3, 4);
    ASSERT_TRUE(first_quadruple == second_quadruple);
}

/*
 * Tests the inequality operator
 */
TEST(Quadruple, Inequality) {
    Quadruple<int, int, int, int> first_quadruple(1, 2, 3, 4);
    Quadruple<int, int, int, int> second_quadruple(1, 2, 3, 5);
    ASSERT_TRUE(first_quadruple != second_quadruple);
}
