#pragma once
#include "hitable.h"
class move_Sphere :
	public hitable
{
public:
	move_Sphere();
	move_Sphere(vec3 center0,vec3 center1, float r, material *m, float t0, float t1) :center0(center0),center1(center1), radius(r), ma(m), time0(t0), time1(t1) {}
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec)const;
	vec3 getCenter(float time)const;
	~move_Sphere();
	vec3 center0;
	vec3 center1;
	float radius;
	material *ma;
	float time0;
	float time1;
};

