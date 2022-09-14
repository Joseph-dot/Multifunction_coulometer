/*
 * touch.h
 *
 *  Created on: 2021年10月19日
 *      Author: Yong
 */

#ifndef TOUCH_TOUCH_H_
#define TOUCH_TOUCH_H_

#include "main.h"				//数据类型声明
#include "sys.h"

#define CST026_I2C_ADDR         0x70	//设备地址


//I2C读写命令	
#define CT_CMD_WR 				0X70    	//写命令
#define CT_CMD_RD 				0X71		//读命令


/* cst026 部分寄存器定义 */
#define TP_PRES_DOWN            0x80  	//触屏被按下
#define TP_COORD_UD             0x40  	//触摸坐标更新标记

#define CST_DEVIDE_MODE 		0x00   	//cst026模式控制寄存器
#define CST_REG_NUM_FINGER       0x02	//触摸状态寄存器

#define CST_TP1_REG 			0X03	//第一个触摸点数据地址
#define CST_TP2_REG 			0X09	//第二个触摸点数据地址

#define	CST_ID_G_LIB_VERSION		0xA1		//版本		
#define CST_ID_G_MODE 			0xA4   	//cst026中断模式控制寄存器
#define CST_ID_G_THGROUP		0x80   	//触摸有效值设置寄存器
#define CST_ID_G_PERIODACTIVE	0x88   	//激活状态周期设置寄存器

/* cst026触摸结构体 */
typedef struct
{
    //触摸状态 b7:按下1/松开0; b6:0没有按键按下/1有按键按下;
    //bit5-bit1:保留；bit0触摸点按下有效标志，有效为1
	uint8_t touch_state;
	uint16_t touch_x;
	uint16_t touch_y;
	uint8_t touch_data[30];
} cst026_touch_point_t;

extern cst026_touch_point_t cst026;

u8 cst026_init(void);
void cst026_scan(u8 mode);

#endif /* TOUCH_TOUCH_H_ */
