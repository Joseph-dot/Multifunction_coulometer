/*
 * touch.c
 *
 *  Created on: 2021��10��19��
 *      Author: Yong
 */

#include "touch.h"
#include "ctiic.h"
#include "usart.h"

cst026_touch_point_t cst026;



//��FT5206д��һ������
//reg:��ʼ�Ĵ�����ַ
//buf:���ݻ�������
//len:д���ݳ���
//����ֵ:0,�ɹ�;1,ʧ��.
u8 CST026_WR_Reg(u16 reg,u8 *buf,u8 len)
{
	u8 i;
	u8 ret=0;
	CT_IIC_Start();	 
	CT_IIC_Send_Byte(CT_CMD_WR);	//����д���� 	 
	CT_IIC_Wait_Ack(); 	 										  		   
	CT_IIC_Send_Byte(reg&0XFF);   	//���͵�8λ��ַ
	CT_IIC_Wait_Ack();  
	for(i=0;i<len;i++)
	{	   
    CT_IIC_Send_Byte(buf[i]);  	//������
		ret=CT_IIC_Wait_Ack();
		if(ret)break;  
	}
    CT_IIC_Stop();					//����һ��ֹͣ����	    
	return ret; 
}
//��FT5206����һ������
//reg:��ʼ�Ĵ�����ַ
//buf:���ݻ�������
//len:�����ݳ���			  
void CST026_RD_Reg(u16 reg,u8 *buf,u8 len)
{
	u8 i; 
 	CT_IIC_Start();	
 	CT_IIC_Send_Byte(CT_CMD_WR);   	//����д���� 	 
	CT_IIC_Wait_Ack(); 	 										  		   
 	CT_IIC_Send_Byte(reg&0XFF);   	//���͵�8λ��ַ
	CT_IIC_Wait_Ack();  
 	CT_IIC_Start();  	 	   
	CT_IIC_Send_Byte(CT_CMD_RD);   	//���Ͷ�����		   
	CT_IIC_Wait_Ack();	   
	for(i=0;i<len;i++)
	{	   
    	buf[i]=CT_IIC_Read_Byte(i==(len-1)?0:1); //������	  
	} 
    CT_IIC_Stop();//����һ��ֹͣ����     
} 


u8 cst026_init(void)
{
	CT_IIC_Init();
	uint8_t temp[2];
	u8 ctp_data[30];
	//Ӳ����λ
	HAL_GPIO_WritePin(Touch_RST_GPIO_Port, Touch_RST_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(Touch_RST_GPIO_Port, Touch_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(120);
	
	temp[0]=0x00;
	CST026_WR_Reg(CST_DEVIDE_MODE,temp,1);	//������������ģʽ 
	CST026_WR_Reg(CST_ID_G_MODE,temp,1);		//��ѯģʽ 
	temp[0]=22;								//������Чֵ��22��ԽСԽ����	
	CST026_WR_Reg(CST_ID_G_THGROUP,temp,1);	//���ô�����Чֵ
	temp[0]=12;								//�������ڣ�����С��12�����14
	CST026_WR_Reg(CST_ID_G_PERIODACTIVE,temp,1); 
	
	//��ȡ�汾�ţ��ο�ֵ��0x3003
//	CST026_RD_Reg(CST_ID_G_LIB_VERSION,&temp[0],2);  
//	sprintf((char *)ctp_data,"CTP_ID:%x\r\n",((u16)temp[0]<<8)+temp[1]);
//	HAL_UART_Transmit(&huart1,ctp_data,30,10);
	return 1;
	
}

const u16 CST026_TPX_TBL[2]={CST_TP1_REG,CST_TP2_REG};

void cst026_scan(u8 mode)
{
	u8 buf[4];
	u8 i=0;
	u8 res=0;
	u8 temp;
	static u8 t=0;//���Ʋ�ѯ���,�Ӷ�����CPUռ����   
	t++;
	if((t%10)==0||t<10)//����ʱ,ÿ����10��CTP_Scan�����ż��1��,�Ӷ���ʡCPUʹ����
	{
		CST026_RD_Reg(CST_REG_NUM_FINGER,&mode,1);//��ȡ�������״̬  
		if((mode&0XF)&&((mode&0XF)<6))
		{
			temp=0XFF<<(mode&0XF);//����ĸ���ת��Ϊ1��λ��,ƥ��tp_dev.sta���� 
			cst026.touch_state=(~temp)|TP_PRES_DOWN; 
			for(i=0;i<1;i++)
			{
				if(cst026.touch_state&(1<<i))		//������Ч?
				{
					CST026_RD_Reg(CST026_TPX_TBL[i],buf,4);	//��ȡXY����ֵ 
////					if(tp_dev.touchtype&0X01)//����
////					{
						cst026.touch_y=240-(((u16)(buf[0]&0X0F)<<8)+buf[1]);
						cst026.touch_x=((u16)(buf[2]&0X0F)<<8)+buf[3];
////					}else
////					{
//						cst026.touch_x=320-(((u16)(buf[0]&0X0F)<<8)+buf[1]);
//						cst026.touch_y=((u16)(buf[2]&0X0F)<<8)+buf[3];
//					}  
					if((buf[0]&0XF0)!=0X80)cst026.touch_x=cst026.touch_y=0;//������contact�¼�������Ϊ��Ч
					//printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);
				}			
			} 
			res=1;
			if(cst026.touch_x==0 && cst026.touch_y==0)mode=0;	//���������ݶ���0,����Դ˴�����
			t=0;		//����һ��,��������������10��,�Ӷ����������
		}
	}
	if((mode&0X1F)==0)//�޴����㰴��
	{ 
		if(cst026.touch_state&TP_PRES_DOWN)	//֮ǰ�Ǳ����µ�
		{
			cst026.touch_state&=~(1<<7);	//��ǰ����ɿ�
		}else						//֮ǰ��û�б�����
		{ 
			cst026.touch_x=0xffff;
			cst026.touch_y=0xffff;
			cst026.touch_state&=0XE0;	//�������Ч���	
		}	 
	} 	
	if(t>240)t=10;//���´�10��ʼ����
}


