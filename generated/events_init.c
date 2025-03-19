/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "custom.h"

static void screen_imgbtn_system_settings_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (dialog_present_flag == false) {
            lv_obj_remove_flag(guider_ui.screen_cont_settings, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_overview_edit_target_yaw_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (dialog_present_flag == false) {
            lv_obj_remove_flag(guider_ui.screen_cont_overview_hardware_edit, LV_OBJ_FLAG_HIDDEN);
            dialog_present_flag = true;
            lv_label_set_text(guider_ui.screen_label_overview_hardware_edit_head, "快速设置Yaw角度");
        }
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_overview_edit_pitch_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (dialog_present_flag == false) {
            lv_obj_remove_flag(guider_ui.screen_cont_overview_hardware_edit, LV_OBJ_FLAG_HIDDEN);
            dialog_present_flag = true;
            lv_label_set_text(guider_ui.screen_label_overview_hardware_edit_head, "快速设置Pitch角度");
        }
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_overview_edit_trigger_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (dialog_present_flag == false) {
            lv_obj_remove_flag(guider_ui.screen_cont_overview_hardware_edit, LV_OBJ_FLAG_HIDDEN);
            dialog_present_flag = true;
            lv_label_set_text(guider_ui.screen_label_overview_hardware_edit_head, "快速设置扳机角度");
        }
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_overview_edit_target_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (dialog_present_flag == false) {
            lv_obj_remove_flag(guider_ui.screen_cont_overview_hardware_edit, LV_OBJ_FLAG_HIDDEN);
            lv_obj_remove_flag(guider_ui.screen_cb_overview_hardware_edit_visual, LV_OBJ_FLAG_HIDDEN);
            dialog_present_flag = true;
            lv_label_set_text(guider_ui.screen_label_overview_hardware_edit_head, "制导信息设置");
        }
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_protocol_edit_slot1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.screen_cont_protocol_slot, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_protocol_edit_slot2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.screen_cont_protocol_slot, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_protocol_edit_slot4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.screen_cont_protocol_slot, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_protocol_edit_slot3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.screen_cont_protocol_slot, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void screen_btn_protocol_slot_save_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.screen_cont_protocol_slot, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void screen_btn_settings_exit_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.screen_cont_settings, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void screen_btn_overview_hardware_edit_save_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        dialog_present_flag = false;
        lv_obj_add_flag(guider_ui.screen_cont_overview_hardware_edit, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_cb_overview_hardware_edit_visual, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void screen_btn_overview_hardware_edit_drop_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        dialog_present_flag = false;
        lv_obj_add_flag(guider_ui.screen_cont_overview_hardware_edit, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_cb_overview_hardware_edit_visual, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

void events_init_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_imgbtn_system_settings, screen_imgbtn_system_settings_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_overview_edit_target_yaw, screen_imgbtn_overview_edit_target_yaw_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_overview_edit_pitch, screen_imgbtn_overview_edit_pitch_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_overview_edit_trigger, screen_imgbtn_overview_edit_trigger_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_overview_edit_target, screen_imgbtn_overview_edit_target_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_protocol_edit_slot1, screen_imgbtn_protocol_edit_slot1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_protocol_edit_slot2, screen_imgbtn_protocol_edit_slot2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_protocol_edit_slot4, screen_imgbtn_protocol_edit_slot4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_protocol_edit_slot3, screen_imgbtn_protocol_edit_slot3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_protocol_slot_save, screen_btn_protocol_slot_save_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_settings_exit, screen_btn_settings_exit_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_overview_hardware_edit_save, screen_btn_overview_hardware_edit_save_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_overview_hardware_edit_drop, screen_btn_overview_hardware_edit_drop_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
