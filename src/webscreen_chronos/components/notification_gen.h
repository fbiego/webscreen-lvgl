/**
 * @file notification_gen.h
 */

#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * notification_create(lv_obj_t * parent, lv_subject_t * title, lv_subject_t * message, lv_subject_t * time);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*NOTIFICATION_H*/