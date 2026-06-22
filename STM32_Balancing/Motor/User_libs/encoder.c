#include "encoder.h"

void encoder_init(encoder_inst *encoder, TIM_HandleTypeDef *htim_encoder, uint32_t channel)
{
	encoder->htim_encoder=htim_encoder;
	encoder->channel=channel;
	
	
	HAL_TIM_Encoder_Start(encoder->htim_encoder, encoder->channel);
}

void get_encoder_speed(encoder_inst *encoder)
{
	encoder->encoder_value= __HAL_TIM_GET_COUNTER(encoder->htim_encoder);
}

void reset_encoder(encoder_inst *encoder)
{
	
}
	