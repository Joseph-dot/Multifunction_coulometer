/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADS_DRDY_Pin GPIO_PIN_3
#define ADS_DRDY_GPIO_Port GPIOE
#define ADS_RESET_Pin GPIO_PIN_5
#define ADS_RESET_GPIO_Port GPIOE
#define USER_LED_Pin GPIO_PIN_0
#define USER_LED_GPIO_Port GPIOC
#define LCD_RES_Pin GPIO_PIN_1
#define LCD_RES_GPIO_Port GPIOC
#define Touch_RST_Pin GPIO_PIN_2
#define Touch_RST_GPIO_Port GPIOC
#define KEY_PWR_Pin GPIO_PIN_3
#define KEY_PWR_GPIO_Port GPIOC
#define KEY_WKUP_Pin GPIO_PIN_0
#define KEY_WKUP_GPIO_Port GPIOA
#define KEY_UP_Pin GPIO_PIN_4
#define KEY_UP_GPIO_Port GPIOC
#define KEY_DOWN_Pin GPIO_PIN_5
#define KEY_DOWN_GPIO_Port GPIOC
#define Touch_INT_Pin GPIO_PIN_1
#define Touch_INT_GPIO_Port GPIOB
#define Touch_INT_EXTI_IRQn EXTI1_IRQn
#define LCD_BL_Pin GPIO_PIN_14
#define LCD_BL_GPIO_Port GPIOE
#define PWR_EN_Pin GPIO_PIN_6
#define PWR_EN_GPIO_Port GPIOC
#define SPI1_NSS_Pin GPIO_PIN_8
#define SPI1_NSS_GPIO_Port GPIOA
#define Touch_SCL_Pin GPIO_PIN_6
#define Touch_SCL_GPIO_Port GPIOB
#define Touch_SDA_Pin GPIO_PIN_7
#define Touch_SDA_GPIO_Port GPIOB
#define USB_IN_Pin GPIO_PIN_0
#define USB_IN_GPIO_Port GPIOE
#define DC_IN_Pin GPIO_PIN_1
#define DC_IN_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
