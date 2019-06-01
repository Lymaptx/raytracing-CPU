#include<iostream>
#include<fstream>
#include"vec3.h"  //Ë«ÒıºÅÒıÓÃ
using namespace std;
int main()
{
	int nx = 200;
	int ny = 100;
	
	ofstream outfile("test.ppm", ios_base::out);
	outfile << "P3\n" << nx << " " << ny << "\n255\n";

	cout <<  "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1 ; j >= 0;j--)
	{
		for (int i = 0;i < nx;i++)
		{
			vec3 color((float)i*1.0 / nx, (float)j*1.0 / ny,0.7);
		
			int ir = 255.99*color[0];
			int ig = 255.99*color[1];
			int ib = 255.99*color[2];

			outfile << ir << " " << ig << " " << ib << "\n";
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
}