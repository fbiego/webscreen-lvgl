/**
 * @file webscreen_chronos_gen.h
 */

#ifndef WEBSCREEN_CHRONOS_GEN_H
#define WEBSCREEN_CHRONOS_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl.h"

/*Include all the widget and components of this library*/
#include "components/navigation_gen.h"
#include "components/notification_gen.h"
#include "screens/main_gen.h"

/*********************
 *      DEFINES
 *********************/

// TODO: should these definitions be prefixed with the project name?


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/* Global Styles */

/* Fonts */
LV_FONT_DECLARE(neon_100);
LV_FONT_DECLARE(sony_50);
LV_FONT_DECLARE(nn_regular_24);
LV_FONT_DECLARE(nn_bold_24);
LV_FONT_DECLARE(nn_regular_30);
LV_FONT_DECLARE(nn_regular_40);
LV_FONT_DECLARE(nn_bold_30);
LV_FONT_DECLARE(nn_bold_50);

/* Images */

/* Subjects */
extern lv_subject_t subject_hour;
extern lv_subject_t subject_minute;
extern lv_subject_t subject_sys_time;
extern lv_subject_t subject_sys_date;
extern lv_subject_t subject_temp;
extern lv_subject_t subject_city;
extern lv_subject_t subject_battery;
extern lv_subject_t subject_connected;
extern lv_subject_t subject_navigate;
extern lv_subject_t subject_notification;
extern lv_subject_t subject_alert;
extern lv_subject_t subject_notif_title;
extern lv_subject_t subject_notif_message;
extern lv_subject_t subject_notif_time;
extern lv_subject_t subject_nav_title;
extern lv_subject_t subject_nav_duration;
extern lv_subject_t subject_nav_eta;
extern lv_subject_t subject_nav_directions;
extern lv_subject_t subject_nav_speed;

extern lv_subject_t subject_text_color;
extern lv_subject_t subject_border_color;

extern lv_obj_t *nav_canvas;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/* callbacks */

/**
 * Initialize the component library
 */

void webscreen_chronos_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WEBSCREEN_CHRONOS_GEN_H*/
