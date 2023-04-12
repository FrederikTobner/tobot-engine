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
 * Testing copy constructor
 */
TEST(Triangle, Copy) {
    Point2D<> point1(1, 2);
    Point2D<> point2(3, 4);
    Point2D<> point3(5, 6);
    Triangle2D<> firstTriangle(point1, point2, point3);
    Triangle2D<> secondTriangle(firstTriangle);

    firstTriangle = {Point2D<>(4, 5), Point2D<>(6, 7), Point2D<>(8, 9)};

    EXPECT_EQ(1, secondTriangle.getA().getX());
    EXPECT_EQ(2, secondTriangle.getA().getY());
    EXPECT_EQ(3, secondTriangle.getB().getX());
    EXPECT_EQ(4, secondTriangle.getB().getY());
    EXPECT_EQ(5, secondTriangle.getC().getX());
    EXPECT_EQ(6, secondTriangle.getC().getY());
}

/*
 * Testing move constructor
 */
TEST(Triangle, Move) {
    Point2D<> point1(1, 2);
    Point2D<> point2(3, 4);
    Point2D<> point3(5, 6);
    Triangle2D<> firstTriangle(point1, point2, point3);
    Triangle2D<> secondTriangle(std::move(firstTriangle));

    firstTriangle = {Point2D<>(4, 5), Point2D<>(6, 7), Point2D<>(8, 9)};

    EXPECT_EQ(1, secondTriangle.getA().getX());
    EXPECT_EQ(2, secondTriangle.getA().getY());
    EXPECT_EQ(3, secondTriangle.getB().getX());
    EXPECT_EQ(4, secondTriangle.getB().getY());
    EXPECT_EQ(5, secondTriangle.getC().getX());
    EXPECT_EQ(6, secondTriangle.getC().getY());
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