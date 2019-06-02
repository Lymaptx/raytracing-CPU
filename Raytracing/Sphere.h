#pragma once
#include "hitable.h"
class Sphere :
	public hitable
{
public:
	Sphere() {};
	Sphere(vec3 center, float r,material *m) :center(center),radius(r) ,ma(m){};//初始化列表
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec)const;
	vec3 center;
	float radius;
	material *ma;
	~Sphere();
};
