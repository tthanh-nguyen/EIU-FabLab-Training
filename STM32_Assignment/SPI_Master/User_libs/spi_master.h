#ifndef SPI_MASTER_H
#define SPI_MASTER_H
#include "stm32f1xx_hal.h"
#include "main.h"

#define BUFFER_SIZE  8

void spi_write_reg(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t data);
void spi_read_reg(SPI_HandleTypeDef *hspi, uint8_t tx_buffer[], uint8_t x_buffer[]);
void spi_master(SPI_HandleTypeDef *hspi,uint8_t tx_buffer[], uint8_t rx_buffer[]);
void receiveSlave(uint64_t *valuefromSlave, uint8_t rx_buffer[]);
#endif
