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
 * Testing copy constructor
 */
TEST(Matrix, Copy) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix(firstMatrix);
    firstMatrix = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    EXPECT_EQ(3, secondMatrix.getRows());
    EXPECT_EQ(3, secondMatrix.getColoumns());
    EXPECT_EQ(1, secondMatrix(0, 0));
    EXPECT_EQ(2, secondMatrix(0, 1));
    EXPECT_EQ(3, secondMatrix(0, 2));
    EXPECT_EQ(4, secondMatrix(1, 0));
    EXPECT_EQ(5, secondMatrix(1, 1));
    EXPECT_EQ(6, secondMatrix(1, 2));
    EXPECT_EQ(7, secondMatrix(2, 0));
    EXPECT_EQ(8, secondMatrix(2, 1));
    EXPECT_EQ(9, secondMatrix(2, 2));
}

/*
 * Testing move constructor
 */
TEST(Matrix, Move) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix(std::move(firstMatrix));
    firstMatrix = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    EXPECT_EQ(3, secondMatrix.getRows());
    EXPECT_EQ(3, secondMatrix.getColoumns());
    EXPECT_EQ(1, secondMatrix(0, 0));
    EXPECT_EQ(2, secondMatrix(0, 1));
    EXPECT_EQ(3, secondMatrix(0, 2));
    EXPECT_EQ(4, secondMatrix(1, 0));
    EXPECT_EQ(5, secondMatrix(1, 1));
    EXPECT_EQ(6, secondMatrix(1, 2));
    EXPECT_EQ(7, secondMatrix(2, 0));
    EXPECT_EQ(8, secondMatrix(2, 1));
    EXPECT_EQ(9, secondMatrix(2, 2));
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
 * Testing addition operator
 */
TEST(Matrix, Addition) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Matrix<> fourthMatrix = firstMatrix + secondMatrix;
    ASSERT_EQ(2, fourthMatrix(0, 0));
    ASSERT_EQ(4, fourthMatrix(0, 1));
    ASSERT_EQ(6, fourthMatrix(0, 2));
    ASSERT_EQ(8, fourthMatrix(1, 0));
    ASSERT_EQ(10, fourthMatrix(1, 1));
    ASSERT_EQ(12, fourthMatrix(1, 2));
    ASSERT_EQ(14, fourthMatrix(2, 0));
    ASSERT_EQ(16, fourthMatrix(2, 1));
    ASSERT_EQ(18, fourthMatrix(2, 2));
}

/*
 * Testing subtraction operator
 */
TEST(Matrix, Subtraction) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Matrix<> fourthMatrix = firstMatrix - secondMatrix;
    ASSERT_EQ(0, fourthMatrix(0, 0));
    ASSERT_EQ(0, fourthMatrix(0, 1));
    ASSERT_EQ(0, fourthMatrix(0, 2));
    ASSERT_EQ(0, fourthMatrix(1, 0));
    ASSERT_EQ(0, fourthMatrix(1, 1));
    ASSERT_EQ(0, fourthMatrix(1, 2));
    ASSERT_EQ(0, fourthMatrix(2, 0));
    ASSERT_EQ(0, fourthMatrix(2, 1));
    ASSERT_EQ(0, fourthMatrix(2, 2));
}

/*
 * Testing multiplication operator with a scalar
 */
TEST(Matrix, ScalarMultiplication) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix = {2, 4, 6, 8, 10, 12, 14, 16, 18};

    Matrix<> fourthMatrix = firstMatrix * 2;
    ASSERT_EQ(2, fourthMatrix(0, 0));
    ASSERT_EQ(4, fourthMatrix(0, 1));
    ASSERT_EQ(6, fourthMatrix(0, 2));
    ASSERT_EQ(8, fourthMatrix(1, 0));
    ASSERT_EQ(10, fourthMatrix(1, 1));
    ASSERT_EQ(12, fourthMatrix(1, 2));
    ASSERT_EQ(14, fourthMatrix(2, 0));
    ASSERT_EQ(16, fourthMatrix(2, 1));
    ASSERT_EQ(18, fourthMatrix(2, 2));
}

