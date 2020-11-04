
#include "transform.h"
//X+方向 ori = 0，Y+方向 ori = pi/2，即顺时针为正
void LP2GP(double lx, double ly, double posx, double posy, double ori, double * gx, double * gy) {
    //此处需完成
    //输入：lx,ly为激光坐标系下激光点坐标；posx,posy,ori为机器人当前位姿；
    //输出：gx,gy即函数输出的变换后的全局坐标
    *gx = posx + lx * sin(ori) + ly * cos(ori);
    *gy = posy - lx * cos(ori) + ly * sin(ori);
}
