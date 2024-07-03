//
// Created by 28487 on 2024/6/30.
//
#include "TJC.h"
#include "key.h"
#include "main.h"
#include "usart.h"
#include "stdio.h"
#include "ad9959.h"
uint8_t set_flag=0;
char tjcstr[100];
uint16_t length = sizeof(tjcstr)/ sizeof(tjcstr[0]);

uint8_t show_num[14]={1,2,3,4,5,6,7,8,9,10,11,12,25,30};

void TJC_START()
{
    TJC_Sendbit(0xff);
}


void TJC_Sendbit(uint8_t bit) {
    uint8_t i;
    for (i = 0; i < 3; i++) {
        if (bit != 0) {
            HAL_UART_Transmit(&huart2, &bit,1,1000);  //发送一个字节
        } else {
            return;
        }
    }
}


void HMISends(uint8_t *buf1)
{
    uint8_t i=0;
    while(1)
    {
        if(buf1[i] != 0)
        {
            HAL_UART_Transmit(&huart2,&buf1[i],1,1000);  //·¢ËÍÒ»¸ö×Ö½Ú
            i++;
        }
        else
        {
            return ;
        }
    }
}
uint16_t i[2]={63488,65535};
uint8_t Hz[10] = "Hz";
uint8_t mV[10] = "mV";
uint8_t ph[10] = "ph";
int j = 0;
int h = 0;
void tjc_show()
{
    if(set_flag == 1)
    {

        if(key4_flag == 1)
        {
            h++;
            if(h>13)
            {
                h = 0;
            }
        }
        key4_flag = 0;
        if(key2_flag == 1)
        {
            h--;
            if(h < 0)
            {
                h = 13;
            }
        }
        key2_flag = 0;
        j = show_num[h];
        switch(j)
        {
            case 1:t1_show();break;
            case 2:t2_show();break;
            case 3:t3_show();break;
            case 4:t4_show();break;
            case 5:t5_show();break;
            case 6:t6_show();break;
            case 7:t7_show();break;
            case 8:t8_show();break;
            case 9:t9_show();break;
            case 10:t10_show();break;
            case 11:t11_show();break;
            case 12:t12_show();break;
            case 25:t25_show();break;
            case 30:t30_show();break;
            default:;
                break;
        }

    }
    else if(set_flag == 0)
    {
        clear_show();
    }
}

void t1_show()
{
    sprintf(tjcstr,"page5.t1.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t29.txt=\"%s\"",Hz);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t2.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t30.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t2_show()
{
    sprintf(tjcstr,"page5.t2.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t1.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t3.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t3_show()
{
    sprintf(tjcstr,"page5.t3.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t2.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t4.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);


}

void t4_show()
{
    sprintf(tjcstr,"page5.t4.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t3.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t5.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t29.txt=\"%s\"",Hz);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t5_show()
{
    sprintf(tjcstr,"page5.t5.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t29.txt=\"%s\"",mV);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t4.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t6.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t6_show()
{
    sprintf(tjcstr,"page5.t6.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t5.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t7.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);
}

void t7_show()
{
    sprintf(tjcstr,"page5.t7.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t8.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t6.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t8_show()
{
    sprintf(tjcstr,"page5.t8.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t9.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t7.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t29.txt=\"%s\"",mV);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t9_show()
{
    sprintf(tjcstr,"page5.t9.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t29.txt=\"%s\"",ph);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t8.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t10.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t10_show()
{
    sprintf(tjcstr,"page5.t10.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t11.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t9.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t11_show()
{
    sprintf(tjcstr,"page5.t11.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t7.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t10.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t12.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t12_show()
{
    sprintf(tjcstr,"page5.t12.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t25.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t11.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t29.txt=\"%s\"",ph);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t25_show()
{
    sprintf(tjcstr,"page5.t25.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t29.txt=\"%d\"",chanel_num);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t12.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t30.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void t30_show()
{
    sprintf(tjcstr,"page5.t30.pco=%d",i[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t1.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t25.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

}

void clear_show()
{
    sprintf(tjcstr,"page5.t1.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t2.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t3.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t4.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t5.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t6.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t7.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t8.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t9.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t10.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t11.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t12.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t25.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t27.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t30.pco=%d",i[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);
}

void show_init()
{

    sprintf(tjcstr,"page5.t13.txt=\"%d\"",fre[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t14.txt=\"%d\"",fre[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t15.txt=\"%d\"",fre[2]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t16.txt=\"%d\"",fre[3]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t17.txt=\"%d\"",amp[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t18.txt=\"%d\"",amp[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t19.txt=\"%d\"",amp[2]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t20.txt=\"%d\"",amp[3]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t21.txt=\"%d\"",pha[0]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t22.txt=\"%d\"",pha[1]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t23.txt=\"%d\"",pha[2]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    sprintf(tjcstr,"page5.t24.txt=\"%d\"",pha[3]);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);
}