#pragma once

#include "vec3.h"

#define THRESHOLD 0.001

class Ray {
    Point origin;
    vec3 dir;

public:
    Ray() = delete;
    Ray(const Point& _origin, const vec3& _dir) noexcept : origin(_origin), dir(_dir)  {}

    static Ray FromPoints(const Point& p1, const Point& p2) noexcept {
        vec3 dir = p2 + (-p1);
        dir /= dir.length();
        std::cout << dir << '\n';
        return Ray(p1, dir);
    }

    const vec3& direction() const {
        return dir;
    }

    Point At(double t) const {
        return origin + t * dir;
    }

    Point Origin() const { return origin; }
};
