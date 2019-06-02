#include "dielectric.h"



dielectric::dielectric()
{
}

bool refract(const vec3 &v, const vec3 &n, float ni_over_nt, vec3&refracted)
{
	vec3 v1 = unit_vector(v);
	float dt = v1.dot(v1, n);
	float dis = 1.0 - ni_over_nt*ni_over_nt*(1.0 - dt*dt);
	if (dis > 0)
	{
		refracted = ni_over_nt*v1 + (ni_over_nt*(-dt) - sqrt(dis))*n;
		return true;
	}
	else
		return false;
}
float schlick(float consine,float ref_idx)   //反射系数
{
	float r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0*r0;
	return r0 + (1 - r0)*pow((1 - consine), 5);
}
bool dielectric::scatter(const ray & r_in, const hit_record & rec, vec3 & attenuation, ray & scattered) const
{
	vec3 outward_normal;
	float ni_over_nt;
	metal a;
	vec3 reflected = a.reflect(r_in.direction(), rec.normal);
	attenuation = vec3(1.0, 1.0, 1.0);
	vec3 refracted;
	float reflect_prob;
	float consine;

	if (refracted.dot(r_in.direction(), rec.normal)>0)
	{
		outward_normal = -rec.normal;
		ni_over_nt = ref_idx;
		consine = refracted.dot(r_in.direction(), rec.normal)/r_in.direction().length();
		//由球射入空气
		
	}
	else
	{
		//空气射入球
		outward_normal = rec.normal;
		ni_over_nt = 1.0 / ref_idx;
		consine = -refracted.dot(r_in.direction(), rec.normal) / r_in.direction().length();
	}
	if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted))
	{
		reflect_prob = schlick(consine, ref_idx);
	}
	else
	{
		
		reflect_prob = 1.0;
	}
	if ((rand() % 100 / 100.0) < reflect_prob)
	{
		scattered = ray(rec.p, reflected);
	}
	else
		scattered = ray(rec.p, refracted);

	return true;
}

