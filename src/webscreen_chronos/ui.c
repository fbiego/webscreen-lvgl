/**
 * @file ui.c
 */

/*********************
 *      INCLUDES
 *********************/
#include "ui.h"

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

void ui_init(const char * asset_path)
{
    LV_LOG_USER("ui_init()\n");
    webscreen_chronos_init(asset_path);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/