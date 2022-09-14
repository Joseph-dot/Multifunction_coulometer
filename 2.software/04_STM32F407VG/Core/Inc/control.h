#ifndef __CONTROL_H
#define __CONTROL_H

#include "sys.h"
#include "main.h"


#define   KEY_PWR    HAL_GPIO_ReadPin(KEY_PWR_GPIO_Port,KEY_PWR_Pin)

typedef struct Sys_Statrus{
	
	u8 KEY_PWR_Status;
	
}SYS;



void SYS_Init(void);
void KEY_PWR_Scanf(void);

#endif
