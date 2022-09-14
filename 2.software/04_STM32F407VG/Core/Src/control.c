#include "control.h"
#include <stdio.h>
#include "uconfig.h"
#include "delay.h"
#include "usart.h"
#include "gpio.h"


SYS sys;


void SYS_Init(void)
{
	MX_GPIO_Init();
  MX_USART1_UART_Init();
	delay_init(168);
}

void PWR_ON(void)
{
	HAL_GPIO_WritePin(PWR_EN_GPIO_Port,PWR_EN_Pin,GPIO_PIN_SET);
}


void PWR_OFF(void)
{
	HAL_GPIO_WritePin(PWR_EN_GPIO_Port,PWR_EN_Pin,GPIO_PIN_RESET);
}




void KEY_PWR_Scanf(void)
{
	u8 data[25];
	
	/*	按键开机操作，防误触开机	*/
	while(!sys.KEY_PWR_Status)
	{
		HAL_UART_Transmit(&huart1,"While KEY_PWR \r\n",20,10);
		delay_ms(user_pwr_delay);
		if(KEY_PWR == GPIO_PIN_RESET)
		{
			sys.KEY_PWR_Status = 1;
			sprintf((char *)data,"KEY_PWR_Status  -> ON \r\n");
			HAL_UART_Transmit(&huart1,data,25,10);
			PWR_ON();
			return;
		}
		else sys.KEY_PWR_Status = 0;
	}
	
	/*	开机状态长按关机	*/
	if(sys.KEY_PWR_Status)
	{
		if(KEY_PWR == GPIO_PIN_RESET)
		{
			delay_ms(200);
			if(KEY_PWR == GPIO_PIN_RESET)
			{
				sys.KEY_PWR_Status = 0;
				HAL_UART_Transmit(&huart1,"KEY_PWR_Status  -> OFF  \r\n",20,10);
				PWR_OFF();
			}
		}
	}
	
	
	/*	*/
	
	
	
}


