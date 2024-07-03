//
// Created by 28487 on 2024/6/27.
//

#ifndef AD9959_MY_SPI_H
#define AD9959_MY_SPI_H
#include "main.h"


void WriteData_AD9959(uint8_t RegisterAddress, uint8_t NumberofRegisters, uint8_t *RegisterData,uint8_t temp);


#endif //AD9959_MY_SPI_H
