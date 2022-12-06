#include <gtest/gtest.h>

#include "math/vec3.h"


#include <iostream>
TEST(Vec3, Sum) {
    ASSERT_TRUE((vec3(1,2,3) + vec3(3, 4, 5)) == vec3(4, 6, 8));
    ASSERT_TRUE((vec3(1,2,3) - vec3(3, 4, 5)) == vec3(-2, -2, -2));
    ASSERT_TRUE((vec3(1,2,3) - vec3(3, 4, 5)) != vec3(-2, -2, -2.1));

    ASSERT_TRUE((-vec3(.1, .2, .3) + vec3(.1, .1, .1)) == vec3(0., -.1, -.2));

}

TEST(Vec3, division) {
    ASSERT_TRUE((vec3(3, 4, 5) / 10) == vec3(.3, .4, .5));
    vec3 v{2,2,2};
    v /= 2;
    ASSERT_TRUE(v == vec3(1, 1, 1));
    v += vec3(1, 2, 3);
    ASSERT_TRUE(v == vec3(2, 3, 4));

    v = vec3(2, 2, 2);
    ASSERT_TRUE((v/2 + vec3(1, 2, 3)) == vec3(2, 3, 4));

}


TEST(Vec3, unity_vector) {
    vec3 orig(1, 2, 3);
    auto u = unit_vector(orig);

    ASSERT_TRUE(u.length_squared() == 1);
    ASSERT_TRUE( cross(u, orig).length_squared() < 0.001 );
}
