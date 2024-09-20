#ifndef _HX_711_H_
#define _HX_711_H_

#include "stm32f10x.h"
#include "SysTick.h"

#define HX_DIN_PORT  GPIOA //GPIOX  // 对单片机来说，数据输入
#define HX_DIN_PIN   GPIO_Pin_2
#define HX_DIN_RCC_PORT RCC_APB2Periph_GPIOA

#define HX_SCK_PORT  GPIOA  // 对单片机来说，数据输出
#define HX_SCK_PIN   GPIO_Pin_5
#define HX_SCK_RCC_PORT RCC_APB2Periph_GPIOA

#define HX_DIN PAin(2)   //表示GPIOB PIN2 输入 接收数据
#define HX_SCK PAout(5)  //表示GPIOB PIN5 输出 提供时钟信号

void HX711_Init(void);
u32 HX711_Read(void);
u32 Value_Init(void);  // 软件清零
#endif

