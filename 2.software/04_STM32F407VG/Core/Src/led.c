#include "led.h"
#include "uconfig.h"
#include "delay.h"
#include "usart.h"

void user_led(void)
{
	HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,GPIO_PIN_RESET);
	delay_ms(user_led_ldelay);
	HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,GPIO_PIN_SET);
	delay_ms(user_led_ldelay);
	
	HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,GPIO_PIN_RESET);
	delay_ms(user_led_ldelay);
	HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,GPIO_PIN_SET);
	delay_ms(user_led_hdelay);
}


void led_on(void)
{
	HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,GPIO_PIN_RESET);
}

void led_off(void)
{
	HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,GPIO_PIN_SET);
}