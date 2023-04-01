#include <gtest/gtest.h>

#include "vector/vector2d.h"

/*
 * Testing simple vector addition
 */
TEST(Vector2D, Addition) {
    Tobot::Math::Vector2D<int> vector1(5, 3);
    Tobot::Math::Vector2D<int> vector2(4, 2);

    Tobot::Math::Vector2D<int> result = vector1 + vector2;

    EXPECT_EQ(9, result.x);
    EXPECT_EQ(5, result.y);
}

/*
 * Testing vector addition assignment
 */
TEST(Vector2D, AdditionAssignment) {
    Tobot::Math::Vector2D<int> vector1(5, 3);
    Tobot::Math::Vector2D<int> vector2(4, 2);

    vector1 += vector2;

    EXPECT_EQ(9, vector1.x);
    EXPECT_EQ(5, vector1.y);
}

/*
 * Testing simple vector subtraction
 */
TEST(Vector2D, Subtraction) {
    Tobot::Math::Vector2D<int> vector1(5, 4);
    Tobot::Math::Vector2D<int> vector2(4, 2);

    Tobot::Math::Vector2D<int> result = vector1 - vector2;

    EXPECT_EQ(1, result.x);
    EXPECT_EQ(2, result.y);
}

/*
 * Testing vector subtraction assignment
 */
TEST(Vector2D, SubtractionAssignment) {
    Tobot::Math::Vector2D<int> vector1(5, 4);
    Tobot::Math::Vector2D<int> vector2(4, 2);

    vector1 -= vector2;

    EXPECT_EQ(1, vector1.x);
    EXPECT_EQ(2, vector1.y);
}

/*
 * Testing simple vector multiplication
 */
TEST(Vector2D, Multiplication) {
    Tobot::Math::Vector2D<int> vector1(5, 4);

    Tobot::Math::Vector2D<int> result = vector1 * 3;

    EXPECT_EQ(15, result.x);
    EXPECT_EQ(12, result.y);
}

/*
 * Testing vector multiplication assignment
 */
TEST(Vector2D, MultiplicationAssignment) {
    Tobot::Math::Vector2D<int> vector1(5, 4);

    vector1 *= 3;

    EXPECT_EQ(15, vector1.x);
    EXPECT_EQ(12, vector1.y);
}

/*
 * Testing simple vector division
 */
TEST(Vector2D, Division) {
    Tobot::Math::Vector2D<int> vector1(9, 6);

    Tobot::Math::Vector2D<int> result = vector1 / 3;

    EXPECT_EQ(3, result.x);
    EXPECT_EQ(2, result.y);
}

/*
 * Testing vector division assignment
 */
TEST(Vector2D, DivisionAssignment) {
    Tobot::Math::Vector2D<int> vector1(9, 6);

    vector1 /= 3;

    EXPECT_EQ(3, vector1.x);
    EXPECT_EQ(2, vector1.y);
}

/*
 * Testing vector magnitude
 */
TEST(Vector2D, Magnitude) {
    Tobot::Math::Vector2D<int> leVector(4, 3);
    EXPECT_EQ(5, leVector.Magnitude());
}

/*
 * Testing vector normalization
 */
TEST(Vector2D, Normalize) {
    Tobot::Math::Vector2D<float> leVector(4.0, 3.0);
    leVector.Normalize();
    EXPECT_EQ(1, leVector.Magnitude());
}

/*
 * Testing vector dot product
 */
TEST(Vector2D, DotProduct) {
    Tobot::Math::Vector2D<int> vector1(5, 4);
    Tobot::Math::Vector2D<int> vector2(4, 2);

    EXPECT_EQ(28, vector1.Dot(vector2));
}

/**
 * Testing vector cross product
 */
TEST(Vector2D, CrossProduct) {
    Tobot::Math::Vector2D<int> vector1(5, 4);
    Tobot::Math::Vector2D<int> vector2(4, 2);

    Tobot::Math::Vector2D<int> result = vector1.Cross(vector2);

    EXPECT_EQ(0, result.x);
    EXPECT_EQ(-6, result.y);
}