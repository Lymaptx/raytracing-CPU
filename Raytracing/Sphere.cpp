#include "Sphere.h"





bool Sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec)const
{
	vec3 oc = r.origin() - center;
	float a = oc.dot(r.direction(), r.direction());
	float b = 2.0 * oc.dot(oc, r.direction());
	float c = oc.dot(oc, oc) - radius*radius;
	float discriminant = b*b - 4 * a*c;

	if (discriminant > 0) {
		float temp = (-b - sqrt(discriminant)) / (2.0*a);
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
		temp = (-b + sqrt(discriminant)) / (2.0*a);
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	/*�ж�С���ʹ���Ƿ��ڷ�Χ�ڡ������ж�С���Ƿ��ڷ�Χ�ڡ��ǣ����������Ϣ��Ȼ��ֱ�ӷ��أ����жϴ���Ƿ��ڷ�Χ�ڡ�Ҳ��������ѡС����С�������ٿ��Ǵ�� */
	return false;
}

Sphere::~Sphere()
{
}