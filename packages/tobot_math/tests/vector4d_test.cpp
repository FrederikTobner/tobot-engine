#include <gtest/gtest.h>

#include "vector/vector4d.h"

using namespace Tobot::Math;

/*
 * Testing vector creation
 */
TEST(Vector4D, CanBeCreatedWithList) {
    Vector4D<> vector = {1, 2, 3, 4};
}

/*
 * Testing copy constructor
 */
TEST(Vector4D, Copy) {
    Vector4D<> firstVector(5, 3, 6, 1);
    Vector4D<> secondVector(firstVector);

    firstVector = {4, 5, 6, 1};

    EXPECT_EQ(5, secondVector.getX());
    EXPECT_EQ(3, secondVector.getY());
    EXPECT_EQ(6, secondVector.getZ());
    EXPECT_EQ(1, secondVector.getW());
}

/*
 * Testing move constructor
 */

TEST(Vector4D, Move) {
    Vector4D<> firstVector(5, 3, 6, 1);
    Vector4D<> secondVector(std::move(firstVector));

    firstVector = {4, 5, 6, 1};

    EXPECT_EQ(5, secondVector.getX());
    EXPECT_EQ(3, secondVector.getY());
    EXPECT_EQ(6, secondVector.getZ());
    EXPECT_EQ(1, secondVector.getW());
}

/*
 * Testing simple vector addition
 */
TEST(Vector4D, Addition) {
    Vector4D<> vector1(5, 3, 6, 1);
    Vector4D<> vector2(4, 2, -2, -1);

    Vector4D<> result = vector1 + vector2;

    EXPECT_EQ(9, result.getX());
    EXPECT_EQ(5, result.getY());
    EXPECT_EQ(4, result.getZ());
    EXPECT_EQ(0, result.getW());
}

/*
 * Testing vector addition assignment
 */
TEST(Vector4D, AdditionAssignment) {
    Vector4D<> vector1(5, 3, 6, 1);
    Vector4D<> vector2(4, 2, -2, -1);

    vector1 += vector2;

    EXPECT_EQ(9, vector1.getX());
    EXPECT_EQ(5, vector1.getY());
    EXPECT_EQ(4, vector1.getZ());
    EXPECT_EQ(0, vector1.getW());
}

/*
 * Testing simple vector subtraction
 */
TEST(Vector4D, Subtraction) {
    Vector4D<> vector1(5, 4, 6, 1);
    Vector4D<> vector2(4, 2, -2, -1);

    Vector4D<> result = vector1 - vector2;

    EXPECT_EQ(1, result.getX());
    EXPECT_EQ(2, result.getY());
    EXPECT_EQ(8, result.getZ());
    EXPECT_EQ(2, result.getW());
}

/*
 * Testing vector subtraction assignment
 */
TEST(Vector4D, SubtractionAssignment) {
    Vector4D<> vector1(5, 4, 6, 1);
    Vector4D<> vector2(4, 2, -2, -1);

    vector1 -= vector2;

    EXPECT_EQ(1, vector1.getX());
    EXPECT_EQ(2, vector1.getY());
    EXPECT_EQ(8, vector1.getZ());
    EXPECT_EQ(2, vector1.getW());
}

/*
 * Testing simple vector multiplication
 */
TEST(Vector4D, Multiplication) {
    Vector4D<> vector1(5, 4, 1, 2);

    Vector4D<> result = vector1 * 3;

    EXPECT_EQ(15, result.getX());
    EXPECT_EQ(12, result.getY());
    EXPECT_EQ(3, result.getZ());
    EXPECT_EQ(6, result.getW());
}

/*
 * Testing vector multiplication assignment
 */
TEST(Vector4D, MultiplicationAssignment) {
    Vector4D<> vector1(5, 4, 1, 2);

    vector1 *= 3;

    EXPECT_EQ(15, vector1.getX());
    EXPECT_EQ(12, vector1.getY());
    EXPECT_EQ(3, vector1.getZ());
    EXPECT_EQ(6, vector1.getW());
}

/*
 * Testing simple vector division
 */
TEST(Vector4D, Division) {
    Vector4D<> vector1(9, 6, 3, 12);

    Vector4D<> result = vector1 / 3;

    EXPECT_EQ(3, result.getX());
    EXPECT_EQ(2, result.getY());
    EXPECT_EQ(1, result.getZ());
    EXPECT_EQ(4, result.getW());
}

/*
 * Testing vector division assignment
 */
TEST(Vector4D, DivisionAssignment) {
    Vector4D<> vector1(9, 6, 3, 12);

    vector1 /= 3;

    EXPECT_EQ(3, vector1.getX());
    EXPECT_EQ(2, vector1.getY());
    EXPECT_EQ(1, vector1.getZ());
    EXPECT_EQ(4, vector1.getW());
}

/*
 * Testing vector equality
 */
TEST(Vector4D, Equality) {
    Vector4D<> vector1(9, 6, 3, 12);
    Vector4D<> vector2(9, 6, 3, 12);
    Vector4D<> vector3(9, 6, 3, 13);
    EXPECT_TRUE(vector1 == vector2);
    EXPECT_FALSE(vector1 == vector3);
}

/*
 * Testing vector inequality
 */
TEST(Vector4D, Inequality) {
    Vector4D<> vector1(9, 6, 3, 12);
    Vector4D<> vector2(9, 6, 3, 12);
    Vector4D<> vector3(9, 6, 3, 13);
    EXPECT_TRUE(vector1 != vector3);
    EXPECT_FALSE(vector1 != vector2);
}

/*
 * Testing vector magnitude
 */
TEST(Vector4D, Magnitude) {
    Vector4D<> leVector(4, 3, 0, 0);
    EXPECT_EQ(5, leVector.magnitude());
}

/*
 * Testing vector normalization
 */
TEST(Vector4D, Normalize) {
    Vector4D<> leVector(4.0, 3.0, 2.5, 1.5);
    leVector.normalize();
    EXPECT_EQ(1, leVector.magnitude());
}

/*
 * Testing vector dot product
 */
TEST(Vector4D, DotProduct) {
    Vector4D<> vector1(4, 3, 2, 1);
    Vector4D<> vector2(1, 2, 3, 4);

    EXPECT_EQ(20, vector1.dot(vector2));
}