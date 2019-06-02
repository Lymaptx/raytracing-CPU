#include "material.h"

vec3 simple_sphere()
{
	
		vec3 p;

		do {
			p = 2.0*vec3(rand() % 100 / 100.0, rand() % 100 / 100.0, rand() % 100 / 100.0);

		} while (p.length() >= 1.0);
		return p;
	
}
