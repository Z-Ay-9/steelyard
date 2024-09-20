#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "system_bit.h"

void SysTick_Init(u8 SYSCLK);
void delay_ms(u16 nms);
void delay_us(u32 nus);
void delay_s(u8 s);


#endif
