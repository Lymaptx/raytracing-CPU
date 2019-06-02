#include "lambertian.h"






bool lambertian::scatter(const ray & r_in, const hit_record & rec, vec3 & attenuation, ray & scattered) const
{
	vec3 s = simple_sphere();
	vec3 new_point = rec.p + rec.normal + s;
	scattered=ray (rec.p, new_point - rec.p);
	attenuation = albedo;
	return true;
}

lambertian::~lambertian()
{
}
