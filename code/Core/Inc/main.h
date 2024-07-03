/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define CS_Pin GPIO_PIN_4
#define CS_GPIO_Port GPIOA
#define SCK_Pin GPIO_PIN_5
#define SCK_GPIO_Port GPIOA
#define SD0_Pin GPIO_PIN_7
#define SD0_GPIO_Port GPIOA
#define KEY1_Pin GPIO_PIN_0
#define KEY1_GPIO_Port GPIOB
#define KEY4_Pin GPIO_PIN_1
#define KEY4_GPIO_Port GPIOB
#define KEY5_Pin GPIO_PIN_10
#define KEY5_GPIO_Port GPIOB
#define KEY2_Pin GPIO_PIN_11
#define KEY2_GPIO_Port GPIOB
#define KEY3_Pin GPIO_PIN_12
#define KEY3_GPIO_Port GPIOB
#define UPDATE_Pin GPIO_PIN_8
#define UPDATE_GPIO_Port GPIOA
#define RES_Pin GPIO_PIN_9
#define RES_GPIO_Port GPIOA
#define PDC_Pin GPIO_PIN_10
#define PDC_GPIO_Port GPIOA
#define SD1_Pin GPIO_PIN_3
#define SD1_GPIO_Port GPIOB
#define SD2_Pin GPIO_PIN_4
#define SD2_GPIO_Port GPIOB
#define SD3_Pin GPIO_PIN_5
#define SD3_GPIO_Port GPIOB
#define P0_Pin GPIO_PIN_6
#define P0_GPIO_Port GPIOB
#define P1_Pin GPIO_PIN_7
#define P1_GPIO_Port GPIOB
#define P2_Pin GPIO_PIN_8
#define P2_GPIO_Port GPIOB
#define P3_Pin GPIO_PIN_9
#define P3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
