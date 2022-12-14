#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <limits>

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#endif // MATH_UTILS_H
