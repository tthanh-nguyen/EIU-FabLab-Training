#include "SRF04.h"
#include "main.h"
#include "stm32f1xx_hal_tim.h"

uint8_t is_waiting=0;
float distance;
uint32_t time,debug_time_cnt;

static void delay_us(TIM_HandleTypeDef *htim, uint16_t time_us)
{
	htim->Instance->CNT=0;
	HAL_TIM_Base_Start(htim);
	while (htim->Instance->CNT<time_us);
	HAL_TIM_Base_Stop(htim);
}
void run_timer(TIM_HandleTypeDef *htim)
{
	HAL_TIM_Base_Start(htim);
}
void trigger(TIM_HandleTypeDef *htim)
{
	if (is_waiting ==0)
	{
		HAL_GPIO_WritePin(Trigger_GPIO_Port, Trigger_Pin,1);
		delay_us(htim,10);
		HAL_GPIO_WritePin(Trigger_GPIO_Port, Trigger_Pin,0);
		delay_us(htim,10);
	}
}


void xulitrongNgat(TIM_HandleTypeDef *htim,uint16_t GPIO_Pin)
{
	if (GPIO_Pin==Echo_Pin)
	{
		//GPIO_PinState current_echo=HAL_GPIO_ReadPin(Echo_GPIO_Port,Echo_Pin);
		if (HAL_GPIO_ReadPin(Echo_GPIO_Port,Echo_Pin)==1)
		{
			__HAL_TIM_SET_COUNTER(htim, 0);
			debug_time_cnt=htim->Instance->CNT;
			is_waiting=1;
		}
		
	
		else
		{
			time=__HAL_TIM_GET_COUNTER(htim);
			distance=0.017f*time;
			is_waiting =0;
		}
		
	}
}
