#include<iostream>
#include<fstream>
#include"vec3.h"  //双引号引用
#include"ray.h"
#include"sphere.h"
#include"hitable_list.h"
#include"camera.h"
#include"material.h"
#include"metal.h"
#include"lambertian.h"
#include"dielectric.h"
#include"move_Sphere.h"
using namespace std;
//射线与球求交
//bool hit_with_Sphere(const vec3& center, float r, const ray& ray)
//{
//	vec3 oc = ray.origin() - center;
//	float a = oc.dot(ray.direction(), ray.direction());
//	float b = 2.0* oc.dot(ray.direction(), oc);
//	float c = oc.dot(oc, oc)-r*r;
//	float dis = b*b - 4 * a*c;
//	return (dis > 0);
//
//}
//float hit_Sphere(const vec3& center, float r, const ray& ray)
//{
//	vec3 oc = ray.origin() - center;
//	float a = oc.dot(ray.direction(), ray.direction());
//	float b = 2.0* oc.dot(ray.direction(), oc);
//	float c = oc.dot(oc, oc) - r*r;
//	float dis = b*b - 4 * a*c;
//	if (dis < 0)
//		return -1.0;
//	else
//		return ((-b - sqrt(dis)) / 2);
//}
//vec3 color(const ray&r)
//{
//	float t;
//	vec3 center(0.0, 0.0, -1.0);
//	t=hit_Sphere(center, 0.6, r);
//	if (t - 0.0 > 0.0001)
//	{
//		vec3 normal = unit_vector(r.point_at_parameter(t) - center);
//		normal += vec3(1.0, 1.0, 1.0);
//		return (normal / 2);
//	}
//		
//	else
//	{
//		vec3 unit_direction = unit_vector(r.direction());
//		float a = (unit_direction.y() - (-1)) / 2;
//		return (1.0 - a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);
//	}
//}
vec3 color(const ray&r, hitable *world,int depth)
{
	hit_record rec;
	if (world->hit(r, 0.01, 10000.0, rec))
	{
		ray scattered;
		vec3 attenuation;
		if ((depth < 50) && (rec.mat_ptr->scatter(r, rec, attenuation, scattered)))
		{
			depth++;
			return attenuation*color(scattered, world, depth);

		}
		else
			return vec3(0.0, 0.0, 0.0);
	}

	else
	{
		vec3 unit_direction = unit_vector(r.direction());
		float a = (unit_direction.y() - (-1)) / 2;
		return (1.0 - a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);
	}

}
hitable* random_scene()
{
	int n = 500;
	hitable **list = new hitable *[n + 1];
	list[0] = new Sphere(vec3(0.0, -1000.0, 0.0), 1000, new metal(vec3(0.5, 0.5, 0.5),0.3));
	int count = 1;
	for (int i = -11;i < 11;i++)
	{
		for (int j = -11;j < 11;j++)
		{
			
			float choose_mat = (rand() % 100 / 100.0);
			vec3 center(i + 0.9*(rand() % 100 )/ 100.0, 0.2, j + 0.9*(rand() % 100 / 100.0));
			if ((center - vec3(4.0, 0.2, 0.0)).length() > 0.9)
			{
				if (choose_mat > 0.7)
				{
					list[count++] = new move_Sphere(center,center+vec3(0.0,0.5*(rand()%100)/100.0,0.0), 0.2, 
						new lambertian(vec3((rand() % 100 / 100.0)*(rand() % 100 / 100.0), (rand() % 100 / 100.0)*(rand() % 100 / 100.0), (rand() % 100 / 100.0)*(rand() % 100 / 100.0)))
						,0.0,1.0);
				}
				else if (choose_mat < 0.95)
				{
					list[count++] = new Sphere(center, 0.2,
						new metal(vec3(0.5*(1 + (rand() % (100) / (float)(100))),
							0.5*(1 + (rand() % (100) / (float)(100))),
							0.5*(1 + (rand() % (100) / (float)(100)))),
							0.1*(1 + (rand() % (100) / (float)(100)))));

				
				
				}
				else
				{
					list[count++] = new Sphere(center, 0.2, new dielectric(1.5));
				}
			}
		}
	}
	list[count++] = new Sphere(vec3(0, 1, 0), 1.0, new dielectric(1.5));
	list[count++] = new Sphere(vec3(-4, 1, 0), 1.0, new lambertian(vec3(0.4, 0.2, 0.1)));
	list[count++] = new Sphere(vec3(4, 1, 0), 1.0, new metal(vec3(0.7, 0.6, 0.5), 0.0));

	return new hitable_list(list, count);
}


int main()
{
	int nx = 1200;
	int ny = 800;
	int ns = 50;
	
	ofstream outfile("chapterNext_1.ppm", ios_base::out);
	outfile << "P3\n" << nx << " " << ny << "\n255\n";

	cout <<  "P3\n" << nx << " " << ny << "\n255\n";
	vec3 lookfrom(13, 2, 3);
	vec3 lookat(0, 0, 0.0);
	camera cam(lookfrom, lookat, vec3(0, 1, 0), 20, float(nx) / float(ny),(lookfrom-lookat).length(),0.0,0.0,0.3);

	hitable *list[5];

	list[0] = new Sphere(vec3(0, 0, -1), 0.5, new lambertian(vec3(0.1, 0.2, 0.5)));

	list[4] = new Sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.8, 0.8, 0.0)));

	list[2] = new Sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2), 0.0));

	list[3] = new Sphere(vec3(-1, 0, -1), 0.5, new dielectric(1.5));

	list[1] = new Sphere(vec3(-1, 0, -1), -0.2, new dielectric(1.5));

	hitable *world = random_scene();

	for (int j = ny - 1 ; j >= 0;j--)
	{
		for (int i = 0;i < nx;i++)
		{
			vec3 col(0.0,0.0,0.0);
			for (int k = 0;k < ns;k++)
			{
				float random = rand()%100/100.0;
				float u = 1.0*(i+random) / nx;
				float v = 1.0*(j+random) / ny;
				//cout << random << endl;
				ray r = cam.get_ray(u, v);


				col += color(r, world,0);
				//	vec3 color((float)i*1.0 / nx, (float)j*1.0 / ny,0.7);
			}
			col /= (1.0*ns);
			col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));//gamma2矫正
			int ir = 255.99*col[0];
			int ig = 255.99*col[1];
			int ib = 255.99*col[2];

			outfile << ir << " " << ig << " " << ib << "\n";
			//std::cout << ir << " " << ig << " " << ib << "\n";
			
		}
		cout << j << "end" << endl;
	}
	cout << "______" << "end" << endl;
}