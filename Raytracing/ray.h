#pragma once
//射线类   
#include"vec3.h"
class ray
{
public:
	ray();
	ray(const vec3& a, const vec3&b, const float &time) { A = a, B = b, _time = time; }//构造函数  A表示点，B表示方向向量
	vec3 origin()const { return A; }
	vec3 direction() const { return B; }
	vec3 point_at_parameter(float t) const { return A + t*B; };
	float time() const { return _time; }
	~ray();
	float _time;  //光线时间戳
	vec3 A, B;
};

