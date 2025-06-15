/**
 * @file notification_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "notification_gen.h"
#include "../ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * notification_create(lv_obj_t * parent, lv_subject_t * title, lv_subject_t * message, lv_subject_t * time)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dark;
    static lv_style_t style_w400;
    static lv_style_t style_flex_ver;

    static bool style_inited = false;

    if (!style_inited) {
        
        lv_style_init(&style_dark);
        lv_style_set_width(&style_dark, lv_pct(100));
        lv_style_set_height(&style_dark, lv_pct(100));
        lv_style_set_bg_color(&style_dark, lv_color_hex(0x000000));
        lv_style_set_border_width(&style_dark, 0);
        lv_style_set_radius(&style_dark, 0);
        lv_style_set_pad_all(&style_dark, 0);
        lv_style_set_text_color(&style_dark, lv_color_hex(0xffffff));
        lv_style_set_text_font(&style_dark, &nn_regular_30);

        lv_style_init(&style_w400);
        lv_style_set_width(&style_w400, 375);
        lv_style_set_height(&style_w400, lv_pct(100));
        lv_style_set_pad_all(&style_w400, 10);

        lv_style_init(&style_flex_ver);
        lv_style_set_bg_color(&style_flex_ver, lv_color_hex(0x000000));
        lv_style_set_border_width(&style_flex_ver, 1);
        lv_style_set_radius(&style_flex_ver, 10);
        lv_style_set_layout(&style_flex_ver, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_flex_ver, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_track_place(&style_flex_ver, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_main_place(&style_flex_ver, LV_FLEX_ALIGN_START);
        lv_style_set_flex_cross_place(&style_flex_ver, LV_FLEX_ALIGN_CENTER);
        lv_style_set_text_color(&style_flex_ver, lv_color_hex(0xffffff));
        lv_style_set_text_font(&style_flex_ver, &nn_regular_30);
        lv_style_set_pad_all(&style_flex_ver, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_1 = lv_obj_create(parent);
        lv_obj_add_style(lv_obj_1, &style_dark, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_2, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_flex_main_place(lv_obj_2, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    
    lv_label_bind_text(lv_label_1, time, NULL);
    lv_obj_set_align(lv_label_1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_width(lv_label_1, lv_pct(100));
    lv_obj_set_style_text_align(lv_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_3, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_height(lv_obj_3, 40);
    lv_obj_set_align(lv_obj_3, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_style_flex_main_place(lv_obj_3, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_3);
    
    lv_label_bind_text(lv_label_2, &subject_sys_time, NULL);
    lv_obj_set_style_text_font(lv_label_2, &nn_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_4, &style_dark, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_4, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_4, &style_w400, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(lv_obj_4, LV_ALIGN_TOP_RIGHT);

    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_4);
    
    lv_label_bind_text(lv_label_3, title, NULL);
    lv_obj_set_style_text_font(lv_label_3, &nn_bold_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_label_3, lv_pct(100));

    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_4);
    
    lv_label_bind_text(lv_label_4, message, NULL);
    lv_obj_set_width(lv_label_4, lv_pct(100));

    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_1);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_2);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_3);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_4);

    lv_subject_add_observer(&subject_border_color, border_color_observer_cb, lv_obj_2);
    lv_subject_add_observer(&subject_border_color, border_color_observer_cb, lv_obj_3);
    lv_subject_add_observer(&subject_border_color, border_color_observer_cb, lv_obj_4);


    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_1;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/