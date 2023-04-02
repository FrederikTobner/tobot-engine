#include <gtest/gtest.h>

#include "matrix.h"

/*
 * Testing simple matrix creation
 */
TEST(Matrix, Creation) {
    Tobot::Math::Matrix<int, 3, 3> leMatrix({1, 2, 3, 4, 5, 6, 7, 8, 9});
    EXPECT_EQ(3, leMatrix.getRows());
    EXPECT_EQ(3, leMatrix.getColoumns());
    EXPECT_EQ(1, leMatrix(0, 0));
    EXPECT_EQ(2, leMatrix(0, 1));
    EXPECT_EQ(3, leMatrix(0, 2));
    EXPECT_EQ(4, leMatrix(1, 0));
    EXPECT_EQ(5, leMatrix(1, 1));
    EXPECT_EQ(6, leMatrix(1, 2));
    EXPECT_EQ(7, leMatrix(2, 0));
    EXPECT_EQ(8, leMatrix(2, 1));
    EXPECT_EQ(9, leMatrix(2, 2));
}

/*
 * Testing simple matrix creation from list
 */
TEST(Matrix, CreationFromList) {
    Tobot::Math::Matrix<int, 3, 3> leMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(3, leMatrix.getRows());
    EXPECT_EQ(3, leMatrix.getColoumns());
    EXPECT_EQ(1, leMatrix(0, 0));
    EXPECT_EQ(2, leMatrix(0, 1));
    EXPECT_EQ(3, leMatrix(0, 2));
    EXPECT_EQ(4, leMatrix(1, 0));
    EXPECT_EQ(5, leMatrix(1, 1));
    EXPECT_EQ(6, leMatrix(1, 2));
    EXPECT_EQ(7, leMatrix(2, 0));
    EXPECT_EQ(8, leMatrix(2, 1));
    EXPECT_EQ(9, leMatrix(2, 2));
}

/*
 * Testing eaulity operator
 */
TEST(Matrix, Equality) {
    Tobot::Math::Matrix<int, 3, 3> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tobot::Math::Matrix<int, 3, 3> secondMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tobot::Math::Matrix<int, 3, 3> thirdMatrix = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    ASSERT_TRUE(firstMatrix == secondMatrix);
    ASSERT_FALSE(firstMatrix == thirdMatrix);
}

/*
 * Testing inequality operator
 */
TEST(Matrix, Inequality) {
    Tobot::Math::Matrix<int, 3, 3> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tobot::Math::Matrix<int, 3, 3> secondMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tobot::Math::Matrix<int, 3, 3> thirdMatrix = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    ASSERT_FALSE(firstMatrix != secondMatrix);
    ASSERT_TRUE(firstMatrix != thirdMatrix);
}