#ifndef BUTTON_H
#define BUTTON_H
#include "stm32l4xx_hal.h"

typedef struct
{
	GPIO_TypeDef *GPIO_button1;
	//GPIO_TypeDef *GPIO_button2;
	
	uint16_t button1_pin;
	//uint16_t button2_pin;
	
	uint8_t is_debouncing;
	uint32_t time_debounce;
	uint32_t time_start_press;
	uint8_t is_press_timeout;
} BUTTON1;

void button_handle();
void btn_pressing_callback();
void btn_release_callback();
void btn_press_short_callback();
void btn_press_timeout_callback();

#endif
