#include <gtest/gtest.h>

#include "vector/vector2d.h"

using namespace Tobot::Math;

/*
 * Testing vector creation
 */
TEST(Vector2D, CanBeCreatedWithList) {
    Vector2D<> vector = {1.0, 2.0};
}

/*
 * Testing copy constructor
 */
TEST(Vector2D, Copy) {
    Vector2D<> firstVector(5.0, 3.0);
    Vector2D<> secondVector(firstVector);

    firstVector = {4.0, 5.0};

    EXPECT_EQ(5, secondVector.getX());
    EXPECT_EQ(3, secondVector.getY());
}

/*
 * Testing move constructor
 */
TEST(Vector2D, Move) {
    Vector2D<> firstVector(5.0, 3.0);
    Vector2D<> secondVector(std::move(firstVector));

    firstVector = {4.0, 5.0};

    EXPECT_EQ(5, secondVector.getX());
    EXPECT_EQ(3, secondVector.getY());
}

/*
 * Testing simple vector addition
 */
TEST(Vector2D, Addition) {
    Vector2D<> vector1(5.0, 3.0);
    Vector2D<> vector2(4.0, 2.0);

    Vector2D<> result = vector1 + vector2;

    EXPECT_EQ(9, result.getX());
    EXPECT_EQ(5, result.getY());
}

/*
 * Testing vector addition assignment
 */
TEST(Vector2D, AdditionAssignment) {
    Vector2D<> vector1(5.0, 3.0);
    Vector2D<> vector2(4.0, 2.0);

    vector1 += vector2;

    EXPECT_EQ(9, vector1.getX());
    EXPECT_EQ(5, vector1.getY());
}

/*
 * Testing simple vector subtraction
 */
TEST(Vector2D, Subtraction) {
    Vector2D<> vector1(5.0, 4.0);
    Vector2D<> vector2(4.0, 2.0);

    Vector2D<> result = vector1 - vector2;

    EXPECT_EQ(1, result.getX());
    EXPECT_EQ(2, result.getY());
}

/*
 * Testing vector subtraction assignment
 */
TEST(Vector2D, SubtractionAssignment) {
    Vector2D<> vector1(5.0, 4.0);
    Vector2D<> vector2(4.0, 2.0);

    vector1 -= vector2;

    EXPECT_EQ(1, vector1.getX());
    EXPECT_EQ(2, vector1.getY());
}

/*
 * Testing simple vector multiplication
 */
TEST(Vector2D, Multiplication) {
    Vector2D<> vector1(5.0, 4.0);

    Vector2D<> result = vector1 * 3.0;

    EXPECT_EQ(15, result.getX());
    EXPECT_EQ(12, result.getY());
}

/*
 * Testing vector multiplication assignment
 */
TEST(Vector2D, MultiplicationAssignment) {
    Vector2D<> vector1(5.0, 4.0);

    vector1 *= 3.0;

    EXPECT_EQ(15.0, vector1.getX());
    EXPECT_EQ(12.0, vector1.getY());
}

/*
 * Testing simple vector division
 */
TEST(Vector2D, Division) {
    Vector2D<> vector1(9.0, 6.0);

    Vector2D<> result = vector1 / 3.0;

    EXPECT_EQ(3.0, result.getX());
    EXPECT_EQ(2.0, result.getY());
}

/*
 * Testing vector division assignment
 */
TEST(Vector2D, DivisionAssignment) {
    Vector2D<> vector1(9.0, 6.0);

    vector1 /= 3.0;

    EXPECT_EQ(3.0, vector1.getX());
    EXPECT_EQ(2.0, vector1.getY());
}

/*
 * Testing vector equality
 */
TEST(Vector2D, Equality) {
    Vector2D<> vector1(5.0, 4.0);
    Vector2D<> vector2(5.0, 4.0);
    Vector2D<> vector3(4.0, 2.0);
    EXPECT_TRUE(vector1 == vector2);
    EXPECT_FALSE(vector1 == vector3);
}

/*
 * Testing vector inequality
 */
TEST(Vector2D, Inequality) {
    Vector2D<> vector1(5.0, 4.0);
    Vector2D<> vector2(5.0, 4.0);
    Vector2D<> vector3(4.0, 2.0);
    EXPECT_FALSE(vector1 != vector2);
    EXPECT_TRUE(vector1 != vector3);
}

/*
 * Testing vector magnitude
 */
TEST(Vector2D, Magnitude) {
    Vector2D<> leVector(4.0, 3.0);
    EXPECT_EQ(5, leVector.magnitude());
}

/*
 * Testing vector normalization
 */
TEST(Vector2D, Normalize) {
    Vector2D<> leVector(4.0, 3.0);
    leVector.normalize();
    EXPECT_EQ(1.0, leVector.magnitude());
}

/*
 * Testing vector dot product
 */
TEST(Vector2D, DotProduct) {
    Vector2D<> vector1(5.0, 4.0);
    Vector2D<> vector2(4.0, 2.0);

    EXPECT_EQ(28, vector1.dot(vector2));
}

/**
 * Testing vector cross product
 */
TEST(Vector2D, CrossProduct) {
    Vector2D<> vector1(5.0, 4.0);
    Vector2D<> vector2(4.0, 2.0);

    Vector2D<> result = vector1.cross(vector2);

    EXPECT_EQ(0.0, result.getX());
    EXPECT_EQ(-6.0, result.getY());
}
