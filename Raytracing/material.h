#ifndef MATERIAL_H
#define MATERIAL_H
#include "hitable.h"
class ray;
class hit_record;
class vec3;
vec3 simple_sphere();
class material
{
public:
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
	
};

#endif // MATERIAL_H
