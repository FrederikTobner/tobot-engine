#include <gtest/gtest.h>

#include "vector/vector3d.h"

using namespace Tobot::Math;

/*
 * Testing vector creation
 */
TEST(Vector3D, CanBeCreatedWithList) {
    Vector3D<> vector = {1, 2, 3};
}

/*
 * Testing copy constructor
 */
TEST(Vector3D, Copy) {
    Vector3D<> firstVector(5, 3, 6);
    Vector3D<> secondVector(firstVector);

    firstVector = {4, 5, 6};

    EXPECT_EQ(5, secondVector.getX());
    EXPECT_EQ(3, secondVector.getY());
    EXPECT_EQ(6, secondVector.getZ());
}

/*
 * Testing move constructor
 */
TEST(Vector3D, Move) {
    Vector3D<> firstVector(5, 3, 6);
    Vector3D<> secondVector(std::move(firstVector));

    firstVector = {4, 5, 6};

    EXPECT_EQ(5, secondVector.getX());
    EXPECT_EQ(3, secondVector.getY());
    EXPECT_EQ(6, secondVector.getZ());
}

/*
 * Testing simple vector addition
 */
TEST(Vector3D, Addition) {
    Vector3D<> vector1(5, 3, 6);
    Vector3D<> vector2(4, 2, -2);

    Vector3D<> result = vector1 + vector2;

    EXPECT_EQ(9, result.getX());
    EXPECT_EQ(5, result.getY());
    EXPECT_EQ(4, result.getZ());
}

/*
 * Testing vector addition assignment
 */
TEST(Vector3D, AdditionAssignment) {
    Vector3D<> vector1(5, 3, 6);
    Vector3D<> vector2(4, 2, -2);

    vector1 += vector2;

    EXPECT_EQ(9, vector1.getX());
    EXPECT_EQ(5, vector1.getY());
    EXPECT_EQ(4, vector1.getZ());
}

/*
 * Testing simple vector subtraction
 */
TEST(Vector3D, Subtraction) {
    Vector3D<> vector1(5, 4, 6);
    Vector3D<> vector2(4, 2, -2);

    Vector3D<> result = vector1 - vector2;

    EXPECT_EQ(1, result.getX());
    EXPECT_EQ(2, result.getY());
    EXPECT_EQ(8, result.getZ());
}

/*
 * Testing vector subtraction assignment
 */
TEST(Vector3D, SubtractionAssignment) {
    Vector3D<> vector1(5, 4, 6);
    Vector3D<> vector2(4, 2, -2);

    vector1 -= vector2;

    EXPECT_EQ(1, vector1.getX());
    EXPECT_EQ(2, vector1.getY());
    EXPECT_EQ(8, vector1.getZ());
}

/*
 * Testing simple vector multiplication
 */
TEST(Vector3D, Multiplication) {
    Vector3D<> vector1(5, 4, 1);

    Vector3D<> result = vector1 * 3;

    EXPECT_EQ(15, result.getX());
    EXPECT_EQ(12, result.getY());
    EXPECT_EQ(3, result.getZ());
}

/*
 * Testing vector multiplication assignment
 */
TEST(Vector3D, MultiplicationAssignment) {
    Vector3D<> vector1(5, 4, 1);

    vector1 *= 3;

    EXPECT_EQ(15, vector1.getX());
    EXPECT_EQ(12, vector1.getY());
    EXPECT_EQ(3, vector1.getZ());
}

/*
 * Testing simple vector division
 */
TEST(Vector3D, Division) {
    Vector3D<> vector1(9, 6, 3);

    Vector3D<> result = vector1 / 3;

    EXPECT_EQ(3, result.getX());
    EXPECT_EQ(2, result.getY());
    EXPECT_EQ(1, result.getZ());
}

/**
 * Testing vector division assignment
 */
TEST(Vector3D, DivisionAssignment) {
    Vector3D<> vector1(9, 6, 3);

    vector1 /= 3;

    EXPECT_EQ(3, vector1.getX());
    EXPECT_EQ(2, vector1.getY());
    EXPECT_EQ(1, vector1.getZ());
}

/*
 * Testing vector equality
 */
TEST(Vector3D, Equality) {
    Vector3D<> vector1(9, 6, 3);
    Vector3D<> vector2(9, 6, 3);
    Vector3D<> vector3(9, 6, 4);
    EXPECT_TRUE(vector1 == vector2);
    EXPECT_FALSE(vector1 == vector3);
}

/*
 * Testing vector inequality
 */
TEST(Vector3D, Inequality) {
    Vector3D<> vector1(9, 6, 3);
    Vector3D<> vector2(9, 6, 3);
    Vector3D<> vector3(9, 6, 4);
    EXPECT_FALSE(vector1 != vector2);
    EXPECT_TRUE(vector1 != vector3);
}

/*
 * Testing vector magnitude
 */
TEST(Vector3D, Magnitude) {
    Vector3D<> leVector(4, 3, 0);
    EXPECT_EQ(5, leVector.magnitude());
}

/*
 * Testing vector normalization
 */
TEST(Vector3D, Normalize) {
    Vector3D<> leVector(4.0, 3.0, 2.5);
    leVector.normalize();
    EXPECT_EQ(1, leVector.magnitude());
}

/*
 * Testing vector dot product
 */
TEST(Vector3D, DotProduct) {
    Vector3D<> vector1(5, 4, 1);
    Vector3D<> vector2(4, 2, -2);

    EXPECT_EQ(26, vector1.dot(vector2));
}

/*
 * Testing vector cross product
 */
TEST(Vector3D, CrossProduct) {
    Vector3D<> vector1(5, 4, 1);
    Vector3D<> vector2(4, 2, -2);

    Vector3D<> result = vector1.cross(vector2);

    EXPECT_EQ(-10, result.getX());
    EXPECT_EQ(14, result.getY());
    EXPECT_EQ(-6, result.getZ());
}