#pragma once
#include"ray.h"
#define M_PI 3.1415926

class camera
{

	public:
		camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float focus_dist, float aperture, float t0,float t1) {
			//foces_dist Ωπæ‡
			//aperture π‚»¶
			time0 = t0;
			time1 = t1;

			lens_r = aperture / 2;
			float theta = vfov*M_PI / 180.0;
			float half_height = tan(theta / 2.0);
			float half_width = aspect*half_height;
			origin = lookfrom;
			w = unit_vector(lookfrom - lookat);
			u = unit_vector(w.cross(vup, w));
			v = w.cross(w, u);
			
			lower_left_corner = origin - half_width*u*focus_dist - half_height*v*focus_dist - w*focus_dist;
			horizontal = 2 * half_width*focus_dist*u;
			vertical = 2 * half_height*focus_dist*v;
			//lower_left_corner = vec3(-2.0, -1.0, -1.0);
			/*horizontal = vec3(4.0, 0.0, 0.0);
			vertical = vec3(0.0, 2.0, 0.0);
			origin = vec3(0.0, 0.0, 0.0);*/
		}
		ray get_ray(float s, float t) { 
			float time = time0+(rand()%100)/100.0*(time1 - time0);
			vec3 rpoint = lens_r*simple_disk();
			vec3 offset = u*rpoint.x() + v*rpoint.y();
			return ray(origin+offset, lower_left_corner + s*horizontal + t*vertical-(origin+offset),time); 
		}

		vec3 lower_left_corner;
		vec3 horizontal;
		vec3 vertical;
		vec3 origin;
		float lens_r;
		vec3 u, v, w;
		vec3 simple_disk();
		float time0, time1;

	};




