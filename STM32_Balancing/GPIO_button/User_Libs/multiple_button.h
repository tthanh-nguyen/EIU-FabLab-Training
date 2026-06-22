#ifndef MULTIPLE_BUTTON_H
#define MULTIPLE_BUTTON_H
#include "stm32l4xx_hal.h"


typedef struct
{
	GPIO_TypeDef *GPIO_button;
	
	uint16_t button_pin;
	
	uint8_t btn_current;
	uint8_t btn_previous;
	uint8_t btn_filter;
	
	uint8_t is_debouncing;
	uint32_t time_debounce;
	uint32_t time_start_press;
	uint8_t is_press_timeout;
} BUTTON;

void button_init(BUTTON *button, GPIO_TypeDef *port_button, uint16_t pin_button);
void button_handle(BUTTON *button);
void btn_pressing_callback(BUTTON *button);
void btn_release_callback(BUTTON *button);
void btn_press_short_callback(BUTTON *button);
void btn_press_long_callback(BUTTON *button);


#endif
