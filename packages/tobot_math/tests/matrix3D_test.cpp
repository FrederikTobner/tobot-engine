#include <gtest/gtest.h>

#include "matrix3D.h"

using namespace Tobot::Math;

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