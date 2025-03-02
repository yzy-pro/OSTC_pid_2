#include "motor.h"
#include "main.h"
#include "tim.h"
#include "robot.h"

void motor_control(const uint8_t name, uint8_t speed)
{
    if (speed > abs_max_speed || speed < -abs_max_speed)
    {
        if (speed > abs_max_speed)
        {
            speed = abs_max_speed;
        }
        else if (speed < -abs_max_speed)
        {
            speed = -abs_max_speed;
        }
    }

    if (name == 'E')
    {
        if (speed == 0)
        {
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, E_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, E_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, E_MOTOR_1_Pin, speed);
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, E_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, E_MOTOR_1_Pin, 0);
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, E_MOTOR_2_Pin, speed);
        }

    }
    else if (name == 'S')
    {
        if (speed == 0)
        {
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, S_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, S_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, S_MOTOR_1_Pin, speed);
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, S_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, S_MOTOR_1_Pin, 0);
            __HAL_TIM_SetCompare(&E_S_MOTOR_TIM, S_MOTOR_2_Pin, speed);
        }

    }
    else if (name == 'W')
    {
        if (speed == 0)
        {
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, W_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, W_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, W_MOTOR_1_Pin, speed);
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, W_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, W_MOTOR_1_Pin, 0);
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, W_MOTOR_2_Pin, speed);
        }

    }
    else if (name == 'N')
    {
        if (speed == 0)
        {
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, N_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, N_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, N_MOTOR_1_Pin, speed);
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, N_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, N_MOTOR_1_Pin, 0);
            __HAL_TIM_SetCompare(&W_N_MOTOR_TIM, N_MOTOR_2_Pin, speed);
        }
    }
}

void robot_go(const float speed, const uint8_t direction)
{
    //应该是要根据实际电机和轮子改正负号
    const int8_t pwm_speed = conversion_factor * speed;
    const int8_t pwm_vertical_speed = vertical_velocity_ratio * pwm_speed;
    if (speed == 0)
    {
        motor_control('E', 0);
        motor_control('S', 0);
        motor_control('W', 0);
        motor_control('N', 0);
        return;
    }

    if (direction == 0)
    {
        motor_control('E', pwm_vertical_speed);
        motor_control('S', pwm_speed);
        motor_control('W', -pwm_vertical_speed);
        motor_control('N', -pwm_speed);
    }
    else if (direction == 90)
    {
        motor_control('S', pwm_vertical_speed);
        motor_control('W', pwm_speed);
        motor_control('N', -pwm_vertical_speed);
        motor_control('E', -pwm_speed);
    }
    else if (direction == 180)
    {
        motor_control('W', pwm_vertical_speed);
        motor_control('N', pwm_speed);
        motor_control('E', -pwm_vertical_speed);
        motor_control('S', -pwm_speed);
    }
    else if (direction == 270)
    {
        motor_control('N', pwm_vertical_speed);
        motor_control('E', pwm_speed);
        motor_control('S', -pwm_vertical_speed);
        motor_control('W', -pwm_speed);
    }

}

void robot_turn(float speed, uint8_t angle)
{
    //这个原地转圈肯定要优化，例如用中断取代Delay
    const int8_t pwm_speed = conversion_factor * speed;
    angle = angle % 360;

    if (0 < angle || 0 == angle && angle < 180 || angle ==180)
    {
        const float rad_angle = angle * PI / 180;
        const float turning_time = rad_angle * R_of_robot / speed * 1000;

        motor_control('E', pwm_speed);
        motor_control('S', pwm_speed);
        motor_control('W', pwm_speed);
        motor_control('N', pwm_speed);

        HAL_Delay(turning_time);

        robot_go(0, 0);
    }
    else
    {
        angle = 360 - angle;
        const float rad_angle = angle * PI / 180;
        const float turning_time = rad_angle * R_of_robot / speed * 1000;

        motor_control('E', -pwm_speed);
        motor_control('S', -pwm_speed);
        motor_control('W', -pwm_speed);
        motor_control('N', -pwm_speed);

        HAL_Delay(turning_time);

        robot_go(0, 0);
    }


}