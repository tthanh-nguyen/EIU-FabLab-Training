#ifndef MOTOR_H
#define MOTOR_H
#include "stm32l4xx_hal.h"

typedef struct
{
	TIM_HandleTypeDef *htim_motor;
	uint32_t channel;
	GPIO_TypeDef *stsp_port;
	uint16_t stsp_pin;
	
	GPIO_TypeDef *port_PH;
	uint16_t pin_PH;
	

	
	
} motor_inst;

void pwm_set_duty(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t duty);
void motor_init(motor_inst *motor, TIM_HandleTypeDef *htim_motor, uint32_t channel, GPIO_TypeDef *stsp_port, uint16_t stsp_pin,GPIO_TypeDef *port_PH,uint16_t pin_PH);

void enable_motor(motor_inst *motor);
void disable_motor(motor_inst *motor);


void set_speed_open(motor_inst *motor, float duty_cycle_percent);

void set_speed_zero(motor_inst *motor);
#endif
