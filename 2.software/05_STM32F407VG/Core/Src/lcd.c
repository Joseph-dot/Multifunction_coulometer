#include "lcd.h"
#include "gpio.h"
#include "uconfig.h"
#include "delay.h"
#include "usart.h"


SRAM_HandleTypeDef TFTSRAM_Handler;    //SRAM句柄(用于控制LCD)


//写寄存器函数
//regval:寄存器值
void LCD_WR_REG(vu16 regval)
{   
	regval=regval;		//使用-O2优化的时候,必须插入的延时
	LCD->LCD_REG=regval;//写入要写的寄存器序号	 
}

//写LCD数据
//data:要写入的值
void LCD_WR_DATA(vu16 data)
{	  
	data=data;			//使用-O2优化的时候,必须插入的延时
	LCD->LCD_RAM=data;		 
}


//读LCD数据
//返回值:读到的值
u16 LCD_RD_DATA(void)
{
	vu16 ram;			//防止被优化
	ram=LCD->LCD_RAM;	
	return ram;	 
}

//写寄存器
//LCD_Reg:寄存器地址
//LCD_RegValue:要写入的数据
void LCD_WriteReg(u16 LCD_Reg,u16 LCD_RegValue)
{	
	LCD->LCD_REG = LCD_Reg;		//写入要写的寄存器序号	 
	LCD->LCD_RAM = LCD_RegValue;//写入数据	    		 
}

//读寄存器
//LCD_Reg:寄存器地址
//返回值:读到的数据
u16 LCD_ReadReg(u16 LCD_Reg)
{										   
	LCD_WR_REG(LCD_Reg);		//写入要读的寄存器序号
	delay_us(5);		  
	return LCD_RD_DATA();		//返回读到的值
}

//LCD写GRAM
//RGB_Code:颜色值
void LCD_WriteRAM(u16 RGB_Code)
{
	LCD->LCD_RAM = RGB_Code>>8;
	delay_us(1);		//必须，去掉显示一半并颜色错误
	LCD->LCD_RAM = RGB_Code&0xff;//写十六位GRAM
}


//LCD开启显示
void LCD_DisplayOn(void)
{					   
	LCD_WR_REG(0X29);       //开启显示
}

//LCD关闭显示
void LCD_DisplayOff(void)
{	   
	LCD_WR_REG(0X28);       //关闭显示
}

//设置光标位置
//Xpos:横坐标
//Ypos:纵坐标
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
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1>>8);
		LCD_WR_DATA(x1&0xff);
		LCD_WR_DATA(x2>>8);
		LCD_WR_DATA(x2&0xff);
		
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1>>8);
		LCD_WR_DATA(y1&0xff);
		LCD_WR_DATA(y2>>8);
		LCD_WR_DATA(y2&0xff);
		
		
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1>>8);
		LCD_WR_DATA(x1&0xff);
		LCD_WR_DATA(x2>>8);
		LCD_WR_DATA(x2&0xff);
		
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1>>8);
		LCD_WR_DATA(y1&0xff);
		LCD_WR_DATA(y2>>8);
		LCD_WR_DATA(y2&0xff);
		
		
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1>>8);
		LCD_WR_DATA(x1&0xff);
		LCD_WR_DATA(x2>>8);
		LCD_WR_DATA(x2&0xff);
		
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1>>8);
		LCD_WR_DATA(y1&0xff);
		LCD_WR_DATA(y2>>8);
		LCD_WR_DATA(y2&0xff);
		
		
		LCD_WR_REG(0x2c);//储存器写
	}
	else
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1>>8);
		LCD_WR_DATA(x1&0xff);
		LCD_WR_DATA(x2>>8);
		LCD_WR_DATA(x2&0xff);
		
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1>>8);
		LCD_WR_DATA(y1&0xff);
		LCD_WR_DATA(y2>>8);
		LCD_WR_DATA(y2&0xff);
		
		
		LCD_WR_REG(0x2c);//储存器写
	}
}




//初始化lcd
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
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
								color       要填充的颜色
      返回值：  无
***********************************************************************7*******/
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{          
	u16 i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			LCD_WriteRAM(color);
		}
	} 					  	    
}


//在指定区域内填充指定颜色块
//(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)
//color:要填充的颜色
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color)
{  
	u16 height,width;
	u16 i,j; 
	width=ex-sx+1; 			//得到填充的宽度
	height=ey-sy+1;			//高度
	for(i=0;i<height;i++)
	{
		LCD_SetCursor(sx,sy+i);   	//设置光标位置 
        for (j = 0; j < width; j++)
        {
			LCD_WriteRAM(color[i * width + j]); //写入数据
        }
    }
}



/*	复位LCD屏幕	*/
void LCD_RES(void)
{
	HAL_GPIO_WritePin(LCD_RES_GPIO_Port,LCD_RES_Pin,GPIO_PIN_RESET);
	delay_ms(100);
	HAL_GPIO_WritePin(LCD_RES_GPIO_Port,LCD_RES_Pin,GPIO_PIN_SET);
	delay_ms(100);
}

/*	打开背光	*/
void LCD_BL_ON(void)
{
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port,LCD_BL_Pin,GPIO_PIN_SET);
	delay_ms(100);
}

/*	关闭背光	*/
void LCD_BL_OFF(void)
{
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port,LCD_BL_Pin,GPIO_PIN_RESET);
	delay_ms(100);
}
