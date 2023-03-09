#include <gtest/gtest.h>

#include "math/vector2d.h"

/**
 * @brief Testing simple vector addition
 *
 */
TEST(Vector2DTest, Addition) {
    Tobot::Math::Vector2D<int> vector1(5, 5);
    Tobot::Math::Vector2D<int> vector2(5, 5);

    Tobot::Math::Vector2D<int> result = vector1 + vector2;

    EXPECT_EQ(result.x, 5 + 5);
    EXPECT_EQ(result.y, 5 + 5);
}

/**
 * @brief Testing vector addition assignment
 *
 */
TEST(Vector2DTest, AdditionAssignment) {
    Tobot::Math::Vector2D<int> vector1(5, 5);
    Tobot::Math::Vector2D<int> vector2(5, 5);

    vector1 += vector2;

    EXPECT_EQ(vector1.x, 5 + 5);
    EXPECT_EQ(vector1.y, 5 + 5);
}

/**
 * @brief Testing vector simple multiplication
 *
 */
TEST(Vector2DTest, Multiplication) {
    Tobot::Math::Vector2D<int> vector1(5, 5);
    Tobot::Math::Vector2D<int> vector2(5, 5);

    Tobot::Math::Vector2D<int> result = vector1 * vector2;

    EXPECT_EQ(result.x, 5 * 5);
    EXPECT_EQ(result.y, 5 * 5);
}

/**
 * @brief Testing vector multiplication assignment
 *
 */
TEST(Vector2DTest, MultiplicationAssignment) {
    Tobot::Math::Vector2D<int> vector1(5, 5);
    Tobot::Math::Vector2D<int> vector2(5, 5);

    vector1 *= vector2;

    EXPECT_EQ(vector1.x, 5 * 5);
    EXPECT_EQ(vector1.y, 5 * 5);
}