#ifndef ROBOT_H
#define ROBOT_H

#ifdef __cplusplus
extern "C" {
#endif
//规定车辆的N轮为参考正方向（x正），E为y正，逆时针旋转时角速度为正
//但是目前还不知道麦轮是左旋还是右旋的，此代码中认为麦轮全部是右旋

//定义一些车辆基本数据，1.23456表示待测值，参考提供的代码
#define PID_rate 50

#define R_of_robot 1.23456
#define R_of_wheel 1.23456

#define encoder_resolution 13 //编码器分辨率
#define encoder_gear_ratio 30 //减速比
#define encoder_resolution_u (4 * encoder_resolution * encoder_gear_ratio)

#define conversion_factor (2 * PI * R_of_wheel *PID_rate / \
encoder_resolution_u) //轮子速度m/s与编码器转换系数

#define  vertical_velocity_ratio 1 //麦轮运动时垂直方向的速度比，查阅资料得在 理想状态 下是1

//可能需要的数学常数
#define PI 3.14159265358979323846
#define unknown 1.23456

typedef struct
{
    double  recent_velocity;       //车轮实时速度，单位m/s
    float  target_velocity;       //车轮目标速度，单位m/s
    short  PWM_velocity;      //车轮PWM控制速度

}wheel_condition;

typedef struct
{
    float x_velocity;
    float y_velocity;
    float yaw_velocity;
}robot_condition;

#ifdef __cplusplus
}
#endif

#endif //ROBOT_H
