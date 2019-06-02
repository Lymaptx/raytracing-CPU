#pragma once
#include "material.h"
#include"lambertian.h"
class metal :
	public material
{
public:
	metal();
	metal(const vec3&a,const float &fuzz) :albedo(a),fuzz(fuzz) {}
	~metal();
	vec3 albedo;
	float fuzz;
	virtual bool scatter(const ray&r_in, const hit_record &rec, vec3&attenuation, ray& scattered)const;
};

