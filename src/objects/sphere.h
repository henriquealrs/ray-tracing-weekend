#ifndef SPHERE_CPP
#define SPHERE_CPP

#include "objects/object.h"
#include "math/vec3.h"
#include "math/ray.h"

class Sphere : public Object
{
public:
    Sphere() = delete;
    Sphere(const Point& c, double r) : centre(c), radius(r), radius_sqr(r*r) {}

private:
    Point centre;
    double radius;
    double radius_sqr;

    // Object interface
public:

    // Object interface
public:
    bool ray_hit(const Ray &ray, double t_min, double t_max, hit_record &rec) const override;
};

#endif // SPHERE_CPP


