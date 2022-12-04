#ifndef UTILS_H
#define UTILS_H

constexpr double clamp(double x, double min, double max)
{
    if(x<min) {
        return min;
    }
    if (x > max) {
        return max;
    }
    return x;
}

#endif // UTILS_H
