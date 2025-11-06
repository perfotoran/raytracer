#pragma once

#include "hittable.h"
#include "color.h"

class material {
    public:
    virtual ~material() = default;

    virtual bool scatter(ray const& r_in, hit_record const& rec, color& attenuation, ray& scattered) const { return false; }
};