#include <gtest/gtest.h>

#include "point2d.h"

/*
 * Testing point creation
 */
TEST(Point2D, CanBeCreatedWithList) {
    Tobot::Math::Point2D<> point = {1, 2};
}

/*
 * Testing copy constructor
 */
TEST(Point2D, Copy) {
    Tobot::Math::Point2D<> firstPoint(5, 3);
    Tobot::Math::Point2D<> secondPoint(firstPoint);

    EXPECT_EQ(5, secondPoint.x());
    EXPECT_EQ(3, secondPoint.y());
}

/*
 * Testing point distance
 */
TEST(Point2D, Distance) {
    Tobot::Math::Point2D<> point1(5, 3);
    Tobot::Math::Point2D<> point2(4, 2);

    EXPECT_EQ(1.41421354f, point1.distance(point2));
}