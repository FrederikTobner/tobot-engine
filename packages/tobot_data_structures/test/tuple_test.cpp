#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

TEST(Tuple, CanBeCreated) {
    Tuple<int, int> tuple(1, 2);
}

TEST(Tuple, CanBeCreatedWithDifferentTypes) {
    Tuple<int, char> tuple(1, 'a');
}