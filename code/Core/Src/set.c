//
// Created by 28487 on 2024/7/3.
//

#include "set.h"
#include "main.h"
#include "key.h"
#include "ad9959.h"
#include "TJC.h"
#include "stdio.h"
#include "tim.h"

int32_t HZa = 1000,HZb = 1000,HZc = 1000,HZd = 1000;
int32_t HZ = 0;

int16_t mVa = 550,mVb = 550,mVc = 550,mVd = 550;
int16_t mV_f = 0;

int16_t ph1 = 0,ph2 = 0,ph3 = 0,ph4 = 0;
int16_t ph_f = 0;

int8_t s = 0;

int danwei[8];
void set()
{
    if(set_flag ==1)
    {
        if(j >= 1 && j <=4)
        {
            set_Hz();
        }
        else if(j >= 5 && j <= 8)
        {
            set_mV();
        }
        else if(j >= 9 && j <= 12)
        {
            set_ph();
        }
        else if(j == 25)
        {
            set_chanelnum();
        }
        else if(j == 30)
        {
            set_scanfre();
        }
    }
    else if(set_flag ==0)
    {
        Do();
    }

}

void set_Hz()
{
    sprintf(tjcstr,"page5.t28.txt=\"%d\"",HZ);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    switch(j)
    {
        case 1:HZ = HZa;
            break;
        case 2:HZ = HZb;
            break;
        case 3:HZ = HZc;
            break;
        case 4:HZ = HZd;
            break;
    }
    if(key1_flag == 1)
    {
        if(long_pass[0] == 0)
        {
            HZ -= 1000;
            HAL_Delay(120);
        }
        else if(long_pass[0] == 1)
        {
            HZ -= 100000;
            HAL_Delay(120);
        }

    }
    else if(key3_flag == 1)
    {
        if(long_pass[2] == 0)
        {
            HZ += 1000;
            HAL_Delay(120);
        }
        else if(long_pass[2] == 1)
        {
            HZ += 100000;
            HAL_Delay(120);
        }
    }
    HZ > 500000000 ? HZ=500000000 : HZ;
    HZ < 0 ? HZ=0 : HZ;
    switch(j)
    {
        case 1:HZa = HZ;
            break;
        case 2:HZb = HZ;
            break;
        case 3:HZc = HZ;
            break;
        case 4:HZd = HZ;
            break;
    }

}

void set_mV()
{
    sprintf(tjcstr,"page5.t28.txt=\"%d\"",mV_f);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    switch(j)
    {
        case 5:mV_f = mVa;
            break;
        case 6:mV_f = mVb;
            break;
        case 7:mV_f = mVc;
            break;
        case 8:mV_f = mVd;
            break;
    }
    if(key1_flag == 1)
    {
        if(long_pass[0] == 0)
        {
            mV_f -= 10;
            HAL_Delay(120);
        }
        else if(long_pass[0] == 1)
        {
            mV_f -= 100;
            HAL_Delay(120);
        }
    }
    else if(key3_flag == 1)
    {
        if(long_pass[2] == 0)
        {
            mV_f += 10;
            HAL_Delay(120);
        }
        else if(long_pass[2] == 1)
        {
            mV_f += 100;
            HAL_Delay(120);
        }
    }

    mV_f > 550 ? mV_f=550 : mV_f;
    mV_f < 0 ? mV_f=0 : mV_f;

    switch(j)
    {
        case 5:mVa = mV_f;
            break;
        case 6:mVb = mV_f;
            break;
        case 7:mVc = mV_f;
            break;
        case 8:mVd = mV_f;
            break;
    }

}

void set_ph()
{
    sprintf(tjcstr,"page5.t28.txt=\"%d\"",ph_f);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);

    switch(j)
    {
        case 9:ph_f = ph1;
            break;
        case 10:ph_f = ph2;
            break;
        case 11:ph_f = ph3;
            break;
        case 12:ph_f = ph4;
            break;
    }
    if(key1_flag == 1)
    {
        if(long_pass[0] == 0)
        {
            ph_f -= 10;
            HAL_Delay(120);
        }
        else if(long_pass[0] == 1)
        {
            ph_f -= 30;
            HAL_Delay(120);
        }
    }
    else if(key3_flag == 1)
    {
        if(long_pass[2] == 0)
        {
            ph_f += 10;
            HAL_Delay(120);
        }
        else if(long_pass[2] == 1)
        {
            ph_f += 100;
            HAL_Delay(120);
        }
    }

    ph_f > 360 ? ph_f=360 : ph_f;
    ph_f < 0 ? ph_f=0 : ph_f;

    switch(j)
    {
        case 9:ph1 = ph_f;
            break;
        case 10:ph2 = ph_f;
            break;
        case 11:ph3 = ph_f;
            break;
        case 12:ph4 = ph_f;
            break;
    }

}

