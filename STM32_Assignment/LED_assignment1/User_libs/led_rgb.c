#include "led_rgb.h"

void rgb_init(RGB *rgb, GPIO_TypeDef *port_rgb[], uint16_t pin_rgb[])
{
	rgb->GPIO_red = port_rgb[0];
	rgb->GPIO_blue = port_rgb[1];
	rgb->GPIO_green = port_rgb[2];
	
	rgb->red_pin = pin_rgb[0];
	rgb->blue_pin = pin_rgb[1];
	rgb->green_pin = pin_rgb[2];
	
	rgb->state = LOW;
	
	rgb->color = OFF;
	
	
	
	rgb->last_time_on = HAL_GetTick();
	rgb->last_time_on1 = HAL_GetTick();
}

void rgb_setcolor(RGB *rgb, Color color)
{
	if (color == OFF)
	{
		rgb->state = LOW;
	}
	else
	{
		rgb->state = HIGH;
	}
	switch(color)
	{
		case RED:
			HAL_GPIO_WritePin(rgb->GPIO_red, rgb->red_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->GPIO_blue, rgb->blue_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->GPIO_green, rgb->green_pin, GPIO_PIN_RESET);
			break;
		
		case GREEN:
			HAL_GPIO_WritePin(rgb->GPIO_red, rgb->red_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->GPIO_blue, rgb->blue_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->GPIO_green, rgb->green_pin, GPIO_PIN_SET);
			break;
		
		case BLUE:
			HAL_GPIO_WritePin(rgb->GPIO_red, rgb->red_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->GPIO_blue, rgb->blue_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->GPIO_green, rgb->green_pin, GPIO_PIN_RESET);
			break;
		
		case WHITE:
			HAL_GPIO_WritePin(rgb->GPIO_red, rgb->red_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->GPIO_blue, rgb->blue_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->GPIO_green, rgb->green_pin, GPIO_PIN_SET);
			break;
		
		case YELLOW:
			HAL_GPIO_WritePin(rgb->GPIO_red, rgb->red_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->GPIO_blue, rgb->blue_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->GPIO_green, rgb->green_pin, GPIO_PIN_SET);
			break;
		
		case PURPLE:
			HAL_GPIO_WritePin(rgb->GPIO_red, rgb->red_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->GPIO_blue, rgb->blue_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->GPIO_green, rgb->green_pin, GPIO_PIN_RESET);
		
		case OFF:
			HAL_GPIO_WritePin(rgb->GPIO_red, rgb->red_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->GPIO_blue, rgb->blue_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->GPIO_green, rgb->green_pin, GPIO_PIN_RESET);
			break;
		
		default:
			break;
	}
}

static void rgb_toggle(RGB *rgb, Color color)
{
	if(rgb->state == HIGH)
	{
		rgb_setcolor(rgb,OFF);
		rgb->state = LOW;
	}
	else
	{
		rgb_setcolor(rgb,color);
		rgb->state = HIGH;
	}
	
}


void rgb_blink(RGB *rgb, Color color, uint16_t blink_time)
{
	if (HAL_GetTick() - rgb->last_time_on >= blink_time)
			{
					rgb_toggle(rgb, color);
					rgb->last_time_on = HAL_GetTick();
			}
}
