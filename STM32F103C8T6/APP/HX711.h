#ifndef _HX_711_H_
#define _HX_711_H_

#include "stm32f10x.h"
#include "SysTick.h"

#define HX_DIN_PORT  GPIOA //GPIOX  // �Ե�Ƭ����˵����������
#define HX_DIN_PIN   GPIO_Pin_2
#define HX_DIN_RCC_PORT RCC_APB2Periph_GPIOA

#define HX_SCK_PORT  GPIOA  // �Ե�Ƭ����˵���������
#define HX_SCK_PIN   GPIO_Pin_5
#define HX_SCK_RCC_PORT RCC_APB2Periph_GPIOA

#define HX_DIN PAin(2)   //��ʾGPIOB PIN2 ���� ��������
#define HX_SCK PAout(5)  //��ʾGPIOB PIN5 ��� �ṩʱ���ź�

void HX711_Init(void);
u32 HX711_Read(void);
u32 Value_Init(void);  // �������
#endif

