#include <gtest/gtest.h>

#include "objects/sphere.h"
#include "math/ray.h"

#include <iostream>
TEST(Sphere, hit) {
    Sphere s(vec3(-10, 0, 0), 5);

    hit_record rec;
    ASSERT_TRUE(s.ray_hit(Ray(vec3(0, 0, 0), vec3(-1, 0, 0)), 0, 100, rec));
    ASSERT_TRUE(rec.p == vec3(-5, 0, 0));
    ASSERT_TRUE(rec.normal == vec3(1, 0, 0));

    std::cout << "AAAA" <<  "\n";

    ASSERT_FALSE(s.ray_hit(Ray(vec3(0, 0, 0), vec3(1, 0, 0)), 0, 100, rec));
    ASSERT_FALSE(s.ray_hit(Ray(vec3(0, 0, 0), vec3(0, 1, 0)), -100, 100, rec));
}
