#include "key.h"
#include <stdio.h>
#include "uconfig.h"
#include "delay.h"
#include "led.h"

KEY key;




u8 KEY_Scan(void)
{
	if(KEY_UP == GPIO_PIN_RESET)
	{
		delay_ms(200);
		if(KEY_UP == GPIO_PIN_RESET)
		{
			key.KEY_Status = 1;
			key.KEY_UP_Status = 1;
		}
	}
	
	if(KEY_DOWN == GPIO_PIN_RESET)
	{
		delay_ms(200);
		if(KEY_DOWN == GPIO_PIN_RESET)
		{
			key.KEY_Status = 1;
			key.KEY_DOWN_Status = 1;
		}
	}
	
	if(KEY_WKUP == GPIO_PIN_RESET)
	{
		delay_ms(200);
		if(KEY_WKUP == GPIO_PIN_RESET)
		{
			key.KEY_Status = 1;
			key.KEY_WKUP_Status = 1;
		}
	}
}


void KEY_Demo(void)
{
	KEY_Scan();
	if(key.KEY_Status == 1)
	{
		if(key.KEY_UP_Status == 1)
		{
			led_on();
			key.KEY_UP_Status=0;
		}
		else if(key.KEY_DOWN_Status == 1)
		{
			led_off();
			key.KEY_DOWN_Status=0;
		}
		else if(key.KEY_WKUP_Status == 1)
		{
			led_on();
			delay_ms(1000);
			led_off();
			key.KEY_WKUP_Status=0;
		}
		else
		{
			key.KEY_Status=0;
		}
	}
}