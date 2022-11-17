#include "gui.h"
#include "lvgl.h"
#include "ads131A04.h"


//adc_value_struct adc_value;


lv_obj_t *parent1;

lv_obj_t *parent2;

lv_obj_t *parent3;

lv_obj_t *parent4;



lv_obj_t *adc_label_1;
lv_obj_t *adc_label_2;
lv_obj_t *adc_label_3;
lv_obj_t *adc_label_4;





void parent1_init(void)
{
    parent1 = lv_obj_create(lv_scr_act());  //设置父类
    lv_obj_set_size(parent1,140,90);    //设置大小
    lv_obj_set_style_bg_color(parent1,lv_color_make(0xf0,0x80,0x80),0); //设置颜色F08080
    lv_obj_align(parent1,LV_ALIGN_TOP_LEFT,10,30);  //设置位置
}

void parent2_init(void)
{
    parent2 = lv_obj_create(lv_scr_act());  //设置父类
    lv_obj_set_size(parent2,140,90);    //设置大小
    lv_obj_set_style_bg_color(parent2,lv_color_make(0x54,0xff,0x9f),0); //设置颜色54FF9F
    lv_obj_align(parent2,LV_ALIGN_TOP_RIGHT,-10,30);  //设置位置
}

void parent3_init(void)
{
    parent3 = lv_obj_create(lv_scr_act());  //设置父类
    lv_obj_set_size(parent3,140,90);    //设置大小
    lv_obj_set_style_bg_color(parent3,lv_color_make(0xff,0xec,0x8b),0); //设置颜色FFEC8B
    lv_obj_align(parent3,LV_ALIGN_BOTTOM_LEFT,10,-10);  //设置位置
}

void parent4_init(void)
{
    parent4 = lv_obj_create(lv_scr_act());  //设置父类
    lv_obj_set_size(parent4,140,90);    //设置大小
    lv_obj_set_style_bg_color(parent4,lv_color_make(0xff,0xa5,0x00),0); //设置颜色FFA500
    lv_obj_align(parent4,LV_ALIGN_BOTTOM_RIGHT,-10,-10);  //设置位置
}

void label1_init(void)
{
    adc_label_1 = lv_label_create(parent1);
    lv_obj_set_style_text_align(adc_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_style_text_font(adc_label_1,&lv_font_montserrat_12,LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(adc_label_1, lv_color_make(0xff,0xff,0xff), LV_PART_MAIN);
    lv_label_set_text_fmt(adc_label_1,"Voltage: %f V",ads131_value.ADC1_Value);
}

void label2_init(void)
{
    adc_label_2 = lv_label_create(parent2);
    lv_obj_set_style_text_align(adc_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_style_text_font(adc_label_2,&lv_font_montserrat_12,LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(adc_label_2, lv_color_make(0xff,0xff,0xff), LV_PART_MAIN);
    lv_label_set_text_fmt(adc_label_2,"Voltage: %f V",ads131_value.ADC2_Value);
}


void label3_init(void)
{
    adc_label_3 = lv_label_create(parent3);
    lv_obj_set_style_text_align(adc_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_style_text_font(adc_label_3,&lv_font_montserrat_12,LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(adc_label_3, lv_color_make(0xff,0xff,0xff), LV_PART_MAIN);
    lv_label_set_text_fmt(adc_label_3,"Voltage: %f V",ads131_value.ADC3_Value);
}

void label4_init(void)
{
    adc_label_4 = lv_label_create(parent4);
    lv_obj_set_style_text_align(adc_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_style_text_font(adc_label_4,&lv_font_montserrat_12,LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(adc_label_4, lv_color_make(0xff,0xff,0xff), LV_PART_MAIN);
    lv_label_set_text_fmt(adc_label_4,"Voltage: %f V",ads131_value.ADC4_Value);
}




void lv_gui(void)
{
    parent1_init();
    parent2_init();
    parent3_init();
    parent4_init();
    label1_init();
		label2_init();
		label3_init();
		label4_init();
	
}
