#include <gtest/gtest.h>

#include "matrix3D.h"

using namespace Tobot::Math;

/*
 * Testing to construct a matrix.
 */
TEST(Matrix3DTest, Constructor) {
    Matrix3D matrix;
    EXPECT_EQ(matrix[0][0], 0.0f);
    EXPECT_EQ(matrix[0][1], 0.0f);
    EXPECT_EQ(matrix[0][2], 0.0f);
    EXPECT_EQ(matrix[1][0], 0.0f);
    EXPECT_EQ(matrix[1][1], 0.0f);
    EXPECT_EQ(matrix[1][2], 0.0f);
    EXPECT_EQ(matrix[2][0], 0.0f);
    EXPECT_EQ(matrix[2][1], 0.0f);
    EXPECT_EQ(matrix[2][2], 0.0f);
}

/*
 * Testing to construct a matrix from a 2D array.
 */
TEST(Matrix3DTest, ConstructorWithMatrix) {
    float matrix[3][3] = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}};
    Matrix3D matrix3D(matrix);
    EXPECT_EQ(matrix3D[0][0], 1.0f);
    EXPECT_EQ(matrix3D[0][1], 2.0f);
    EXPECT_EQ(matrix3D[0][2], 3.0);
    EXPECT_EQ(matrix3D[1][0], 4.0f);
    EXPECT_EQ(matrix3D[1][1], 5.0f);
    EXPECT_EQ(matrix3D[1][2], 6.0f);
    EXPECT_EQ(matrix3D[2][0], 7.0f);
    EXPECT_EQ(matrix3D[2][1], 8.0f);
    EXPECT_EQ(matrix3D[2][2], 9.0f);
}

/*
 * Testing to construct a matrix from another matrix.
 */
TEST(Matrix3DTest, ConstructorWithMatrix3D) {
    Matrix3D matrix3D1;
    Matrix3D matrix3D2(matrix3D1);
    EXPECT_EQ(matrix3D2[0][0], 0.0f);
    EXPECT_EQ(matrix3D2[0][1], 0.0f);
    EXPECT_EQ(matrix3D2[0][2], 0.0f);
    EXPECT_EQ(matrix3D2[1][0], 0.0f);
    EXPECT_EQ(matrix3D2[1][1], 0.0f);
    EXPECT_EQ(matrix3D2[1][2], 0.0f);
    EXPECT_EQ(matrix3D2[2][0], 0.0f);
    EXPECT_EQ(matrix3D2[2][1], 0.0f);
    EXPECT_EQ(matrix3D2[2][2], 0.0f);
}
/*
 * Testing to construct a matrix from a list of values.
 */
TEST(Matrix3DTest, ConstructorWithInitializerList) {
    Matrix3D matrix3D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
    EXPECT_EQ(matrix3D[0][0], 1.0f);
    EXPECT_EQ(matrix3D[0][1], 2.0f);
    EXPECT_EQ(matrix3D[0][2], 3.0f);
    EXPECT_EQ(matrix3D[1][0], 4.0f);
    EXPECT_EQ(matrix3D[1][1], 5.0f);
    EXPECT_EQ(matrix3D[1][2], 6.0f);
    EXPECT_EQ(matrix3D[2][0], 7.0f);
    EXPECT_EQ(matrix3D[2][1], 8.0f);
    EXPECT_EQ(matrix3D[2][2], 9.0f);
}

/*
 * Testing addition of two matrices.
 */
TEST(Matrix3DTest, Addition) {
    Matrix3D matrix3D1({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
    Matrix3D matrix3D2({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
    Matrix3D matrix3D3 = matrix3D1 + matrix3D2;
    EXPECT_EQ(matrix3D3[0][0], 2.0f);
    EXPECT_EQ(matrix3D3[0][1], 4.0f);
    EXPECT_EQ(matrix3D3[0][2], 6.0f);
    EXPECT_EQ(matrix3D3[1][0], 8.0f);
    EXPECT_EQ(matrix3D3[1][1], 10.0f);
    EXPECT_EQ(matrix3D3[1][2], 12.0f);
    EXPECT_EQ(matrix3D3[2][0], 14.0f);
    EXPECT_EQ(matrix3D3[2][1], 16.0f);
    EXPECT_EQ(matrix3D3[2][2], 18.0f);
}

/*
 * Testing subtraction of two matrices.
 */
TEST(Matrix3DTest, Subtraction) {
    Matrix3D matrix3D1({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
    Matrix3D matrix3D2({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
    Matrix3D matrix3D3 = matrix3D1 - matrix3D2;
    EXPECT_EQ(matrix3D3[0][0], 0.0f);
    EXPECT_EQ(matrix3D3[0][1], 0.0f);
    EXPECT_EQ(matrix3D3[0][2], 0.0f);
    EXPECT_EQ(matrix3D3[1][0], 0.0f);
    EXPECT_EQ(matrix3D3[1][1], 0.0f);
    EXPECT_EQ(matrix3D3[1][2], 0.0f);
    EXPECT_EQ(matrix3D3[2][0], 0.0f);
    EXPECT_EQ(matrix3D3[2][1], 0.0f);
    EXPECT_EQ(matrix3D3[2][2], 0.0f);
}

/*
 * Testing multiplication of two matrices.
 */
TEST(Matrix3DTest, Multiplication) {
    Matrix3D matrix3D1({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
    Matrix3D matrix3D2({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
    Matrix3D matrix3D3 = matrix3D1 * matrix3D2;
    EXPECT_EQ(matrix3D3[0][0], 30.0f);
    EXPECT_EQ(matrix3D3[0][1], 36.0f);
    EXPECT_EQ(matrix3D3[0][2], 42.0f);
    EXPECT_EQ(matrix3D3[1][0], 66.0f);
    EXPECT_EQ(matrix3D3[1][1], 81.0f);
    EXPECT_EQ(matrix3D3[1][2], 96.0f);
    EXPECT_EQ(matrix3D3[2][0], 102.0f);
    EXPECT_EQ(matrix3D3[2][1], 126.0f);
    EXPECT_EQ(matrix3D3[2][2], 150.0f);
}

/*
 * Tetsing the calculation of the determinant of a matrix.
 */
TEST(Matrix3DTest, Determinant) {
    Matrix3D matrix3D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f});
    EXPECT_EQ(matrix3D.determinant(), 0.0f);
}