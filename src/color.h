#pragma once

#include "vec3.h"
#include "interval.h"

using color = vec3;

void write_color(std::ostream& out, color const& pixel_color) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	// [0, 1] - > [0, 255]

	static const interval intensity(0.000, 0.999);
	int rbyte = static_cast<int>(256 * intensity.clamp(r));
	int gbyte = static_cast<int>(256 * intensity.clamp(g));
	int bbyte = static_cast<int>(256 * intensity.clamp(b));

	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}