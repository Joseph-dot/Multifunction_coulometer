/*
 * touch.h
 *
 *  Created on: 2021��10��19��
 *      Author: Yong
 */

#ifndef TOUCH_TOUCH_H_
#define TOUCH_TOUCH_H_

#include "main.h"				//������������
#include "sys.h"

#define CST026_I2C_ADDR         0x70	//�豸��ַ


//I2C��д����	
#define CT_CMD_WR 				0X70    	//д����
#define CT_CMD_RD 				0X71		//������


/* cst026 ���ּĴ������� */
#define TP_PRES_DOWN            0x80  	//����������
#define TP_COORD_UD             0x40  	//����������±��

#define CST_DEVIDE_MODE 		0x00   	//cst026ģʽ���ƼĴ���
#define CST_REG_NUM_FINGER       0x02	//����״̬�Ĵ���

#define CST_TP1_REG 			0X03	//��һ�����������ݵ�ַ
#define CST_TP2_REG 			0X09	//�ڶ������������ݵ�ַ

#define	CST_ID_G_LIB_VERSION		0xA1		//�汾		
#define CST_ID_G_MODE 			0xA4   	//cst026�ж�ģʽ���ƼĴ���
#define CST_ID_G_THGROUP		0x80   	//������Чֵ���üĴ���
#define CST_ID_G_PERIODACTIVE	0x88   	//����״̬�������üĴ���

/* cst026�����ṹ�� */
typedef struct
{
    //����״̬ b7:����1/�ɿ�0; b6:0û�а�������/1�а�������;
    //bit5-bit1:������bit0�����㰴����Ч��־����ЧΪ1
	uint8_t touch_state;
	uint16_t touch_x;
	uint16_t touch_y;
	uint8_t touch_data[30];
} cst026_touch_point_t;

extern cst026_touch_point_t cst026;

u8 cst026_init(void);
void cst026_scan(u8 mode);

#endif /* TOUCH_TOUCH_H_ */
