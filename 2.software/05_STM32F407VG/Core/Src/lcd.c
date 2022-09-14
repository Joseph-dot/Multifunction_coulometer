#include "lcd.h"
#include "gpio.h"
#include "uconfig.h"
#include "delay.h"
#include "usart.h"


SRAM_HandleTypeDef TFTSRAM_Handler;    //SRAM���(���ڿ���LCD)


//д�Ĵ�������
//regval:�Ĵ���ֵ
void LCD_WR_REG(vu16 regval)
{   
	regval=regval;		//ʹ��-O2�Ż���ʱ��,����������ʱ
	LCD->LCD_REG=regval;//д��Ҫд�ļĴ������	 
}

//дLCD����
//data:Ҫд���ֵ
void LCD_WR_DATA(vu16 data)
{	  
	data=data;			//ʹ��-O2�Ż���ʱ��,����������ʱ
	LCD->LCD_RAM=data;		 
}


//��LCD����
//����ֵ:������ֵ
u16 LCD_RD_DATA(void)
{
	vu16 ram;			//��ֹ���Ż�
	ram=LCD->LCD_RAM;	
	return ram;	 
}

//д�Ĵ���
//LCD_Reg:�Ĵ�����ַ
//LCD_RegValue:Ҫд�������
void LCD_WriteReg(u16 LCD_Reg,u16 LCD_RegValue)
{	
	LCD->LCD_REG = LCD_Reg;		//д��Ҫд�ļĴ������	 
	LCD->LCD_RAM = LCD_RegValue;//д������	    		 
}

//���Ĵ���
//LCD_Reg:�Ĵ�����ַ
//����ֵ:����������
u16 LCD_ReadReg(u16 LCD_Reg)
{										   
	LCD_WR_REG(LCD_Reg);		//д��Ҫ���ļĴ������
	delay_us(5);		  
	return LCD_RD_DATA();		//���ض�����ֵ
}

//LCDдGRAM
//RGB_Code:��ɫֵ
void LCD_WriteRAM(u16 RGB_Code)
{
	LCD->LCD_RAM = RGB_Code>>8;
	delay_us(1);		//���룬ȥ����ʾһ�벢��ɫ����
	LCD->LCD_RAM = RGB_Code&0xff;//дʮ��λGRAM
}


//LCD������ʾ
void LCD_DisplayOn(void)
{					   
	LCD_WR_REG(0X29);       //������ʾ
}

//LCD�ر���ʾ
void LCD_DisplayOff(void)
{	   
	LCD_WR_REG(0X28);       //�ر���ʾ
}

//���ù��λ��
//Xpos:������
//Ypos:������
void LCD_SetCursor(u16 Xpos, u16 Ypos)
{
	LCD_WR_REG(0x2a);
	LCD_WR_DATA(Xpos >> 8);
	LCD_WR_DATA(Xpos & 0XFF);
	
	LCD_WR_REG(0x2b);
	LCD_WR_DATA(Ypos >> 8);
	LCD_WR_DATA(Ypos & 0XFF);
	
	LCD_WR_REG(0x2c);
	}


/******************************************************************************
      ����˵����������ʼ�ͽ�����ַ
      ������ݣ�x1,x2 �����е���ʼ�ͽ�����ַ
                y1,y2 �����е���ʼ�ͽ�����ַ
      ����ֵ��  ��
******************************************************************************/
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);//�е�ַ����
		LCD_WR_DATA(x1>>8);
		LCD_WR_DATA(x1&0xff);
		LCD_WR_DATA(x2>>8);
		LCD_WR_DATA(x2&0xff);
		
		LCD_WR_REG(0x2b);//�е�ַ����
		LCD_WR_DATA(y1>>8);
		LCD_WR_DATA(y1&0xff);
		LCD_WR_DATA(y2>>8);
		LCD_WR_DATA(y2&0xff);
		
		
		LCD_WR_REG(0x2c);//������д
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);//�е�ַ����
		LCD_WR_DATA(x1>>8);
		LCD_WR_DATA(x1&0xff);
		LCD_WR_DATA(x2>>8);
		LCD_WR_DATA(x2&0xff);
		
		LCD_WR_REG(0x2b);//�е�ַ����
		LCD_WR_DATA(y1>>8);
		LCD_WR_DATA(y1&0xff);
		LCD_WR_DATA(y2>>8);
		LCD_WR_DATA(y2&0xff);
		
		
		LCD_WR_REG(0x2c);//������д
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);//�е�ַ����
		LCD_WR_DATA(x1>>8);
		LCD_WR_DATA(x1&0xff);
		LCD_WR_DATA(x2>>8);
		LCD_WR_DATA(x2&0xff);
		
		LCD_WR_REG(0x2b);//�е�ַ����
		LCD_WR_DATA(y1>>8);
		LCD_WR_DATA(y1&0xff);
		LCD_WR_DATA(y2>>8);
		LCD_WR_DATA(y2&0xff);
		
		
		LCD_WR_REG(0x2c);//������д
	}
	else
	{
		LCD_WR_REG(0x2a);//�е�ַ����
		LCD_WR_DATA(x1>>8);
		LCD_WR_DATA(x1&0xff);
		LCD_WR_DATA(x2>>8);
		LCD_WR_DATA(x2&0xff);
		
		LCD_WR_REG(0x2b);//�е�ַ����
		LCD_WR_DATA(y1>>8);
		LCD_WR_DATA(y1&0xff);
		LCD_WR_DATA(y2>>8);
		LCD_WR_DATA(y2&0xff);
		
		
		LCD_WR_REG(0x2c);//������д
	}
}




