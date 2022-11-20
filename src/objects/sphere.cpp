#include "objects/sphere.h"
#include "math/vec3.h"

bool Sphere::ray_hit(const Ray& ray) const
{
    auto oc = ray.Origin() -  this->centre;
    auto a = dot(ray.direction(), ray.direction());
    auto b = 2. * dot(ray.direction(), oc);
    auto c = dot(oc, oc) - this->radius_sqr;
    auto discriminant = b*b - 4 * a *c;
    return discriminant >= 0;
}
