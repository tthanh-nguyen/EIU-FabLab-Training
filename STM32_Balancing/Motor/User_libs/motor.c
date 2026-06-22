#include "motor.h"


void pwm_set_duty(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t duty)
{
	uint32_t ccr;
	
	if (duty>100)
	{
		duty=100;
	}
	ccr = ((htim->Instance->ARR+1) * duty)/100;
	__HAL_TIM_SET_COMPARE(htim, Channel, ccr);
}

void motor_init(motor_inst *motor, TIM_HandleTypeDef *htim_motor, uint32_t channel, GPIO_TypeDef *stsp_port, uint16_t stsp_pin,GPIO_TypeDef *port_PH,uint16_t pin_PH)
{
	motor->htim_motor=htim_motor;
	motor->channel=channel;
	motor->stsp_port=stsp_port;
	motor->stsp_pin=stsp_pin;
	motor->port_PH=port_PH;
	motor->pin_PH=pin_PH;
	
	HAL_TIM_PWM_Start(motor->htim_motor, motor->channel);
}
void enable_motor(motor_inst *motor)
{
	HAL_GPIO_WritePin(motor->stsp_port,motor->stsp_pin,1);
//	uint32_t ccr = ((motor->htim_motor->Instance->ARR+1) * duty_cycle)/100;
//	__HAL_TIM_SET_COMPARE(motor->htim_motor, motor->channel, ccr);
}
void disable_motor(motor_inst *motor)
{
	HAL_GPIO_WritePin(motor->stsp_port,motor->stsp_pin,0);
}

void set_speed_open(motor_inst *motor, float duty_cycle_percent)
{
	if(duty_cycle_percent>0)
	{
		HAL_GPIO_WritePin(motor->port_PH,motor->pin_PH,0);
		
		uint32_t ccr = ((motor->htim_motor->Instance->ARR+1) * duty_cycle_percent)/100;
		
		__HAL_TIM_SET_COMPARE(motor->htim_motor, motor->channel, ccr);
	}
	else 
	{
		HAL_GPIO_WritePin(motor->port_PH,motor->pin_PH,1);
		uint32_t ccr = ((motor->htim_motor->Instance->ARR+1)  * -duty_cycle_percent)/100;
		
		__HAL_TIM_SET_COMPARE(motor->htim_motor, motor->channel, ccr);
	}
}