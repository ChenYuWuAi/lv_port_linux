/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_img_background;
	lv_obj_t *screen_label_title;
	lv_obj_t *screen_imgbtn_system_settings;
	lv_obj_t *screen_imgbtn_system_settings_label;
	lv_obj_t *screen_img_rm;
	lv_obj_t *screen_digital_clock;
	lv_obj_t *screen_label_system_state;
	lv_obj_t *screen_tabview;
	lv_obj_t *screen_tabview_tab_1;
	lv_obj_t *screen_tabview_tab_2;
	lv_obj_t *screen_tabview_tab_3;
	lv_obj_t *screen_cont_overview;
	lv_obj_t *screen_label_5;
	lv_obj_t *screen_label_4;
	lv_obj_t *screen_label_6;
	lv_obj_t *screen_label_overview;
	lv_obj_t *screen_line_1;
	lv_obj_t *screen_label_7;
	lv_obj_t *screen_label_8;
	lv_obj_t *screen_label_9;
	lv_obj_t *screen_label_overview_yaw;
	lv_obj_t *screen_label__overview_pitch;
	lv_obj_t *screen_label_overview_trigger;
	lv_obj_t *screen_label_overview_guide_target;
	lv_obj_t *screen_label_overview_flysys_state;
	lv_obj_t *screen_label_16;
	lv_obj_t *screen_label_overview_process;
	lv_obj_t *screen_label_47;
	lv_obj_t *screen_label_overview_rm_info;
	lv_obj_t *screen_label_49;
	lv_obj_t *screen_label_overview_gate_info;
	lv_obj_t *screen_ddlist_overview_protocol;
	lv_obj_t *screen_imgbtn_overview_edit_target_yaw;
	lv_obj_t *screen_imgbtn_overview_edit_target_yaw_label;
	lv_obj_t *screen_imgbtn_overview_edit_pitch;
	lv_obj_t *screen_imgbtn_overview_edit_pitch_label;
	lv_obj_t *screen_imgbtn_overview_edit_trigger;
	lv_obj_t *screen_imgbtn_overview_edit_trigger_label;
	lv_obj_t *screen_imgbtn_overview_edit_target;
	lv_obj_t *screen_imgbtn_overview_edit_target_label;
	lv_obj_t *screen_cont_launch_history;
	lv_obj_t *screen_label_launch_history;
	lv_obj_t *screen_line_2;
	lv_obj_t *screen_table_launch_history;
	lv_obj_t *screen_imgbtn_launch_history_clear;
	lv_obj_t *screen_imgbtn_launch_history_clear_label;
	lv_obj_t *screen_cont_shortcut;
	lv_obj_t *screen_imgbtn_shortcut_service_restart;
	lv_obj_t *screen_imgbtn_shortcut_service_restart_label;
	lv_obj_t *screen_label_32;
	lv_obj_t *screen_label_33;
	lv_obj_t *screen_imgbtn_shortcut_protocol_reload;
	lv_obj_t *screen_imgbtn_shortcut_protocol_reload_label;
	lv_obj_t *screen_label_34;
	lv_obj_t *screen_imgbtn_shortcut_guidelight;
	lv_obj_t *screen_imgbtn_shortcut_guidelight_label;
	lv_obj_t *screen_cont_flysys_info;
	lv_obj_t *screen_label_flysys_info;
	lv_obj_t *screen_line_4;
	lv_obj_t *screen_table_flysys_info;
	lv_obj_t *screen_cont_protocol_edit;
	lv_obj_t *screen_label_68;
	lv_obj_t *screen_label_66;
	lv_obj_t *screen_line_5;
	lv_obj_t *screen_ddlist_protocol_edit;
	lv_obj_t *screen_imgbtn_protocol_edit_drop;
	lv_obj_t *screen_imgbtn_protocol_edit_drop_label;
	lv_obj_t *screen_btn_protocol_edit_rename;
	lv_obj_t *screen_btn_protocol_edit_rename_label;
	lv_obj_t *screen_btn_protocol_edit_new;
	lv_obj_t *screen_btn_protocol_edit_new_label;
	lv_obj_t *screen_cb_protocol_edit_trig;
	lv_obj_t *screen_cb_protocol_edit_yaw;
	lv_obj_t *screen_cb_protocol_edit_visual_x;
	lv_obj_t *screen_cb_protocol_edit_slt1;
	lv_obj_t *screen_cb_protocol_edit_slt2;
	lv_obj_t *screen_cb_protocol_edit_slt3;
	lv_obj_t *screen_cb_protocol_edit_slt4;
	lv_obj_t *screen_ta_protocol_edit_rename;
	lv_obj_t *screen_btn_protocol_edit_reference;
	lv_obj_t *screen_btn_protocol_edit_reference_label;
	lv_obj_t *screen_cb_protocol_edit_choose_all;
	lv_obj_t *screen_spinbox_protocol_edit_trig;
	lv_obj_t *screen_spinbox_protocol_edit_trig_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_trig_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_yaw;
	lv_obj_t *screen_spinbox_protocol_edit_yaw_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_yaw_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_slt1_yaw;
	lv_obj_t *screen_spinbox_protocol_edit_slt1_yaw_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_slt1_yaw_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_slt2_yaw;
	lv_obj_t *screen_spinbox_protocol_edit_slt2_yaw_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_slt2_yaw_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_slt3_yaw;
	lv_obj_t *screen_spinbox_protocol_edit_slt3_yaw_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_slt3_yaw_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_slt4_yaw;
	lv_obj_t *screen_spinbox_protocol_edit_slt4_yaw_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_slt4_yaw_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_visual_x;
	lv_obj_t *screen_spinbox_protocol_edit_visual_x_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_visual_x_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_slt1_trig;
	lv_obj_t *screen_spinbox_protocol_edit_slt1_trig_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_slt1_trig_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_slt2_trig;
	lv_obj_t *screen_spinbox_protocol_edit_slt2_trig_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_slt2_trig_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_slt3_trig;
	lv_obj_t *screen_spinbox_protocol_edit_slt3_trig_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_slt3_trig_btn_minus;
	lv_obj_t *screen_spinbox_protocol_edit_slt4_trig;
	lv_obj_t *screen_spinbox_protocol_edit_slt4_trig_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_slt4_trig_btn_minus;
	lv_obj_t *screen_ddlist_protocol_edit_ref_source;
	lv_obj_t *screen_imgbtn_protocol_edit_slot1;
	lv_obj_t *screen_imgbtn_protocol_edit_slot1_label;
	lv_obj_t *screen_imgbtn_protocol_edit_slot2;
	lv_obj_t *screen_imgbtn_protocol_edit_slot2_label;
	lv_obj_t *screen_imgbtn_protocol_edit_slot4;
	lv_obj_t *screen_imgbtn_protocol_edit_slot4_label;
	lv_obj_t *screen_imgbtn_protocol_edit_slot3;
	lv_obj_t *screen_imgbtn_protocol_edit_slot3_label;
	lv_obj_t *screen_label_90;
	lv_obj_t *screen_label_91;
	lv_obj_t *screen_line_8;
	lv_obj_t *screen_label_95;
	lv_obj_t *screen_sw_protocol_edit_visual;
	lv_obj_t *screen_spinbox_protocol_edit_yaw_visual;
	lv_obj_t *screen_spinbox_protocol_edit_yaw_visual_btn_plus;
	lv_obj_t *screen_spinbox_protocol_edit_yaw_visual_btn_minus;
	lv_obj_t *screen_btn_protocol_edit_del;
	lv_obj_t *screen_btn_protocol_edit_del_label;
	lv_obj_t *screen_cont_protocol_slot;
	lv_obj_t *screen_label_88;
	lv_obj_t *screen_label_protocol_slot;
	lv_obj_t *screen_line_7;
	lv_obj_t *screen_sw_protocol_slot_guided_dart;
	lv_obj_t *screen_btn_protocol_slot_save;
	lv_obj_t *screen_btn_protocol_slot_save_label;
	lv_obj_t *screen_ta_protocol_slot_dart_id;
	lv_obj_t *screen_label_89;
	lv_obj_t *screen_sw_protocol_slot_id_first;
	lv_obj_t *screen_label_92;
	lv_obj_t *screen_cont_protocol_save;
	lv_obj_t *screen_label_protocol_save;
	lv_obj_t *screen_imgbtn_protocol_save;
	lv_obj_t *screen_imgbtn_protocol_save_label;
	lv_obj_t *screen_canvas_camera;
	lv_obj_t *screen_cont_vision;
	lv_obj_t *screen_label_108;
	lv_obj_t *screen_label_107;
	lv_obj_t *screen_imgbtn_vision_exposure_reset;
	lv_obj_t *screen_imgbtn_vision_exposure_reset_label;
	lv_obj_t *screen_line_10;
	lv_obj_t *screen_spinbox_vision_exposure;
	lv_obj_t *screen_spinbox_vision_exposure_btn_plus;
	lv_obj_t *screen_spinbox_vision_exposure_btn_minus;
	lv_obj_t *screen_label_110;
	lv_obj_t *screen_label_vision_target;
	lv_obj_t *screen_imgbtn_vision_target_edit;
	lv_obj_t *screen_imgbtn_vision_target_edit_label;
	lv_obj_t *screen_cont_banner;
	lv_obj_t *screen_label_banner_title;
	lv_obj_t *screen_line_3;
	lv_obj_t *screen_label_banner_info;
	lv_obj_t *screen_cont_settings;
	lv_obj_t *screen_label_76;
	lv_obj_t *screen_label_73;
	lv_obj_t *screen_line_6;
	lv_obj_t *screen_sw_settings_protocol_generate;
	lv_obj_t *screen_btn_settings_exit;
	lv_obj_t *screen_btn_settings_exit_label;
	lv_obj_t *screen_cont_settings_shortcuts;
	lv_obj_t *screen_imgbtn_settings_shortcuts_reboot;
	lv_obj_t *screen_imgbtn_settings_shortcuts_reboot_label;
	lv_obj_t *screen_label_79;
	lv_obj_t *screen_label_78;
	lv_obj_t *screen_imgbtn_settings_shortcuts_ap;
	lv_obj_t *screen_imgbtn_settings_shortcuts_ap_label;
	lv_obj_t *screen_label_77;
	lv_obj_t *screen_imgbtn_settings_shortcuts_graphic;
	lv_obj_t *screen_imgbtn_settings_shortcuts_graphic_label;
	lv_obj_t *screen_label_80;
	lv_obj_t *screen_label_settings_ip;
	lv_obj_t *screen_cont_notification_1;
	lv_obj_t *screen_label_notification_1;
	lv_obj_t *screen_img_2;
	lv_obj_t *screen_cont_overview_hardware_edit;
	lv_obj_t *screen_label_102;
	lv_obj_t *screen_label_overview_hardware_edit_head;
	lv_obj_t *screen_line_9;
	lv_obj_t *screen_btn_overview_hardware_edit_save;
	lv_obj_t *screen_btn_overview_hardware_edit_save_label;
	lv_obj_t *screen_imgbtn_overview_hardware_edit_rst;
	lv_obj_t *screen_imgbtn_overview_hardware_edit_rst_label;
	lv_obj_t *screen_spinbox_overview_hardware_edit;
	lv_obj_t *screen_spinbox_overview_hardware_edit_btn_plus;
	lv_obj_t *screen_spinbox_overview_hardware_edit_btn_minus;
	lv_obj_t *screen_cb_overview_hardware_edit_ptcl;
	lv_obj_t *screen_btn_overview_hardware_edit_drop;
	lv_obj_t *screen_btn_overview_hardware_edit_drop_label;
	lv_obj_t *screen_cb_overview_hardware_edit_visual;
	lv_obj_t *screen_cont_notification_2;
	lv_obj_t *screen_label_notification_2;
	lv_obj_t *screen_img_3;
	lv_obj_t *g_kb_top_layer;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
