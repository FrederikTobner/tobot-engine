#include <gtest/gtest.h>

#include "tobot_data_structures.h"

TOBOT_ENUM(Number, ONE, TWO, THREE)

/*
 * Tests whether an object of of the class we generated with the ENUM_CLASS macro can be created
 */
TEST(ENUM, CanBeCreated) {
    Number number = Number::ONE;
}

/*
 * Tests whether we can get all the values of the enum
 */
TEST(ENUM, CanReturnAllValues) {
    Number::Enum const * const values = Number::values();
    ASSERT_EQ(values[0], Number::ONE);
    ASSERT_EQ(values[1], Number::TWO);
    ASSERT_EQ(values[2], Number::THREE);
}

/*
 * Tests whether the size of the enum is correct
 */
TEST(Enum, SizeIsCorrect) {
    ASSERT_EQ(Number::size(), 3);
}

/*
 * Tests the equality operator
 */
TEST(Enum, EqualityOperator) {
    Number number1 = Number::ONE;
    Number number2 = Number::TWO;
    Number number3 = Number::ONE;
    ASSERT_FALSE(number1 == number2);
    ASSERT_TRUE(number1 == number3);
}

/*
 * Tests the inequality operator
 */
TEST(Enum, InequalityOperator) {
    Number number1 = Number::ONE;
    Number number2 = Number::TWO;
    Number number3 = Number::ONE;
    ASSERT_TRUE(number1 != number2);
    ASSERT_FALSE(number1 != number3);
}

/*
 * Tests whether the enum can be converted to a string
 */
TEST(Enum, CanBeConvertedToString) {
    ASSERT_EQ(Number::toString(), "Number");
}

/*
 * Tests whether the enum can be retrieved by index
 */
TEST(Enum, CanBeRetrievedByIndex) {
    ASSERT_EQ(Number::get(0), Number::ONE);
    ASSERT_EQ(Number::get(1), Number::TWO);
    ASSERT_EQ(Number::get(2), Number::THREE);
}

/*
 * Tests whether the enum ordinal is correct
 */
TEST(Enum, OrdinalIsCorrect) {
    Number number = Number::Enum::ONE;
    ASSERT_EQ(number.ordinal(), 0);
}

/*
 * Tests whether the enum can be iterated over
 */
TEST(Enum, CanBeIteratedOver) {
    std::vector<Number::Enum> values;
    for (auto it = Number::begin(); it != Number::end(); ++it) {
        values.push_back(*it);
    }
    ASSERT_EQ(values[0], Number::ONE);
    ASSERT_EQ(values[1], Number::TWO);
    ASSERT_EQ(values[2], Number::THREE);
}