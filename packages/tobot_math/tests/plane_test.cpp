#include <gtest/gtest.h>

#include "plane.h"
#include "vector/vector3d.h"

/*
 * Testing plane creation
 */
TEST(Plane, CanBeCreatedWithList) {
    Tobot::Math::Plane<int> plane = {1, 2, 3, 4};
}

/*
 * Testing plane Distance
 */
TEST(Plane, Distance) {
    Tobot::Math::Plane<int> plane(5, 3, 2, 1);
    Tobot::Math::Vector3D<int> point(1, 2, 3);

    EXPECT_EQ(18, plane.Distance(point));
}

/*
 * Testing plane Normal
 */
TEST(Plane, Normal) {
    Tobot::Math::Plane<int> plane(5, 3, 2, 1);
    Tobot::Math::Vector3D<int> normal = plane.GetNormal();

    EXPECT_EQ(5, normal.x);
    EXPECT_EQ(3, normal.y);
    EXPECT_EQ(2, normal.z);
}