/*
 * Testing division operator with a scalar
 */
TEST(Matrix, ScalarDivision) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix = {2, 4, 6, 8, 10, 12, 14, 16, 18};

    Matrix<> fourthMatrix = secondMatrix / 2;
    ASSERT_EQ(1, fourthMatrix(0, 0));
    ASSERT_EQ(2, fourthMatrix(0, 1));
    ASSERT_EQ(3, fourthMatrix(0, 2));
    ASSERT_EQ(4, fourthMatrix(1, 0));
    ASSERT_EQ(5, fourthMatrix(1, 1));
    ASSERT_EQ(6, fourthMatrix(1, 2));
    ASSERT_EQ(7, fourthMatrix(2, 0));
    ASSERT_EQ(8, fourthMatrix(2, 1));
    ASSERT_EQ(9, fourthMatrix(2, 2));
}

/*
 * Testing determinant calculation
 */
TEST(Matrix, Determinant) {
    Matrix<> firstMatrix = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<> secondMatrix = {1.0f, 2.0f, -1.0f, 2.0f, 1.0f, 2.0f, -1.0f, 2.0f, 1.0f};
    Matrix<> thirdMatrix = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    ASSERT_EQ(0, firstMatrix.determinant());
    /*det A = 1 (cofactor of 1) + 2 (cofactor of 2) + (-1) cofactor of (-1)
     * = 1(-3) + 2(-4) + (-1)5
     * = -3 - 8 - 5
     * = -16
     */
    ASSERT_EQ(-16.0f, secondMatrix.determinant());
    ASSERT_EQ(0, thirdMatrix.determinant());
}

/*
 * Testing matrix inversion
 */
TEST(Matrix, Inversion) {
    Matrix<> matrix({1.0f, 2.0f, -1.0f, 2.0f, 1.0f, 2.0f, -1.0f, 2.0f, 1.0f});
    Matrix<> matrix2 = matrix.inverse();
    EXPECT_EQ(matrix2[0][0], 0.1875f);  // 3 / 16
    EXPECT_EQ(matrix2[0][1], 0.25f);    // 1 / 4
    EXPECT_EQ(matrix2[0][2], -0.3125f); // -5 / 16
    EXPECT_EQ(matrix2[1][0], 0.25f);    // 1 / 4
    EXPECT_EQ(matrix2[1][1], 0.0f);     // 0
    EXPECT_EQ(matrix2[1][2], 0.25f);    // 1 / 4
    EXPECT_EQ(matrix2[2][0], -0.3125f); // -5 / 16
    EXPECT_EQ(matrix2[2][1], 0.25f);    // 1 / 4
    EXPECT_EQ(matrix2[2][2], 0.1875f);  // 3 / 16
}

/*
 * Testing matrix inversion with inversion operator
 */
TEST(Matrix, InversionOperator) {
    Matrix<> matrix({1.0f, 2.0f, -1.0f, 2.0f, 1.0f, 2.0f, -1.0f, 2.0f, 1.0f});
    Matrix<> matrix2 = !matrix;
    EXPECT_EQ(matrix2[0][0], 0.1875f);  // 3 / 16
    EXPECT_EQ(matrix2[0][1], 0.25f);    // 1 / 4
    EXPECT_EQ(matrix2[0][2], -0.3125f); // -5 / 16
    EXPECT_EQ(matrix2[1][0], 0.25f);    // 1 / 4
    EXPECT_EQ(matrix2[1][1], 0.0f);     // 0
    EXPECT_EQ(matrix2[1][2], 0.25f);    // 1 / 4
    EXPECT_EQ(matrix2[2][0], -0.3125f); // -5 / 16
    EXPECT_EQ(matrix2[2][1], 0.25f);    // 1 / 4
    EXPECT_EQ(matrix2[2][2], 0.1875f);  // 3 / 16
}
