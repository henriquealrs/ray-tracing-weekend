
#include "color/color.h"
#include "math/ray.h"
#include "math/vec3.h"
#include "math/math_utils.h"
#include "objects/object.h"
#include "objects/sphere.h"
#include "scene/scene.h"
#include "objects/camera.h"
#include "utils/rng.h"

#include <iostream>

using std::vector;

Color ray_color(const Ray& r, const Scene& world) {
    hit_record rec;
    if (world.ray_hit(r, 0, infinity, rec)) {
//        std::cerr << "== " << rec.normal << "\n";
        auto ret = 0.5 * (rec.normal + Color(1,1,1));
//        std::cerr << "===  " << ret << "\n";
        return ret;
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*Color(1.0, 1.0, 1.0) + t*Color(0.5, 0.7, 1.0);
}

int main() {

//    Camera cam_;

//    Scene scene_;
//    auto s = std::make_shared<Sphere>(vec3(0, 0, -1), .55);

//    scene_.add_object(s);
//    auto ray = cam_.get_ray(.5, .5);
//    hit_record rec;
//    scene_.ray_hit(ray, -1000, 1000, rec);
//    std::cout << rec.normal << " And " << rec.p << " and " << rec.t << "\n";

//    return 0;


    Scene scene;
    scene.add_object(std::make_shared<Sphere>(Point(0,0,-1), 0.5));
    scene.add_object(std::make_shared<Sphere>(Point(0,-100.5,-1), 100));

    // Image
    constexpr auto aspect_ratio = 16.0 / 9.0;
    constexpr int image_width = 400;
    constexpr int image_height = static_cast<int>(image_width / aspect_ratio);
    constexpr int samples_per_pixel = 100;

    // Camera
    Camera cam;

    // Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            Color pixel_color(0, 0, 0);
            for(int i = 0; i < samples_per_pixel; ++i) {
                auto u = (i + random_double<double>()) / (image_width - 1);
                auto v = (j + random_double<double>()) / (image_height - 1);
                auto ray = cam.get_ray(u, v);
                pixel_color += ray_color(ray, scene);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}
