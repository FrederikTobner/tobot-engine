#include <gtest/gtest.h>

#include "gradient2D.h"

using namespace Tobot::Math;

/*
 * Testing gradiant creation
 */
TEST(Gradient2D, Creation) {
    Gradient2D<> leGradient(1, 2);
    EXPECT_EQ(1, leGradient.getSlope());
    EXPECT_EQ(2, leGradient.getYIntercept());
}

/*
 * Testing gradiant intersection
 */
TEST(Gradient2D, Intersection) {
    // f(x) = 1x + 2
    Gradient2D<> firstGradient(1, 2);
    // f(x) = 3x + 4
    Gradient2D<> secondGradient(3, 4);
    // 1x + 2 = 3x + 4    | -3x
    // -2x + 2 = 4        | -2
    // -2x = 2            | / -2
    // x = -1
    Point2D<> * intersection = firstGradient.intersection(secondGradient);
    ASSERT_TRUE(intersection);
    // The intersection is (1, 1)
    EXPECT_EQ(-1, intersection->getX());
    EXPECT_EQ(1, intersection->getY());
}