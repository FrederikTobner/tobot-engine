#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the Pair can be created
 */
TEST(Pair, CanBeCreated) {
    Pair<int, int> pair(1, 2);
}

/*
 * Tests whether the Pair can be created with different types
 */
TEST(Pair, CanBeCreatedWithDifferentTypes) {
    Pair<int, char> pair(1, 'a');
}

/*
 * Tests whether the Pair can be created with initializer list
 */
TEST(Pair, Equality) {
    Pair<int, int> first_pair(1, 2);
    Pair<int, int> second_pair(1, 2);
    ASSERT_TRUE(first_pair == second_pair);
}