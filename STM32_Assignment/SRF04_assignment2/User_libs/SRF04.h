#ifndef SRF04_H
#define SRF04_H
#include "stm32f1xx_hal.h"




static void delay_us(TIM_HandleTypeDef *htim, uint16_t time_us);
void run_timer(TIM_HandleTypeDef *htim);
void trigger(TIM_HandleTypeDef *htim);
void xulitrongNgat(TIM_HandleTypeDef *htim,uint16_t GPIO_Pin);
#endif
