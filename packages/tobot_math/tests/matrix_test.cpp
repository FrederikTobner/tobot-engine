#include <gtest/gtest.h>

#include "matrix.h"

using namespace Tobot::Math;

/*
 * Testing simple matrix creation
 */
TEST(Matrix, Creation) {
    Matrix<> leMatrix({1, 2, 3, 4, 5, 6, 7, 8, 9});
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
    Matrix<> leMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
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
 * Testing eqaulity operator
 */
TEST(Matrix, Equality) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> thirdMatrix = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    ASSERT_TRUE(firstMatrix == secondMatrix);
    ASSERT_FALSE(firstMatrix == thirdMatrix);
}

/*
 * Testing inequality operator
 */
TEST(Matrix, Inequality) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> thirdMatrix = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    ASSERT_FALSE(firstMatrix != secondMatrix);
    ASSERT_TRUE(firstMatrix != thirdMatrix);
}

/*
 * Testing determinant calculation
 */
TEST(Matrix, Determinant) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> thirdMatrix = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    ASSERT_EQ(0, firstMatrix.determinant());
    ASSERT_EQ(0, secondMatrix.determinant());
    ASSERT_EQ(0, thirdMatrix.determinant());
}
