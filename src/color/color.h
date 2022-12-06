#pragma once

#include "math/vec3.h"
#include "utils/utils.h"

//constexpr double get_color_for_samples(double c, int samples)
//{
//    auto scale = 1./samples;
//    c *= scale;
//    return static_cast<int>(256 * clamp(c, .0, .999));
//}

void write_color(std::ostream &out, const Color& pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples.
    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}
