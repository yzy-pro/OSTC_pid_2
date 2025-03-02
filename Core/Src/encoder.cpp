#include "encoder.h"
#include "tim.h"


uint16_t encoder_getcounter (const uint8_t name)
{
    uint16_t counter = 0;
    if (name == 'E')
    {
        counter = __HAL_TIM_GetCounter(&E_ENCODER_TIM);
    }
    else if (name == 'S')
    {
        counter = __HAL_TIM_GetCounter(&S_ENCODER_TIM);
    }
    else if (name == 'W')
    {
        counter = __HAL_TIM_GetCounter(&W_ENCODER_TIM);
    }
    else if (name == 'N')
    {
        counter = __HAL_TIM_GetCounter(&N_ENCODER_TIM);
    }

    return counter;

}

void encoder_setcounter (const uint8_t name, const uint16_t value)
{
    if (name == 'E')
    {
        __HAL_TIM_SetCounter(&E_ENCODER_TIM, value);
    }
    else if (name == 'S')
    {
        __HAL_TIM_SetCounter(&S_ENCODER_TIM, value);
    }
    else if (name == 'W')
    {
        __HAL_TIM_SetCounter(&W_ENCODER_TIM, value);
    }
    else if (name == 'N')
    {
        __HAL_TIM_SetCounter(&N_ENCODER_TIM, value);
    }
}