//��ʼ��lcd
void LCD_Init(void)
{
	LCD_RES();
	delay_ms(100); // delay 100 ms 
	
	LCD_WR_REG(0x11);

	delay_ms(120);

	LCD_WR_REG(0x36);
	if(USE_HORIZONTAL==0)LCD_WR_DATA(0x00);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA(0xC0);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA(0x70);
	else LCD_WR_DATA(0xA0);


	LCD_WR_REG(0x3A);
	LCD_WR_DATA(0X05);

	LCD_WR_REG(0xB2);
	LCD_WR_DATA(0x0C);
	LCD_WR_DATA(0x0C);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x33);
	LCD_WR_DATA(0x33);

	LCD_WR_REG(0xB7);
	LCD_WR_DATA(0x35);

	LCD_WR_REG(0xBB);       //vcom
	LCD_WR_DATA(0x19);      //30

	LCD_WR_REG(0xC0);
	LCD_WR_DATA(0x2C);

	LCD_WR_REG(0xC2);
	LCD_WR_DATA(0x01);

	LCD_WR_REG(0xC3);       //vrh
	LCD_WR_DATA(0x12);      //17 0D

	LCD_WR_REG(0xC4);       //vdv
	LCD_WR_DATA(0x20);      //20

	LCD_WR_REG(0xC6);
	LCD_WR_DATA(0x0F);

	LCD_WR_REG(0xD0);
	LCD_WR_DATA(0xA4);
	LCD_WR_DATA(0xA1);

	LCD_WR_REG(0xE0);       //Set Gamma
	LCD_WR_DATA(0xD0);
	LCD_WR_DATA(0x04);
	LCD_WR_DATA(0x0D);
	LCD_WR_DATA(0x11);
	LCD_WR_DATA(0x13);
	LCD_WR_DATA(0x2B);
	LCD_WR_DATA(0x3F);
	LCD_WR_DATA(0X54);
	LCD_WR_DATA(0x4C);
	LCD_WR_DATA(0x18);
	LCD_WR_DATA(0x0D);
	LCD_WR_DATA(0x0B);
	LCD_WR_DATA(0x1F);
	LCD_WR_DATA(0x23);

	LCD_WR_REG(0XE1);       //Set Gamma
	LCD_WR_DATA(0xD0);
	LCD_WR_DATA(0x04);
	LCD_WR_DATA(0x0C);
	LCD_WR_DATA(0x11);
	LCD_WR_DATA(0x13);
	LCD_WR_DATA(0x2C);
	LCD_WR_DATA(0x3F);
	LCD_WR_DATA(0x44);
	LCD_WR_DATA(0x51);
	LCD_WR_DATA(0x2F);
	LCD_WR_DATA(0x1F);
	LCD_WR_DATA(0x1F);
	LCD_WR_DATA(0x20);
	LCD_WR_DATA(0x23);

	LCD_WR_REG(0x21);

	LCD_WR_REG(0x29);       //display on
	
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK);
	delay_ms(20);
	LCD_BL_ON();
}  



/******************************************************************************
      ����˵������ָ�����������ɫ
      ������ݣ�xsta,ysta   ��ʼ����
                xend,yend   ��ֹ����
								color       Ҫ������ɫ
      ����ֵ��  ��
***********************************************************************7*******/
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{          
	u16 i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//������ʾ��Χ
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			LCD_WriteRAM(color);
		}
	} 					  	    
}


//��ָ�����������ָ����ɫ��
//(sx,sy),(ex,ey):�����ζԽ�����,�����СΪ:(ex-sx+1)*(ey-sy+1)
//color:Ҫ������ɫ
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color)
{  
	u16 height,width;
	u16 i,j; 
	width=ex-sx+1; 			//�õ����Ŀ��
	height=ey-sy+1;			//�߶�
	for(i=0;i<height;i++)
	{
		LCD_SetCursor(sx,sy+i);   	//���ù��λ�� 
        for (j = 0; j < width; j++)
        {
			LCD_WriteRAM(color[i * width + j]); //д������
        }
    }
}



/*	��λLCD��Ļ	*/
void LCD_RES(void)
{
	HAL_GPIO_WritePin(LCD_RES_GPIO_Port,LCD_RES_Pin,GPIO_PIN_RESET);
	delay_ms(100);
	HAL_GPIO_WritePin(LCD_RES_GPIO_Port,LCD_RES_Pin,GPIO_PIN_SET);
	delay_ms(100);
}

/*	�򿪱���	*/
void LCD_BL_ON(void)
{
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port,LCD_BL_Pin,GPIO_PIN_SET);
	delay_ms(100);
}

/*	�رձ���	*/
void LCD_BL_OFF(void)
{
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port,LCD_BL_Pin,GPIO_PIN_RESET);
	delay_ms(100);
}
