#pragma once
#include "hitable.h"
class Sphere :
	public hitable
{
public:
	Sphere() {};
	Sphere(vec3 center, float r) :center(center),radius(r) {};//初始化列表
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec)const;
	vec3 center;
	float radius;
	~Sphere();
};
