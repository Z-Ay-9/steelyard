#ifndef _FILTER_H_
#define _FILTER_H_

#include "stm32f10x.h"


//�������˲�

typedef struct {  
    float q;  // ��������Э����  
    float r;  // ��������Э����  
    float x;  // ����ֵ  
    float p;  // �������Э����  
    float k;  // ����������  
} KalmanFilter; 


// ��ͨ�˲�




#endif

