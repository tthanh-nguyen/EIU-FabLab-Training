#ifndef SPI_PROTOCOL_H
#define SPI_PROTOCOL_H

#include "main.h"

#define REG_LED_CTRL 0xAE
#define LED1_ON 0x01
#define LED_ALL_OFF 0x00
#define BUFFER_SIZE  8


void SPI_Process_Command(uint8_t *rx_buffer, uint16_t blink_data);
void spi_read_reg(SPI_HandleTypeDef *hspi, uint8_t rx_buffer[]);
void dataHandle(uint64_t data, uint8_t tx_buffer[]);
void spi_slave(SPI_HandleTypeDef *hspi, uint8_t tx_buffer[],uint8_t rx_buffer[]);
#endif