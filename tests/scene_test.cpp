#include <gtest/gtest.h>

#include "objects/sphere.h"
#include "math/ray.h"
#include "scene/scene.h"

TEST(Scene, hit) {
    Scene scene;
    auto s = std::make_shared<Sphere>(vec3(-10, 0, 0), 5);

    scene.add_object(s);
    hit_record rec;
    ASSERT_TRUE(scene.ray_hit(Ray(vec3(0, 0, 0), vec3(-1, 0, 0)), 0, 100, rec));
    ASSERT_TRUE(rec.p == vec3(-5, 0, 0));
    ASSERT_TRUE(rec.normal == vec3(1, 0, 0));

    std::cout << "AAAA" <<  "\n";

    ASSERT_FALSE(scene.ray_hit(Ray(vec3(0, 0, 0), vec3(1, 0, 0)), 0, 100, rec));
    ASSERT_FALSE(scene.ray_hit(Ray(vec3(0, 0, 0), vec3(0, 1, 0)), -100, 100, rec));
}
