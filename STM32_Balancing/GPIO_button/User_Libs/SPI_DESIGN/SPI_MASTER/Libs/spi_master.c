#include "spi_master.h"
#include "main.h"

void spi_write_reg (SPI_HandleTypeDef *hspi, uint8_t address, uint8_t state)
{
	uint8_t buffer[] = {address, state};
	
	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, 0);
	HAL_SPI_Transmit(hspi, buffer, 2, 100);
	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, 1);
}