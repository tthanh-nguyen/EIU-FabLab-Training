#include "multiple_button.h"




void button_init(BUTTON *button, GPIO_TypeDef *port_button, uint16_t pin_button)
{
	button->GPIO_button = port_button;
	
	button->button_pin = pin_button;
	
	button->btn_current = 1;
	button->btn_previous = 1;
	button->btn_filter = 1;
}


__weak void btn_pressing_callback(BUTTON *button)
{

}
__weak void btn_release_callback(BUTTON *button)
{
//	btn2++;
}
__weak void btn_press_short_callback(BUTTON *button)
{
	//btn3++;
}
__weak void btn_press_long_callback(BUTTON *button)
{

}



void button_handle(BUTTON *button) 
{
	//uint8_t read_current_status = HAL_GPIO_ReadPin(GPIOA, BT2_Pin);
	uint8_t read_current_status = HAL_GPIO_ReadPin(button->GPIO_button, button->button_pin);
	// XU LY NHIEU
	if(read_current_status != button->btn_filter)
	{
		button->btn_filter = read_current_status;
		button->time_debounce = HAL_GetTick();
		button->is_debouncing = 1;
	}
	
	// TRANG THAI XAC LAP
	if(button->is_debouncing == 1 && HAL_GetTick() - button->time_debounce > 15)
	{
		button->is_debouncing = 0;
		button->btn_current = button->btn_filter;
	}
	
	//XU LY SU KIEN
	if(button->btn_current != button->btn_previous)
	{
		if (button->btn_current==0)
		{
			btn_pressing_callback(button);
			button->time_start_press = HAL_GetTick();
			button->is_press_timeout = 1;
		}
		else
		{
			if (HAL_GetTick() - button->time_start_press <=1000)
			{
				btn_press_short_callback(button);
			}
			
			btn_release_callback(button);
			button->is_press_timeout=0;
			
		}
		button->btn_previous = button->btn_current;
		
	}
	if (button->is_press_timeout==1 && HAL_GetTick() -  button->time_start_press >3000)
		{
			btn_press_long_callback(button);
			button->is_press_timeout = 0;
		}
}
