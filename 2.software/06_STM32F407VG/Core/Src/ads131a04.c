#include "ads131a04.h"
#include "spi.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"


adc_data_struct ads131_data;

#define VREF 2.5000
#define V_24bit	4194304


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
	
	receive=SPI1_ReadWriteByte(cmd>>8);
	receive<<=8;
	receive|=SPI1_ReadWriteByte(cmd&0x00FF);
	
	SPI1_ReadWriteByte(0x00);
	SPI1_ReadWriteByte(0x00);
	SPI1_NSS_H;
	ADS_DRDY_H;
	return receive;
}

void ADS131_WRITE_REG(uint8_t addres,uint8_t data)
{
	SPI1_NSS_L;
	ADS_DRDY_L;
	SPI1_ReadWriteByte(addres);		//addres
	SPI1_ReadWriteByte(data);	//8 bit data
	
	SPI1_ReadWriteByte(0x00);
	SPI1_ReadWriteByte(0x00);
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
	uint32_t RECEIVE=0x0000,i=0,count=0;
	uint8_t data[100]={0};
	ads_reset();
	do
	{
		ADS131_WRITE_CMD(OPCODE_NULL);
		RECEIVE=ADS131_WRITE_CMD(OPCODE_NULL);
		sprintf((char *)data,"receive data is : %04X...\r\n",RECEIVE);
		HAL_UART_Transmit(&huart1,data,sizeof(data),100);
		memset(data,0,sizeof(data));
		if(RECEIVE == 0xff04)
		{
			sprintf((char *)data,"ADS131A04 is ready! Configuring Registers...\r\n");
			HAL_UART_Transmit(&huart1,data,sizeof(data),100);
			memset(data,0,sizeof(data));
			delay_ms(5);
		}
		
	}while(RECEIVE != 0xff04);
	
	ADS131_WRITE_CMD(OPCODE_UNLOCK);
	RECEIVE=ADS131_WRITE_CMD(OPCODE_NULL);
	sprintf((char *)data,"unlock return data is : %04X...\r\n",RECEIVE);
	HAL_UART_Transmit(&huart1,data,sizeof(data),100);
	memset(data,0,sizeof(data));
	
	ADS131_WRITE_REG((OPCODE_WREG>>8)|D_SYS_CFG_ADDRESS,D_SYS_CFG_DEFAULT|D_SYS_CFG_FIXED_MASK);
	ADS131_WRITE_REG((OPCODE_WREG>>8)|CLK1_ADDRESS,CLK1_CLK_DIV_8);
	ADS131_WRITE_REG((OPCODE_WREG>>8)|CLK2_ADDRESS,CLK2_ICLK_DIV_2|CLK2_OSR_2048);
	ADS131_WRITE_REG((OPCODE_WREG>>8)|ADC_ENA_ADDRESS,ADC_ENA_ENA_ALL_CH_PWUP);
	
	ADS131_WRITE_CMD(OPCODE_WAKEUP);
	RECEIVE=ADS131_WRITE_CMD(OPCODE_NULL);
	sprintf((char *)data,"wakeup return data is : %04X...\r\n",RECEIVE);
	HAL_UART_Transmit(&huart1,data,sizeof(data),100);
	memset(data,0,sizeof(data));
	
	ADS131_WRITE_CMD(OPCODE_LOCK);
	RECEIVE=ADS131_WRITE_CMD(OPCODE_NULL);
	sprintf((char *)data,"lock return data is : %04X...\r\n",RECEIVE);
	HAL_UART_Transmit(&huart1,data,sizeof(data),100);
	memset(data,0,sizeof(data));
	
}

void ADS131_GetValue(void)
{
	int32_t Value_H,Value_L;
	uint8_t adc_data[30]={0};
	uint8_t data[200]={0};
	
	double value_1,value_2,value_3,value_4;
	
	SPI1_NSS_L;
	
	for(int i=0;i<21;i++)
	{
		adc_data[i]=SPI1_ReadWriteByte(0x00);
	}
	
	SPI1_NSS_H;
	
	ads131_data.response=((uint16_t)adc_data[0]<<8);
	ads131_data.response|=((uint16_t)adc_data[1]&0x00FF);
	
	Value_H=((int32_t)adc_data[4]<<24);
	Value_H|=((int32_t)adc_data[5]<<16);
	Value_L=((int32_t)adc_data[6]<<8);
	Value_L|=((int32_t)adc_data[7]);
	ads131_data.channel1=((Value_H|Value_L)>>8);
	
	
	Value_H=((int32_t)adc_data[8]<<24);
	Value_H|=((int32_t)adc_data[9]<<16);
	Value_L=((int32_t)adc_data[10]<<8);
	Value_L|=((int32_t)adc_data[11]);
	ads131_data.channel2=((Value_H|Value_L)>>8);
	
	
	Value_H=((int32_t)adc_data[12]<<24);
	Value_H|=((int32_t)adc_data[13]<<16);
	Value_L=((int32_t)adc_data[14]<<8);
	Value_L|=((int32_t)adc_data[15]);
	ads131_data.channel3=((Value_H|Value_L)>>8);
	
	
	Value_H=((int32_t)adc_data[16]<<24);
	Value_H|=((int32_t)adc_data[17]<<16);
	Value_L=((int32_t)adc_data[18]<<8);
	Value_L|=((int32_t)adc_data[19]);
	ads131_data.channel4=((Value_H|Value_L)>>8);
	
	value_1=(ads131_data.channel1*VREF)/V_24bit;
	value_2=(ads131_data.channel2*VREF)/V_24bit;
	value_3=(ads131_data.channel3*VREF)/V_24bit;
	value_4=(ads131_data.channel4*VREF)/V_24bit;
	
	
	if(ads131_data.response==0x2230)
	{
	
		HAL_UART_Transmit(&huart1,"***************** \r\n",20,100);
		HAL_UART_Transmit(&huart1," adc data is OK \r\n",18,100);
//		sprintf((char *)data," ADC1=%d \r\n ADC2=%d \r\n ADC3=%d \r\n ADC4=%d \r\n",ads131_data.channel1,ads131_data.channel2,ads131_data.channel3,ads131_data.channel4);
//		HAL_UART_Transmit(&huart1,data,sizeof(data),100);
//		memset(data,0,sizeof(data));
		
		sprintf((char *)data," ADC1=%.8lf V\r\n ADC2=%.8lf V\r\n ADC3=%.8lf V\r\n ADC4=%.8lf V\r\n",value_1,value_2,value_3,value_4);
		HAL_UART_Transmit(&huart1,data,sizeof(data),200);
		memset(data,0,sizeof(data));
		
		HAL_UART_Transmit(&huart1,"***************** \r\n",20,100);
	}

//	HAL_UART_Transmit(&huart1,adc_data,sizeof(adc_data),100);
}




