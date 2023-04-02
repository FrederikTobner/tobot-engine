#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the Tuple can be created
 */
TEST(Tuple, CanBeCreated) {
    Tuple<int, int> tuple(1, 2);
}

/*
 * Tests whether the Tuple can be created with different types
 */
TEST(Tuple, CanBeCreatedWithDifferentTypes) {
    Tuple<int, char> tuple(1, 'a');
}

/*
 * Tests whether the Tuple can be created with initializer list
 */
TEST(Tuple, Equality) {
    Tuple<int, int> tuple1(1, 2);
    Tuple<int, int> tuple2(1, 2);
    ASSERT_TRUE(tuple1 == tuple2);
}