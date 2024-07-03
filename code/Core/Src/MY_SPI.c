//
// Created by 28487 on 2024/6/27.
//

#include "MY_SPI.h"
#include "main.h"
#include "ad9959.h"

void WriteData_AD9959(uint8_t RegisterAddress, uint8_t NumberofRegisters, uint8_t *RegisterData,uint8_t temp)
{
    uint8_t	ControlValue = 0;
    uint8_t	ValueToWrite = 0;
    uint8_t	RegisterIndex = 0;
    uint8_t	i = 0;

    ControlValue = RegisterAddress;
    HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_RESET);
    for(i=0; i<8; i++)
    {
        HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_RESET);
        if(0x80 == (ControlValue & 0x80))
            HAL_GPIO_WritePin(SD0_GPIO_Port,SD0_Pin,GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(SD0_GPIO_Port,SD0_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_SET);
        ControlValue <<= 1;
    }
    HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_RESET);

    for (RegisterIndex=0; RegisterIndex<NumberofRegisters; RegisterIndex++)
    {
        ValueToWrite = RegisterData[RegisterIndex];
        for (i=0; i<8; i++)
        {
            HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_RESET);
            if(0x80 == (ValueToWrite & 0x80))
                HAL_GPIO_WritePin(SD0_GPIO_Port,SD0_Pin,GPIO_PIN_SET);
            else
                HAL_GPIO_WritePin(SD0_GPIO_Port,SD0_Pin,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_SET);
            ValueToWrite <<= 1;
        }
        HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_SET);
    }
    if(temp != 0)
        update();
    HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_SET);
}

