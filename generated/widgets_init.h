/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef WIDGET_INIT_H
#define WIDGET_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "gui_guider.h"

__attribute__((unused)) void kb_event_cb(lv_event_t *e);
__attribute__((unused)) void ta_event_cb(lv_event_t *e);
#if LV_USE_ANALOGCLOCK != 0
void clock_count(int *hour, int *min, int *sec);
void digital_clock_count(int * hour, int * minute, int * seconds, char * meridiem);
#endif


void screen_digital_clock_timer(lv_timer_t *timer);extern lv_obj_t * screen_spinbox_protocol_edit_trig;
void lv_screen_spinbox_protocol_edit_trig_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_trig_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_yaw;
void lv_screen_spinbox_protocol_edit_yaw_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_yaw_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_slt1_yaw;
void lv_screen_spinbox_protocol_edit_slt1_yaw_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_slt1_yaw_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_slt2_yaw;
void lv_screen_spinbox_protocol_edit_slt2_yaw_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_slt2_yaw_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_slt3_yaw;
void lv_screen_spinbox_protocol_edit_slt3_yaw_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_slt3_yaw_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_slt4_yaw;
void lv_screen_spinbox_protocol_edit_slt4_yaw_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_slt4_yaw_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_visual_x;
void lv_screen_spinbox_protocol_edit_visual_x_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_visual_x_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_slt1_trig;
void lv_screen_spinbox_protocol_edit_slt1_trig_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_slt1_trig_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_slt2_trig;
void lv_screen_spinbox_protocol_edit_slt2_trig_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_slt2_trig_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_slt3_trig;
void lv_screen_spinbox_protocol_edit_slt3_trig_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_slt3_trig_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_slt4_trig;
void lv_screen_spinbox_protocol_edit_slt4_trig_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_slt4_trig_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_protocol_edit_yaw_visual;
void lv_screen_spinbox_protocol_edit_yaw_visual_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_protocol_edit_yaw_visual_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_vision_exposure;
void lv_screen_spinbox_vision_exposure_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_vision_exposure_decrement_event_cb(lv_event_t * event);
extern lv_obj_t * screen_spinbox_overview_hardware_edit;
void lv_screen_spinbox_overview_hardware_edit_increment_event_cb(lv_event_t * event);
void lv_screen_spinbox_overview_hardware_edit_decrement_event_cb(lv_event_t * event);



#ifdef __cplusplus
}
#endif
#endif
