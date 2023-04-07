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
 * Testing plane Distance
 */
TEST(Plane, Distance) {
    Plane<> plane(5, 3, 2, 1);
    Vector3D<> point(1, 2, 3);

    EXPECT_EQ(18, plane.Distance(point));
}

/*
 * Testing plane Normal
 */
TEST(Plane, Normal) {
    Plane<> plane(5, 3, 2, 1);
    Vector3D<> normal = plane.GetNormal();

    EXPECT_EQ(5, normal.x);
    EXPECT_EQ(3, normal.y);
    EXPECT_EQ(2, normal.z);
}