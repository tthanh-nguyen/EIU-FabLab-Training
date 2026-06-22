#include "button.h"
#include "main.h"
uint8_t btn_current=1;
uint8_t btn_previous=1;
uint8_t btn_filter=1;
uint8_t is_debouncing;
uint32_t time_debounce;
uint32_t time_start_press;
uint8_t is_press_timeout;



__weak void btn_pressing_callback()
{
	//btn1++;
}
__weak void btn_release_callback()
{
//	btn2++;
}
__weak void btn_press_short_callback()
{
	//btn3++;
}
__weak void btn_press_timeout_callback()
{

}

void button_handle()  
{
	uint8_t read_current_status = HAL_GPIO_ReadPin(GPIOA, BT2_Pin);
	// XU LY NHIEU
	if(read_current_status != btn_filter)
	{
		btn_filter = read_current_status;
		time_debounce = HAL_GetTick();
		is_debouncing = 1;
	}
	
	// TRANG THAI XAC LAP
	if(is_debouncing == 1 && HAL_GetTick() - time_debounce > 15)
	{
		is_debouncing = 0;
		btn_current = btn_filter;
	}
	
	//XU LY SU KIEN
	if(btn_current != btn_previous)
	{
		if (btn_current==0)
		{
			btn_pressing_callback();
			time_start_press = HAL_GetTick();
			is_press_timeout = 1;
		}
		else
		{
			if (HAL_GetTick() - time_start_press <=1000)
			{
				btn_press_short_callback();
			}
			
			btn_release_callback();
			
		}
		btn_previous = btn_current;
		
		if (is_press_timeout==1 && HAL_GetTick() -  time_start_press >3000)
		{
			btn_press_timeout_callback();
			is_press_timeout = 0;
		}
	}
}