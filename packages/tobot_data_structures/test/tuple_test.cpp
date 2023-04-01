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