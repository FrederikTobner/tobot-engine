#include <gtest/gtest.h>

#include "matrix.h"

/**
 * @brief Testing simple matrix creation
 *
 */
TEST(Matrix, Creation) {
    Tobot::Math::Matrix<int, 3, 3> leMatrix({1, 2, 3, 4, 5, 6, 7, 8, 9});
    EXPECT_EQ(3, leMatrix.getRows());
    EXPECT_EQ(3, leMatrix.getColoumns());
}