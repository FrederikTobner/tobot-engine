#include <gtest/gtest.h>

#include "matrix3d.h"

/**
 * @brief Testing simple matrix creation
 *
 */
TEST(Matrix3D, Creation) {
    Tobot::Math::Matrix3D<int> leMatrix({1, 2, 3, 4, 5, 6, 7, 8, 9});
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