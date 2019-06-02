#include "metal.h"


metal::metal()
{
}


metal::~metal()
{
}
vec3 reflect(const vec3 &v, const vec3&n)
{
	vec3 a;
	return (v - 2.0*a.dot(v, n)*n);
}
bool metal::scatter(const ray & r_in, const hit_record & rec, vec3 & attenuation, ray & scattered) const
{
	vec3 newReflect = reflect(unit_vector(r_in.direction()), rec.normal);
	scattered = ray(rec.p, newReflect+fuzz*simple_sphere());
	attenuation = albedo;
	return (newReflect.dot(unit_vector(scattered.direction()), rec.normal)>0);
}