#ifndef ROBOT_H
#define ROBOT_H

#ifdef __cplusplus
extern "C" {
#endif

#define PID_rate 50

#define R_of_robot 1.23456
#define R_of_wheel 1.23456

#define encoder_resolution 13
#define encoder_gear_ratio 30
#define encoder_resolution_u (4 * encoder_resolution * encoder_gear_ratio)

#define conversion_factor (2 * PI * R_of_wheel *PID_rate / \
encoder_resolution_u)

#define PI 3.14159265358979323846
#define c 1.23456

typedef struct
{
    double  recent_velocity;       //车轮实时速度，单位m/s
    float  target_velocity;       //车轮目标速度，单位m/s
    short  PWM_velocity;      //车轮PWM控制速度

}robot_wheel;

#ifdef __cplusplus
}
#endif

#endif //ROBOT_H
