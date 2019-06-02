#include "hitable_list.h"





bool hitable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec)const
//遍历整个list，将每次的碰撞情况存于temp_rec中，最后rec存放的是最终的碰撞点
{
	hit_record temp_rec;  //用于存放碰撞点
	bool isHit=false;
	float temp_max = t_max;
	for (int i = 0;i < list_size;i++)
	{
		if ((list[i]->hit(r, t_min, temp_max, temp_rec)))
		{
			isHit = true;
			temp_max = rec.t;
			*temp_rec.mat_ptr;
			rec = temp_rec;
		}
	}
	return isHit;
}

hitable_list::~hitable_list()
{
}
