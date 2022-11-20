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

    // Object interface
    bool ray_hit(const Ray &ray) const;

private:
    Point centre;
    double radius;
    double radius_sqr;
};

#endif // SPHERE_CPP


