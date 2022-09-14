#ifndef __LCD_H_
#define __LCD_H_

#include "main.h"
#include "sys.h"
#include "stdlib.h" 




extern SRAM_HandleTypeDef TFTSRAM_Handler;    //SRAM句柄(用于控制LCD)



#define USE_HORIZONTAL 0  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏


#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 240
#define LCD_H 320

#else
#define LCD_W 320
#define LCD_H 240
#endif


//LCD地址结构体
typedef struct
{
	u8 LCD_REG;
	u8 LCD_RAM;
} LCD_TypeDef;

//使用NOR/SRAM的 Bank1.sector1,地址位HADDR[27,26]=11 A16作为数据命令区分线 
//注意设置时STM32内部会右移一位对其! 111 1110=0X7E			    
#define LCD_BASE        ((u32)(0x60000000 | 0x0000FFFF))
#define LCD             ((LCD_TypeDef *) LCD_BASE)
//////////////////////////////////////////////////////////////////////////////////



//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	 0X841F //浅绿色
//#define LIGHTGRAY        0XEF5B //浅灰色(PANNEL)
#define LGRAY 			 0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色

void LCD_Init(void);													   	//初始化
void LCD_DisplayOn(void);													//开显示
void LCD_DisplayOff(void);													//关显示
//void LCD_Clear(u16 Color);	 												//清屏

void LCD_RES(void);
void LCD_BL_ON(void);
void LCD_BL_OFF(void);
void LCD_WR_COLOR(vu16 data);
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);

#endif
