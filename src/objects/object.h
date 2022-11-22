#pragma once

#include "math/vec3.h"
#include "math/ray.h"


struct hit_record {
    Point p;
    vec3 normal;
    double t;

    bool front_face;

    inline void set_fase_normal(const Ray& ray, const vec3& outward_normal) {
        front_face = dot(ray.direction(), outward_normal) < 0;
        normal = front_face? outward_normal : -outward_normal;
    }
};

class Object {
public:
    virtual bool ray_hit(const Ray& ray, double t_min, double t_max, hit_record& rec) const = 0;
    virtual ~Object() = default;
};
