/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tim.c
  * @brief   This file provides code for the configuration
  *          of the TIM instances.
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
/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */
#include "key.h"
#include "TJC.h"
#include "set.h"
#include "ad9959.h"
/* USER CODE END 0 */

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/* TIM2 init function */
void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7200-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 100-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}
/* TIM3 init function */
void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 720-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 100-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspInit 0 */

  /* USER CODE END TIM2_MspInit 0 */
    /* TIM2 clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();

    /* TIM2 interrupt Init */
    HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
  /* USER CODE BEGIN TIM2_MspInit 1 */

  /* USER CODE END TIM2_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspInit 0 */

  /* USER CODE END TIM3_MspInit 0 */
    /* TIM3 clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();

    /* TIM3 interrupt Init */
    HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspInit 1 */

  /* USER CODE END TIM3_MspInit 1 */
  }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspDeInit 0 */

  /* USER CODE END TIM2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM2_CLK_DISABLE();

    /* TIM2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM2_IRQn);
  /* USER CODE BEGIN TIM2_MspDeInit 1 */

  /* USER CODE END TIM2_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspDeInit 0 */

  /* USER CODE END TIM3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM3_CLK_DISABLE();

    /* TIM3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspDeInit 1 */

  /* USER CODE END TIM3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
uint8_t count[5]={0,0,0,0,0};
uint8_t long_pass[5] = {0,0,0,0,0};
uint8_t no_pass = 0;
uint8_t no_pass_flag = 0;
uint32_t scan_fre = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

    if (htim->Instance == htim3.Instance)
    {
        if(set_flag == 0)
        {
            if(s==1)
            {
                scan_fre++;
                if(scan_fre <= 1000)
                {
                    Write_frequence(0,scan_fre);
                }
                scan_fre > 1000? scan_fre=0:scan_fre;
            }
        }


    }

    if (htim->Instance == htim2.Instance)
    {
//=================================================================key5========================================================
        if ((key5_flag == 1) && (long_pass[4] ==0))
        {
            no_pass = 0;
            no_pass_flag = 0;
            count[4]++;
            if(count[4] >= 100)
            {
                HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
                long_pass[4] = 1;
                set_flag = !set_flag;
            }
        }
        else if(key5_flag == 0)
        {
            long_pass[4] = 0;
            count[4] = 0;
            no_pass++;
        }
        if(no_pass >= 100 && no_pass_flag ==0)
        {
            key5_multipass = 0;
            no_pass_flag = 1;
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        }
//=================================================================key5========================================================
//=================================================================key1========================================================
        if ((key1_flag == 1) && (long_pass[0] ==0))
        {
            count[0]++;
            if(count[0] >= 100)
            {
                HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
                long_pass[0] = 1;
            }
        }
        else if(key1_flag == 0)
        {
            long_pass[0] = 0;
            count[0] = 0;
        }
//=================================================================key1========================================================
//=================================================================key2========================================================
        if ((key2_flag == 1) && (long_pass[1] ==0))
        {
            count[1]++;
            if(count[1] >= 100)
            {
                HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
                long_pass[1] = 1;
            }
        }
        else if(key2_flag == 0)
        {
            long_pass[1] = 0;
            count[1] = 0;
        }
//=================================================================key2========================================================
//=================================================================key3========================================================
        if ((key3_flag == 1) && (long_pass[2] ==0))
        {
            count[2]++;
            if(count[2] >= 100)
            {
                HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
                long_pass[2] = 1;
            }
        }
        else if(key3_flag == 0)
        {
            long_pass[2] = 0;
            count[2] = 0;
        }
//=================================================================key3========================================================
//=================================================================key4========================================================
        if ((key4_flag == 1) && (long_pass[3] ==0))
        {
            count[3]++;
            if(count[3] >= 100)
            {
                HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
                long_pass[3] = 1;
            }
        }
        else if(key4_flag == 0)
        {
            long_pass[3] = 0;
            count[3] = 0;
        }
//=================================================================key4========================================================
    }
}
/* USER CODE END 1 */
