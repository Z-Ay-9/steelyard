#ifndef _FILTER_H_
#define _FILTER_H_

#include "stm32f10x.h"


//卡尔曼滤波

typedef struct {  
    float q;  // 过程噪声协方差  
    float r;  // 测量噪声协方差  
    float x;  // 估计值  
    float p;  // 估计误差协方差  
    float k;  // 卡尔曼增益  
} KalmanFilter; 


// 低通滤波




#endif

