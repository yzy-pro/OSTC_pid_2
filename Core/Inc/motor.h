#ifndef MOTOR_H
#define MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif
#include <sys/_stdint.h>
#define abs_max_speed 100

void motor_control(uint8_t name, uint8_t speed);
//电机控制函数
//轮子编号，速度（pwm）0~100

void robot_go(float speed, uint8_t direction);
//机器人整体直线运动控制函数
//速度，方向（只支持四向移动，0,90,180,270）

void robot_turn(float speed, uint8_t angle);
//机器人整体旋转运动控制函数
//速度，角度

#ifdef __cplusplus
}
#endif

#endif //MOTOR_H
