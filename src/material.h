#pragma once

#include "color.h"
#include "hittable.h"

class material {
public:
	virtual ~material() = default;

	virtual bool scatter(ray const& r_in, hit_record const& rec, color& attenuation,
	                     ray& scattered) const {
		return false;
	}
};

class lambertian : public material {
private:
	color albedo;

public:
	lambertian(color const& albedo) : albedo(albedo) {}

	bool scatter(ray const& r_in, hit_record const& rec, color& attenuation,
	             ray& scattered) const override {
		auto scatter_direction = rec.normal + random_unit_vector();

		// Catch degenerate scatter direction
		if (scatter_direction.near_zero())
			scatter_direction = rec.normal;

		scattered = ray(rec.point, scatter_direction);
		attenuation = albedo;
		return true;
	}
};

class metal : public material {
private:
	color albedo;
	double fuzz;

public:
	metal(color const& albedo, double fuzz) : albedo(albedo), fuzz(fuzz) {}

	bool scatter(ray const& r_in, hit_record const& rec, color& attenuation,
	             ray& scattered) const override {
		vec3 reflected = reflect(r_in.direction(), rec.normal);
		reflected = unit_vector(reflected) + (fuzz * random_unit_vector());
		scattered = ray(rec.point, reflected);
		attenuation = albedo;
		return dot(scattered.direction(), rec.normal) > 0;
	}
};