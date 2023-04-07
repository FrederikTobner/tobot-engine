#include <gtest/gtest.h>

#include "point2d.h"

using namespace Tobot::Math;

/*
 * Testing point creation
 */
TEST(Point2D, CanBeCreatedWithList) {
    Point2D<> point = {1, 2};
}

/*
 * Testing copy constructor
 */
TEST(Point2D, Copy) {
    Point2D<> firstPoint(5, 3);
    Point2D<> secondPoint(firstPoint);

    EXPECT_EQ(5, secondPoint.x());
    EXPECT_EQ(3, secondPoint.y());
}

/*
 * Testing point distance
 */
TEST(Point2D, Distance) {
    Point2D<> point1(0, 0);
    Point2D<> point2(3, 4);

    // Distance between (0, 0) and (3, 4) is 5, because sqrt(3^2 + 4^2) = 5
    // Pythagoras theorem
    EXPECT_EQ(5.0f, point1.distance(point2));
}