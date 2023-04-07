#include <gtest/gtest.h>

#include "point2D.h"
#include "shape/rectangle.h"

using namespace Tobot::Math;

/*
 * Testing rectangle creation
 */
TEST(Rectangle, Creation) {
    Point2D<> point1(1, 2);
    Rectangle2D<> rectangle(point1, 2, 2, 0);
}

/*
 * Testing rectangle creation with list
 */
TEST(Rectangle, CreationWithList) {
    Rectangle2D<> rectangle = {1, 2, 2, 2, 0};
}

/*
 * Testing copy constructor
 */
TEST(Rectangle, Copy) {
    Point2D<> point1(1, 2);
    Rectangle2D<> firstRectangle(point1, 2, 2, 0);
    Rectangle2D<> secondRectangle(firstRectangle);

    firstRectangle = {4, 5, 2, 2, 0};

    EXPECT_EQ(1, secondRectangle.getCenter().x());
    EXPECT_EQ(2, secondRectangle.getCenter().y());
    EXPECT_EQ(2, secondRectangle.getWidth());
    EXPECT_EQ(2, secondRectangle.getHeight());
    EXPECT_EQ(0, secondRectangle.getRotation());
}

/*
 * Testing rectangle area
 */
TEST(Rectangle, Area) {
    Point2D<> point1(1, 2);
    Rectangle2D<> rectangle(point1, 2, 2, 0);

    EXPECT_EQ(4, rectangle.getArea());
}

/*
 * Testing rectangle perimeter
 */
TEST(Rectangle, Circumference) {
    Point2D<> point1(1, 2);
    Rectangle2D<> rectangle(point1, 2, 2, 0);

    EXPECT_EQ(8, rectangle.getPerimeter());
}

/*
 * Testing rectangle contains
 */
TEST(Rectangle, Contains) {
    Point2D<> point1(1, 2);
    Rectangle2D<> rectangle(point1, 2, 2, 0);

    Point2D<> point2(1.5f, 2.5f);

    EXPECT_TRUE(rectangle.contains(point2));
}