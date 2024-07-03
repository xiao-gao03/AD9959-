//
// Created by 28487 on 2024/7/1.
//

#ifndef AD9959_KEY_H
#define AD9959_KEY_H
#include "main.h"

extern uint8_t key1_flag;
extern uint8_t key2_flag;
extern uint8_t key3_flag;
extern uint8_t key4_flag;
extern uint8_t key5_flag;

extern uint8_t key1_state;
extern uint8_t key2_state;
extern uint8_t key3_state;
extern uint8_t key4_state;
extern uint8_t key5_state;

extern uint8_t key5_multipass;

extern uint8_t no_me[5];
void key_scan();

#endif //AD9959_KEY_H
