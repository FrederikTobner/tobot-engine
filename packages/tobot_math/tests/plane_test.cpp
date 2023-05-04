#include <gtest/gtest.h>

#include "plane.h"
#include "vector/vector3d.h"

using namespace Tobot::Math;

/*
 * Testing plane creation
 */
TEST(Plane, CanBeCreatedWithList) {
    Plane<> plane = {1, 2, 3, 4};
}

/*
 * Testing plane creation
 */
TEST(Plane, CanBeCreatedWithValues) {
    Plane<> plane(1, 2, 3, 4);
}

/*
 * Testing copy constructor
 */
TEST(Plane, Copy) {
    Plane<> firstPlane(5, 3, 2, 1);
    Plane<> secondPlane(firstPlane);

    firstPlane = {0, 0, 0, 0};

    EXPECT_EQ(5, secondPlane.getA());
    EXPECT_EQ(3, secondPlane.getB());
    EXPECT_EQ(2, secondPlane.getC());
    EXPECT_EQ(1, secondPlane.getD());
}

/*
 * Testing plane move constructor
 */
TEST(Plane, Move) {
    Plane<> firstPlane(5, 3, 2, 1);
    Plane<> secondPlane(std::move(firstPlane));

    firstPlane = {0, 0, 0, 0};

    EXPECT_EQ(5, secondPlane.getA());
    EXPECT_EQ(3, secondPlane.getB());
    EXPECT_EQ(2, secondPlane.getC());
    EXPECT_EQ(1, secondPlane.getD());
}

/*
 * Testing equality operator
 */
TEST(Plane, EqualityOperator) {
    Plane<> plane1(1, 2, 3, 4);
    Plane<> plane2(1, 2, 3, 4);

    EXPECT_TRUE(plane1 == plane2);
}

/*
 * Testing inequality operator
 */
TEST(Plane, InequalityOperator) {
    Plane<> plane1(1, 2, 3, 4);
    Plane<> plane2(5, 6, 7, 8);

    EXPECT_TRUE(plane1 != plane2);
}

/*
 * Testing plane Distance
 */
TEST(Plane, Distance) {
    Plane<> plane(5, 3, 2, 1);
    Vector3D<> point(1, 2, 3);

    EXPECT_EQ(18, plane.distance(point));
}

/*
 * Testing plane Normal
 */
TEST(Plane, Normal) {
    Plane<> plane(5, 3, 2, 1);
    Vector3D<> normal = plane.getNormal();

    EXPECT_EQ(5, normal.getX());
    EXPECT_EQ(3, normal.getY());
    EXPECT_EQ(2, normal.getZ());
}