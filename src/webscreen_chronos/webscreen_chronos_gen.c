/**
 * @file webscreen_chronos_gen.c
 */

/*********************
 *      INCLUDES
 *********************/
#include "webscreen_chronos_gen.h"

#if LV_USE_XML
#endif

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
 *  GLOBAL VARIABLES
 **********************/

/* Global Styles */

/* Fonts */
// // lv_font_t * neon_100;
// // lv_font_t * sony_50;
// // lv_font_t * nn_regular_24;
// // lv_font_t * nn_bold_24;
// // lv_font_t * nn_regular_30;
// // lv_font_t * nn_regular_40;
// // lv_font_t * nn_bold_30;
// // lv_font_t * nn_bold_50;

/* Images */

/*Subjects*/
lv_subject_t subject_hour;
lv_subject_t subject_minute;
lv_subject_t subject_sys_time;
lv_subject_t subject_sys_date;
lv_subject_t subject_temp;
lv_subject_t subject_city;
lv_subject_t subject_battery;
lv_subject_t subject_connected;
lv_subject_t subject_navigate;
lv_subject_t subject_notification;
lv_subject_t subject_alert;
lv_subject_t subject_notif_title;
lv_subject_t subject_notif_message;
lv_subject_t subject_notif_time;
lv_subject_t subject_nav_title;
lv_subject_t subject_nav_duration;
lv_subject_t subject_nav_eta;
lv_subject_t subject_nav_directions;
lv_subject_t subject_nav_speed;

lv_subject_t subject_text_color;
lv_subject_t subject_border_color;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void webscreen_chronos_init_gen(const char * asset_path)
{
    char buf[256];

    /* Global Styles */

    /* Subjects */
    lv_subject_init_int(&subject_hour, 13);
    lv_subject_init_int(&subject_minute, 5);
    static char subject_sys_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_sys_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_sys_time,
                            subject_sys_time_buf,
                            subject_sys_time_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "13:05"
                          );
    static char subject_sys_date_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_sys_date_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_sys_date,
                            subject_sys_date_buf,
                            subject_sys_date_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "Sun 15 Jun"
                          );
    lv_subject_init_int(&subject_temp, 15);
    static char subject_city_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_city_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_city,
                            subject_city_buf,
                            subject_city_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "Nairobi"
                          );
    lv_subject_init_int(&subject_battery, 75);
    lv_subject_init_int(&subject_connected, 1);
    lv_subject_init_int(&subject_navigate, 0);
    lv_subject_init_int(&subject_notification, 0);
    lv_subject_init_int(&subject_alert, 0);
    static char subject_notif_title_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_notif_title_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_notif_title,
                            subject_notif_title_buf,
                            subject_notif_title_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "Notification"
                          );
    static char subject_notif_message_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_notif_message_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_notif_message,
                            subject_notif_message_buf,
                            subject_notif_message_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "This is a notification"
                          );
    static char subject_notif_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_notif_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_notif_time,
                            subject_notif_time_buf,
                            subject_notif_time_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "13:45"
                          );
    static char subject_nav_title_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_nav_title_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_nav_title,
                            subject_nav_title_buf,
                            subject_nav_title_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "410m"
                          );
    static char subject_nav_duration_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_nav_duration_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_nav_duration,
                            subject_nav_duration_buf,
                            subject_nav_duration_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "2min 850m"
                          );
    static char subject_nav_eta_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_nav_eta_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_nav_eta,
                            subject_nav_eta_buf,
                            subject_nav_eta_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "18:03 ETA"
                          );
    static char subject_nav_directions_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_nav_directions_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_nav_directions,
                            subject_nav_directions_buf,
                            subject_nav_directions_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "Turn right towards Moi Avenue"
                          );
    static char subject_nav_speed_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_nav_speed_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_nav_speed,
                            subject_nav_speed_buf,
                            subject_nav_speed_prev_buf,
                            UI_SUBJECT_STRING_LENGTH,
                            "4 km/h"
                          );

    lv_subject_init_color(&subject_text_color, lv_color_hex(0xffffff));
    lv_subject_init_color(&subject_border_color, lv_color_hex(0xffffff));

    /* Fonts */
    /* create tiny ttf font "neon_100" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/Neoneon.otf");
	// 	// neon_100 = lv_tiny_ttf_create_file(buf, 100);
    /* create tiny ttf font "sony_50" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/Sony_Sketch_EF.ttf");
	// 	// sony_50 = lv_tiny_ttf_create_file(buf, 50);
    /* create tiny ttf font "nn_regular_24" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Regular.ttf");
	// 	// nn_regular_24 = lv_tiny_ttf_create_file(buf, 24);
    /* create tiny ttf font "nn_bold_24" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Bold.ttf");
	// 	// nn_bold_24 = lv_tiny_ttf_create_file(buf, 24);
    /* create tiny ttf font "nn_regular_30" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Regular.ttf");
	// 	// nn_regular_30 = lv_tiny_ttf_create_file(buf, 30);
    /* create tiny ttf font "nn_regular_40" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Regular.ttf");
	// 	// nn_regular_40 = lv_tiny_ttf_create_file(buf, 40);
    /* create tiny ttf font "nn_bold_30" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Bold.ttf");
	// 	// nn_bold_30 = lv_tiny_ttf_create_file(buf, 30);
    /* create tiny ttf font "nn_bold_50" from file */
	// 	// lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/NunitoSans_10pt_Bold.ttf");
	// 	// nn_bold_50 = lv_tiny_ttf_create_file(buf, 50);

    /* Images */

    #if LV_USE_XML

        lv_xml_register_font(NULL, "neon_100", neon_100);
        lv_xml_register_font(NULL, "sony_50", sony_50);
        lv_xml_register_font(NULL, "nn_regular_24", nn_regular_24);
        lv_xml_register_font(NULL, "nn_bold_24", nn_bold_24);
        lv_xml_register_font(NULL, "nn_regular_30", nn_regular_30);
        lv_xml_register_font(NULL, "nn_regular_40", nn_regular_40);
        lv_xml_register_font(NULL, "nn_bold_30", nn_bold_30);
        lv_xml_register_font(NULL, "nn_bold_50", nn_bold_50);


        lv_xml_register_subject(NULL, "hour", &subject_hour);
        lv_xml_register_subject(NULL, "minute", &subject_minute);
        lv_xml_register_subject(NULL, "sys_time", &subject_sys_time);
        lv_xml_register_subject(NULL, "sys_date", &subject_sys_date);
        lv_xml_register_subject(NULL, "temp", &subject_temp);
        lv_xml_register_subject(NULL, "city", &subject_city);
        lv_xml_register_subject(NULL, "battery", &subject_battery);
        lv_xml_register_subject(NULL, "connected", &subject_connected);
        lv_xml_register_subject(NULL, "navigate", &subject_navigate);
        lv_xml_register_subject(NULL, "notification", &subject_notification);
        lv_xml_register_subject(NULL, "alert", &subject_alert);
        lv_xml_register_subject(NULL, "notif_title", &subject_notif_title);
        lv_xml_register_subject(NULL, "notif_message", &subject_notif_message);
        lv_xml_register_subject(NULL, "notif_time", &subject_notif_time);
        lv_xml_register_subject(NULL, "nav_title", &subject_nav_title);
        lv_xml_register_subject(NULL, "nav_duration", &subject_nav_duration);
        lv_xml_register_subject(NULL, "nav_eta", &subject_nav_eta);
        lv_xml_register_subject(NULL, "nav_directions", &subject_nav_directions);
        lv_xml_register_subject(NULL, "nav_speed", &subject_nav_speed);

    #endif
}

/* callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/
