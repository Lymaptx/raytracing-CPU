#pragma once
#include "material.h"
#include"metal.h"
class metal;
class dielectric :
	public material
{
public:
	dielectric();
	dielectric(float a) :ref_idx(a) {}
	virtual bool scatter(const ray&r_in, const hit_record &rec, vec3&attenuation, ray& scattered)const;
	~dielectric();
	float ref_idx;
};

