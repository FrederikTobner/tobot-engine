#include <gtest/gtest.h>

#include "point2d.h"
#include "shape/triangle.h"

using namespace Tobot::Math;

/*
 * Testing triangle creation
 */
TEST(Triangle, Creation) {
    Point2D<> point1(1, 2);
    Point2D<> point2(3, 4);
    Point2D<> point3(5, 6);
    Triangle2D<> triangle(point1, point2, point3);
}

/*
 * Testing triangle area
 */
TEST(Triangle, Area) {
    Point2D<> point1(1, 2);
    Point2D<> point2(3, 4);
    Point2D<> point3(5, 6);
    Triangle2D<> triangle(point1, point2, point3);

    auto v = triangle.getArea();

    EXPECT_EQ(0.158248395f, v);
}