#include <gtest/gtest.h>

#include "point2d.hpp"
#include "shape/circle.hpp"

using namespace Tobot::Math;

/*
 * Testing circle creation
 */
TEST(Circle, Creation) {
    Point2D<> lePoint(1, 2);
    Circle<> leCircle(lePoint, 3);
    EXPECT_EQ(1, leCircle.center().getX());
    EXPECT_EQ(2, leCircle.center().getY());
    EXPECT_EQ(3, leCircle.radius());
}

/*
 * Testing circle creation with a list
 */
TEST(Circle, CreationList) {
    Circle<> leCircle = {1, 2, 3};
    EXPECT_EQ(1, leCircle.center().getX());
    EXPECT_EQ(2, leCircle.center().getY());
    EXPECT_EQ(3, leCircle.radius());
}

/*
 * Testing copy constructor
 */
TEST(Circle, Copy) {
    Point2D<> lePoint(1, 2);
    Circle<> firstCircle(lePoint, 3);
    Circle<> secondCircle(firstCircle);
    firstCircle = {4, 5, 6};

    EXPECT_EQ(1, secondCircle.center().getX());
    EXPECT_EQ(2, secondCircle.center().getY());
    EXPECT_EQ(3, secondCircle.radius());
}

/*
 * Testing move constructor
 */
TEST(Circle, Move) {
    Point2D<> lePoint(1, 2);
    Circle<> firstCircle(lePoint, 3);
    Circle<> secondCircle(std::move(firstCircle));
    firstCircle = {4, 5, 6};

    EXPECT_EQ(1, secondCircle.center().getX());
    EXPECT_EQ(2, secondCircle.center().getY());
    EXPECT_EQ(3, secondCircle.radius());
}

/*
 * Testing circle area
 */
TEST(Circle, Area) {
    Point2D<> lePoint(1, 2);
    Circle<> leCircle(lePoint, 3);

    EXPECT_EQ(28.274334f, leCircle.getArea());
}

/*
 * Testing circle circumference
 */
TEST(Circle, Circumference) {
    Point2D<> lePoint(1, 2);
    Circle<> leCircle(lePoint, 3);

    EXPECT_EQ(18.849556f, leCircle.getCircumference());
}

/*
 * Testing circle distance
 */
TEST(Circle, Distance) {
    Point2D<> lePoint(5.0f, 3.0f);
    Circle<> leCircle(lePoint, 1.0f);

    Point2D<> lePoint2(4.0f, 2.0f);

    EXPECT_EQ(0.41421354f, leCircle.getDistance(lePoint2));
}