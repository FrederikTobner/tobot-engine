#include <gtest/gtest.h>

#include "tobot_data_structures.h"

using namespace Tobot::DataStructures;

/*
 * Tests whether the Array can be created
 */
TEST(Array, CanBeCreated) {
    Array<int, 3> array;
}

/*
 * Tests whether the Array can be created with initializer list
 */
TEST(Array, CanBeCreatedWithInitializerList) {
    Array<int, 3> array = {1, 2, 3};
}

/*
 * Tests whether the the equality operator works
 */
TEST(Array, EqualsOperator) {
    Array<int, 3> array1 = {1, 2, 3};
    Array<int, 3> array2 = {1, 2, 3};
    Array<int, 3> array3 = {1, 2, 4};
    ASSERT_TRUE(array1 == array2);
    ASSERT_FALSE(array1 == array3);
}

/*
 * Tests whether the the not equals operator works
 */
TEST(Array, NotEqualsOperator) {
    Array<int, 3> array1 = {1, 2, 3};
    Array<int, 3> array2 = {1, 2, 4};
    Array<int, 3> array3 = {1, 2, 3};
    ASSERT_TRUE(array1 != array2);
    ASSERT_FALSE(array1 != array3);
}

/*
 * Tests whether the the index operator works
 */
TEST(Array, IndexOperator) {
    Array<int, 3> array = {1, 2, 3};
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 2);
    ASSERT_EQ(array[2], 3);
}

/*
 * Tests whether the for each loop works
 */
TEST(Array, ForEach) {
    Array<int, 3> array = {1, 2, 3};
    int sum = 0;
    array.ForEach([&sum](int value) { sum += value; });
    ASSERT_EQ(sum, 6);
}