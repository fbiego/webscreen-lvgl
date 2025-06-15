/**
 * @file webscreen_chronos.c
 */

/*********************
 *      INCLUDES
 *********************/
#include "webscreen_chronos.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void webscreen_chronos_init(const char * asset_path)
{
    webscreen_chronos_init_gen(asset_path);
}

void text_color_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    lv_obj_t * obj = (lv_obj_t *)lv_observer_get_user_data(observer);
    lv_color_t color = lv_subject_get_color(subject);
    lv_obj_set_style_text_color(obj, color, 0);
}

void border_color_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    lv_obj_t * obj = (lv_obj_t *)lv_observer_get_user_data(observer);
    lv_color_t color = lv_subject_get_color(subject);
    lv_obj_set_style_border_color(obj, color, 0);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/