
#include "color/color.h"
#include "math/ray.h"
#include "math/vec3.h"
#include "math/math_utils.h"
#include "objects/object.h"
#include "objects/sphere.h"
#include "scene/scene.h"

#include <iostream>

using std::vector;

Color ray_color(const Ray& r, const Scene& world) {
    hit_record rec;
    if (world.ray_hit(r, 0, infinity, rec)) {
        std::cerr << "== " << rec.normal << "\n";
        auto ret = 0.5 * (rec.normal + Color(1,1,1));
        std::cerr << "===  " << ret << "\n";
        return ret;
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*Color(1.0, 1.0, 1.0) + t*Color(0.5, 0.7, 1.0);
}

int main() {
//    Sphere s(vec3(-15, 0, 0), 5);
//    hit_record rec;
//    s.ray_hit(Ray(vec3(0, 0, 0), vec3(-1, 0, 0)), -100, 100, rec);
//    std::cout << rec.p << "\n";
//    return 0;


    Scene scene;
    scene.add_object(std::make_shared<Sphere>(Point(0,0,-1), 0.5));
    scene.add_object(std::make_shared<Sphere>(Point(0,-100.5,-1), 100));

    // Image
    constexpr auto aspect_ratio = 16.0 / 9.0;
    constexpr int image_width = 400;
    constexpr int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera
    constexpr auto viewport_height = 2.0;
    constexpr auto viewport_width = aspect_ratio * viewport_height;
    constexpr auto focal_length = 1.0;

    auto origin = Point(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    // Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width-1);
            auto v = double(j) / (image_height-1);
            Ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);

            auto pixel_color = ray_color(r, scene);

            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}
