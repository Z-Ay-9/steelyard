//#include "Delay.h"
#include "SysTick.h" // Device header
//#include "smg.h"
#include "OLED.h"
#include "HX711.h"
int main(void){
	SysTick_Init(72); // Ä¬ÈÏ72MHzÊ±ÖÓÔ´
	//SMG_Init();
	HX711_Init();
	OLED_Init();
	//u32 zero_DATA =0;
	u32 DATA_=0;
	OLED_ShowNum(0,0,DATA_,8,OLED_8X16);
	OLED_ShowChar(64,0,'?',OLED_8X16);
	OLED_Update();
	//zero_DATA = Value_Init();
	while(1){
		
		DATA_ = HX711_Read()/100;
		//if(DATA_>10000000)DATA_=0;
		OLED_ShowNum(0,0,DATA_,8,OLED_8X16);
		OLED_Update();
		
	}
	
}
