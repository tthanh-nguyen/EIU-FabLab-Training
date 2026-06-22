#include "spi_master.h"
uint8_t test;

void spi_write_reg(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t data)
{
	
	uint8_t rx_buffer[2];
	test = rx_buffer[0];
	rx_buffer[0]=address;
	rx_buffer[1]=data;
	HAL_GPIO_WritePin(SPI1_OUT_GPIO_Port,SPI1_OUT_Pin,0);
	HAL_SPI_Transmit(hspi,rx_buffer,2,1000);
	HAL_GPIO_WritePin(SPI1_OUT_GPIO_Port,SPI1_OUT_Pin,1);
}
void spi_read_reg(SPI_HandleTypeDef *hspi, uint8_t tx_buffer[], uint8_t rx_buffer[])
{
	HAL_GPIO_WritePin(SPI1_OUT_GPIO_Port,SPI1_OUT_Pin,0);
	HAL_SPI_TransmitReceive(hspi,tx_buffer,rx_buffer,8,1000);
	HAL_GPIO_WritePin(SPI1_OUT_GPIO_Port,SPI1_OUT_Pin,1);
}
void spi_master(SPI_HandleTypeDef *hspi,uint8_t tx_buffer[], uint8_t rx_buffer[])
{
	HAL_GPIO_WritePin(SPI1_OUT_GPIO_Port,SPI1_OUT_Pin,0);
	HAL_SPI_TransmitReceive(hspi,tx_buffer,rx_buffer,BUFFER_SIZE,100);
	HAL_GPIO_WritePin(SPI1_OUT_GPIO_Port,SPI1_OUT_Pin,1);
}
void receiveSlave(uint64_t *valuefromSlave, uint8_t rx_buffer[])
{
	uint64_t temp=0x00;
	for (int i = 7; i>=0;i--)
	{		
		temp=temp<<8;
		temp= temp |rx_buffer[i];
		
		//data=data|temp;
	}
	*valuefromSlave=temp;
}

