#pragma once
#include <cmath>
#include <iostream>

class vec3 {
    const double COMPARE_THRESHOLD = 0.0001;
    double len_sqr;
    double len;
public:
    vec3() : e{0,0,0} {}
    vec3(double x, double y, double z) :
        len_sqr(x*x + y*y + z*z), len(std::sqrt(len_sqr)), e{x, y, z}
    {}

    vec3 operator+(const vec3& op) const noexcept {
        return vec3(this->e[0] + op.e[0], this->e[1] + op.e[1], this->e[2] + op.e[2]);
    }

    vec3 operator*(double x) const noexcept {
        return vec3(this->e[0] * x, this->e[1] * x, this->e[2] * x);
    }

    vec3 operator/(double x) const  noexcept {
        return vec3(this->e[0] / x, this->e[1] / x, this->e[2] / x);
    }

    vec3& operator+=(const vec3& op) {
        this->e[0] += op.e[0];
        this->e[1] += op.e[1];
        this->e[2] += op.e[2];
        return *this;
    }

    vec3& operator*=(const double x) noexcept {
        this->e[0] *= x;
        this->e[1] *= x;
        this->e[2] *= x;
        return *this;
    }

    vec3& operator/=(const double x) noexcept {
        this->e[0] /= x;
        this->e[1] /= x;
        this->e[2] /= x;
        return *this;
    }

    double x() const noexcept {return e[0];}
    double y() const noexcept {return e[1];}
    double z() const noexcept {return e[2];}

    double length_squared() const noexcept {
        return this->len_sqr;
    }

    double length() const noexcept {
        return this->len;
    }

    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    bool operator==(const vec3& v) {
        return ( std::abs(e[0] -  v.e[0]) <= COMPARE_THRESHOLD) &&
                ( std::abs(e[1] -  v.e[1]) <= COMPARE_THRESHOLD) &&
                ( std::abs(e[2] -  v.e[2]) <= COMPARE_THRESHOLD);
    }

    bool operator!=(const vec3& v) {
        return ( std::abs(e[0] -  v.e[0]) > COMPARE_THRESHOLD) ||
                ( std::abs(e[1] -  v.e[1]) > COMPARE_THRESHOLD) ||
                ( std::abs(e[2] -  v.e[2]) > COMPARE_THRESHOLD);
    }

    vec3 operator=(const vec3& orig) {
        return vec3(orig);
    }

    double e[3];
};

using Point = vec3;
using Color = vec3;


inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// inline vec3 operator+(const vec3 &u, const vec3 &v) {
//     return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
// }

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    auto ret = v / v.length();
    std::cerr << v << " >>> " << ret.length() <<  "\n";
    return ret;
}
