#include "HX711.h"


void HX711_Init(void){
	
	
	RCC_APB2PeriphClockCmd(HX_DIN_RCC_PORT|HX_SCK_RCC_PORT,ENABLE); // GPIO时钟初始化
	
	//
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = HX_DIN_PIN;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HX_DIN_PORT, &GPIO_InitStructure);
	
	//
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = HX_SCK_PIN;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HX_SCK_PORT, &GPIO_InitStructure);
	
	GPIO_SetBits(HX_SCK_PORT,HX_SCK_PIN);
	
}
// 读到的数据为24bit ,最大1677,7215
u32 HX711_Read(void){
	u32 DATA=0;
	u8 i;
	HX_SCK = 0;
	
	while(HX_DIN);
	
	// 发送24个脉冲，接收24位数据，高位在前
	// 数据为补码
	
	for(i=0;i<24;i++){
		HX_SCK = 1;
		delay_us(10);
		
		
		DATA = DATA<<1;
		if(HX_DIN)
			DATA++;
		HX_SCK = 0;
		delay_us(10);
		
		
	}
	HX_SCK = 1;
	delay_us(10);
	HX_SCK = 0;
	delay_us(10);
	DATA = DATA^0x800000;  // 补码转原码  
	return DATA;
}

u32 Value_Init(void){
	u8 i=0;
	u32 num;
	for(i=0;i<10;i++){
		num = num +HX711_Read();
		delay_ms(10);
	}
	return (num/10);
}
