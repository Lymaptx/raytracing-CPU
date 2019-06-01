#pragma once
//射线类   
#include"vec3.h"
class ray
{
public:
	ray();
	ray(const vec3& a, const vec3&b) { A = a, B = b; }//构造函数  A表示点，B表示方向向量
	vec3 origin()const { return A; }
	vec3 direction() const { return B; }
	vec3 point_at_parameter(float t) const { return A + t*B; };
	~ray();

	vec3 A, B;
};

