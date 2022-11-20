#include <gtest/gtest.h>

#include "math/vec3.h"


#include <iostream>
TEST(Vec3, Sum) {
    ASSERT_TRUE((vec3(1,2,3) + vec3(3, 4, 5)) == vec3(4, 6, 8));
    ASSERT_TRUE((vec3(1,2,3) - vec3(3, 4, 5)) == vec3(-2, -2, -2));
    ASSERT_TRUE((vec3(1,2,3) - vec3(3, 4, 5)) != vec3(-2, -2, -2.1));

    ASSERT_TRUE((-vec3(.1, .2, .3) + vec3(.1, .1, .1)) == vec3(0., -.1, -.2));

}
