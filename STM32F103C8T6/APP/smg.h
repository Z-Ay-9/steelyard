#ifndef _SMG_H_
#define _SMG_H_

#include "SysTick.h"

extern u8 smg_code[17];

// Ĭ�� GPIO_Pin_0-7 ��������
#define SEG_PIN  ((uint16_t)0x00FF)
#define SEG_PORT GPIOA
#define SEG_RCC  RCC_APB2Periph_GPIOA
// Ĭ�� GPIO_Pin_8-11
#define DIG_PIN  ((uint16_t)0x0F00)
#define DIG_PORT GPIOA
#define DIG_RCC  RCC_APB2Periph_GPIOA

#define SMG_RCC (SEG_RCC | DIG_RCC)

#define DIG_0 PAout(8)
#define DIG_1 PAout(9)
#define DIG_2 PAout(10)
#define DIG_3 PAout(11)

void SMG_Init(void);

// ��λ�������������ʾ�����λ�� 0-9999
void SMG_Display(u8 num);

//��ʾС�� ��ҪDP ��ԭֵ  ��0x80
#endif

