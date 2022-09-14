/*
 * touch.c
 *
 *  Created on: 2021年10月19日
 *      Author: Yong
 */

#include "touch.h"
#include "ctiic.h"
#include "usart.h"

cst026_touch_point_t cst026;



//向FT5206写入一次数据
//reg:起始寄存器地址
//buf:数据缓缓存区
//len:写数据长度
//返回值:0,成功;1,失败.
u8 CST026_WR_Reg(u16 reg,u8 *buf,u8 len)
{
	u8 i;
	u8 ret=0;
	CT_IIC_Start();	 
	CT_IIC_Send_Byte(CT_CMD_WR);	//发送写命令 	 
	CT_IIC_Wait_Ack(); 	 										  		   
	CT_IIC_Send_Byte(reg&0XFF);   	//发送低8位地址
	CT_IIC_Wait_Ack();  
	for(i=0;i<len;i++)
	{	   
    CT_IIC_Send_Byte(buf[i]);  	//发数据
		ret=CT_IIC_Wait_Ack();
		if(ret)break;  
	}
    CT_IIC_Stop();					//产生一个停止条件	    
	return ret; 
}
//从FT5206读出一次数据
//reg:起始寄存器地址
//buf:数据缓缓存区
//len:读数据长度			  
void CST026_RD_Reg(u16 reg,u8 *buf,u8 len)
{
	u8 i; 
 	CT_IIC_Start();	
 	CT_IIC_Send_Byte(CT_CMD_WR);   	//发送写命令 	 
	CT_IIC_Wait_Ack(); 	 										  		   
 	CT_IIC_Send_Byte(reg&0XFF);   	//发送低8位地址
	CT_IIC_Wait_Ack();  
 	CT_IIC_Start();  	 	   
	CT_IIC_Send_Byte(CT_CMD_RD);   	//发送读命令		   
	CT_IIC_Wait_Ack();	   
	for(i=0;i<len;i++)
	{	   
    	buf[i]=CT_IIC_Read_Byte(i==(len-1)?0:1); //发数据	  
	} 
    CT_IIC_Stop();//产生一个停止条件     
} 


u8 cst026_init(void)
{
	CT_IIC_Init();
	uint8_t temp[2];
	u8 ctp_data[30];
	//硬件复位
	HAL_GPIO_WritePin(Touch_RST_GPIO_Port, Touch_RST_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(Touch_RST_GPIO_Port, Touch_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(120);
	
	temp[0]=0x00;
	CST026_WR_Reg(CST_DEVIDE_MODE,temp,1);	//进入正常操作模式 
	CST026_WR_Reg(CST_ID_G_MODE,temp,1);		//查询模式 
	temp[0]=22;								//触摸有效值，22，越小越灵敏	
	CST026_WR_Reg(CST_ID_G_THGROUP,temp,1);	//设置触摸有效值
	temp[0]=12;								//激活周期，不能小于12，最大14
	CST026_WR_Reg(CST_ID_G_PERIODACTIVE,temp,1); 
	
	//读取版本号，参考值：0x3003
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
	static u8 t=0;//控制查询间隔,从而降低CPU占用率   
	t++;
	if((t%10)==0||t<10)//空闲时,每进入10次CTP_Scan函数才检测1次,从而节省CPU使用率
	{
		CST026_RD_Reg(CST_REG_NUM_FINGER,&mode,1);//读取触摸点的状态  
		if((mode&0XF)&&((mode&0XF)<6))
		{
			temp=0XFF<<(mode&0XF);//将点的个数转换为1的位数,匹配tp_dev.sta定义 
			cst026.touch_state=(~temp)|TP_PRES_DOWN; 
			for(i=0;i<1;i++)
			{
				if(cst026.touch_state&(1<<i))		//触摸有效?
				{
					CST026_RD_Reg(CST026_TPX_TBL[i],buf,4);	//读取XY坐标值 
////					if(tp_dev.touchtype&0X01)//横屏
////					{
						cst026.touch_y=240-(((u16)(buf[0]&0X0F)<<8)+buf[1]);
						cst026.touch_x=((u16)(buf[2]&0X0F)<<8)+buf[3];
////					}else
////					{
//						cst026.touch_x=320-(((u16)(buf[0]&0X0F)<<8)+buf[1]);
//						cst026.touch_y=((u16)(buf[2]&0X0F)<<8)+buf[3];
//					}  
					if((buf[0]&0XF0)!=0X80)cst026.touch_x=cst026.touch_y=0;//必须是contact事件，才认为有效
					//printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);
				}			
			} 
			res=1;
			if(cst026.touch_x==0 && cst026.touch_y==0)mode=0;	//读到的数据都是0,则忽略此次数据
			t=0;		//触发一次,则会最少连续监测10次,从而提高命中率
		}
	}
	if((mode&0X1F)==0)//无触摸点按下
	{ 
		if(cst026.touch_state&TP_PRES_DOWN)	//之前是被按下的
		{
			cst026.touch_state&=~(1<<7);	//标记按键松开
		}else						//之前就没有被按下
		{ 
			cst026.touch_x=0xffff;
			cst026.touch_y=0xffff;
			cst026.touch_state&=0XE0;	//清除点有效标记	
		}	 
	} 	
	if(t>240)t=10;//重新从10开始计数
}


