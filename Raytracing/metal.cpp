#include "metal.h"


metal::metal()
{
}


metal::~metal()
{
}

vec3 metal::reflect(const vec3 & v, const vec3 & n)
{

	vec3 a;
	return (v - 2.0*a.dot(v, n)*n);
}
bool metal::scatter(const ray & r_in, const hit_record & rec, vec3 & attenuation, ray & scattered) const
{
	metal a;
	vec3 newReflect = a.reflect(unit_vector(r_in.direction()), rec.normal);
	scattered = ray(rec.p, newReflect+fuzz*simple_sphere(),r_in.time());
	attenuation = albedo;
	return (newReflect.dot(unit_vector(scattered.direction()), rec.normal)>0);
}
