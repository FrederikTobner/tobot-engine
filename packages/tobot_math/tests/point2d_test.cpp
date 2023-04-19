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
 * Testing point creation
 */
TEST(Point2D, CanBeCreatedWithXAndY) {
    Point2D<> point(1, 2);
}

/*
 * Testing copy constructor
 */
TEST(Point2D, Copy) {
    Point2D<> firstPoint(5, 3);
    Point2D<> secondPoint(firstPoint);

    firstPoint = {4, 5};

    EXPECT_EQ(5, secondPoint.getX());
    EXPECT_EQ(3, secondPoint.getY());
}

/*
 * Testing move constructor
 */
TEST(Point2D, Move) {
    Point2D<> firstPoint(5, 3);
    Point2D<> secondPoint(std::move(firstPoint));

    firstPoint = {4, 5};

    EXPECT_EQ(5, secondPoint.getX());
    EXPECT_EQ(3, secondPoint.getY());
}

/*
 * Testing equality operator
 */
TEST(Point2D, EqualityOperator) {
    Point2D<> point1(1, 2);
    Point2D<> point2(1, 2);

    EXPECT_TRUE(point1 == point2);
}

/*
 * Testing inequality operator
 */
TEST(Point2D, InequalityOperator) {
    Point2D<> point1(1, 2);
    Point2D<> point2(3, 4);

    EXPECT_TRUE(point1 != point2);
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