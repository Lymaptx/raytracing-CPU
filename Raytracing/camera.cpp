#include "camera.h"

vec3 camera::simple_disk()
{
	
		vec3 p;
		do {
			p = 2.0*vec3(rand() % 100 / 100.0, rand() % 100 / 100.0, 0) - vec3(1.0, 1.0, 0.0);
		} while (p.dot(p, p) >= 1);
		return p;
	
}
