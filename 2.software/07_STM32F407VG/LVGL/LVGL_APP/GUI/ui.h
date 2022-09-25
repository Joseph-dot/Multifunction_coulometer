// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: ADC

#ifndef _ADC_UI_H
#define _ADC_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

extern lv_obj_t * ui_Screen1;
void ui_event_Panel1(lv_event_t * e);
extern lv_obj_t * ui_Panel1;
void ui_event_Panel2(lv_event_t * e);
extern lv_obj_t * ui_Panel2;
void ui_event_Panel3(lv_event_t * e);
extern lv_obj_t * ui_Panel3;
void ui_event_Panel4(lv_event_t * e);
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_ADC1;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Chart2;
extern lv_obj_t * ui_Switch1;
extern lv_obj_t * ui_ADC2;
void ui_event_Button2(lv_event_t * e);
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_ADC3;
void ui_event_Button3(lv_event_t * e);
extern lv_obj_t * ui_Button3;
extern lv_obj_t * ui_ADC4;
void ui_event_Button4(lv_event_t * e);
extern lv_obj_t * ui_Button4;






void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
