/**
 * @file main_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "main_gen.h"
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

lv_obj_t * main_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dark;
    static lv_style_t style_alert;
    static lv_style_t style_alert_big;
    static lv_style_t style_flex_ver;
    static lv_style_t style_w300;

    static bool style_inited = false;

    if(!style_inited) {
        
        lv_style_init(&style_dark);
        lv_style_set_width(&style_dark, lv_pct(100));
        lv_style_set_height(&style_dark, lv_pct(100));
        lv_style_set_bg_color(&style_dark, lv_color_hex(0x000000));
        lv_style_set_border_width(&style_dark, 0);
        lv_style_set_radius(&style_dark, 0);
        lv_style_set_pad_all(&style_dark, 10);
        lv_style_set_text_color(&style_dark, lv_color_hex(0xffffff));

        lv_style_init(&style_alert);
        lv_style_set_width(&style_alert, 100);
        lv_style_set_height(&style_alert, 100);
        lv_style_set_bg_opa(&style_alert, 0);
        lv_style_set_radius(&style_alert, 50);
        lv_style_set_border_width(&style_alert, 5);
        lv_style_set_shadow_color(&style_alert, lv_color_hex(0xffffff));
        lv_style_set_shadow_width(&style_alert, 50);
        lv_style_set_shadow_spread(&style_alert, 5);
        lv_style_set_shadow_opa(&style_alert, 128);

        lv_style_init(&style_alert_big);
        lv_style_set_width(&style_alert_big, lv_pct(100));
        lv_style_set_height(&style_alert_big, lv_pct(100));
        lv_style_set_bg_opa(&style_alert_big, 0);
        lv_style_set_radius(&style_alert_big, 10);
        lv_style_set_border_width(&style_alert_big, 1);
        lv_style_set_shadow_color(&style_alert_big, lv_color_hex(0xffffff));
        lv_style_set_shadow_width(&style_alert_big, 50);
        lv_style_set_shadow_spread(&style_alert_big, 5);
        lv_style_set_shadow_opa(&style_alert_big, 128);

        lv_style_init(&style_flex_ver);
        lv_style_set_bg_color(&style_flex_ver, lv_color_hex(0x000000));
        lv_style_set_border_width(&style_flex_ver, 1);
        lv_style_set_radius(&style_flex_ver, 10);
        lv_style_set_pad_all(&style_flex_ver, 0);
        lv_style_set_text_color(&style_flex_ver, lv_color_hex(0xffffff));
        lv_style_set_text_font(&style_flex_ver, &nn_regular_40);
        lv_style_set_layout(&style_flex_ver, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_flex_ver, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_track_place(&style_flex_ver, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_main_place(&style_flex_ver, LV_FLEX_ALIGN_SPACE_AROUND);
        lv_style_set_flex_cross_place(&style_flex_ver, LV_FLEX_ALIGN_CENTER);

        lv_style_init(&style_w300);
        lv_style_set_width(&style_w300, 340);
        lv_style_set_height(&style_w300, lv_pct(100));

        style_inited = true;
    }

    lv_obj_t * lv_obj_1 = lv_obj_create(NULL);
        lv_obj_add_style(lv_obj_1, &style_dark, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_2, &style_dark, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_2, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_2, &style_w300, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_TOP_RIGHT);

    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    
    lv_label_bind_text(lv_label_1, &subject_sys_time, NULL);
    lv_obj_set_style_text_font(lv_label_1, &neon_100, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_2);
    
    lv_label_bind_text(lv_label_2, &subject_sys_date, NULL);
    lv_obj_set_style_text_font(lv_label_2, &sony_50, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_3, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_obj_3, 166);
    lv_obj_set_height(lv_obj_3, 120);

    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_3);
    
    lv_label_bind_text(lv_label_3, &subject_temp, "%d°C");
    lv_obj_set_style_text_font(lv_label_3, &nn_regular_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_3);
    
    lv_label_bind_text(lv_label_4, &subject_city, NULL);
    lv_obj_set_style_text_font(lv_label_4, &nn_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_4, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_obj_4, 166);
    lv_obj_set_height(lv_obj_4, 90);
    lv_obj_set_align(lv_obj_4, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_style_flex_main_place(lv_obj_4, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_bind_flag_if_eq(lv_obj_4, &subject_connected, LV_OBJ_FLAG_HIDDEN, 0);

    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_4);
    lv_label_set_text(lv_label_5, "Phone");
    lv_obj_set_style_text_font(lv_label_5, &nn_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_4);
    
    lv_label_bind_text(lv_label_6, &subject_battery, "%d%%");
    lv_obj_set_style_text_font(lv_label_6, &nn_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * notification_1 = notification_create(lv_obj_1, &subject_notif_title, &subject_notif_message, &subject_notif_time);
    lv_obj_bind_flag_if_eq(notification_1, &subject_notification, LV_OBJ_FLAG_HIDDEN, 0);

    lv_obj_t * navigation_1 = navigation_create(lv_obj_1);
    lv_obj_bind_flag_if_eq(navigation_1, &subject_navigate, LV_OBJ_FLAG_HIDDEN, 0);

    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_5, &style_alert_big, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_bind_flag_if_eq(lv_obj_5, &subject_alert, LV_OBJ_FLAG_HIDDEN, 0);

    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_1);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_2);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_3);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_4);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_5);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_6);

    lv_subject_add_observer(&subject_border_color, border_color_observer_cb, lv_obj_2);
    lv_subject_add_observer(&subject_border_color, border_color_observer_cb, lv_obj_3);
    lv_subject_add_observer(&subject_border_color, border_color_observer_cb, lv_obj_4);


    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_1;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

