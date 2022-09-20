#include "ads131a04.h"
#include "spi.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"

static void ads_reset(void)
{
	ADS_RESET_L;
	delay_ms(50);
	ADS_RESET_H;
	SPI1_NSS_H;
	ADS_DRDY_H;
	delay_ms(50);
}


uint16_t ADS131_WRITE_CMD(uint16_t cmd)
{
	uint16_t receive=0x0000;
	
	SPI1_NSS_L;
	ADS_DRDY_L;
	delay_us(10);
	receive=SPI1_ReadWriteByte(cmd>>8);
	receive<<=8;
	receive|=SPI1_ReadWriteByte(cmd&0x00FF);
	delay_us(10);
	SPI1_NSS_H;
	ADS_DRDY_H;
	return receive;
}

void ADS131_WRITE_REG(uint8_t addres,uint8_t data)
{
	SPI1_NSS_L;
	ADS_DRDY_L;
	SPI1_ReadWriteByte(addres);		//addres
	SPI1_ReadWriteByte(data);	//high 8 bit data
	SPI1_NSS_H;
	ADS_DRDY_H;
}

uint16_t ADS131_READ_DATA(uint8_t addres)
{
	uint16_t data;
	SPI1_NSS_L;
	ADS_DRDY_L;
	SPI1_ReadWriteByte(addres);		//addres
	data=SPI1_ReadWriteByte(OPCODE_NULL>>8);
	data<<=8;
	data=SPI1_ReadWriteByte(OPCODE_NULL&0x00FF);
	SPI1_NSS_H;
	ADS_DRDY_H;
	return data;
}


uint8_t getRegisterValue(uint8_t address)
{
	
}




void ADS131_Init(void)
{
	uint16_t RECEIVE=0x0000,i=0,count=0;
	uint8_t data[100]={0};
	ads_reset();
	ADS131_WRITE_CMD(OPCODE_NULL);
	do
	{
		RECEIVE=ADS131_WRITE_CMD(OPCODE_NULL);
		sprintf((char *)data,"receive data is : %X...\r\n",RECEIVE);
		HAL_UART_Transmit(&huart1,data,sizeof(data),100);
		if(RECEIVE == 0xff04)
		{
			sprintf((char *)data,"ADS131A04 is ready! Configuring Registers...\r\n");
			HAL_UART_Transmit(&huart1,data,sizeof(data),100);
			delay_ms(5);
		}
		
	}while(RECEIVE != 0xff04);
	ADS131_WRITE_CMD(OPCODE_UNLOCK);
	RECEIVE=ADS131_WRITE_CMD(OPCODE_NULL);
	sprintf((char *)data,"unlock return data is : %X...\r\n",RECEIVE);
	HAL_UART_Transmit(&huart1,data,sizeof(data),100);
	ADS131_WRITE_REG((OPCODE_WREG>>8)|CLK1_ADDRESS,CLK1_CLK_DIV_8);
	ADS131_WRITE_REG((OPCODE_WREG>>8)|CLK2_ADDRESS,CLK2_ICLK_DIV_2|CLK2_OSR_2048);
	ADS131_WRITE_REG((OPCODE_WREG>>8)|ADC_ENA_ADDRESS,ADC_ENA_ENA_ALL_CH_PWUP);
	ADS131_WRITE_CMD(OPCODE_WAKEUP);
	
//	// Write to D_SYS_CFG_ADDRESS
//	ads_write_reg(D_SYS_CFG_ADDRESS,D_SYS_CFG_DEFAULT | D_SYS_CFG_FIXED_MASK);

//	// Configure data rate
//	ads_write_reg(CLK1_ADDRESS,CLK1_CLK_DIV_2);
//	ads_write_reg(CLK2_ADDRESS,CLK2_ICLK_DIV_2 | CLK2_OSR_2048);
//	
//	// Enable all ADC channels
//	ads_write_reg(ADC_ENA_ADDRESS,ADC_ENA_ENA_ALL_CH_PWUP);
	
}

uint16_t ADS131_GetValue(uint8_t ADC_Channel)
{
	
}


