// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: ADC

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
void ui_event_Panel1(lv_event_t * e);
lv_obj_t * ui_Panel1;
void ui_event_Panel2(lv_event_t * e);
lv_obj_t * ui_Panel2;
void ui_event_Panel3(lv_event_t * e);
lv_obj_t * ui_Panel3;
void ui_event_Panel4(lv_event_t * e);
lv_obj_t * ui_Panel4;
lv_obj_t * ui_ADC1;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Chart2;
lv_obj_t * ui_Switch1;
lv_obj_t * ui_ADC2;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_ADC3;
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
lv_obj_t * ui_ADC4;
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Panel1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ADC1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Panel2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ADC2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Panel3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ADC3, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Panel4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ADC4, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel1, 120);
    lv_obj_set_height(ui_Panel1, 80);
    lv_obj_set_x(ui_Panel1, -70);
    lv_obj_set_y(ui_Panel1, -40);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel2, 120);
    lv_obj_set_height(ui_Panel2, 80);
    lv_obj_set_x(ui_Panel2, 70);
    lv_obj_set_y(ui_Panel2, -40);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel3 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel3, 120);
    lv_obj_set_height(ui_Panel3, 80);
    lv_obj_set_x(ui_Panel3, -70);
    lv_obj_set_y(ui_Panel3, 60);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel4 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel4, 120);
    lv_obj_set_height(ui_Panel4, 80);
    lv_obj_set_x(ui_Panel4, 70);
    lv_obj_set_y(ui_Panel4, 60);
    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Panel1, ui_event_Panel1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel2, ui_event_Panel2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel3, ui_event_Panel3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel4, ui_event_Panel4, LV_EVENT_ALL, NULL);

}
void ui_ADC1_screen_init(void)
{
    ui_ADC1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ADC1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button1 = lv_btn_create(ui_ADC1);
    lv_obj_set_width(ui_Button1, 50);
    lv_obj_set_height(ui_Button1, 25);
    lv_obj_set_x(ui_Button1, -120);
    lv_obj_set_y(ui_Button1, -100);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label3 = lv_label_create(ui_ADC1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, -120);
    lv_obj_set_y(ui_Label3, -100);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "return");

    ui_Chart2 = lv_chart_create(ui_ADC1);
    lv_obj_set_width(ui_Chart2, 316);
    lv_obj_set_height(ui_Chart2, 165);
    lv_obj_set_x(ui_Chart2, 0);
    lv_obj_set_y(ui_Chart2, 36);
    lv_obj_set_align(ui_Chart2, LV_ALIGN_CENTER);

    ui_Switch1 = lv_switch_create(ui_ADC1);
    lv_obj_set_width(ui_Switch1, 50);
    lv_obj_set_height(ui_Switch1, 25);
    lv_obj_set_x(ui_Switch1, 120);
    lv_obj_set_y(ui_Switch1, -100);
    lv_obj_set_align(ui_Switch1, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);

}
void ui_ADC2_screen_init(void)
{
    ui_ADC2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ADC2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button2 = lv_btn_create(ui_ADC2);
    lv_obj_set_width(ui_Button2, 50);
    lv_obj_set_height(ui_Button2, 25);
    lv_obj_set_x(ui_Button2, -120);
    lv_obj_set_y(ui_Button2, -100);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);

}
void ui_ADC3_screen_init(void)
{
    ui_ADC3 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ADC3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button3 = lv_btn_create(ui_ADC3);
    lv_obj_set_width(ui_Button3, 50);
    lv_obj_set_height(ui_Button3, 25);
    lv_obj_set_x(ui_Button3, -120);
    lv_obj_set_y(ui_Button3, -100);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);

}
void ui_ADC4_screen_init(void)
{
    ui_ADC4 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ADC4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button4 = lv_btn_create(ui_ADC4);
    lv_obj_set_width(ui_Button4, 50);
    lv_obj_set_height(ui_Button4, 25);
    lv_obj_set_x(ui_Button4, -120);
    lv_obj_set_y(ui_Button4, -100);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_ADC1_screen_init();
    ui_ADC2_screen_init();
    ui_ADC3_screen_init();
    ui_ADC4_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
