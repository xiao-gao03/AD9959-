//
// Created by 28487 on 2024/6/27.
//
#include "main.h"
#include "ad9959.h"
#include "MY_SPI.h"

uint32_t fre[4] = {1000,1000,1000,1000};
uint32_t amp[4] = {550,550,550,550};
uint32_t pha[4] = {0,0,0,0};

uint8_t ch0[1] = {0x10};
uint8_t ch1[1] = {0x20};
uint8_t ch2[1] = {0x40};
uint8_t ch3[1] = {0x80};

uint8_t CSR_data[1] = {0xF0};
uint8_t FR1_data[3] = {0xD0,0x00,0x00};
uint8_t FR2_data[2] = {0x20,0x00};
uint8_t CFR_data[3] = {0x00,0x03,0x02};
uint8_t CFTWO_data[4] = {0x00,0x00,0x00,0x00};
uint8_t CPOWO_data[2] = {0x00,0x00};
uint8_t ACR_data[3] = {0x00,0x00,0x00};

uint8_t chanel_num = 0;

void delay1 (uint32_t length)
{
    length = length*12;
    while(length--);
}

void update()  //更新
{
    HAL_GPIO_WritePin(UPDATE_GPIO_Port,UPDATE_Pin,GPIO_PIN_RESET);
    delay1(2);
    HAL_GPIO_WritePin(UPDATE_GPIO_Port,UPDATE_Pin,GPIO_PIN_SET);
    delay1(4);
    HAL_GPIO_WritePin(UPDATE_GPIO_Port,UPDATE_Pin,GPIO_PIN_RESET);
}


void IO_Init(void)  //IO口初始化
{
    HAL_GPIO_WritePin(PDC_GPIO_Port,PDC_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(UPDATE_GPIO_Port,UPDATE_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(P0_GPIO_Port,P0_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(P1_GPIO_Port,P1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(P2_GPIO_Port,P2_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(P3_GPIO_Port,P3_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SD0_GPIO_Port,SD0_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SD1_GPIO_Port,SD1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SD2_GPIO_Port,SD2_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SD3_GPIO_Port,SD3_Pin,GPIO_PIN_RESET);
}

void Reset(void)  //复位
{
    HAL_GPIO_WritePin(RES_GPIO_Port,RES_Pin,GPIO_PIN_RESET);
    delay1(1);
    HAL_GPIO_WritePin(RES_GPIO_Port,RES_Pin,GPIO_PIN_SET);
    delay1(30);
    HAL_GPIO_WritePin(RES_GPIO_Port,RES_Pin,GPIO_PIN_RESET);
}


//FTW/2^32=freq  设置频率
void Write_frequence(uint8_t channel,uint32_t freq)
{
    uint32_t temp;
    temp=(uint32_t)freq*8.589934592;	   //将输入频率因子分为四个字节  8.589934592=(2^32)/1000000000
    //从数组0开始发送。但实际数据是从高位到地位接收的
    CFTWO_data[3] = (uint8_t)temp;
    CFTWO_data[2] = (uint8_t)(temp>>8);
    CFTWO_data[1] = (uint8_t)(temp>>16);
    CFTWO_data[0] = (uint8_t)(temp>>24);
    switch(channel)
    {
        case 0:WriteData_AD9959(CSR,1,ch0,1);break;//开启通道一
        case 1:WriteData_AD9959(CSR,1,ch1,1);break;
        case 2:WriteData_AD9959(CSR,1,ch2,1);break;
        case 3:WriteData_AD9959(CSR,1,ch3,1);break;
        default:break;
    }
    WriteData_AD9959(CFTWO,4,CFTWO_data,1);
}

//设置相位
void Write_Phase(uint8_t channel,uint16_t Phase)
{
    uint16_t P_temp,tmep;
    if(Phase > 360)
    {
        Phase = 360;
    }
    tmep = Phase*4095/90;
    P_temp = (uint16_t)tmep;
    CPOWO_data[1] = (uint8_t)P_temp;
    CPOWO_data[0] = (uint8_t)(P_temp >> 8);
    switch(channel)
    {
        case 0:WriteData_AD9959(CSR,1,ch0,1);break;//开启通道一
        case 1:WriteData_AD9959(CSR,1,ch1,1);break;
        case 2:WriteData_AD9959(CSR,1,ch2,1);break;
        case 3:WriteData_AD9959(CSR,1,ch3,1);break;
        default:break;
    }
    WriteData_AD9959(CPOWO,2,CPOWO_data,1);
}
//设置幅度
void Write_Amplitude(uint8_t channel,uint16_t Amplitude)
{
    uint16_t A_temp, temp;
    if(Amplitude > 550)
    {
        Amplitude = 550;
    }
    temp = Amplitude*1023/550;
    if(temp > 1023)
    {
        temp=1023;
    }
    A_temp = temp | 0x1000;
    ACR_data[2] = (uint8_t)A_temp;
    ACR_data[1] = (uint8_t)(A_temp >> 8);
    switch(channel)
        {
            case 0:WriteData_AD9959(CSR,1,ch0,1);break;//开启通道一
            case 1:WriteData_AD9959(CSR,1,ch1,1);break;
            case 2:WriteData_AD9959(CSR,1,ch2,1);break;
            case 3:WriteData_AD9959(CSR,1,ch3,1);break;
            default:break;
        }
    WriteData_AD9959(ACR,3,ACR_data,1);

}

void ad9959_init()
{
    IO_Init();
    Reset();
    delay1(20);
    WriteData_AD9959(FR1,3,FR1_data,1);
    WriteData_AD9959(FR2,2,FR2_data,1);
    delay1(20);
    Write_frequence(0,fre[0]);
    Write_frequence(1,fre[1]);
    Write_frequence(2,fre[2]);
    Write_frequence(3,fre[3]);
    delay1(20);
    Write_Amplitude(0,amp[0]);
    Write_Amplitude(1,amp[1]);
    Write_Amplitude(2,amp[2]);
    Write_Amplitude(3,amp[3]);
    delay1(20);
    Write_Phase(0,pha[0]);
    Write_Phase(1,pha[1]);
    Write_Phase(2,pha[2]);
    Write_Phase(3,pha[3]);
}
