#include<iostream>
#include<fstream>
#include"vec3.h"  //Ë«ÒýºÅÒýÓÃ
#include"ray.h"
using namespace std;

vec3 color(const ray&r)
{
	vec3 unit_direction = unit_vector(r.direction());
	float a = (unit_direction.y() -(- 1) )/ 2;
	return (1.0 - a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);
}
int main()
{
	int nx = 200;
	int ny = 100;
	
	ofstream outfile("chapter3.ppm", ios_base::out);
	outfile << "P3\n" << nx << " " << ny << "\n255\n";

	cout <<  "P3\n" << nx << " " << ny << "\n255\n";

	vec3 center(0.0, 0.0, 0.0);
	vec3 left_lower(-2.0, -1.0, -1.0);
	vec3 hor(4.0, 0.0, 0.0);
	vec3 ver(0.0, 2.0, 0.0);

	for (int j = ny - 1 ; j >= 0;j--)
	{
		for (int i = 0;i < nx;i++)
		{
			float u = 1.0*i / nx;
			float v = 1.0*j / ny;

			ray r(center, left_lower + u*hor + v*ver - center);
			vec3 col = color(r);
		//	vec3 color((float)i*1.0 / nx, (float)j*1.0 / ny,0.7);
			
			int ir = 255.99*col[0];
			int ig = 255.99*col[1];
			int ib = 255.99*col[2];

			outfile << ir << " " << ig << " " << ib << "\n";
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
}