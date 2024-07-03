//
// Created by 28487 on 2024/6/30.
//

#ifndef AD9959_TJC_H
#define AD9959_TJC_H
#include "main.h"

extern uint8_t set_flag;
extern int j;
extern char tjcstr[100];

void TJC_Sendbit(uint8_t bit);
void TJC_START();
void HMISends(uint8_t *buf1);

void show_init();
void tjc_show();
void t1_show();
void t2_show();
void t3_show();
void t4_show();
void t5_show();
void t6_show();
void t7_show();
void t8_show();
void t9_show();
void t10_show();
void t11_show();
void t12_show();
void t25_show();
void t30_show();
void clear_show();

#endif //AD9959_TJC_H
