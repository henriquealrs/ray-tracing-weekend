#pragma once

#include "math/vec3.h"
#include "math/ray.h"



class Object {
public:
    virtual bool ray_hit(const Ray& ray) const = 0;
    virtual ~Object() = default;
};
