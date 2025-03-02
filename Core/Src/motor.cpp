#include "motor.h"
#include "main.h"
#include "tim.h"

void motor_control(uint8_t name, uint8_t speed)
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
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, E_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, E_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, E_MOTOR_1_Pin, speed);
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, E_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, E_MOTOR_1_Pin, 0);
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, E_MOTOR_2_Pin, speed);
        }

    }
    else if (name == 'S')
    {
        if (speed == 0)
        {
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, S_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, S_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, S_MOTOR_1_Pin, speed);
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, S_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, S_MOTOR_1_Pin, 0);
            __HAL_TIM_SET_COUNTER(&E_S_MOTOR_TIM, S_MOTOR_2_Pin, speed);
        }

    }
    else if (name == 'W')
    {
        if (speed == 0)
        {
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, W_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, W_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, W_MOTOR_1_Pin, speed);
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, W_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, W_MOTOR_1_Pin, 0);
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, W_MOTOR_2_Pin, speed);
        }

    }
    else if (name == 'N')
    {
        if (speed == 0)
        {
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, N_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, N_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, N_MOTOR_1_Pin, speed);
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, N_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, N_MOTOR_1_Pin, 0);
            __HAL_TIM_SET_COUNTER(&W_N_MOTOR_TIM, N_MOTOR_2_Pin, speed);
        }
    }
}
