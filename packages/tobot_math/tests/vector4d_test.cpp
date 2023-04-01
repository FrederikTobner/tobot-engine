#include <gtest/gtest.h>

#include "vector4d.h"

/**
 * @brief Testing simple vector addition
 *
 */
TEST(Vector4D, Addition) {
    Tobot::Math::Vector4D<int> vector1(5, 3, 6, 1);
    Tobot::Math::Vector4D<int> vector2(4, 2, -2, -1);

    Tobot::Math::Vector4D<int> result = vector1 + vector2;

    EXPECT_EQ(9, result.x);
    EXPECT_EQ(5, result.y);
    EXPECT_EQ(4, result.z);
    EXPECT_EQ(0, result.w);
}

/**
 * @brief Testing vector addition assignment
 *
 */
TEST(Vector4D, AdditionAssignment) {
    Tobot::Math::Vector4D<int> vector1(5, 3, 6, 1);
    Tobot::Math::Vector4D<int> vector2(4, 2, -2, -1);

    vector1 += vector2;

    EXPECT_EQ(9, vector1.x);
    EXPECT_EQ(5, vector1.y);
    EXPECT_EQ(4, vector1.z);
    EXPECT_EQ(0, vector1.w);
}

/**
 * @brief Testing simple vector subtraction
 *
 */
TEST(Vector4D, Subtraction) {
    Tobot::Math::Vector4D<int> vector1(5, 4, 6, 1);
    Tobot::Math::Vector4D<int> vector2(4, 2, -2, -1);

    Tobot::Math::Vector4D<int> result = vector1 - vector2;

    EXPECT_EQ(1, result.x);
    EXPECT_EQ(2, result.y);
    EXPECT_EQ(8, result.z);
    EXPECT_EQ(2, result.w);
}

/**
 * @brief Testing vector subtraction assignment
 *
 */
TEST(Vector4D, SubtractionAssignment) {
    Tobot::Math::Vector4D<int> vector1(5, 4, 6, 1);
    Tobot::Math::Vector4D<int> vector2(4, 2, -2, -1);

    vector1 -= vector2;

    EXPECT_EQ(1, vector1.x);
    EXPECT_EQ(2, vector1.y);
    EXPECT_EQ(8, vector1.z);
    EXPECT_EQ(2, vector1.w);
}

/**
 * @brief Testing simple vector multiplication
 *
 */
TEST(Vector4D, Multiplication) {
    Tobot::Math::Vector4D<int> vector1(5, 4, 1, 2);

    Tobot::Math::Vector4D<int> result = vector1 * 3;

    EXPECT_EQ(15, result.x);
    EXPECT_EQ(12, result.y);
    EXPECT_EQ(3, result.z);
    EXPECT_EQ(6, result.w);
}

/**
 * @brief Testing vector multiplication assignment
 *
 */
TEST(Vector4D, MultiplicationAssignment) {
    Tobot::Math::Vector4D<int> vector1(5, 4, 1, 2);

    vector1 *= 3;

    EXPECT_EQ(15, vector1.x);
    EXPECT_EQ(12, vector1.y);
    EXPECT_EQ(3, vector1.z);
    EXPECT_EQ(6, vector1.w);
}

/**
 * @brief Testing simple vector division
 *
 */
TEST(Vector4D, Division) {
    Tobot::Math::Vector4D<int> vector1(9, 6, 3, 12);

    Tobot::Math::Vector4D<int> result = vector1 / 3;

    EXPECT_EQ(3, result.x);
    EXPECT_EQ(2, result.y);
    EXPECT_EQ(1, result.z);
    EXPECT_EQ(4, result.w);
}

/**
 * @brief Testing vector division assignment
 *
 */
TEST(Vector4D, DivisionAssignment) {
    Tobot::Math::Vector4D<int> vector1(9, 6, 3, 12);

    vector1 /= 3;

    EXPECT_EQ(3, vector1.x);
    EXPECT_EQ(2, vector1.y);
    EXPECT_EQ(1, vector1.z);
    EXPECT_EQ(4, vector1.w);
}

/**
 * @brief Testing vector magnitude
 *
 */
TEST(Vector4D, Magnitude) {
    Tobot::Math::Vector4D<int> leVector(4, 3, 0, 0);
    EXPECT_EQ(5, leVector.Magnitude());
}

/**
 * @brief Testing vector normalization
 *
 */
TEST(Vector4D, Normalize) {
    Tobot::Math::Vector4D<float> leVector(4.0, 3.0, 2.5, 1.5);
    leVector.Normalize();
    EXPECT_EQ(1, leVector.Magnitude());
}