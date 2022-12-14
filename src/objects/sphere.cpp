#include "objects/sphere.h"
#include "math/vec3.h"
#include <cmath>

#include <iostream>

bool Sphere::ray_hit(const Ray &r, double t_min, double t_max, hit_record &rec) const
{
    vec3 oc = r.Origin() - this->centre;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - this->radius_sqr;

    auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    rec.t = root;
    rec.p = r.At(rec.t);

    auto outward_normal = (rec.p - centre) / radius;
    rec.set_fase_normal(r, outward_normal);

    return true;

}
