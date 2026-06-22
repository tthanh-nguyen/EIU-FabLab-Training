#include "spi_protocol.h"



void spi_read_reg(SPI_HandleTypeDef *hspi, uint8_t rx_buffer[])
{
	HAL_SPI_Receive(hspi, rx_buffer,2,1000);
	switch (rx_buffer[0])
	{
			case 0xAE:
				
				switch (rx_buffer[1])
				{
					case 0x01:
						HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin,1);
						break;
					case 0x00:
						HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin,0);
						break;
				}
				break;
				
			default:
				break;
	}
}

void dataHandle(uint64_t data, uint8_t tx_buffer[])
{
	for (uint8_t i = 0; i<8;i++)
	{
		tx_buffer[i]=data&0xff;
		data=data>>8;
	}

}

void spi_slave(SPI_HandleTypeDef *hspi, uint8_t tx_buffer[],uint8_t rx_buffer[])
{
	HAL_SPI_TransmitReceive(hspi,tx_buffer,rx_buffer,BUFFER_SIZE,100);
}

