#include <gtest/gtest.h>

#include "vector/vector2d.h"

/*
 * Testing vector creation
 */
TEST(Vector2D, CanBeCreatedWithList) {
    Tobot::Math::Vector2D<> vector = {1.0, 2.0};
}

/*
 * Testing copy constructor
 */
TEST(Vector2D, Copy) {
    Tobot::Math::Vector2D<> firstVector(5.0, 3.0);
    Tobot::Math::Vector2D<> secondVector(firstVector);

    EXPECT_EQ(5, secondVector.x);
    EXPECT_EQ(3, secondVector.y);
}

/*
 * Testing simple vector addition
 */
TEST(Vector2D, Addition) {
    Tobot::Math::Vector2D<> vector1(5.0, 3.0);
    Tobot::Math::Vector2D<> vector2(4.0, 2.0);

    Tobot::Math::Vector2D<> result = vector1 + vector2;

    EXPECT_EQ(9, result.x);
    EXPECT_EQ(5, result.y);
}

/*
 * Testing vector addition assignment
 */
TEST(Vector2D, AdditionAssignment) {
    Tobot::Math::Vector2D<> vector1(5.0, 3.0);
    Tobot::Math::Vector2D<> vector2(4.0, 2.0);

    vector1 += vector2;

    EXPECT_EQ(9, vector1.x);
    EXPECT_EQ(5, vector1.y);
}

/*
 * Testing simple vector subtraction
 */
TEST(Vector2D, Subtraction) {
    Tobot::Math::Vector2D<> vector1(5.0, 4.0);
    Tobot::Math::Vector2D<> vector2(4.0, 2.0);

    Tobot::Math::Vector2D<> result = vector1 - vector2;

    EXPECT_EQ(1, result.x);
    EXPECT_EQ(2, result.y);
}

/*
 * Testing vector subtraction assignment
 */
TEST(Vector2D, SubtractionAssignment) {
    Tobot::Math::Vector2D<> vector1(5.0, 4.0);
    Tobot::Math::Vector2D<> vector2(4.0, 2.0);

    vector1 -= vector2;

    EXPECT_EQ(1, vector1.x);
    EXPECT_EQ(2, vector1.y);
}

/*
 * Testing simple vector multiplication
 */
TEST(Vector2D, Multiplication) {
    Tobot::Math::Vector2D<> vector1(5.0, 4.0);

    Tobot::Math::Vector2D<> result = vector1 * 3.0;

    EXPECT_EQ(15, result.x);
    EXPECT_EQ(12, result.y);
}

/*
 * Testing vector multiplication assignment
 */
TEST(Vector2D, MultiplicationAssignment) {
    Tobot::Math::Vector2D<> vector1(5.0, 4.0);

    vector1 *= 3.0;

    EXPECT_EQ(15.0, vector1.x);
    EXPECT_EQ(12.0, vector1.y);
}

/*
 * Testing simple vector division
 */
TEST(Vector2D, Division) {
    Tobot::Math::Vector2D<> vector1(9.0, 6.0);

    Tobot::Math::Vector2D<> result = vector1 / 3.0;

    EXPECT_EQ(3.0, result.x);
    EXPECT_EQ(2.0, result.y);
}

/*
 * Testing vector division assignment
 */
TEST(Vector2D, DivisionAssignment) {
    Tobot::Math::Vector2D<> vector1(9.0, 6.0);

    vector1 /= 3.0;

    EXPECT_EQ(3.0, vector1.x);
    EXPECT_EQ(2.0, vector1.y);
}

/*
 * Testing vector equality
 */
TEST(Vector2D, Equality) {
    Tobot::Math::Vector2D<> vector1(5.0, 4.0);
    Tobot::Math::Vector2D<> vector2(5.0, 4.0);
    Tobot::Math::Vector2D<> vector3(4.0, 2.0);
    EXPECT_TRUE(vector1 == vector2);
    EXPECT_FALSE(vector1 == vector3);
}

/*
 * Testing vector inequality
 */
TEST(Vector2D, Inequality) {
    Tobot::Math::Vector2D<> vector1(5.0, 4.0);
    Tobot::Math::Vector2D<> vector2(5.0, 4.0);
    Tobot::Math::Vector2D<> vector3(4.0, 2.0);
    EXPECT_FALSE(vector1 != vector2);
    EXPECT_TRUE(vector1 != vector3);
}

/*
 * Testing vector magnitude
 */
TEST(Vector2D, Magnitude) {
    Tobot::Math::Vector2D<> leVector(4.0, 3.0);
    EXPECT_EQ(5, leVector.Magnitude());
}

/*
 * Testing vector normalization
 */
TEST(Vector2D, Normalize) {
    Tobot::Math::Vector2D<> leVector(4.0, 3.0);
    leVector.Normalize();
    EXPECT_EQ(1.0, leVector.Magnitude());
}

/*
 * Testing vector dot product
 */
TEST(Vector2D, DotProduct) {
    Tobot::Math::Vector2D<> vector1(5.0, 4.0);
    Tobot::Math::Vector2D<> vector2(4.0, 2.0);

    EXPECT_EQ(28, vector1.Dot(vector2));
}

/**
 * Testing vector cross product
 */
TEST(Vector2D, CrossProduct) {
    Tobot::Math::Vector2D<> vector1(5.0, 4.0);
    Tobot::Math::Vector2D<> vector2(4.0, 2.0);

    Tobot::Math::Vector2D<> result = vector1.Cross(vector2);

    EXPECT_EQ(0.0, result.x);
    EXPECT_EQ(-6.0, result.y);
}
