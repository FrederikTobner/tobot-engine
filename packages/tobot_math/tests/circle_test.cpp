#include <gtest/gtest.h>

#include "point2d.h"
#include "shape/circle.h"

using namespace Tobot::Math;

/*
 * Testing circle creation
 */
TEST(Circle, Creation) {
    Point2D<> lePoint(1, 2);
    Circle<> leCircle(lePoint, 3);
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