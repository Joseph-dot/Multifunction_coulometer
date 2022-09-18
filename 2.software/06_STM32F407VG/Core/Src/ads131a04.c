#include "ads131a04.h"
#include "spi.h"
#include "delay.h"


static void ads_reset(void)
{
	ADS_RESET_L;
	delay_ms(50);
	ADS_RESET_H;
	delay_ms(50);
}


void ads_write_reg(uint8_t addres,uint8_t reg)
{
	SPI1_NSS_L;
	ADS_DRDY_L;
	SPI1_ReadWriteByte(addres);		//addres
	SPI1_ReadWriteByte(reg);	//high 8 bit data
	SPI1_NSS_H;
	ADS_DRDY_H;
}

uint8_t ads_read_data(uint8_t addres)
{
	uint8_t data;
	SPI1_NSS_L;
	ADS_DRDY_L;
	SPI1_ReadWriteByte(addres);		//addres
	data=SPI1_ReadWriteByte(0xFF);
	SPI1_NSS_H;
	ADS_DRDY_H;
	return data;
}


uint8_t getRegisterValue(uint8_t address)
{
	
}




void ads_Init(void)
{
	ads_reset();
	// Write to D_SYS_CFG_ADDRESS
	ads_write_reg(D_SYS_CFG_ADDRESS,D_SYS_CFG_DEFAULT | D_SYS_CFG_FIXED_MASK);

	// Configure data rate
	ads_write_reg(CLK1_ADDRESS,CLK1_CLK_DIV_2);
	ads_write_reg(CLK2_ADDRESS,CLK2_ICLK_DIV_2 | CLK2_OSR_2048);
	
	// Enable all ADC channels
	ads_write_reg(ADC_ENA_ADDRESS,ADC_ENA_ENA_ALL_CH_PWUP);
	
}