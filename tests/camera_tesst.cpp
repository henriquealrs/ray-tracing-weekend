#include <gtest/gtest.h>

#include "objects/sphere.h"
#include "math/ray.h"
#include "scene/scene.h"
#include "objects/camera.h"

TEST(Camera, ray) {
    Camera cam;

    Scene scene;
    auto s = std::make_shared<Sphere>(vec3(-10, 0, 0), 5);

    scene.add_object(s);


    auto ray = cam.get_ray(1, 2);
    hit_record rec;
    scene.ray_hit(ray, -100, 100, rec);
}