int num = 4;

void set_chanelnum()
{
    if(key1_flag == 1)
    {
        num--;
        HAL_Delay(120);
    }
    else if(key3_flag == 1)
    {
        num++;
        HAL_Delay(120);
    }

    num > 4 ? num=4 : num;
    num < 0 ? num=0 : num;

    sprintf(tjcstr,"page5.t26.txt=\"%d\"",num);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);
}

void set_scanfre()
{
    if(key1_flag == 1)
    {
        s--;
        HAL_Delay(120);
    }
    else if(key3_flag == 1)
    {
        s++;
        HAL_Delay(120);
    }

    s > 1 ? s=1 : s;
    s < 0 ? s=0 : s;

    sprintf(tjcstr,"page5.t31.txt=\"%d\"",s);
    HMISends(tjcstr);
    TJC_Sendbit(0xff);
}

int num_last = 0;
void Do()
{
    if(fre[0] != HZa)
    {
        fre[0] = HZa;

        Write_frequence(0,HZa);
        sprintf(tjcstr,"page5.t13.txt=\"%d\"",HZa);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }
    else if(fre[1] != HZb)
    {
        fre[1] = HZb;

        Write_frequence(1,HZb);
        sprintf(tjcstr,"page5.t14.txt=\"%d\"",HZb);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }
    else if(fre[2] != HZc)
    {
        fre[2] = HZc;

        Write_frequence(2,HZc);
        sprintf(tjcstr,"page5.t15.txt=\"%d\"",HZc);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }
    else if(fre[3] != HZd)
    {
        fre[3] = HZd;

        Write_frequence(3,HZd);
        sprintf(tjcstr,"page5.t16.txt=\"%d\"",HZd);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }

    if(amp[0] != mVa)
    {
        amp[0] = mVa;

        Write_Amplitude(0,mVa);
        sprintf(tjcstr,"page5.t17.txt=\"%d\"",mVa);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }
    else if(amp[1] != mVb)
    {
        amp[1] = mVb;

        Write_Amplitude(1,mVb);
        sprintf(tjcstr,"page5.t18.txt=\"%d\"",mVb);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }
    else if(amp[2] != mVc)
    {
        amp[2] = mVc;

        Write_Amplitude(2,mVc);
        sprintf(tjcstr,"page5.t19.txt=\"%d\"",mVc);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }
    else if(amp[3] != mVd)
    {
        amp[3] = mVd;

        Write_Amplitude(3,mVd);
        sprintf(tjcstr,"page5.t20.txt=\"%d\"",mVd);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }

    if(pha[0] != ph1)
    {
        pha[0] = ph1;

        Write_Phase(0,ph1);
        sprintf(tjcstr,"page5.t21.txt=\"%d\"",ph1);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }
    else if(pha[1] != ph2)
    {
        pha[1] = ph1;

        Write_Phase(1,ph2);
        sprintf(tjcstr,"page5.t22.txt=\"%d\"",ph2);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }
    else if(pha[2] != ph3)
    {
        pha[2] = ph1;

        Write_Phase(2,ph3);
        sprintf(tjcstr,"page5.t23.txt=\"%d\"",ph3);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }
    else if(pha[3] != ph4)
    {
        pha[3] = ph1;

        Write_Phase(3,ph4);
        sprintf(tjcstr,"page5.t24.txt=\"%d\"",ph4);
        HMISends(tjcstr);
        TJC_Sendbit(0xff);
    }

    if(num_last != num)
    {
        switch (num)
        {
            case 0:
                Write_frequence(0,0);
                Write_frequence(1,0);
                Write_frequence(2,0);
                Write_frequence(3,0);
                break;
            case 1:
                Write_frequence(0,HZa);
                Write_frequence(1,0);
                Write_frequence(2,0);
                Write_frequence(3,0);
                break;
            case 2:
                Write_frequence(0,HZa);
                Write_frequence(1,HZb);
                Write_frequence(2,0);
                Write_frequence(3,0);
                break;
            case 3:
                Write_frequence(0,HZa);
                Write_frequence(1,HZb);
                Write_frequence(2,HZc);
                Write_frequence(3,0);
                break;
            case 4:
                Write_frequence(0,HZa);
                Write_frequence(1,HZb);
                Write_frequence(2,HZc);
                Write_frequence(3,HZd);
                break;
        }
        num_last = num;
    }


}

