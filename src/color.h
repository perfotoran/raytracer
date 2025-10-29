#pragma once

#include "vec3.h"

using color = vec3;

void write_color(std::ostream& out, color const& pixel_color) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	// [0, 1] - > [0, 255]

	int rbyte = static_cast<int>(255.999 * r);
	int gbyte = static_cast<int>(255.999 * g);
	int bbyte = static_cast<int>(255.999 * b);

	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}