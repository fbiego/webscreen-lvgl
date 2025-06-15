/**
 * @file webscreen_chronos.h
 */

#ifndef WEBSCREEN_CHRONOS_H
#define WEBSCREEN_CHRONOS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "webscreen_chronos_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the component library
 */
void webscreen_chronos_init(const char * asset_path);

void text_color_observer_cb(lv_observer_t * observer, lv_subject_t * subject);

void border_color_observer_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WEBSCREEN_CHRONOS_H*/