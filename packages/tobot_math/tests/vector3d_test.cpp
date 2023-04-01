#include <gtest/gtest.h>

#include "vector/vector3d.h"

/**
 * @brief Testing simple vector addition
 *
 */
TEST(Vector3D, Addition) {
    Tobot::Math::Vector3D<int> vector1(5, 3, 6);
    Tobot::Math::Vector3D<int> vector2(4, 2, -2);

    Tobot::Math::Vector3D<int> result = vector1 + vector2;

    EXPECT_EQ(9, result.x);
    EXPECT_EQ(5, result.y);
    EXPECT_EQ(4, result.z);
}

/**
 * @brief Testing vector addition assignment
 *
 */
TEST(Vector3D, AdditionAssignment) {
    Tobot::Math::Vector3D<int> vector1(5, 3, 6);
    Tobot::Math::Vector3D<int> vector2(4, 2, -2);

    vector1 += vector2;

    EXPECT_EQ(9, vector1.x);
    EXPECT_EQ(5, vector1.y);
    EXPECT_EQ(4, vector1.z);
}

/**
 * @brief Testing simple vector subtraction
 *
 */
TEST(Vector3D, Subtraction) {
    Tobot::Math::Vector3D<int> vector1(5, 4, 6);
    Tobot::Math::Vector3D<int> vector2(4, 2, -2);

    Tobot::Math::Vector3D<int> result = vector1 - vector2;

    EXPECT_EQ(1, result.x);
    EXPECT_EQ(2, result.y);
    EXPECT_EQ(8, result.z);
}

/**
 * @brief Testing vector subtraction assignment
 *
 */
TEST(Vector3D, SubtractionAssignment) {
    Tobot::Math::Vector3D<int> vector1(5, 4, 6);
    Tobot::Math::Vector3D<int> vector2(4, 2, -2);

    vector1 -= vector2;

    EXPECT_EQ(1, vector1.x);
    EXPECT_EQ(2, vector1.y);
    EXPECT_EQ(8, vector1.z);
}

/**
 * @brief Testing simple vector multiplication
 *
 */
TEST(Vector3D, Multiplication) {
    Tobot::Math::Vector3D<int> vector1(5, 4, 1);

    Tobot::Math::Vector3D<int> result = vector1 * 3;

    EXPECT_EQ(15, result.x);
    EXPECT_EQ(12, result.y);
    EXPECT_EQ(3, result.z);
}

/**
 * @brief Testing vector multiplication assignment
 *
 */
TEST(Vector3D, MultiplicationAssignment) {
    Tobot::Math::Vector3D<int> vector1(5, 4, 1);

    vector1 *= 3;

    EXPECT_EQ(15, vector1.x);
    EXPECT_EQ(12, vector1.y);
    EXPECT_EQ(3, vector1.z);
}

/**
 * @brief Testing simple vector division
 *
 */
TEST(Vector3D, Division) {
    Tobot::Math::Vector3D<int> vector1(9, 6, 3);

    Tobot::Math::Vector3D<int> result = vector1 / 3;

    EXPECT_EQ(3, result.x);
    EXPECT_EQ(2, result.y);
    EXPECT_EQ(1, result.z);
}

/**
 * @brief Testing vector division assignment
 *
 */
TEST(Vector3D, DivisionAssignment) {
    Tobot::Math::Vector3D<int> vector1(9, 6, 3);

    vector1 /= 3;

    EXPECT_EQ(3, vector1.x);
    EXPECT_EQ(2, vector1.y);
    EXPECT_EQ(1, vector1.z);
}

/**
 * @brief Testing vector magnitude
 *
 */
TEST(Vector3D, Magnitude) {
    Tobot::Math::Vector3D<int> leVector(4, 3, 0);
    EXPECT_EQ(5, leVector.Magnitude());
}

/**
 * @brief Testing vector normalization
 *
 */
TEST(Vector3D, Normalize) {
    Tobot::Math::Vector3D<float> leVector(4.0, 3.0, 2.5);
    leVector.Normalize();
    EXPECT_EQ(1, leVector.Magnitude());
}