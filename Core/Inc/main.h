/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define E_MOTOR_1_Pin GPIO_PIN_0
#define E_MOTOR_1_GPIO_Port GPIOA
#define E_MOTOR_2_Pin GPIO_PIN_1
#define E_MOTOR_2_GPIO_Port GPIOA
#define S_MOTOR_1_Pin GPIO_PIN_2
#define S_MOTOR_1_GPIO_Port GPIOA
#define S_MOTOR_2_Pin GPIO_PIN_3
#define S_MOTOR_2_GPIO_Port GPIOA
#define W_ENCODER_1_Pin GPIO_PIN_6
#define W_ENCODER_1_GPIO_Port GPIOA
#define W_ENCODER_2_Pin GPIO_PIN_7
#define W_ENCODER_2_GPIO_Port GPIOA
#define E_ENCODER_1_Pin GPIO_PIN_9
#define E_ENCODER_1_GPIO_Port GPIOE
#define E_ENCODER_2_Pin GPIO_PIN_11
#define E_ENCODER_2_GPIO_Port GPIOE
#define N_ENCODER_1_Pin GPIO_PIN_12
#define N_ENCODER_1_GPIO_Port GPIOD
#define N_ENCODER_2_Pin GPIO_PIN_13
#define N_ENCODER_2_GPIO_Port GPIOD
#define W_MOTOR_1_Pin GPIO_PIN_6
#define W_MOTOR_1_GPIO_Port GPIOC
#define W_MOTOR_2_Pin GPIO_PIN_7
#define W_MOTOR_2_GPIO_Port GPIOC
#define N_MOTOR_1_Pin GPIO_PIN_8
#define N_MOTOR_1_GPIO_Port GPIOC
#define N_MOTOR_2_Pin GPIO_PIN_9
#define N_MOTOR_2_GPIO_Port GPIOC
#define S_ENCODER_1_Pin GPIO_PIN_15
#define S_ENCODER_1_GPIO_Port GPIOA
#define S_ENCODER_2_Pin GPIO_PIN_3
#define S_ENCODER_2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
