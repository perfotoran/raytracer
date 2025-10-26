#pragma once

#include "vec3.h"

class ray {
	point3 orig;
	vec3 dir;

public:
	ray() = default;
	ray(point3 const& origin, vec3 const& direction) : orig(origin), dir(direction) {}

	const point3& origin() const { return orig; }
	const vec3& direction() const { return dir; }

	point3 at(double t) const { return orig + t * dir; }
};