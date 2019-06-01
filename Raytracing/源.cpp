#include<iostream>
#include<fstream>
#include"vec3.h"  //双引号引用
#include"ray.h"
#include"sphere.h"
#include"hitable_list.h"

using namespace std;
//射线与球求交
bool hit_with_Sphere(const vec3& center, float r, const ray& ray)
{
	vec3 oc = ray.origin() - center;
	float a = oc.dot(ray.direction(), ray.direction());
	float b = 2.0* oc.dot(ray.direction(), oc);
	float c = oc.dot(oc, oc)-r*r;
	float dis = b*b - 4 * a*c;
	return (dis > 0);

}
float hit_Sphere(const vec3& center, float r, const ray& ray)
{
	vec3 oc = ray.origin() - center;
	float a = oc.dot(ray.direction(), ray.direction());
	float b = 2.0* oc.dot(ray.direction(), oc);
	float c = oc.dot(oc, oc) - r*r;
	float dis = b*b - 4 * a*c;
	if (dis < 0)
		return -1.0;
	else
		return ((-b - sqrt(dis)) / 2);
}
vec3 color(const ray&r)
{
	float t;
	vec3 center(0.0, 0.0, -1.0);
	t=hit_Sphere(center, 0.6, r);
	if (t - 0.0 > 0.0001)
	{
		vec3 normal = unit_vector(r.point_at_parameter(t) - center);
		normal += vec3(1.0, 1.0, 1.0);
		return (normal / 2);
	}
		
	else
	{
		vec3 unit_direction = unit_vector(r.direction());
		float a = (unit_direction.y() - (-1)) / 2;
		return (1.0 - a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);
	}
}

vec3 color(const ray&r, hitable *world)
{
	hit_record rec;
	if (world->hit(r, 0.0, 10000.0, rec))
	{
		rec.normal += vec3(1.0, 1.0, 1.0);
		return (rec.normal / 2);
	}
	else
	{
		vec3 unit_direction = unit_vector(r.direction());
		float a = (unit_direction.y() - (-1)) / 2;
		return (1.0 - a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);
	}

}
int main()
{
	int nx = 200;
	int ny = 100;
	
	ofstream outfile("chapter5_1.ppm", ios_base::out);
	outfile << "P3\n" << nx << " " << ny << "\n255\n";

	cout <<  "P3\n" << nx << " " << ny << "\n255\n";

	vec3 center(0.0, 0.0, 0.0);
	vec3 left_lower(-2.0, -1.0, -1.0);
	vec3 hor(4.0, 0.0, 0.0);
	vec3 ver(0.0, 2.0, 0.0);

	hitable *list[2];
	list[0] = new Sphere(vec3(0.0, 0.0, -1.0), 0.5);
	list[1] = new Sphere(vec3(0.0, -100.5, -1.0), 100);
	hitable *world = new hitable_list(list, 2);
	for (int j = ny - 1 ; j >= 0;j--)
	{
		for (int i = 0;i < nx;i++)
		{
			float u = 1.0*i / nx;
			float v = 1.0*j / ny;

			ray r(center, left_lower + u*hor + v*ver - center);


			vec3 col = color(r,world);
		//	vec3 color((float)i*1.0 / nx, (float)j*1.0 / ny,0.7);
			
			int ir = 255.99*col[0];
			int ig = 255.99*col[1];
			int ib = 255.99*col[2];

			outfile << ir << " " << ig << " " << ib << "\n";
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
}