/**
 * @file navigation_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "navigation_gen.h"
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

lv_obj_t *nav_canvas;

/***********************
 *  STATIC PROTOTYPES
 **********************/
static void icon_color_observer_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * navigation_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dark;
    static lv_style_t style_w300;
    static lv_style_t style_flex_ver;
    static lv_style_t style_canvas;

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
        lv_style_set_text_font(&style_dark, &nn_regular_40);

        lv_style_init(&style_w300);
        lv_style_set_width(&style_w300, 340);
        lv_style_set_height(&style_w300, lv_pct(100));
        lv_style_set_pad_all(&style_w300, 5);

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

        lv_style_init(&style_canvas);
        lv_style_set_width(&style_canvas, 48);
        lv_style_set_height(&style_canvas, 48);
        lv_style_set_bg_color(&style_canvas, lv_color_hex(0xffffff));

        style_inited = true;
    }

    lv_obj_t * lv_obj_1 = lv_obj_create(parent);
        lv_obj_add_style(lv_obj_1, &style_dark, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_2, &style_dark, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_2, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(lv_obj_2, &style_w300, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_TOP_RIGHT);

    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    
    lv_label_bind_text(lv_label_1, &subject_nav_eta, NULL);
    lv_obj_set_width(lv_label_1, lv_pct(100));
    lv_obj_set_style_text_align(lv_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_2);
    
    lv_label_bind_text(lv_label_2, &subject_nav_duration, NULL);
    lv_obj_set_width(lv_label_2, lv_pct(100));
    lv_obj_set_style_text_align(lv_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_2);
    
    lv_label_bind_text(lv_label_3, &subject_nav_directions, NULL);
    lv_obj_set_width(lv_label_3, lv_pct(100));
    lv_obj_set_style_text_align(lv_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(lv_label_3, &nn_regular_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_3, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_obj_3, 166);
    lv_obj_set_height(lv_obj_3, 170);
    lv_obj_set_style_flex_main_place(lv_obj_3, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);

    LV_DRAW_BUF_DEFINE_STATIC(cbuf, 48, 48, LV_COLOR_FORMAT_I2);
    LV_DRAW_BUF_INIT_STATIC(cbuf);

    nav_canvas = lv_canvas_create(lv_obj_3);
    lv_obj_remove_style_all(nav_canvas);
    lv_canvas_set_draw_buf(nav_canvas, &cbuf);
    lv_obj_set_width(nav_canvas, 48);
    lv_obj_set_height(nav_canvas, 48);
    lv_obj_set_style_bg_color(nav_canvas, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(nav_canvas, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(nav_canvas, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_canvas_fill_bg(nav_canvas, lv_color_black(), LV_OPA_COVER);
    lv_canvas_set_palette(nav_canvas, 0, lv_color32_make(0, 0, 0, 255));
    lv_canvas_set_palette(nav_canvas, 1, lv_color32_make(255, 255, 255, 255));
    lv_obj_add_flag(nav_canvas, LV_OBJ_FLAG_HIDDEN);

    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_3);
    
    lv_label_bind_text(lv_label_4, &subject_nav_title, NULL);
    lv_obj_set_style_text_font(lv_label_4, &nn_bold_50, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_3);
    
    lv_label_bind_text(lv_label_5, &subject_nav_speed, NULL);
    lv_obj_set_style_text_font(lv_label_5, &nn_regular_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_4, &style_flex_ver, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_obj_4, 166);
    lv_obj_set_height(lv_obj_4, 40);
    lv_obj_set_align(lv_obj_4, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_style_flex_main_place(lv_obj_4, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_4);
    
    lv_label_bind_text(lv_label_6, &subject_sys_time, NULL);
    lv_obj_set_style_text_font(lv_label_6, &nn_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_1);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_2);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_3);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_4);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_5);
    lv_subject_add_observer(&subject_text_color, text_color_observer_cb, lv_label_6);

    lv_subject_add_observer(&subject_border_color, border_color_observer_cb, lv_obj_2);
    lv_subject_add_observer(&subject_border_color, border_color_observer_cb, lv_obj_3);
    lv_subject_add_observer(&subject_border_color, border_color_observer_cb, lv_obj_4);

    lv_subject_add_observer(&subject_text_color, icon_color_observer_cb, nav_canvas);


    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_1;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void icon_color_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    lv_obj_t * canvas = (lv_obj_t *)lv_observer_get_user_data(observer);
    lv_color_t color = lv_subject_get_color(subject);
    lv_canvas_set_palette(canvas, 1, lv_color_to_32(color, 255));
}