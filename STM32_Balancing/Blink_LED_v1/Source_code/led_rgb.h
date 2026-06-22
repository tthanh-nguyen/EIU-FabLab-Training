#ifndef LED_RGB_H
#define LED_RGB_H
#include "stm32l4xx_hal.h"

#define HIGH 1
#define LOW 0

typedef enum
{
	RED,
	GREEN,
	BLUE,
	WHITE,
	YELLOW,
	PURPLE,
	OFF,
}Color;


typedef struct
{
	GPIO_TypeDef *GPIO_red;
	GPIO_TypeDef *GPIO_blue;
	GPIO_TypeDef *GPIO_green;
	
	uint16_t red_pin;
	uint16_t blue_pin;
	uint16_t green_pin;
	
	uint8_t num_of_led;
	uint8_t state;
	uint32_t last_time_on;
	Color color;
	
}RGB;



void rgb_init(RGB *rgb, GPIO_TypeDef *port[], uint16_t pin[]);
void rgb_setcolor(RGB *rgb, Color color);
static void rgb_toggle(RGB *rgb, Color color);
void rgb_blink(RGB *rgb, Color color, uint16_t blink_time);
#endif