LV_IMAGE_DECLARE(_logo_3SE_RGB565_1024x600);
LV_IMAGE_DECLARE(_settings_24dp_F3F3F3_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50);
LV_IMAGE_DECLARE(_settings_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50);
LV_IMAGE_DECLARE(_single_r_RGB565A8_49x41);
LV_IMAGE_DECLARE(_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
LV_IMAGE_DECLARE(_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
LV_IMAGE_DECLARE(_delete_24dp_434343_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
LV_IMAGE_DECLARE(_delete_24dp_78A75A_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
LV_IMAGE_DECLARE(_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_upload_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_upload_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_model_training_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_model_training_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
LV_IMAGE_DECLARE(_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
LV_IMAGE_DECLARE(_rocket_launch_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
LV_IMAGE_DECLARE(_rocket_launch_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
LV_IMAGE_DECLARE(_cell_tower_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_cell_tower_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_desktop_windows_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_desktop_windows_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60);
LV_IMAGE_DECLARE(_info_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
LV_IMAGE_DECLARE(_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50);
LV_IMAGE_DECLARE(_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50);

LV_FONT_DECLARE(lv_font_misans_32)
LV_FONT_DECLARE(lv_font_misans_16)
LV_FONT_DECLARE(lv_font_misans_12)
LV_FONT_DECLARE(lv_font_misans_28)
LV_FONT_DECLARE(lv_font_misans_20)
LV_FONT_DECLARE(lv_font_misans_10)
LV_FONT_DECLARE(lv_font_misans_14)
LV_FONT_DECLARE(lv_font_misans_18)
LV_FONT_DECLARE(lv_font_misans_24)
LV_FONT_DECLARE(lv_font_misans_23)
LV_FONT_DECLARE(lv_font_misans_36)


#ifdef __cplusplus
}
#endif
#endif
