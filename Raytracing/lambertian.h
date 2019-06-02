#pragma once
#include "material.h"
class lambertian :
	public material
{
public:
	lambertian(const vec3&a) :albedo(a) {}
	virtual bool scatter(const ray&r_in, const hit_record &rec, vec3&attenuation, ray& scattered)const;
	~lambertian();
	vec3 albedo;
};

