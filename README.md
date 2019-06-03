# raytracing-CPU
a raytracing project accroding to 《Ray Tracing in One Weekend》 
#Ray Tracing: The Next Week  
##Chapter 1: 动态模糊  
曝光时间内物体发生运动，像素的颜色为这段时间内像素的均值；
具体实现需要进行如下操作：  
1.射线 ray.h： 射线需要记录时间信息，在采样时进行求交计算。  
2.相机 camera: ①设置曝光时间，②在曝光时间内生成采样射线。      
<<<<<<< HEAD
3.移动物体 move_Sphere: 新的类，继承在hitable，新增属性运动时间（与曝光时间不必相同）和一个方法计算在某个时刻球心所在的位置center。  
=======
3.移动物体 move_Sphere: 新的类，继承在hitable，新增属性运动时间（与曝光时间不必相同）和一个方法计算在某个时刻球心所在的位置center。  


>>>>>>> 1f7570275c7cc6f61adcc3086a2c5d1051fbba96
