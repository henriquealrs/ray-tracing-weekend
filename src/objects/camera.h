#ifndef CAMERA_H
#define CAMERA_H
#include "math/vec3.h"
#include "math/ray.h"

class Camera
{
    Point origin;
    Point lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
public:
    Camera();
    Ray get_ray(double u, double v) const;
};

#endif // CAMERA_H
