#include <gtest/gtest.h>

#include "point2d.hpp"
#include "shape/polygon.hpp"

using namespace Tobot::Math;

/*
 * Testing polygon creation
 */
TEST(Polygon, Creation) {
    Point2D<> point1(1, 2);
    Point2D<> point2(3, 4);
    Point2D<> point3(5, 6);
    Polygon2D<> polygon = {point1, point2, point3};
}

/*
 * Testing copy constructor
 */
TEST(Polygon, Copy) {
    Point2D<> point1(1, 2);
    Point2D<> point2(3, 4);
    Point2D<> point3(5, 6);
    Polygon2D<> firstPolygon = {point1, point2, point3};
    Polygon2D<> secondPolygon(firstPolygon);

    firstPolygon = {{4, 5}, {6, 7}, {8, 9}};

    EXPECT_EQ(3, secondPolygon.getPoints().size());
    EXPECT_EQ(1, secondPolygon.getPoints()[0].getX());
    EXPECT_EQ(2, secondPolygon.getPoints()[0].getY());
    EXPECT_EQ(3, secondPolygon.getPoints()[1].getX());
    EXPECT_EQ(4, secondPolygon.getPoints()[1].getY());
    EXPECT_EQ(5, secondPolygon.getPoints()[2].getX());
    EXPECT_EQ(6, secondPolygon.getPoints()[2].getY());
}
