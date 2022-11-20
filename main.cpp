
#include "color/color.h"
#include "math/ray.h"
#include "math/vec3.h"
#include "objects/object.h"
#include "objects/sphere.h"

#include <vector>
#include <iostream>
#include <memory>

using ObjectPtr = std::shared_ptr<Object>;
using std::vector;

Color ray_color(const Ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*Color(1.0, 1.0, 1.0) + t*Color(0.5, 0.7, 1.0);
}

int main() {
    std::cerr << (-vec3(.1, .2, .3) + vec3(.1, .1, .1)) << std::endl;
    std::cerr << ((-vec3(.1, .2, .3) + vec3(.1, .1, .1)) == vec3(0., -.1, -.2)) << "\n";

    vector<ObjectPtr> scene;
    scene.push_back(std::make_shared<Sphere>(vec3(0, 0, -1), .5));

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

            auto pixel_color = [&scene](const Ray& r) {
                for(auto& obj : scene) {
                    if(obj->ray_hit(r)) {
                        return Color(1, 0, 0);
                    }
                }
                return ray_color(r);
            }(r);

            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}
