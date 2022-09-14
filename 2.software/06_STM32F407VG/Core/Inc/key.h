#ifndef __KEY_H
#define __KEY_H

#include "sys.h"
#include "main.h"



#define   KEY_UP     HAL_GPIO_ReadPin(KEY_UP_GPIO_Port,KEY_UP_Pin)
#define   KEY_DOWN   HAL_GPIO_ReadPin(KEY_DOWN_GPIO_Port,KEY_DOWN_Pin)
#define   KEY_WKUP   HAL_GPIO_ReadPin(KEY_WKUP_GPIO_Port,KEY_WKUP_Pin)



typedef struct KEY_Scanf{
	
	u8 KEY_UP_Status;
	u8 KEY_DOWN_Status;
	u8 KEY_WKUP_Status;
	
	u8 KEY_Status;
}KEY;


extern KEY key;



u8 KEY_Scan(void);
void KEY_Demo(void);


#endif
