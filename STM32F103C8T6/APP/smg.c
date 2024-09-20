#include "smg.h"


//  共阴极码表 0-F 高位在前 从DP-A
u8 smg_code[17] ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
//DP 即并上 0x80
u8 smg_code_dot [17] ={0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,
					   0xff,0xef,0xf7,0xfc,0xb9,0xde,0xf9,0xf1};
u8 smgs_code[5];
void SMG_Init(void){
	RCC_APB2PeriphClockCmd(SMG_RCC, ENABLE);
	// 八位数码管引脚初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin   = SEG_PIN;
	
	GPIO_Init(SEG_PORT,&GPIO_InitStructure);
	
	// 四段引脚初始化
	GPIO_InitStructure.GPIO_Pin   = DIG_PIN;
	GPIO_Init(DIG_PORT,&GPIO_InitStructure);
	
	GPIO_SetBits(SEG_PORT, SEG_PIN);
	GPIO_SetBits(DIG_PORT, DIG_PIN);
}

// 将单位数字对应的码值存入缓存数组中
void SMG_SET(u8 index, u8 data){
	
	smgs_code[index] = smg_code[data];
	
}

//共阴极四位数码管
void SMG_Write_Num(u8 num){
	
	u8 num_bit,i;
	for(i=0;i<4;i++){
		num_bit = num%10;
		SMG_SET(3-i,num_bit);
		num = num/10;
	}
	
}
// 连续端口输出 GPIO_Pin 从最小端口逐次左移  实现一位数码管控制
void SMG_Write_Data(u16 GPIO_Pin,u8 data)
{
	u8 i,j=GPIO_Pin;    
	for(i=0;i<8;i++)
	{
		if(data&0x01)
			GPIO_WriteBit(SEG_PORT, j<<i ,Bit_SET); 
		else
			GPIO_WriteBit(SEG_PORT, j<<i ,Bit_RESET); 
		data = data >> 1 ; 
	}
}

void SMG_Display(u8 num){
	
	u8 index=0;
	SMG_Write_Num(num);
	for(index = 0;index<4;index++){
		
		//段选完成
		switch(index){
			
			case 0:
				DIG_0 = 0;
				DIG_1 = 1;
				DIG_2 = 1;
				DIG_3 = 1;
			break;
			
			case 1:
				DIG_0 = 1;
				DIG_1 = 0;
				DIG_2 = 1;
				DIG_3 = 1;
			break;
			
			case 2:
				DIG_0 = 1;
				DIG_1 = 1;
				DIG_2 = 0;
				DIG_3 = 1;
			break;
			
			case 3:
				DIG_0 = 1;
				DIG_1 = 1;
				DIG_2 = 1;
				DIG_3 = 0;
			break;
			
		}
		
		SMG_Write_Data(GPIO_Pin_0, smgs_code[index]);
		delay_ms(5);
		SMG_Write_Data(GPIO_Pin_0, 0x00);
		
	}
	
}
