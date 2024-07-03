//
// Created by 28487 on 2024/7/1.
//

#include "key.h"
#include "main.h"

uint8_t key1_flag = 0;
uint8_t key2_flag = 0;
uint8_t key3_flag = 0;
uint8_t key4_flag = 0;
uint8_t key5_flag = 0;

uint8_t key1_f = 1;
uint8_t key2_f = 1;
uint8_t key3_f = 1;
uint8_t key4_f = 1;
uint8_t key5_f = 1;

uint8_t key1_state = 0;
uint8_t key2_state = 0;
uint8_t key3_state = 0;
uint8_t key4_state = 0;
uint8_t key5_state = 0;

uint8_t key5_multipass = 0;

uint8_t no_me[5] = {0,0,0,0,0};

uint8_t a,b,c,d,e;
void key_scan()
{
    key1_state = HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin);
    key2_state = HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin);
    key3_state = HAL_GPIO_ReadPin(KEY3_GPIO_Port,KEY3_Pin);
    key4_state = HAL_GPIO_ReadPin(KEY4_GPIO_Port,KEY4_Pin);
    key5_state = HAL_GPIO_ReadPin(KEY5_GPIO_Port,KEY5_Pin);
//======================================================================key5=============================================
    if((key5_state != 1) && (key5_f == 1) && no_me[4] == 0)
    {
        key5_flag = 1;
        key5_f = 0;
        key5_multipass++;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(e = 0 ; e < 5; e++)
        {
            no_me[e] = 1;
        }
    }
    if(key5_state == 1 && key5_f == 0)
    {
        key5_f = 1;
        key5_flag = 0;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(e = 0 ; e < 5; e++)
        {
            no_me[e] = 0;
        }
    }

//======================================================================key5=============================================
//======================================================================key1=============================================
    if((key1_state != 1) && (key1_f == 1) && no_me[0] == 0)
    {
            key1_flag = 1;
            key1_f = 0;
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(a = 0 ; a < 5; a++)
        {
            no_me[a+1] = 1;
        }
    }
    if(key1_state == 1 && key1_f == 0)
    {
        key1_f = 1;
        key1_flag = 0;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(a = 0 ; a < 5; a++)
        {
            no_me[a+1] = 0;
        }
    }
//======================================================================key1=============================================
//======================================================================key2=============================================
    if((key2_state != 1) && (key2_f == 1) && no_me[1] == 0)
    {
        key2_flag = 1;
        key2_f = 0;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(b = 0 ; b < 5; b++)
        {
            if(b == 1)
            {
                no_me[b+1] = 1;
            }
            else
            {
                no_me[b] = 1;
            }

        }
    }
    if(key2_state == 1 && key2_f == 0)
    {
        key2_f = 1;
        key2_flag = 0;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(b = 0 ; b < 5; b++)
        {
            if(b == 1)
            {
                no_me[b+1] = 0;
            }
            else
            {
                no_me[b] = 0;
            }

        }

    }
//======================================================================key2=============================================
//======================================================================key3=============================================
    if((key3_state != 1) && (key3_f == 1) && no_me[2] == 0)
    {
        key3_flag = 1;
        key3_f = 0;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(c = 0 ; c < 5; c++)
        {
            if(c == 2)
            {
                no_me[c+1] = 1;
            }
            else
            {
                no_me[c] = 1;
            }

        }
    }
    if(key3_state == 1 && key3_f == 0)
    {
        key3_f = 1;
        key3_flag = 0;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(c = 0 ; c < 5; c++)
        {
            if(c == 2)
            {
                no_me[c+1] = 0;
            }
            else
            {
                no_me[c] = 0;
            }

        }

    }
//======================================================================key3=============================================
//======================================================================key4=============================================
    if((key4_state != 1) && (key4_f == 1) && no_me[3] == 0)
    {
            key4_flag = 1;
            key4_f = 0;
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(d = 0 ; d < 5; d++)
        {
            if(d == 3)
            {
                no_me[d+1] = 1;
            }
            else
            {
                no_me[d] = 1;
            }

        }
    }
    if(key4_state == 1 && key4_f == 0)
    {
        key4_f = 1;
        key4_flag = 0;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        for(d = 0 ; d < 4; d++)
        {
            if(d == 3)
            {
                no_me[d+1] = 0;
            }
            else
            {
                no_me[d] = 0;
            }

        }
    }
//======================================================================key4=============================================

}