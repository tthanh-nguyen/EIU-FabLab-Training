#ifndef SPI_MASTER_H
#define SPI_MASTER_H
#include "stm32f1xx_hal.h"

#define led_address 0xAE
#define led_on 0x01
#define led_off 0x00

void spi_write_reg (SPI_HandleTypeDef *hspi, uint8_t address, uint8_t state);
#endif