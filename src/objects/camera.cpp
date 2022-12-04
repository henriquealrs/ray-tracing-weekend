#include "objects/camera.h"

Camera::Camera()
{
    auto aspect_ratio = 16.0 / 9.0;
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    origin = Point(0, 0, 0);
    horizontal = vec3(viewport_width, 0.0, 0.0);
    vertical = vec3(0.0, viewport_height, 0.0);
    lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

}

Ray Camera::get_ray(double u, double v) const
{
    return Ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}
