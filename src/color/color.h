#pragma once

#include "math/vec3.h"
#include "utils/utils.h"

constexpr double get_color_for_samples(double c, int samples)
{
    auto scale = 1./samples;
    c *= scale;
    return static_cast<int>(256 * clamp(c, .0, .999));
}

void write_color(std::ostream &out, const Color& pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Write the translated [0,255] value of each color component.
    out << get_color_for_samples(r, samples_per_pixel) << ' '
        << get_color_for_samples(g, samples_per_pixel) << ' '
        << get_color_for_samples(b, samples_per_pixel) << '\n';
}
