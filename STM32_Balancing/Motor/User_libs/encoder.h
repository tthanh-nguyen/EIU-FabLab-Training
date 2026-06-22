#ifndef ENCODER_H
#define ENCODER_H
#include "stm32l4xx_hal.h"

typedef struct
{
	TIM_HandleTypeDef *htim_encoder;
	uint32_t channel;
	uint64_t encoder_value;
	
} encoder_inst;

void encoder_init(encoder_inst *encoder, TIM_HandleTypeDef *htim_encoder, uint32_t channel);
void get_encoder_speed(encoder_inst *encoder);
void reset_encoder(encoder_inst *encoder);
#endif