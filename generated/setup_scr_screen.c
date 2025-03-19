/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



extern int screen_digital_clock_min_value;
extern int screen_digital_clock_hour_value;
extern int screen_digital_clock_sec_value;
void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 1024, 600);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_background
    ui->screen_img_background = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_background, 0, 0);
    lv_obj_set_size(ui->screen_img_background, 1024, 600);
    lv_obj_add_flag(ui->screen_img_background, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_background, &_logo_3SE_RGB565_1024x600);
    lv_image_set_pivot(ui->screen_img_background, 50,50);
    lv_image_set_rotation(ui->screen_img_background, 0);

    //Write style for screen_img_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_background, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_title
    ui->screen_label_title = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_title, 100, 32);
    lv_obj_set_size(ui->screen_label_title, 239, 39);
    lv_label_set_text(ui->screen_label_title, "飞镖发射中控塔");
    lv_label_set_long_mode(ui->screen_label_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_title, lv_color_hex(0xd7d7d7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_title, &lv_font_misans_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_system_settings
    ui->screen_imgbtn_system_settings = lv_imagebutton_create(ui->screen);
    lv_obj_set_pos(ui->screen_imgbtn_system_settings, 919, 23);
    lv_obj_set_size(ui->screen_imgbtn_system_settings, 50, 50);
    lv_obj_add_flag(ui->screen_imgbtn_system_settings, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_system_settings, LV_IMAGEBUTTON_STATE_RELEASED, &_settings_24dp_F3F3F3_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_system_settings, LV_IMAGEBUTTON_STATE_PRESSED, &_settings_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_system_settings, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_settings_24dp_F3F3F3_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_system_settings, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_settings_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50, NULL, NULL);
    ui->screen_imgbtn_system_settings_label = lv_label_create(ui->screen_imgbtn_system_settings);
    lv_label_set_text(ui->screen_imgbtn_system_settings_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_system_settings_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_system_settings_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_system_settings, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_system_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_system_settings, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_system_settings, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_system_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_system_settings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_system_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_system_settings, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_system_settings, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_system_settings, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_system_settings, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_system_settings, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_system_settings, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_system_settings, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_system_settings, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_system_settings, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_system_settings, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_system_settings, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_system_settings, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_system_settings, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_system_settings, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_system_settings, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_system_settings, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_system_settings, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_img_rm
    ui->screen_img_rm = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_rm, 35, 29);
    lv_obj_set_size(ui->screen_img_rm, 49, 41);
    lv_obj_add_flag(ui->screen_img_rm, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_rm, &_single_r_RGB565A8_49x41);
    lv_image_set_pivot(ui->screen_img_rm, 50,50);
    lv_image_set_rotation(ui->screen_img_rm, 0);

    //Write style for screen_img_rm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_rm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_rm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_digital_clock
    static bool screen_digital_clock_timer_enabled = false;
    ui->screen_digital_clock = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_digital_clock, 785, 29);
    lv_obj_set_size(ui->screen_digital_clock, 129, 38);
    lv_label_set_text(ui->screen_digital_clock, "0:00:00");
    if (!screen_digital_clock_timer_enabled) {
        lv_timer_create(screen_digital_clock_timer, 1000, NULL);
        screen_digital_clock_timer_enabled = true;
    }

    //Write style for screen_digital_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_digital_clock, lv_color_hex(0xf7f7f7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_digital_clock, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_digital_clock, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_digital_clock, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_digital_clock, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_system_state
    ui->screen_label_system_state = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_system_state, 362, 32);
    lv_obj_set_size(ui->screen_label_system_state, 221, 38);
    lv_label_set_text(ui->screen_label_system_state, "Unknown");
    lv_label_set_long_mode(ui->screen_label_system_state, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_system_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_system_state, lv_color_hex(0xd7d7d7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_system_state, &lv_font_misans_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_system_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_system_state, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_system_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_tabview
    ui->screen_tabview = lv_tabview_create(ui->screen);
    lv_obj_set_pos(ui->screen_tabview, 0, 89);
    lv_obj_set_size(ui->screen_tabview, 1024, 510);
    lv_obj_set_scrollbar_mode(ui->screen_tabview, LV_SCROLLBAR_MODE_OFF);
    lv_tabview_set_tab_bar_position(ui->screen_tabview, LV_DIR_LEFT);
    lv_tabview_set_tab_bar_size(ui->screen_tabview, 60);

    //Write style for screen_tabview, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_tabview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_tabview, lv_color_hex(0xeeeeee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_tabview, &lv_font_misans_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_tabview, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_tabview, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_tabview, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_tabview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_tabview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_tabview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_tabview_extra_btnm_main_default
    static lv_style_t style_screen_tabview_extra_btnm_main_default;
    ui_init_style(&style_screen_tabview_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_screen_tabview_extra_btnm_main_default, 199);
    lv_style_set_bg_color(&style_screen_tabview_extra_btnm_main_default, lv_color_hex(0x001422));
    lv_style_set_bg_grad_dir(&style_screen_tabview_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_tabview_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_screen_tabview_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_bar(ui->screen_tabview), &style_screen_tabview_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_tabview_extra_btnm_items_default
    static lv_style_t style_screen_tabview_extra_btnm_items_default;
    ui_init_style(&style_screen_tabview_extra_btnm_items_default);

    lv_style_set_text_color(&style_screen_tabview_extra_btnm_items_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_tabview_extra_btnm_items_default, &lv_font_misans_10);
    lv_style_set_text_opa(&style_screen_tabview_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_bar(ui->screen_tabview), &style_screen_tabview_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_tabview_extra_btnm_items_checked
    static lv_style_t style_screen_tabview_extra_btnm_items_checked;
    ui_init_style(&style_screen_tabview_extra_btnm_items_checked);

    lv_style_set_text_color(&style_screen_tabview_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_text_font(&style_screen_tabview_extra_btnm_items_checked, &lv_font_misans_10);
    lv_style_set_text_opa(&style_screen_tabview_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_screen_tabview_extra_btnm_items_checked, 4);
    lv_style_set_border_opa(&style_screen_tabview_extra_btnm_items_checked, 236);
    lv_style_set_border_color(&style_screen_tabview_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_border_side(&style_screen_tabview_extra_btnm_items_checked, LV_BORDER_SIDE_RIGHT);
    lv_style_set_radius(&style_screen_tabview_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_screen_tabview_extra_btnm_items_checked, 18);
    lv_style_set_bg_color(&style_screen_tabview_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_tabview_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_bar(ui->screen_tabview), &style_screen_tabview_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes 概览
    ui->screen_tabview_tab_1 = lv_tabview_add_tab(ui->screen_tabview,"概览");
    lv_obj_t * screen_tabview_tab_1_label = lv_label_create(ui->screen_tabview_tab_1);
    lv_label_set_text(screen_tabview_tab_1_label, "");

    //Write codes screen_cont_overview
    ui->screen_cont_overview = lv_obj_create(ui->screen_tabview_tab_1);
    lv_obj_set_pos(ui->screen_cont_overview, 28, -7);
    lv_obj_set_size(ui->screen_cont_overview, 479, 455);
    lv_obj_set_scrollbar_mode(ui->screen_cont_overview, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_add_flag(ui->screen_cont_overview, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for screen_cont_overview, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_overview, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_overview, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_overview, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_overview, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_overview, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_overview, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_overview, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_overview, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_5
    ui->screen_label_5 = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_5, 40, 138);
    lv_obj_set_size(ui->screen_label_5, 86, 36);
    lv_label_set_text(ui->screen_label_5, "Pitch");
    lv_label_set_long_mode(ui->screen_label_5, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_5, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_5, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_4
    ui->screen_label_4 = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_4, 40, 88);
    lv_obj_set_size(ui->screen_label_4, 87, 36);
    lv_label_set_text(ui->screen_label_4, "Yaw");
    lv_label_set_long_mode(ui->screen_label_4, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_4, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_4, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_6
    ui->screen_label_6 = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_6, 40, 188);
    lv_obj_set_size(ui->screen_label_6, 86, 36);
    lv_label_set_text(ui->screen_label_6, "扳机");
    lv_label_set_long_mode(ui->screen_label_6, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_6, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_6, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_overview
    ui->screen_label_overview = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_overview, 50, 29);
    lv_obj_set_size(ui->screen_label_overview, 94, 36);
    lv_label_set_text(ui->screen_label_overview, "概览");
    lv_label_set_long_mode(ui->screen_label_overview, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_overview, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_overview, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_overview, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_overview, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_overview, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_overview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_line_1
    ui->screen_line_1 = lv_line_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_line_1, 44, 22);
    lv_obj_set_size(ui->screen_line_1, 28, 30);
    static lv_point_precise_t screen_line_1[] = {{0, 0},{0, 403}};
    lv_line_set_points(ui->screen_line_1, screen_line_1, 2);

    //Write style for screen_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_line_1, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_line_1, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_7
    ui->screen_label_7 = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_7, 40, 238);
    lv_obj_set_size(ui->screen_label_7, 158, 36);
    lv_label_set_text(ui->screen_label_7, "制导目标");
    lv_label_set_long_mode(ui->screen_label_7, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_7, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_7, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_8
    ui->screen_label_8 = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_8, 40, 288);
    lv_obj_set_size(ui->screen_label_8, 196, 36);
    lv_label_set_text(ui->screen_label_8, "飞行整备");
    lv_label_set_long_mode(ui->screen_label_8, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_8, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_8, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_9
    ui->screen_label_9 = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_9, 37, 338);
    lv_obj_set_size(ui->screen_label_9, 120, 36);
    lv_label_set_text(ui->screen_label_9, "打击协议");
    lv_label_set_long_mode(ui->screen_label_9, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_9, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_9, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_overview_yaw
    ui->screen_label_overview_yaw = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_overview_yaw, 198, 88);
    lv_obj_set_size(ui->screen_label_overview_yaw, 266, 36);
    lv_label_set_text(ui->screen_label_overview_yaw, "400000");
    lv_label_set_long_mode(ui->screen_label_overview_yaw, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_overview_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_overview_yaw, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_overview_yaw, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_overview_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_overview_yaw, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_overview_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label__overview_pitch
    ui->screen_label__overview_pitch = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label__overview_pitch, 198, 138);
    lv_obj_set_size(ui->screen_label__overview_pitch, 266, 36);
    lv_label_set_text(ui->screen_label__overview_pitch, "20000");
    lv_label_set_long_mode(ui->screen_label__overview_pitch, LV_LABEL_LONG_WRAP);

    //Write style for screen_label__overview_pitch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label__overview_pitch, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label__overview_pitch, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label__overview_pitch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label__overview_pitch, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label__overview_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_overview_trigger
    ui->screen_label_overview_trigger = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_overview_trigger, 198, 188);
    lv_obj_set_size(ui->screen_label_overview_trigger, 266, 36);
    lv_label_set_text(ui->screen_label_overview_trigger, "4000000");
    lv_label_set_long_mode(ui->screen_label_overview_trigger, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_overview_trigger, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_overview_trigger, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_overview_trigger, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_overview_trigger, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_overview_trigger, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_overview_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_overview_guide_target
    ui->screen_label_overview_guide_target = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_overview_guide_target, 198, 238);
    lv_obj_set_size(ui->screen_label_overview_guide_target, 266, 36);
    lv_label_set_text(ui->screen_label_overview_guide_target, "N/A");
    lv_label_set_long_mode(ui->screen_label_overview_guide_target, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_overview_guide_target, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_overview_guide_target, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_overview_guide_target, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_overview_guide_target, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_overview_guide_target, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_overview_guide_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_overview_flysys_state
    ui->screen_label_overview_flysys_state = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_overview_flysys_state, 198, 288);
    lv_obj_set_size(ui->screen_label_overview_flysys_state, 266, 36);
    lv_label_set_text(ui->screen_label_overview_flysys_state, "等待启机");
    lv_label_set_long_mode(ui->screen_label_overview_flysys_state, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_overview_flysys_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_overview_flysys_state, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_overview_flysys_state, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_overview_flysys_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_overview_flysys_state, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_overview_flysys_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_16
    ui->screen_label_16 = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_16, 37, 388);
    lv_obj_set_size(ui->screen_label_16, 120, 36);
    lv_label_set_text(ui->screen_label_16, "打击进度");
    lv_label_set_long_mode(ui->screen_label_16, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_16, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_16, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_16, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_overview_process
    ui->screen_label_overview_process = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_overview_process, 198, 388);
    lv_obj_set_size(ui->screen_label_overview_process, 266, 36);
    lv_label_set_text(ui->screen_label_overview_process, "整备中");
    lv_label_set_long_mode(ui->screen_label_overview_process, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_overview_process, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_overview_process, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_overview_process, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_overview_process, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_overview_process, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_overview_process, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_47
    ui->screen_label_47 = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_47, 37, 438);
    lv_obj_set_size(ui->screen_label_47, 120, 36);
    lv_label_set_text(ui->screen_label_47, "比赛信息");
    lv_label_set_long_mode(ui->screen_label_47, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_47, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_47, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_47, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_47, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_47, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_overview_rm_info
    ui->screen_label_overview_rm_info = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_overview_rm_info, 198, 438);
    lv_obj_set_size(ui->screen_label_overview_rm_info, 266, 36);
    lv_label_set_text(ui->screen_label_overview_rm_info, "红方 赛间");
    lv_label_set_long_mode(ui->screen_label_overview_rm_info, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_overview_rm_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_overview_rm_info, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_overview_rm_info, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_overview_rm_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_overview_rm_info, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_overview_rm_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_49
    ui->screen_label_49 = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_49, 37, 488);
    lv_obj_set_size(ui->screen_label_49, 120, 36);
    lv_label_set_text(ui->screen_label_49, "舱门信号");
    lv_label_set_long_mode(ui->screen_label_49, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_49, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_49, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_49, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_49, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_49, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_overview_gate_info
    ui->screen_label_overview_gate_info = lv_label_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_label_overview_gate_info, 198, 488);
    lv_obj_set_size(ui->screen_label_overview_gate_info, 116, 36);
    lv_label_set_text(ui->screen_label_overview_gate_info, "无信号");
    lv_label_set_long_mode(ui->screen_label_overview_gate_info, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_overview_gate_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_overview_gate_info, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_overview_gate_info, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_overview_gate_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_overview_gate_info, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_overview_gate_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ddlist_overview_protocol
    ui->screen_ddlist_overview_protocol = lv_dropdown_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_ddlist_overview_protocol, 195, 336);
    lv_obj_set_size(ui->screen_ddlist_overview_protocol, 211, 33);
    lv_dropdown_set_options(ui->screen_ddlist_overview_protocol, "BR-250313-1920\nBB-250314-1920*\nBRG-250315-1920");

    //Write style for screen_ddlist_overview_protocol, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_ddlist_overview_protocol, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ddlist_overview_protocol, &lv_font_misans_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ddlist_overview_protocol, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_ddlist_overview_protocol, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ddlist_overview_protocol, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ddlist_overview_protocol, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ddlist_overview_protocol, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ddlist_overview_protocol, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ddlist_overview_protocol, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ddlist_overview_protocol, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ddlist_overview_protocol, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ddlist_overview_protocol, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ddlist_overview_protocol, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_overview_protocol, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ddlist_overview_protocol, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_ddlist_overview_protocol_extra_list_selected_checked
    static lv_style_t style_screen_ddlist_overview_protocol_extra_list_selected_checked;
    ui_init_style(&style_screen_ddlist_overview_protocol_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_ddlist_overview_protocol_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_ddlist_overview_protocol_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_ddlist_overview_protocol_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_overview_protocol_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_overview_protocol_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_overview_protocol_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_ddlist_overview_protocol_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_overview_protocol_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_overview_protocol), &style_screen_ddlist_overview_protocol_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_overview_protocol_extra_list_main_default
    static lv_style_t style_screen_ddlist_overview_protocol_extra_list_main_default;
    ui_init_style(&style_screen_ddlist_overview_protocol_extra_list_main_default);

    lv_style_set_max_height(&style_screen_ddlist_overview_protocol_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_ddlist_overview_protocol_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_ddlist_overview_protocol_extra_list_main_default, &lv_font_misans_14);
    lv_style_set_text_opa(&style_screen_ddlist_overview_protocol_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_ddlist_overview_protocol_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_ddlist_overview_protocol_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_ddlist_overview_protocol_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_overview_protocol_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_overview_protocol_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_overview_protocol_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_overview_protocol_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_overview_protocol_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_overview_protocol), &style_screen_ddlist_overview_protocol_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_overview_protocol_extra_list_scrollbar_default
    static lv_style_t style_screen_ddlist_overview_protocol_extra_list_scrollbar_default;
    ui_init_style(&style_screen_ddlist_overview_protocol_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_ddlist_overview_protocol_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_overview_protocol_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_overview_protocol_extra_list_scrollbar_default, lv_color_hex(0x1e1e1e));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_overview_protocol_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_overview_protocol), &style_screen_ddlist_overview_protocol_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_overview_edit_target_yaw
    ui->screen_imgbtn_overview_edit_target_yaw = lv_imagebutton_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_imgbtn_overview_edit_target_yaw, 118, 79);
    lv_obj_set_size(ui->screen_imgbtn_overview_edit_target_yaw, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_overview_edit_target_yaw, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_target_yaw, LV_IMAGEBUTTON_STATE_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_target_yaw, LV_IMAGEBUTTON_STATE_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_target_yaw, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_target_yaw, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_overview_edit_target_yaw_label = lv_label_create(ui->screen_imgbtn_overview_edit_target_yaw);
    lv_label_set_text(ui->screen_imgbtn_overview_edit_target_yaw_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_overview_edit_target_yaw_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_overview_edit_target_yaw_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_overview_edit_target_yaw, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_edit_target_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_target_yaw, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_target_yaw, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_target_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_overview_edit_target_yaw, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_target_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_edit_target_yaw, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_target_yaw, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_target_yaw, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_target_yaw, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_target_yaw, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_target_yaw, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_target_yaw, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_overview_edit_target_yaw, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_target_yaw, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_target_yaw, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_target_yaw, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_target_yaw, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_target_yaw, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_target_yaw, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_overview_edit_target_yaw, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_target_yaw, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_target_yaw, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_imgbtn_overview_edit_pitch
    ui->screen_imgbtn_overview_edit_pitch = lv_imagebutton_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_imgbtn_overview_edit_pitch, 118, 129);
    lv_obj_set_size(ui->screen_imgbtn_overview_edit_pitch, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_overview_edit_pitch, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_pitch, LV_IMAGEBUTTON_STATE_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_pitch, LV_IMAGEBUTTON_STATE_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_pitch, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_pitch, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_overview_edit_pitch_label = lv_label_create(ui->screen_imgbtn_overview_edit_pitch);
    lv_label_set_text(ui->screen_imgbtn_overview_edit_pitch_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_overview_edit_pitch_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_overview_edit_pitch_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_overview_edit_pitch, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_edit_pitch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_pitch, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_pitch, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_pitch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_overview_edit_pitch, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_edit_pitch, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_pitch, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_pitch, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_pitch, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_pitch, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_pitch, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_pitch, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_overview_edit_pitch, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_pitch, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_pitch, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_pitch, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_pitch, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_pitch, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_pitch, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_overview_edit_pitch, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_pitch, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_pitch, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_imgbtn_overview_edit_trigger
    ui->screen_imgbtn_overview_edit_trigger = lv_imagebutton_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_imgbtn_overview_edit_trigger, 118, 179);
    lv_obj_set_size(ui->screen_imgbtn_overview_edit_trigger, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_overview_edit_trigger, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_trigger, LV_IMAGEBUTTON_STATE_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_trigger, LV_IMAGEBUTTON_STATE_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_trigger, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_trigger, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_overview_edit_trigger_label = lv_label_create(ui->screen_imgbtn_overview_edit_trigger);
    lv_label_set_text(ui->screen_imgbtn_overview_edit_trigger_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_overview_edit_trigger_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_overview_edit_trigger_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_overview_edit_trigger, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_edit_trigger, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_trigger, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_trigger, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_trigger, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_overview_edit_trigger, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_edit_trigger, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_trigger, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_trigger, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_trigger, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_trigger, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_trigger, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_trigger, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_overview_edit_trigger, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_trigger, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_trigger, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_trigger, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_trigger, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_trigger, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_trigger, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_overview_edit_trigger, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_trigger, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_trigger, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_imgbtn_overview_edit_target
    ui->screen_imgbtn_overview_edit_target = lv_imagebutton_create(ui->screen_cont_overview);
    lv_obj_set_pos(ui->screen_imgbtn_overview_edit_target, 153, 231);
    lv_obj_set_size(ui->screen_imgbtn_overview_edit_target, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_overview_edit_target, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_target, LV_IMAGEBUTTON_STATE_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_target, LV_IMAGEBUTTON_STATE_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_target, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_edit_target, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_overview_edit_target_label = lv_label_create(ui->screen_imgbtn_overview_edit_target);
    lv_label_set_text(ui->screen_imgbtn_overview_edit_target_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_overview_edit_target_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_overview_edit_target_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_overview_edit_target, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_edit_target, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_target, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_target, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_target, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_overview_edit_target, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_edit_target, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_target, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_target, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_target, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_target, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_target, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_target, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_overview_edit_target, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_target, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_target, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_edit_target, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_edit_target, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_edit_target, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_edit_target, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_overview_edit_target, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_edit_target, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_edit_target, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_cont_launch_history
    ui->screen_cont_launch_history = lv_obj_create(ui->screen_tabview_tab_1);
    lv_obj_set_pos(ui->screen_cont_launch_history, 540, -7);
    lv_obj_set_size(ui->screen_cont_launch_history, 728, 275);
    lv_obj_set_scrollbar_mode(ui->screen_cont_launch_history, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_add_flag(ui->screen_cont_launch_history, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for screen_cont_launch_history, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_launch_history, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_launch_history, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_launch_history, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_launch_history, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_launch_history, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_launch_history, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_launch_history, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_launch_history, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_launch_history
    ui->screen_label_launch_history = lv_label_create(ui->screen_cont_launch_history);
    lv_obj_set_pos(ui->screen_label_launch_history, 57, 25);
    lv_obj_set_size(ui->screen_label_launch_history, 134, 33);
    lv_label_set_text(ui->screen_label_launch_history, "历史打击");
    lv_label_set_long_mode(ui->screen_label_launch_history, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_launch_history, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_launch_history, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_launch_history, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_launch_history, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_launch_history, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_line_2
    ui->screen_line_2 = lv_line_create(ui->screen_cont_launch_history);
    lv_obj_set_pos(ui->screen_line_2, 47, 20);
    lv_obj_set_size(ui->screen_line_2, 28, 40);
    static lv_point_precise_t screen_line_2[] = {{0, 0},{0, 40}};
    lv_line_set_points(ui->screen_line_2, screen_line_2, 2);

    //Write style for screen_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_line_2, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_line_2, lv_color_hex(0x78A75A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_table_launch_history
    ui->screen_table_launch_history = lv_table_create(ui->screen_cont_launch_history);
    lv_obj_set_pos(ui->screen_table_launch_history, 35, 74);
    lv_obj_set_scrollbar_mode(ui->screen_table_launch_history, LV_SCROLLBAR_MODE_OFF);
    lv_table_set_column_count(ui->screen_table_launch_history,5);
    lv_table_set_row_count(ui->screen_table_launch_history,1);
    lv_table_set_cell_value(ui->screen_table_launch_history,0,0,"打击时间");
    lv_table_set_cell_value(ui->screen_table_launch_history,0,1,"飞镖ID");
    lv_table_set_cell_value(ui->screen_table_launch_history,0,2,"扳机");
    lv_table_set_cell_value(ui->screen_table_launch_history,0,3,"Yaw");
    lv_table_set_cell_value(ui->screen_table_launch_history,0,4,"空速");

    //Write style for screen_table_launch_history, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_table_launch_history, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_table_launch_history, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_table_launch_history, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_table_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_table_launch_history, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_table_launch_history, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_table_launch_history, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_table_launch_history, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_table_launch_history, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_table_launch_history, lv_color_hex(0xd5dee6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_table_launch_history, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_table_launch_history, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_table_launch_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_table_launch_history, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_table_launch_history, lv_color_hex(0x293333), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_table_launch_history, &lv_font_misans_18, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_table_launch_history, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_table_launch_history, LV_TEXT_ALIGN_CENTER, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_table_launch_history, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_table_launch_history, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_table_launch_history, 7, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_table_launch_history, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_table_launch_history, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_table_launch_history, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_launch_history_clear
    ui->screen_imgbtn_launch_history_clear = lv_imagebutton_create(ui->screen_cont_launch_history);
    lv_obj_set_pos(ui->screen_imgbtn_launch_history_clear, 205, 20);
    lv_obj_set_size(ui->screen_imgbtn_launch_history_clear, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_launch_history_clear, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_launch_history_clear, LV_IMAGEBUTTON_STATE_RELEASED, &_delete_24dp_434343_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_launch_history_clear, LV_IMAGEBUTTON_STATE_PRESSED, &_delete_24dp_78A75A_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_launch_history_clear, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_delete_24dp_434343_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_launch_history_clear, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_delete_24dp_78A75A_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_launch_history_clear_label = lv_label_create(ui->screen_imgbtn_launch_history_clear);
    lv_label_set_text(ui->screen_imgbtn_launch_history_clear_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_launch_history_clear_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_launch_history_clear_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_launch_history_clear, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_launch_history_clear, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_launch_history_clear, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_launch_history_clear, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_launch_history_clear, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_launch_history_clear, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_launch_history_clear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_launch_history_clear, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_launch_history_clear, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_launch_history_clear, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_launch_history_clear, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_launch_history_clear, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_launch_history_clear, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_launch_history_clear, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_launch_history_clear, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_launch_history_clear, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_launch_history_clear, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_launch_history_clear, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_launch_history_clear, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_launch_history_clear, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_launch_history_clear, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_launch_history_clear, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_launch_history_clear, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_launch_history_clear, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_cont_shortcut
    ui->screen_cont_shortcut = lv_obj_create(ui->screen_tabview_tab_1);
    lv_obj_set_pos(ui->screen_cont_shortcut, 539, 295);
    lv_obj_set_size(ui->screen_cont_shortcut, 516, 152);
    lv_obj_set_scrollbar_mode(ui->screen_cont_shortcut, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_cont_shortcut, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for screen_cont_shortcut, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_shortcut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_shortcut, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_shortcut, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_shortcut, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_shortcut, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_shortcut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_shortcut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_shortcut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_shortcut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_shortcut, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_shortcut, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_shortcut, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_shortcut, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_shortcut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_shortcut, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_shortcut_service_restart
    ui->screen_imgbtn_shortcut_service_restart = lv_imagebutton_create(ui->screen_cont_shortcut);
    lv_obj_set_pos(ui->screen_imgbtn_shortcut_service_restart, 66, 28);
    lv_obj_set_size(ui->screen_imgbtn_shortcut_service_restart, 60, 60);
    lv_obj_add_flag(ui->screen_imgbtn_shortcut_service_restart, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_service_restart, LV_IMAGEBUTTON_STATE_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_service_restart, LV_IMAGEBUTTON_STATE_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_service_restart, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_service_restart, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    ui->screen_imgbtn_shortcut_service_restart_label = lv_label_create(ui->screen_imgbtn_shortcut_service_restart);
    lv_label_set_text(ui->screen_imgbtn_shortcut_service_restart_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_shortcut_service_restart_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_shortcut_service_restart_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_shortcut_service_restart, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_shortcut_service_restart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_shortcut_service_restart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_shortcut_service_restart, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_shortcut_service_restart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_shortcut_service_restart, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_shortcut_service_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_shortcut_service_restart, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_shortcut_service_restart, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_shortcut_service_restart, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_shortcut_service_restart, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_shortcut_service_restart, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_shortcut_service_restart, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_shortcut_service_restart, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_shortcut_service_restart, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_shortcut_service_restart, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_shortcut_service_restart, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_shortcut_service_restart, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_shortcut_service_restart, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_shortcut_service_restart, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_shortcut_service_restart, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_shortcut_service_restart, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_shortcut_service_restart, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_shortcut_service_restart, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_label_32
    ui->screen_label_32 = lv_label_create(ui->screen_cont_shortcut);
    lv_obj_set_pos(ui->screen_label_32, 28, 98);
    lv_obj_set_size(ui->screen_label_32, 134, 29);
    lv_label_set_text(ui->screen_label_32, "服务复位");
    lv_label_set_long_mode(ui->screen_label_32, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_32, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_32, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_32, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_32, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_32, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_33
    ui->screen_label_33 = lv_label_create(ui->screen_cont_shortcut);
    lv_obj_set_pos(ui->screen_label_33, 181, 99);
    lv_obj_set_size(ui->screen_label_33, 134, 29);
    lv_label_set_text(ui->screen_label_33, "协议覆写");
    lv_label_set_long_mode(ui->screen_label_33, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_33, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_33, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_33, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_33, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_33, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_shortcut_protocol_reload
    ui->screen_imgbtn_shortcut_protocol_reload = lv_imagebutton_create(ui->screen_cont_shortcut);
    lv_obj_set_pos(ui->screen_imgbtn_shortcut_protocol_reload, 218, 28);
    lv_obj_set_size(ui->screen_imgbtn_shortcut_protocol_reload, 60, 60);
    lv_obj_add_flag(ui->screen_imgbtn_shortcut_protocol_reload, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_protocol_reload, LV_IMAGEBUTTON_STATE_RELEASED, &_upload_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_protocol_reload, LV_IMAGEBUTTON_STATE_PRESSED, &_upload_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_protocol_reload, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_upload_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_protocol_reload, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_upload_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    ui->screen_imgbtn_shortcut_protocol_reload_label = lv_label_create(ui->screen_imgbtn_shortcut_protocol_reload);
    lv_label_set_text(ui->screen_imgbtn_shortcut_protocol_reload_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_shortcut_protocol_reload_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_shortcut_protocol_reload_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_shortcut_protocol_reload, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_shortcut_protocol_reload, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_shortcut_protocol_reload, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_shortcut_protocol_reload, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_shortcut_protocol_reload, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_shortcut_protocol_reload, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_shortcut_protocol_reload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_shortcut_protocol_reload, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_shortcut_protocol_reload, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_shortcut_protocol_reload, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_shortcut_protocol_reload, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_shortcut_protocol_reload, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_shortcut_protocol_reload, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_shortcut_protocol_reload, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_shortcut_protocol_reload, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_shortcut_protocol_reload, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_shortcut_protocol_reload, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_shortcut_protocol_reload, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_shortcut_protocol_reload, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_shortcut_protocol_reload, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_shortcut_protocol_reload, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_shortcut_protocol_reload, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_shortcut_protocol_reload, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_shortcut_protocol_reload, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_label_34
    ui->screen_label_34 = lv_label_create(ui->screen_cont_shortcut);
    lv_obj_set_pos(ui->screen_label_34, 333, 99);
    lv_obj_set_size(ui->screen_label_34, 134, 29);
    lv_label_set_text(ui->screen_label_34, "引导灯");
    lv_label_set_long_mode(ui->screen_label_34, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_34, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_34, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_34, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_34, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_34, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_shortcut_guidelight
    ui->screen_imgbtn_shortcut_guidelight = lv_imagebutton_create(ui->screen_cont_shortcut);
    lv_obj_set_pos(ui->screen_imgbtn_shortcut_guidelight, 370, 28);
    lv_obj_set_size(ui->screen_imgbtn_shortcut_guidelight, 60, 60);
    lv_obj_add_flag(ui->screen_imgbtn_shortcut_guidelight, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_guidelight, LV_IMAGEBUTTON_STATE_RELEASED, &_model_training_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_guidelight, LV_IMAGEBUTTON_STATE_PRESSED, &_model_training_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_guidelight, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_model_training_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_shortcut_guidelight, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_model_training_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    ui->screen_imgbtn_shortcut_guidelight_label = lv_label_create(ui->screen_imgbtn_shortcut_guidelight);
    lv_label_set_text(ui->screen_imgbtn_shortcut_guidelight_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_shortcut_guidelight_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_shortcut_guidelight_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_shortcut_guidelight, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_shortcut_guidelight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_shortcut_guidelight, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_shortcut_guidelight, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_shortcut_guidelight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_shortcut_guidelight, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_shortcut_guidelight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_shortcut_guidelight, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_shortcut_guidelight, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_shortcut_guidelight, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_shortcut_guidelight, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_shortcut_guidelight, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_shortcut_guidelight, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_shortcut_guidelight, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_shortcut_guidelight, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_shortcut_guidelight, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_shortcut_guidelight, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_shortcut_guidelight, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_shortcut_guidelight, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_shortcut_guidelight, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_shortcut_guidelight, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_shortcut_guidelight, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_shortcut_guidelight, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_shortcut_guidelight, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_cont_flysys_info
    ui->screen_cont_flysys_info = lv_obj_create(ui->screen_tabview_tab_1);
    lv_obj_set_pos(ui->screen_cont_flysys_info, 1304, -7);
    lv_obj_set_size(ui->screen_cont_flysys_info, 476, 453);
    lv_obj_set_scrollbar_mode(ui->screen_cont_flysys_info, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_add_flag(ui->screen_cont_flysys_info, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for screen_cont_flysys_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_flysys_info, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_flysys_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_flysys_info, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_flysys_info, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_flysys_info, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_flysys_info, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_flysys_info, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_flysys_info, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_flysys_info
    ui->screen_label_flysys_info = lv_label_create(ui->screen_cont_flysys_info);
    lv_obj_set_pos(ui->screen_label_flysys_info, 57, 29);
    lv_obj_set_size(ui->screen_label_flysys_info, 120, 36);
    lv_label_set_text(ui->screen_label_flysys_info, "飞行整备");
    lv_label_set_long_mode(ui->screen_label_flysys_info, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_flysys_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_flysys_info, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_flysys_info, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_flysys_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_flysys_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_line_4
    ui->screen_line_4 = lv_line_create(ui->screen_cont_flysys_info);
    lv_obj_set_pos(ui->screen_line_4, 44, 22);
    lv_obj_set_size(ui->screen_line_4, 28, 25);
    static lv_point_precise_t screen_line_4[] = {{0, 0},{0, 403}};
    lv_line_set_points(ui->screen_line_4, screen_line_4, 2);

    //Write style for screen_line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_line_4, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_line_4, lv_color_hex(0x904E29), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_line_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_table_flysys_info
    ui->screen_table_flysys_info = lv_table_create(ui->screen_cont_flysys_info);
    lv_obj_set_pos(ui->screen_table_flysys_info, 40, 72);
    lv_obj_set_scrollbar_mode(ui->screen_table_flysys_info, LV_SCROLLBAR_MODE_OFF);
    lv_table_set_column_count(ui->screen_table_flysys_info,3);
    lv_table_set_row_count(ui->screen_table_flysys_info,1);
    lv_table_set_cell_value(ui->screen_table_flysys_info,0,0,"节点ID");
    lv_table_set_cell_value(ui->screen_table_flysys_info,0,1,"电量");
    lv_table_set_cell_value(ui->screen_table_flysys_info,0,2,"状态");

    //Write style for screen_table_flysys_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_table_flysys_info, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_table_flysys_info, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_table_flysys_info, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_table_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_table_flysys_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_table_flysys_info, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_table_flysys_info, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_table_flysys_info, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_table_flysys_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_table_flysys_info, lv_color_hex(0xd5dee6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_table_flysys_info, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_table_flysys_info, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_table_flysys_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_table_flysys_info, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_table_flysys_info, lv_color_hex(0x293333), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_table_flysys_info, &lv_font_misans_18, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_table_flysys_info, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_table_flysys_info, LV_TEXT_ALIGN_CENTER, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_table_flysys_info, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_table_flysys_info, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_table_flysys_info, 7, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_table_flysys_info, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_table_flysys_info, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_table_flysys_info, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes 协议
    ui->screen_tabview_tab_2 = lv_tabview_add_tab(ui->screen_tabview,"协议");
    lv_obj_t * screen_tabview_tab_2_label = lv_label_create(ui->screen_tabview_tab_2);
    lv_label_set_text(screen_tabview_tab_2_label, "");

    //Write codes screen_cont_protocol_edit
    ui->screen_cont_protocol_edit = lv_obj_create(ui->screen_tabview_tab_2);
    lv_obj_set_pos(ui->screen_cont_protocol_edit, 45, 3);
    lv_obj_set_size(ui->screen_cont_protocol_edit, 795, 456);
    lv_obj_set_scrollbar_mode(ui->screen_cont_protocol_edit, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_add_flag(ui->screen_cont_protocol_edit, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for screen_cont_protocol_edit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_protocol_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_protocol_edit, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_protocol_edit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_protocol_edit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_protocol_edit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_protocol_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_protocol_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_protocol_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_protocol_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_protocol_edit, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_protocol_edit, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_protocol_edit, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_protocol_edit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_protocol_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_protocol_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_68
    ui->screen_label_68 = lv_label_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_label_68, 91, 83);
    lv_obj_set_size(ui->screen_label_68, 176, 30);
    lv_label_set_text(ui->screen_label_68, "打击协议");
    lv_label_set_long_mode(ui->screen_label_68, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_68, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_68, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_68, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_68, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_68, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_66
    ui->screen_label_66 = lv_label_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_label_66, 57, 29);
    lv_obj_set_size(ui->screen_label_66, 126, 36);
    lv_label_set_text(ui->screen_label_66, "协议编辑");
    lv_label_set_long_mode(ui->screen_label_66, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_66, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_66, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_66, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_66, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_66, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_line_5
    ui->screen_line_5 = lv_line_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_line_5, 94, 680);
    lv_obj_set_size(ui->screen_line_5, 28, 30);
    static lv_point_precise_t screen_line_5[] = {{0, 0},{0, 403}};
    lv_line_set_points(ui->screen_line_5, screen_line_5, 2);

    //Write style for screen_line_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_opa(ui->screen_line_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ddlist_protocol_edit
    ui->screen_ddlist_protocol_edit = lv_dropdown_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_ddlist_protocol_edit, 257, 81);
    lv_obj_set_size(ui->screen_ddlist_protocol_edit, 263, 33);
    lv_dropdown_set_options(ui->screen_ddlist_protocol_edit, "BR-250313-1920\nBB-250314-1920*\nBRG-250315-1920");

    //Write style for screen_ddlist_protocol_edit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_ddlist_protocol_edit, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ddlist_protocol_edit, &lv_font_misans_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ddlist_protocol_edit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_ddlist_protocol_edit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ddlist_protocol_edit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ddlist_protocol_edit, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ddlist_protocol_edit, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ddlist_protocol_edit, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ddlist_protocol_edit, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ddlist_protocol_edit, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ddlist_protocol_edit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ddlist_protocol_edit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ddlist_protocol_edit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_protocol_edit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ddlist_protocol_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_ddlist_protocol_edit_extra_list_selected_checked
    static lv_style_t style_screen_ddlist_protocol_edit_extra_list_selected_checked;
    ui_init_style(&style_screen_ddlist_protocol_edit_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_ddlist_protocol_edit_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_ddlist_protocol_edit_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_ddlist_protocol_edit_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_protocol_edit_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_protocol_edit_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_protocol_edit_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_ddlist_protocol_edit_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_protocol_edit_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_protocol_edit), &style_screen_ddlist_protocol_edit_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_protocol_edit_extra_list_main_default
    static lv_style_t style_screen_ddlist_protocol_edit_extra_list_main_default;
    ui_init_style(&style_screen_ddlist_protocol_edit_extra_list_main_default);

    lv_style_set_max_height(&style_screen_ddlist_protocol_edit_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_ddlist_protocol_edit_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_ddlist_protocol_edit_extra_list_main_default, &lv_font_misans_14);
    lv_style_set_text_opa(&style_screen_ddlist_protocol_edit_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_ddlist_protocol_edit_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_ddlist_protocol_edit_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_ddlist_protocol_edit_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_protocol_edit_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_protocol_edit_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_protocol_edit_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_protocol_edit_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_protocol_edit_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_protocol_edit), &style_screen_ddlist_protocol_edit_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_protocol_edit_extra_list_scrollbar_default
    static lv_style_t style_screen_ddlist_protocol_edit_extra_list_scrollbar_default;
    ui_init_style(&style_screen_ddlist_protocol_edit_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_ddlist_protocol_edit_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_protocol_edit_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_protocol_edit_extra_list_scrollbar_default, lv_color_hex(0x1e1e1e));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_protocol_edit_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_protocol_edit), &style_screen_ddlist_protocol_edit_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_protocol_edit_drop
    ui->screen_imgbtn_protocol_edit_drop = lv_imagebutton_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_imgbtn_protocol_edit_drop, 570, 77);
    lv_obj_set_size(ui->screen_imgbtn_protocol_edit_drop, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_protocol_edit_drop, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_drop, LV_IMAGEBUTTON_STATE_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_drop, LV_IMAGEBUTTON_STATE_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_drop, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_drop, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_protocol_edit_drop_label = lv_label_create(ui->screen_imgbtn_protocol_edit_drop);
    lv_label_set_text(ui->screen_imgbtn_protocol_edit_drop_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_protocol_edit_drop_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_protocol_edit_drop_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_protocol_edit_drop, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_drop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_drop, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_drop, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_drop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_protocol_edit_drop, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_drop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_drop, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_drop, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_drop, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_drop, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_drop, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_drop, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_drop, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_protocol_edit_drop, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_drop, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_drop, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_drop, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_drop, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_drop, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_drop, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_protocol_edit_drop, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_drop, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_drop, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_btn_protocol_edit_rename
    ui->screen_btn_protocol_edit_rename = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_btn_protocol_edit_rename, 361, 141);
    lv_obj_set_size(ui->screen_btn_protocol_edit_rename, 91, 42);
    ui->screen_btn_protocol_edit_rename_label = lv_label_create(ui->screen_btn_protocol_edit_rename);
    lv_label_set_text(ui->screen_btn_protocol_edit_rename_label, "重命名");
    lv_label_set_long_mode(ui->screen_btn_protocol_edit_rename_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_protocol_edit_rename_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_protocol_edit_rename, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_protocol_edit_rename_label, LV_PCT(100));

    //Write style for screen_btn_protocol_edit_rename, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_protocol_edit_rename, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_protocol_edit_rename, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_protocol_edit_rename, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_protocol_edit_rename, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_protocol_edit_rename, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_protocol_edit_rename, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_protocol_edit_rename, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_protocol_edit_rename, &lv_font_misans_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_protocol_edit_rename, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_protocol_edit_rename, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_protocol_edit_new
    ui->screen_btn_protocol_edit_new = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_btn_protocol_edit_new, 474, 141);
    lv_obj_set_size(ui->screen_btn_protocol_edit_new, 104, 42);
    ui->screen_btn_protocol_edit_new_label = lv_label_create(ui->screen_btn_protocol_edit_new);
    lv_label_set_text(ui->screen_btn_protocol_edit_new_label, "新建协议");
    lv_label_set_long_mode(ui->screen_btn_protocol_edit_new_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_protocol_edit_new_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_protocol_edit_new, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_protocol_edit_new_label, LV_PCT(100));

    //Write style for screen_btn_protocol_edit_new, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_protocol_edit_new, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_protocol_edit_new, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_protocol_edit_new, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_protocol_edit_new, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_protocol_edit_new, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_protocol_edit_new, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_protocol_edit_new, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_protocol_edit_new, &lv_font_misans_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_protocol_edit_new, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_protocol_edit_new, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cb_protocol_edit_trig
    ui->screen_cb_protocol_edit_trig = lv_checkbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_cb_protocol_edit_trig, 87, 319);
    lv_checkbox_set_text(ui->screen_cb_protocol_edit_trig, "扳机");

    //Write style for screen_cb_protocol_edit_trig, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_protocol_edit_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_protocol_edit_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_protocol_edit_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_protocol_edit_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_protocol_edit_trig, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_protocol_edit_trig, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_protocol_edit_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_protocol_edit_trig, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_trig, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_trig, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_trig, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_protocol_edit_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_protocol_edit_trig, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_protocol_edit_trig, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_trig, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_protocol_edit_trig, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_protocol_edit_trig, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_protocol_edit_trig, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_trig, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_trig, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_trig, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_trig, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_cb_protocol_edit_yaw
    ui->screen_cb_protocol_edit_yaw = lv_checkbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_cb_protocol_edit_yaw, 87, 267);
    lv_checkbox_set_text(ui->screen_cb_protocol_edit_yaw, "Yaw");

    //Write style for screen_cb_protocol_edit_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_protocol_edit_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_protocol_edit_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_protocol_edit_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_protocol_edit_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_protocol_edit_yaw, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_protocol_edit_yaw, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_protocol_edit_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_protocol_edit_yaw, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_yaw, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_yaw, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_yaw, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_protocol_edit_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_protocol_edit_yaw, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_protocol_edit_yaw, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_yaw, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_protocol_edit_yaw, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_protocol_edit_yaw, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_protocol_edit_yaw, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_yaw, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_yaw, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_yaw, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_yaw, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_cb_protocol_edit_visual_x
    ui->screen_cb_protocol_edit_visual_x = lv_checkbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_cb_protocol_edit_visual_x, 87, 371);
    lv_checkbox_set_text(ui->screen_cb_protocol_edit_visual_x, "制导目标X");

    //Write style for screen_cb_protocol_edit_visual_x, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_protocol_edit_visual_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_protocol_edit_visual_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_protocol_edit_visual_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_protocol_edit_visual_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_protocol_edit_visual_x, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_protocol_edit_visual_x, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_protocol_edit_visual_x, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_protocol_edit_visual_x, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_visual_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_visual_x, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_visual_x, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_visual_x, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_visual_x, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_protocol_edit_visual_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_protocol_edit_visual_x, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_protocol_edit_visual_x, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_visual_x, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_protocol_edit_visual_x, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_protocol_edit_visual_x, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_protocol_edit_visual_x, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_visual_x, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_visual_x, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_visual_x, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_visual_x, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_cb_protocol_edit_slt1
    ui->screen_cb_protocol_edit_slt1 = lv_checkbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_cb_protocol_edit_slt1, 74, 462);
    lv_checkbox_set_text(ui->screen_cb_protocol_edit_slt1, "槽位1");

    //Write style for screen_cb_protocol_edit_slt1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_protocol_edit_slt1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_protocol_edit_slt1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_protocol_edit_slt1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_protocol_edit_slt1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_protocol_edit_slt1, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_protocol_edit_slt1, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_protocol_edit_slt1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_protocol_edit_slt1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_slt1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_slt1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_slt1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_slt1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_slt1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_protocol_edit_slt1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_protocol_edit_slt1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_protocol_edit_slt1, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_slt1, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_protocol_edit_slt1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_protocol_edit_slt1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_protocol_edit_slt1, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_slt1, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_slt1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_slt1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_slt1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_cb_protocol_edit_slt2
    ui->screen_cb_protocol_edit_slt2 = lv_checkbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_cb_protocol_edit_slt2, 74, 514);
    lv_checkbox_set_text(ui->screen_cb_protocol_edit_slt2, "槽位2");

    //Write style for screen_cb_protocol_edit_slt2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_protocol_edit_slt2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_protocol_edit_slt2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_protocol_edit_slt2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_protocol_edit_slt2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_protocol_edit_slt2, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_protocol_edit_slt2, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_protocol_edit_slt2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_protocol_edit_slt2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_slt2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_slt2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_slt2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_slt2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_slt2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_protocol_edit_slt2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_protocol_edit_slt2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_protocol_edit_slt2, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_slt2, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_protocol_edit_slt2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_protocol_edit_slt2, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_protocol_edit_slt2, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_slt2, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_slt2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_slt2, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_slt2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_cb_protocol_edit_slt3
    ui->screen_cb_protocol_edit_slt3 = lv_checkbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_cb_protocol_edit_slt3, 74, 566);
    lv_checkbox_set_text(ui->screen_cb_protocol_edit_slt3, "槽位3");

    //Write style for screen_cb_protocol_edit_slt3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_protocol_edit_slt3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_protocol_edit_slt3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_protocol_edit_slt3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_protocol_edit_slt3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_protocol_edit_slt3, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_protocol_edit_slt3, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_protocol_edit_slt3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_protocol_edit_slt3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_slt3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_slt3, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_slt3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_slt3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_slt3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_protocol_edit_slt3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_protocol_edit_slt3, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_protocol_edit_slt3, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_slt3, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_protocol_edit_slt3, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_protocol_edit_slt3, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_protocol_edit_slt3, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_slt3, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_slt3, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_slt3, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_slt3, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_cb_protocol_edit_slt4
    ui->screen_cb_protocol_edit_slt4 = lv_checkbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_cb_protocol_edit_slt4, 74, 618);
    lv_checkbox_set_text(ui->screen_cb_protocol_edit_slt4, "槽位4");

    //Write style for screen_cb_protocol_edit_slt4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_protocol_edit_slt4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_protocol_edit_slt4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_protocol_edit_slt4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_protocol_edit_slt4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_protocol_edit_slt4, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_protocol_edit_slt4, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_protocol_edit_slt4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_protocol_edit_slt4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_slt4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_slt4, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_slt4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_slt4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_slt4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_protocol_edit_slt4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_protocol_edit_slt4, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_protocol_edit_slt4, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_slt4, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_protocol_edit_slt4, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_protocol_edit_slt4, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_protocol_edit_slt4, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_slt4, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_slt4, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_slt4, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_slt4, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_ta_protocol_edit_rename
    ui->screen_ta_protocol_edit_rename = lv_textarea_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_ta_protocol_edit_rename, 87, 135);
    lv_obj_set_size(ui->screen_ta_protocol_edit_rename, 244, 53);
    lv_textarea_set_text(ui->screen_ta_protocol_edit_rename, "");
    lv_textarea_set_placeholder_text(ui->screen_ta_protocol_edit_rename, "tmp-***-***-*");
    lv_textarea_set_password_bullet(ui->screen_ta_protocol_edit_rename, "*");
    lv_textarea_set_password_mode(ui->screen_ta_protocol_edit_rename, false);
    lv_textarea_set_one_line(ui->screen_ta_protocol_edit_rename, true);
    lv_textarea_set_accepted_chars(ui->screen_ta_protocol_edit_rename, "");
    lv_textarea_set_max_length(ui->screen_ta_protocol_edit_rename, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_ta_protocol_edit_rename, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_ta_protocol_edit_rename, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_ta_protocol_edit_rename, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ta_protocol_edit_rename, &lv_font_misans_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ta_protocol_edit_rename, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_ta_protocol_edit_rename, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_ta_protocol_edit_rename, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ta_protocol_edit_rename, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ta_protocol_edit_rename, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ta_protocol_edit_rename, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_ta_protocol_edit_rename, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ta_protocol_edit_rename, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ta_protocol_edit_rename, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ta_protocol_edit_rename, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ta_protocol_edit_rename, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ta_protocol_edit_rename, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ta_protocol_edit_rename, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ta_protocol_edit_rename, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ta_protocol_edit_rename, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_ta_protocol_edit_rename, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_ta_protocol_edit_rename, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ta_protocol_edit_rename, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ta_protocol_edit_rename, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ta_protocol_edit_rename, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_btn_protocol_edit_reference
    ui->screen_btn_protocol_edit_reference = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_btn_protocol_edit_reference, 218, 202);
    lv_obj_set_size(ui->screen_btn_protocol_edit_reference, 91, 42);
    ui->screen_btn_protocol_edit_reference_label = lv_label_create(ui->screen_btn_protocol_edit_reference);
    lv_label_set_text(ui->screen_btn_protocol_edit_reference_label, "引用源");
    lv_label_set_long_mode(ui->screen_btn_protocol_edit_reference_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_protocol_edit_reference_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_protocol_edit_reference, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_protocol_edit_reference_label, LV_PCT(100));

    //Write style for screen_btn_protocol_edit_reference, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_protocol_edit_reference, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_protocol_edit_reference, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_protocol_edit_reference, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_protocol_edit_reference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_protocol_edit_reference, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_protocol_edit_reference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_protocol_edit_reference, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_protocol_edit_reference, &lv_font_misans_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_protocol_edit_reference, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_protocol_edit_reference, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cb_protocol_edit_choose_all
    ui->screen_cb_protocol_edit_choose_all = lv_checkbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_cb_protocol_edit_choose_all, 87, 208);
    lv_checkbox_set_text(ui->screen_cb_protocol_edit_choose_all, "全选");

    //Write style for screen_cb_protocol_edit_choose_all, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_protocol_edit_choose_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_protocol_edit_choose_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_protocol_edit_choose_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_protocol_edit_choose_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_protocol_edit_choose_all, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_protocol_edit_choose_all, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_protocol_edit_choose_all, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_protocol_edit_choose_all, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_choose_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_choose_all, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_choose_all, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_choose_all, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_choose_all, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_protocol_edit_choose_all, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_protocol_edit_choose_all, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_protocol_edit_choose_all, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_protocol_edit_choose_all, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_protocol_edit_choose_all, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_protocol_edit_choose_all, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_protocol_edit_choose_all, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_protocol_edit_choose_all, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_protocol_edit_choose_all, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_protocol_edit_choose_all, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_protocol_edit_choose_all, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_trig
    ui->screen_spinbox_protocol_edit_trig = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_trig, 319, 314);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_trig, 319, 314);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_trig, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_trig, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_trig, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_trig, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_trig_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_trig);
    ui->screen_spinbox_protocol_edit_trig_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_trig, 319, 314);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_trig_btn_plus, screen_spinbox_protocol_edit_trig_h, screen_spinbox_protocol_edit_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_trig_btn_plus, ui->screen_spinbox_protocol_edit_trig, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_trig_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_trig_btn_plus, lv_screen_spinbox_protocol_edit_trig_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_trig_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_trig_btn_minus, screen_spinbox_protocol_edit_trig_h, screen_spinbox_protocol_edit_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_trig_btn_minus, ui->screen_spinbox_protocol_edit_trig, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_trig_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_trig_btn_minus, lv_screen_spinbox_protocol_edit_trig_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_trig, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_trig, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_trig, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_trig, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_trig, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_trig, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_trig, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_trig, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_trig, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_trig, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_trig, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_trig, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_trig, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_trig, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_trig_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_trig_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_trig_btn_plus, &style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_trig_btn_minus, &style_screen_spinbox_protocol_edit_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_yaw
    ui->screen_spinbox_protocol_edit_yaw = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_yaw, 294, 262);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_yaw, 294, 262);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_yaw, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_yaw, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_yaw, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_yaw, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_yaw_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_yaw);
    ui->screen_spinbox_protocol_edit_yaw_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_yaw, 294, 262);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_yaw_btn_plus, screen_spinbox_protocol_edit_yaw_h, screen_spinbox_protocol_edit_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_yaw_btn_plus, ui->screen_spinbox_protocol_edit_yaw, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_yaw_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_yaw_btn_plus, lv_screen_spinbox_protocol_edit_yaw_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_yaw_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_yaw_btn_minus, screen_spinbox_protocol_edit_yaw_h, screen_spinbox_protocol_edit_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_yaw_btn_minus, ui->screen_spinbox_protocol_edit_yaw, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_yaw_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_yaw_btn_minus, lv_screen_spinbox_protocol_edit_yaw_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_yaw, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_yaw, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_yaw, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_yaw, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_yaw, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_yaw, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_yaw, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_yaw, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_yaw, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_yaw, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_yaw, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_yaw, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_yaw, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_yaw_btn_plus, &style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_yaw_btn_minus, &style_screen_spinbox_protocol_edit_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_slt1_yaw
    ui->screen_spinbox_protocol_edit_slt1_yaw = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt1_yaw, 252, 457);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt1_yaw, 252, 457);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_slt1_yaw, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_slt1_yaw, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_slt1_yaw, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_slt1_yaw, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_slt1_yaw_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_slt1_yaw);
    ui->screen_spinbox_protocol_edit_slt1_yaw_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt1_yaw, 252, 457);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_plus, screen_spinbox_protocol_edit_slt1_yaw_h, screen_spinbox_protocol_edit_slt1_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_plus, ui->screen_spinbox_protocol_edit_slt1_yaw, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_plus, lv_screen_spinbox_protocol_edit_slt1_yaw_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_slt1_yaw_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_minus, screen_spinbox_protocol_edit_slt1_yaw_h, screen_spinbox_protocol_edit_slt1_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_minus, ui->screen_spinbox_protocol_edit_slt1_yaw, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_minus, lv_screen_spinbox_protocol_edit_slt1_yaw_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_slt1_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt1_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt1_yaw, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt1_yaw, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_slt1_yaw, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_slt1_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_slt1_yaw, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_slt1_yaw, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_slt1_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_slt1_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_slt1_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_slt1_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt1_yaw, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt1_yaw, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt1_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_slt1_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_slt1_yaw, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_slt1_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_slt1_yaw, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt1_yaw, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt1_yaw, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt1_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt1_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt1_yaw, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt1_yaw, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_plus, &style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt1_yaw_btn_minus, &style_screen_spinbox_protocol_edit_slt1_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_slt2_yaw
    ui->screen_spinbox_protocol_edit_slt2_yaw = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt2_yaw, 253, 509);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt2_yaw, 253, 509);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_slt2_yaw, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_slt2_yaw, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_slt2_yaw, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_slt2_yaw, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_slt2_yaw_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_slt2_yaw);
    ui->screen_spinbox_protocol_edit_slt2_yaw_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt2_yaw, 253, 509);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_plus, screen_spinbox_protocol_edit_slt2_yaw_h, screen_spinbox_protocol_edit_slt2_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_plus, ui->screen_spinbox_protocol_edit_slt2_yaw, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_plus, lv_screen_spinbox_protocol_edit_slt2_yaw_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_slt2_yaw_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_minus, screen_spinbox_protocol_edit_slt2_yaw_h, screen_spinbox_protocol_edit_slt2_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_minus, ui->screen_spinbox_protocol_edit_slt2_yaw, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_minus, lv_screen_spinbox_protocol_edit_slt2_yaw_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_slt2_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt2_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt2_yaw, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt2_yaw, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_slt2_yaw, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_slt2_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_slt2_yaw, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_slt2_yaw, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_slt2_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_slt2_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_slt2_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_slt2_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt2_yaw, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt2_yaw, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt2_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_slt2_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_slt2_yaw, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_slt2_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_slt2_yaw, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt2_yaw, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt2_yaw, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt2_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt2_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt2_yaw, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt2_yaw, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_plus, &style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt2_yaw_btn_minus, &style_screen_spinbox_protocol_edit_slt2_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_slt3_yaw
    ui->screen_spinbox_protocol_edit_slt3_yaw = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt3_yaw, 253, 561);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt3_yaw, 253, 561);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_slt3_yaw, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_slt3_yaw, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_slt3_yaw, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_slt3_yaw, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_slt3_yaw_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_slt3_yaw);
    ui->screen_spinbox_protocol_edit_slt3_yaw_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt3_yaw, 253, 561);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_plus, screen_spinbox_protocol_edit_slt3_yaw_h, screen_spinbox_protocol_edit_slt3_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_plus, ui->screen_spinbox_protocol_edit_slt3_yaw, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_plus, lv_screen_spinbox_protocol_edit_slt3_yaw_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_slt3_yaw_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_minus, screen_spinbox_protocol_edit_slt3_yaw_h, screen_spinbox_protocol_edit_slt3_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_minus, ui->screen_spinbox_protocol_edit_slt3_yaw, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_minus, lv_screen_spinbox_protocol_edit_slt3_yaw_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_slt3_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt3_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt3_yaw, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt3_yaw, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_slt3_yaw, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_slt3_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_slt3_yaw, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_slt3_yaw, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_slt3_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_slt3_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_slt3_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_slt3_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt3_yaw, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt3_yaw, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt3_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_slt3_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_slt3_yaw, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_slt3_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_slt3_yaw, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt3_yaw, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt3_yaw, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt3_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt3_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt3_yaw, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt3_yaw, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_plus, &style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt3_yaw_btn_minus, &style_screen_spinbox_protocol_edit_slt3_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_slt4_yaw
    ui->screen_spinbox_protocol_edit_slt4_yaw = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt4_yaw, 253, 613);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt4_yaw, 253, 613);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_slt4_yaw, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_slt4_yaw, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_slt4_yaw, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_slt4_yaw, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_slt4_yaw_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_slt4_yaw);
    ui->screen_spinbox_protocol_edit_slt4_yaw_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt4_yaw, 253, 613);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_plus, screen_spinbox_protocol_edit_slt4_yaw_h, screen_spinbox_protocol_edit_slt4_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_plus, ui->screen_spinbox_protocol_edit_slt4_yaw, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_plus, lv_screen_spinbox_protocol_edit_slt4_yaw_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_slt4_yaw_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_minus, screen_spinbox_protocol_edit_slt4_yaw_h, screen_spinbox_protocol_edit_slt4_yaw_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_minus, ui->screen_spinbox_protocol_edit_slt4_yaw, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_minus, lv_screen_spinbox_protocol_edit_slt4_yaw_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_slt4_yaw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt4_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt4_yaw, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt4_yaw, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_slt4_yaw, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_slt4_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_slt4_yaw, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_slt4_yaw, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_slt4_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_slt4_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_slt4_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_slt4_yaw, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt4_yaw, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt4_yaw, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt4_yaw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_slt4_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_slt4_yaw, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_slt4_yaw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_slt4_yaw, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt4_yaw, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt4_yaw, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt4_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt4_yaw, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt4_yaw, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt4_yaw, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_plus, &style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt4_yaw_btn_minus, &style_screen_spinbox_protocol_edit_slt4_yaw_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_visual_x
    ui->screen_spinbox_protocol_edit_visual_x = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_visual_x, 319, 366);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_visual_x, 319, 366);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_visual_x, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_visual_x, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_visual_x, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_visual_x, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_visual_x_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_visual_x);
    ui->screen_spinbox_protocol_edit_visual_x_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_visual_x, 319, 366);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_visual_x_btn_plus, screen_spinbox_protocol_edit_visual_x_h, screen_spinbox_protocol_edit_visual_x_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_visual_x_btn_plus, ui->screen_spinbox_protocol_edit_visual_x, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_visual_x_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_visual_x_btn_plus, lv_screen_spinbox_protocol_edit_visual_x_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_visual_x_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_visual_x_btn_minus, screen_spinbox_protocol_edit_visual_x_h, screen_spinbox_protocol_edit_visual_x_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_visual_x_btn_minus, ui->screen_spinbox_protocol_edit_visual_x, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_visual_x_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_visual_x_btn_minus, lv_screen_spinbox_protocol_edit_visual_x_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_visual_x, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_visual_x, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_visual_x, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_visual_x, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_visual_x, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_visual_x, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_visual_x, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_visual_x, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_visual_x, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_visual_x, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_visual_x, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_visual_x, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_visual_x, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_visual_x, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_visual_x, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_visual_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_visual_x, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_visual_x, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_visual_x, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_visual_x, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_visual_x, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_visual_x, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_visual_x, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_visual_x, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_visual_x, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_visual_x_btn_plus, &style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_visual_x_btn_minus, &style_screen_spinbox_protocol_edit_visual_x_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_slt1_trig
    ui->screen_spinbox_protocol_edit_slt1_trig = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt1_trig, 500, 457);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt1_trig, 500, 457);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_slt1_trig, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_slt1_trig, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_slt1_trig, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_slt1_trig, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_slt1_trig_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_slt1_trig);
    ui->screen_spinbox_protocol_edit_slt1_trig_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt1_trig, 500, 457);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt1_trig_btn_plus, screen_spinbox_protocol_edit_slt1_trig_h, screen_spinbox_protocol_edit_slt1_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt1_trig_btn_plus, ui->screen_spinbox_protocol_edit_slt1_trig, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt1_trig_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt1_trig_btn_plus, lv_screen_spinbox_protocol_edit_slt1_trig_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_slt1_trig_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt1_trig_btn_minus, screen_spinbox_protocol_edit_slt1_trig_h, screen_spinbox_protocol_edit_slt1_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt1_trig_btn_minus, ui->screen_spinbox_protocol_edit_slt1_trig, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt1_trig_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt1_trig_btn_minus, lv_screen_spinbox_protocol_edit_slt1_trig_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_slt1_trig, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt1_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt1_trig, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt1_trig, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_slt1_trig, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_slt1_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_slt1_trig, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_slt1_trig, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_slt1_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_slt1_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_slt1_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_slt1_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt1_trig, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt1_trig, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt1_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_slt1_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_slt1_trig, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_slt1_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_slt1_trig, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt1_trig, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt1_trig, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt1_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt1_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt1_trig, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt1_trig, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt1_trig_btn_plus, &style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt1_trig_btn_minus, &style_screen_spinbox_protocol_edit_slt1_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_slt2_trig
    ui->screen_spinbox_protocol_edit_slt2_trig = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt2_trig, 500, 509);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt2_trig, 500, 509);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_slt2_trig, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_slt2_trig, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_slt2_trig, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_slt2_trig, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_slt2_trig_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_slt2_trig);
    ui->screen_spinbox_protocol_edit_slt2_trig_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt2_trig, 500, 509);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt2_trig_btn_plus, screen_spinbox_protocol_edit_slt2_trig_h, screen_spinbox_protocol_edit_slt2_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt2_trig_btn_plus, ui->screen_spinbox_protocol_edit_slt2_trig, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt2_trig_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt2_trig_btn_plus, lv_screen_spinbox_protocol_edit_slt2_trig_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_slt2_trig_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt2_trig_btn_minus, screen_spinbox_protocol_edit_slt2_trig_h, screen_spinbox_protocol_edit_slt2_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt2_trig_btn_minus, ui->screen_spinbox_protocol_edit_slt2_trig, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt2_trig_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt2_trig_btn_minus, lv_screen_spinbox_protocol_edit_slt2_trig_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_slt2_trig, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt2_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt2_trig, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt2_trig, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_slt2_trig, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_slt2_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_slt2_trig, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_slt2_trig, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_slt2_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_slt2_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_slt2_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_slt2_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt2_trig, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt2_trig, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt2_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_slt2_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_slt2_trig, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_slt2_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_slt2_trig, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt2_trig, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt2_trig, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt2_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt2_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt2_trig, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt2_trig, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt2_trig_btn_plus, &style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt2_trig_btn_minus, &style_screen_spinbox_protocol_edit_slt2_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_slt3_trig
    ui->screen_spinbox_protocol_edit_slt3_trig = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt3_trig, 500, 561);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt3_trig, 500, 561);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_slt3_trig, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_slt3_trig, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_slt3_trig, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_slt3_trig, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_slt3_trig_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_slt3_trig);
    ui->screen_spinbox_protocol_edit_slt3_trig_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt3_trig, 500, 561);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt3_trig_btn_plus, screen_spinbox_protocol_edit_slt3_trig_h, screen_spinbox_protocol_edit_slt3_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt3_trig_btn_plus, ui->screen_spinbox_protocol_edit_slt3_trig, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt3_trig_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt3_trig_btn_plus, lv_screen_spinbox_protocol_edit_slt3_trig_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_slt3_trig_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt3_trig_btn_minus, screen_spinbox_protocol_edit_slt3_trig_h, screen_spinbox_protocol_edit_slt3_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt3_trig_btn_minus, ui->screen_spinbox_protocol_edit_slt3_trig, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt3_trig_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt3_trig_btn_minus, lv_screen_spinbox_protocol_edit_slt3_trig_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_slt3_trig, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt3_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt3_trig, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt3_trig, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_slt3_trig, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_slt3_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_slt3_trig, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_slt3_trig, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_slt3_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_slt3_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_slt3_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_slt3_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt3_trig, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt3_trig, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt3_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_slt3_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_slt3_trig, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_slt3_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_slt3_trig, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt3_trig, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt3_trig, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt3_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt3_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt3_trig, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt3_trig, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt3_trig_btn_plus, &style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt3_trig_btn_minus, &style_screen_spinbox_protocol_edit_slt3_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_slt4_trig
    ui->screen_spinbox_protocol_edit_slt4_trig = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt4_trig, 500, 613);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt4_trig, 500, 613);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_slt4_trig, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_slt4_trig, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_slt4_trig, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_slt4_trig, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_slt4_trig_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_slt4_trig);
    ui->screen_spinbox_protocol_edit_slt4_trig_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_slt4_trig, 500, 613);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt4_trig_btn_plus, screen_spinbox_protocol_edit_slt4_trig_h, screen_spinbox_protocol_edit_slt4_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt4_trig_btn_plus, ui->screen_spinbox_protocol_edit_slt4_trig, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt4_trig_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt4_trig_btn_plus, lv_screen_spinbox_protocol_edit_slt4_trig_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_slt4_trig_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_slt4_trig_btn_minus, screen_spinbox_protocol_edit_slt4_trig_h, screen_spinbox_protocol_edit_slt4_trig_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_slt4_trig_btn_minus, ui->screen_spinbox_protocol_edit_slt4_trig, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_slt4_trig_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_slt4_trig_btn_minus, lv_screen_spinbox_protocol_edit_slt4_trig_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_slt4_trig, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt4_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt4_trig, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt4_trig, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_slt4_trig, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_slt4_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_slt4_trig, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_slt4_trig, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_slt4_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_slt4_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_slt4_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_slt4_trig, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt4_trig, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt4_trig, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt4_trig, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_slt4_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_slt4_trig, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_slt4_trig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_slt4_trig, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_slt4_trig, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_slt4_trig, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_slt4_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_slt4_trig, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_slt4_trig, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_slt4_trig, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt4_trig_btn_plus, &style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_slt4_trig_btn_minus, &style_screen_spinbox_protocol_edit_slt4_trig_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ddlist_protocol_edit_ref_source
    ui->screen_ddlist_protocol_edit_ref_source = lv_dropdown_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_ddlist_protocol_edit_ref_source, 386, 209);
    lv_obj_set_size(ui->screen_ddlist_protocol_edit_ref_source, 232, 33);
    lv_dropdown_set_options(ui->screen_ddlist_protocol_edit_ref_source, "当前硬件角度\nBB-250314-1920*\nBRG-250315-1920\nBR-250313-1920");

    //Write style for screen_ddlist_protocol_edit_ref_source, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_ddlist_protocol_edit_ref_source, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ddlist_protocol_edit_ref_source, &lv_font_misans_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ddlist_protocol_edit_ref_source, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_ddlist_protocol_edit_ref_source, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ddlist_protocol_edit_ref_source, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ddlist_protocol_edit_ref_source, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ddlist_protocol_edit_ref_source, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ddlist_protocol_edit_ref_source, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ddlist_protocol_edit_ref_source, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ddlist_protocol_edit_ref_source, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ddlist_protocol_edit_ref_source, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ddlist_protocol_edit_ref_source, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ddlist_protocol_edit_ref_source, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_protocol_edit_ref_source, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ddlist_protocol_edit_ref_source, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked
    static lv_style_t style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked;
    ui_init_style(&style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_protocol_edit_ref_source), &style_screen_ddlist_protocol_edit_ref_source_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default
    static lv_style_t style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default;
    ui_init_style(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default);

    lv_style_set_max_height(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, &lv_font_misans_14);
    lv_style_set_text_opa(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_protocol_edit_ref_source), &style_screen_ddlist_protocol_edit_ref_source_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_protocol_edit_ref_source_extra_list_scrollbar_default
    static lv_style_t style_screen_ddlist_protocol_edit_ref_source_extra_list_scrollbar_default;
    ui_init_style(&style_screen_ddlist_protocol_edit_ref_source_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_ddlist_protocol_edit_ref_source_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_protocol_edit_ref_source_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_protocol_edit_ref_source_extra_list_scrollbar_default, lv_color_hex(0x1e1e1e));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_protocol_edit_ref_source_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_protocol_edit_ref_source), &style_screen_ddlist_protocol_edit_ref_source_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_protocol_edit_slot1
    ui->screen_imgbtn_protocol_edit_slot1 = lv_imagebutton_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_imgbtn_protocol_edit_slot1, 696, 457);
    lv_obj_set_size(ui->screen_imgbtn_protocol_edit_slot1, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_protocol_edit_slot1, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot1, LV_IMAGEBUTTON_STATE_RELEASED, &_rocket_launch_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot1, LV_IMAGEBUTTON_STATE_PRESSED, &_rocket_launch_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot1, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_rocket_launch_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot1, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_rocket_launch_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_protocol_edit_slot1_label = lv_label_create(ui->screen_imgbtn_protocol_edit_slot1);
    lv_label_set_text(ui->screen_imgbtn_protocol_edit_slot1_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_protocol_edit_slot1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_protocol_edit_slot1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_protocol_edit_slot1, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_slot1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot1, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_protocol_edit_slot1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_slot1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot1, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_protocol_edit_slot1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot1, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_protocol_edit_slot1, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot1, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot1, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_imgbtn_protocol_edit_slot2
    ui->screen_imgbtn_protocol_edit_slot2 = lv_imagebutton_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_imgbtn_protocol_edit_slot2, 696, 509);
    lv_obj_set_size(ui->screen_imgbtn_protocol_edit_slot2, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_protocol_edit_slot2, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot2, LV_IMAGEBUTTON_STATE_RELEASED, &_rocket_launch_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot2, LV_IMAGEBUTTON_STATE_PRESSED, &_rocket_launch_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot2, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_rocket_launch_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot2, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_rocket_launch_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_protocol_edit_slot2_label = lv_label_create(ui->screen_imgbtn_protocol_edit_slot2);
    lv_label_set_text(ui->screen_imgbtn_protocol_edit_slot2_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_protocol_edit_slot2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_protocol_edit_slot2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_protocol_edit_slot2, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_slot2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot2, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_protocol_edit_slot2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_slot2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot2, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_protocol_edit_slot2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot2, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_protocol_edit_slot2, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot2, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot2, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_imgbtn_protocol_edit_slot4
    ui->screen_imgbtn_protocol_edit_slot4 = lv_imagebutton_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_imgbtn_protocol_edit_slot4, 696, 613);
    lv_obj_set_size(ui->screen_imgbtn_protocol_edit_slot4, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_protocol_edit_slot4, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot4, LV_IMAGEBUTTON_STATE_RELEASED, &_rocket_launch_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot4, LV_IMAGEBUTTON_STATE_PRESSED, &_rocket_launch_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot4, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_rocket_launch_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot4, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_rocket_launch_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_protocol_edit_slot4_label = lv_label_create(ui->screen_imgbtn_protocol_edit_slot4);
    lv_label_set_text(ui->screen_imgbtn_protocol_edit_slot4_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_protocol_edit_slot4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_protocol_edit_slot4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_protocol_edit_slot4, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_slot4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot4, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_protocol_edit_slot4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_slot4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot4, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_protocol_edit_slot4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot4, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_protocol_edit_slot4, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot4, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot4, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_imgbtn_protocol_edit_slot3
    ui->screen_imgbtn_protocol_edit_slot3 = lv_imagebutton_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_imgbtn_protocol_edit_slot3, 696, 561);
    lv_obj_set_size(ui->screen_imgbtn_protocol_edit_slot3, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_protocol_edit_slot3, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot3, LV_IMAGEBUTTON_STATE_RELEASED, &_rocket_launch_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot3, LV_IMAGEBUTTON_STATE_PRESSED, &_rocket_launch_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot3, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_rocket_launch_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_edit_slot3, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_rocket_launch_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_protocol_edit_slot3_label = lv_label_create(ui->screen_imgbtn_protocol_edit_slot3);
    lv_label_set_text(ui->screen_imgbtn_protocol_edit_slot3_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_protocol_edit_slot3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_protocol_edit_slot3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_protocol_edit_slot3, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_slot3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot3, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_protocol_edit_slot3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_edit_slot3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot3, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot3, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_protocol_edit_slot3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_edit_slot3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_edit_slot3, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_edit_slot3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_edit_slot3, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_protocol_edit_slot3, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_edit_slot3, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_edit_slot3, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_label_90
    ui->screen_label_90 = lv_label_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_label_90, 273, 426);
    lv_obj_set_size(ui->screen_label_90, 78, 30);
    lv_label_set_text(ui->screen_label_90, "Yaw偏置");
    lv_label_set_long_mode(ui->screen_label_90, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_90, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_90, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_90, &lv_font_misans_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_90, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_90, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_91
    ui->screen_label_91 = lv_label_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_label_91, 516, 426);
    lv_obj_set_size(ui->screen_label_91, 88, 30);
    lv_label_set_text(ui->screen_label_91, "扳机偏置");
    lv_label_set_long_mode(ui->screen_label_91, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_91, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_91, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_91, &lv_font_misans_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_91, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_91, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_line_8
    ui->screen_line_8 = lv_line_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_line_8, 44, 24);
    lv_obj_set_size(ui->screen_line_8, 28, 30);
    static lv_point_precise_t screen_line_8[] = {{0, 0},{0, 403}};
    lv_line_set_points(ui->screen_line_8, screen_line_8, 2);

    //Write style for screen_line_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_line_8, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_line_8, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_line_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_95
    ui->screen_label_95 = lv_label_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_label_95, 541, 375);
    lv_obj_set_size(ui->screen_label_95, 102, 24);
    lv_label_set_text(ui->screen_label_95, "视觉");
    lv_label_set_long_mode(ui->screen_label_95, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_95, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_95, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_95, &lv_font_misans_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_95, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_95, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_sw_protocol_edit_visual
    ui->screen_sw_protocol_edit_visual = lv_switch_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_sw_protocol_edit_visual, 608, 375);
    lv_obj_set_size(ui->screen_sw_protocol_edit_visual, 46, 23);

    //Write style for screen_sw_protocol_edit_visual, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_protocol_edit_visual, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_protocol_edit_visual, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_protocol_edit_visual, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_protocol_edit_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_protocol_edit_visual, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sw_protocol_edit_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_sw_protocol_edit_visual, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_sw_protocol_edit_visual, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_sw_protocol_edit_visual, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_protocol_edit_visual, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_sw_protocol_edit_visual, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_sw_protocol_edit_visual, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_protocol_edit_visual, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_protocol_edit_visual, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_protocol_edit_visual, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_protocol_edit_visual, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_protocol_edit_visual, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_protocol_edit_yaw_visual
    ui->screen_spinbox_protocol_edit_yaw_visual = lv_spinbox_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_yaw_visual, 534, 262);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_yaw_visual, 534, 262);
    lv_obj_set_width(ui->screen_spinbox_protocol_edit_yaw_visual, 121);
    lv_obj_set_height(ui->screen_spinbox_protocol_edit_yaw_visual, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_protocol_edit_yaw_visual, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_protocol_edit_yaw_visual, -99999999, 99999999);
    int32_t screen_spinbox_protocol_edit_yaw_visual_h = lv_obj_get_height(ui->screen_spinbox_protocol_edit_yaw_visual);
    ui->screen_spinbox_protocol_edit_yaw_visual_btn_plus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_spinbox_protocol_edit_yaw_visual, 534, 262);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_yaw_visual_btn_plus, screen_spinbox_protocol_edit_yaw_visual_h, screen_spinbox_protocol_edit_yaw_visual_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_yaw_visual_btn_plus, ui->screen_spinbox_protocol_edit_yaw_visual, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_yaw_visual_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_yaw_visual_btn_plus, lv_screen_spinbox_protocol_edit_yaw_visual_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_protocol_edit_yaw_visual_btn_minus = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_size(ui->screen_spinbox_protocol_edit_yaw_visual_btn_minus, screen_spinbox_protocol_edit_yaw_visual_h, screen_spinbox_protocol_edit_yaw_visual_h);
    lv_obj_align_to(ui->screen_spinbox_protocol_edit_yaw_visual_btn_minus, ui->screen_spinbox_protocol_edit_yaw_visual, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_protocol_edit_yaw_visual_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_protocol_edit_yaw_visual_btn_minus, lv_screen_spinbox_protocol_edit_yaw_visual_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_protocol_edit_yaw_visual, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_yaw_visual, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_yaw_visual, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_yaw_visual, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_protocol_edit_yaw_visual, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_protocol_edit_yaw_visual, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_protocol_edit_yaw_visual, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_protocol_edit_yaw_visual, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_protocol_edit_yaw_visual, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_protocol_edit_yaw_visual, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_protocol_edit_yaw_visual, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_protocol_edit_yaw_visual, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_yaw_visual, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_yaw_visual, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_yaw_visual, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_protocol_edit_yaw_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_protocol_edit_yaw_visual, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_protocol_edit_yaw_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_protocol_edit_yaw_visual, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_protocol_edit_yaw_visual, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_protocol_edit_yaw_visual, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_protocol_edit_yaw_visual, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_protocol_edit_yaw_visual, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_protocol_edit_yaw_visual, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_protocol_edit_yaw_visual, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default
    static lv_style_t style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_yaw_visual_btn_plus, &style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_protocol_edit_yaw_visual_btn_minus, &style_screen_spinbox_protocol_edit_yaw_visual_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_protocol_edit_del
    ui->screen_btn_protocol_edit_del = lv_button_create(ui->screen_cont_protocol_edit);
    lv_obj_set_pos(ui->screen_btn_protocol_edit_del, 600, 141);
    lv_obj_set_size(ui->screen_btn_protocol_edit_del, 78, 42);
    ui->screen_btn_protocol_edit_del_label = lv_label_create(ui->screen_btn_protocol_edit_del);
    lv_label_set_text(ui->screen_btn_protocol_edit_del_label, "删除");
    lv_label_set_long_mode(ui->screen_btn_protocol_edit_del_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_protocol_edit_del_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_protocol_edit_del, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_protocol_edit_del_label, LV_PCT(100));

    //Write style for screen_btn_protocol_edit_del, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_protocol_edit_del, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_protocol_edit_del, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_protocol_edit_del, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_protocol_edit_del, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_protocol_edit_del, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_protocol_edit_del, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_protocol_edit_del, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_protocol_edit_del, &lv_font_misans_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_protocol_edit_del, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_protocol_edit_del, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_protocol_slot
    ui->screen_cont_protocol_slot = lv_obj_create(ui->screen_tabview_tab_2);
    lv_obj_set_pos(ui->screen_cont_protocol_slot, 154, 90);
    lv_obj_set_size(ui->screen_cont_protocol_slot, 580, 243);
    lv_obj_set_scrollbar_mode(ui->screen_cont_protocol_slot, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_add_flag(ui->screen_cont_protocol_slot, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_cont_protocol_slot, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui->screen_cont_protocol_slot, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_cont_protocol_slot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_protocol_slot, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_protocol_slot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_protocol_slot, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_protocol_slot, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_protocol_slot, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_protocol_slot, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_protocol_slot, 127, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_protocol_slot, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_88
    ui->screen_label_88 = lv_label_create(ui->screen_cont_protocol_slot);
    lv_obj_set_pos(ui->screen_label_88, 63, 98);
    lv_obj_set_size(ui->screen_label_88, 102, 29);
    lv_label_set_text(ui->screen_label_88, "制导镖");
    lv_label_set_long_mode(ui->screen_label_88, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_88, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_88, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_88, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_88, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_88, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_protocol_slot
    ui->screen_label_protocol_slot = lv_label_create(ui->screen_cont_protocol_slot);
    lv_obj_set_pos(ui->screen_label_protocol_slot, 57, 29);
    lv_obj_set_size(ui->screen_label_protocol_slot, 193, 36);
    lv_label_set_text(ui->screen_label_protocol_slot, "槽位1高级设置");
    lv_label_set_long_mode(ui->screen_label_protocol_slot, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_protocol_slot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_protocol_slot, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_protocol_slot, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_protocol_slot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_protocol_slot, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_protocol_slot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_line_7
    ui->screen_line_7 = lv_line_create(ui->screen_cont_protocol_slot);
    lv_obj_set_pos(ui->screen_line_7, 44, 22);
    lv_obj_set_size(ui->screen_line_7, 28, 30);
    static lv_point_precise_t screen_line_7[] = {{0, 0},{0, 403}};
    lv_line_set_points(ui->screen_line_7, screen_line_7, 2);

    //Write style for screen_line_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_line_7, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_line_7, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_line_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_sw_protocol_slot_guided_dart
    ui->screen_sw_protocol_slot_guided_dart = lv_switch_create(ui->screen_cont_protocol_slot);
    lv_obj_set_pos(ui->screen_sw_protocol_slot_guided_dart, 181, 100);
    lv_obj_set_size(ui->screen_sw_protocol_slot_guided_dart, 46, 23);

    //Write style for screen_sw_protocol_slot_guided_dart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_protocol_slot_guided_dart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_protocol_slot_guided_dart, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_protocol_slot_guided_dart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_protocol_slot_guided_dart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_protocol_slot_guided_dart, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sw_protocol_slot_guided_dart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_sw_protocol_slot_guided_dart, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_sw_protocol_slot_guided_dart, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_sw_protocol_slot_guided_dart, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_protocol_slot_guided_dart, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_sw_protocol_slot_guided_dart, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_sw_protocol_slot_guided_dart, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_protocol_slot_guided_dart, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_protocol_slot_guided_dart, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_protocol_slot_guided_dart, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_protocol_slot_guided_dart, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_protocol_slot_guided_dart, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_btn_protocol_slot_save
    ui->screen_btn_protocol_slot_save = lv_button_create(ui->screen_cont_protocol_slot);
    lv_obj_set_pos(ui->screen_btn_protocol_slot_save, 439, 22);
    lv_obj_set_size(ui->screen_btn_protocol_slot_save, 100, 44);
    ui->screen_btn_protocol_slot_save_label = lv_label_create(ui->screen_btn_protocol_slot_save);
    lv_label_set_text(ui->screen_btn_protocol_slot_save_label, "完成");
    lv_label_set_long_mode(ui->screen_btn_protocol_slot_save_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_protocol_slot_save_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_protocol_slot_save, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_protocol_slot_save_label, LV_PCT(100));

    //Write style for screen_btn_protocol_slot_save, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_protocol_slot_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_protocol_slot_save, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_protocol_slot_save, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_protocol_slot_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_protocol_slot_save, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_protocol_slot_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_protocol_slot_save, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_protocol_slot_save, &lv_font_misans_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_protocol_slot_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_protocol_slot_save, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ta_protocol_slot_dart_id
    ui->screen_ta_protocol_slot_dart_id = lv_textarea_create(ui->screen_cont_protocol_slot);
    lv_obj_set_pos(ui->screen_ta_protocol_slot_dart_id, 179, 145);
    lv_obj_set_size(ui->screen_ta_protocol_slot_dart_id, 325, 53);
    lv_textarea_set_text(ui->screen_ta_protocol_slot_dart_id, "dart-flysys-");
    lv_textarea_set_placeholder_text(ui->screen_ta_protocol_slot_dart_id, "");
    lv_textarea_set_password_bullet(ui->screen_ta_protocol_slot_dart_id, "*");
    lv_textarea_set_password_mode(ui->screen_ta_protocol_slot_dart_id, false);
    lv_textarea_set_one_line(ui->screen_ta_protocol_slot_dart_id, true);
    lv_textarea_set_accepted_chars(ui->screen_ta_protocol_slot_dart_id, "");
    lv_textarea_set_max_length(ui->screen_ta_protocol_slot_dart_id, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_ta_protocol_slot_dart_id, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_ta_protocol_slot_dart_id, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_ta_protocol_slot_dart_id, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ta_protocol_slot_dart_id, &lv_font_misans_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ta_protocol_slot_dart_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_ta_protocol_slot_dart_id, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_ta_protocol_slot_dart_id, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ta_protocol_slot_dart_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ta_protocol_slot_dart_id, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ta_protocol_slot_dart_id, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_ta_protocol_slot_dart_id, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ta_protocol_slot_dart_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ta_protocol_slot_dart_id, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ta_protocol_slot_dart_id, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ta_protocol_slot_dart_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ta_protocol_slot_dart_id, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ta_protocol_slot_dart_id, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ta_protocol_slot_dart_id, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ta_protocol_slot_dart_id, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_ta_protocol_slot_dart_id, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_ta_protocol_slot_dart_id, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ta_protocol_slot_dart_id, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ta_protocol_slot_dart_id, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ta_protocol_slot_dart_id, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_label_89
    ui->screen_label_89 = lv_label_create(ui->screen_cont_protocol_slot);
    lv_obj_set_pos(ui->screen_label_89, 63, 156);
    lv_obj_set_size(ui->screen_label_89, 96, 29);
    lv_label_set_text(ui->screen_label_89, "飞镖ID");
    lv_label_set_long_mode(ui->screen_label_89, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_89, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_89, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_89, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_89, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_89, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_sw_protocol_slot_id_first
    ui->screen_sw_protocol_slot_id_first = lv_switch_create(ui->screen_cont_protocol_slot);
    lv_obj_set_pos(ui->screen_sw_protocol_slot_id_first, 403, 99);
    lv_obj_set_size(ui->screen_sw_protocol_slot_id_first, 46, 23);

    //Write style for screen_sw_protocol_slot_id_first, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_protocol_slot_id_first, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_protocol_slot_id_first, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_protocol_slot_id_first, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_protocol_slot_id_first, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_protocol_slot_id_first, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sw_protocol_slot_id_first, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_sw_protocol_slot_id_first, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_sw_protocol_slot_id_first, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_sw_protocol_slot_id_first, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_protocol_slot_id_first, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_sw_protocol_slot_id_first, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_sw_protocol_slot_id_first, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_protocol_slot_id_first, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_protocol_slot_id_first, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_protocol_slot_id_first, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_protocol_slot_id_first, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_protocol_slot_id_first, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_label_92
    ui->screen_label_92 = lv_label_create(ui->screen_cont_protocol_slot);
    lv_obj_set_pos(ui->screen_label_92, 297, 97);
    lv_obj_set_size(ui->screen_label_92, 102, 29);
    lv_label_set_text(ui->screen_label_92, "ID优先");
    lv_label_set_long_mode(ui->screen_label_92, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_92, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_92, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_92, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_92, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_92, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_protocol_save
    ui->screen_cont_protocol_save = lv_obj_create(ui->screen_tabview_tab_2);
    lv_obj_set_pos(ui->screen_cont_protocol_save, 734, -3);
    lv_obj_set_size(ui->screen_cont_protocol_save, 170, 166);
    lv_obj_set_scrollbar_mode(ui->screen_cont_protocol_save, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_cont_protocol_save, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for screen_cont_protocol_save, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_protocol_save, 132, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_protocol_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_protocol_save, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_protocol_save, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_protocol_save, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_protocol_save, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_protocol_save, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_protocol_save, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_protocol_save
    ui->screen_label_protocol_save = lv_label_create(ui->screen_cont_protocol_save);
    lv_obj_set_pos(ui->screen_label_protocol_save, 20, 99);
    lv_obj_set_size(ui->screen_label_protocol_save, 134, 29);
    lv_label_set_text(ui->screen_label_protocol_save, "保存");
    lv_label_set_long_mode(ui->screen_label_protocol_save, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_protocol_save, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_protocol_save, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_protocol_save, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_protocol_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_protocol_save, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_protocol_save
    ui->screen_imgbtn_protocol_save = lv_imagebutton_create(ui->screen_cont_protocol_save);
    lv_obj_set_pos(ui->screen_imgbtn_protocol_save, 57, 34);
    lv_obj_set_size(ui->screen_imgbtn_protocol_save, 60, 60);
    lv_obj_add_flag(ui->screen_imgbtn_protocol_save, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_save, LV_IMAGEBUTTON_STATE_RELEASED, &_upload_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_save, LV_IMAGEBUTTON_STATE_PRESSED, &_upload_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_save, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_upload_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_protocol_save, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_upload_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    ui->screen_imgbtn_protocol_save_label = lv_label_create(ui->screen_imgbtn_protocol_save);
    lv_label_set_text(ui->screen_imgbtn_protocol_save_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_protocol_save_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_protocol_save_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_protocol_save, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_save, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_save, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_save, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_protocol_save, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_protocol_save, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_save, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_save, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_save, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_save, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_save, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_save, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_protocol_save, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_save, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_save, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_protocol_save, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_protocol_save, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_protocol_save, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_protocol_save, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_protocol_save, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_protocol_save, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_protocol_save, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes 视觉
    ui->screen_tabview_tab_3 = lv_tabview_add_tab(ui->screen_tabview,"视觉");
    lv_obj_t * screen_tabview_tab_3_label = lv_label_create(ui->screen_tabview_tab_3);
    lv_label_set_text(screen_tabview_tab_3_label, "");

    //Write codes screen_canvas_camera
    LV_DRAW_BUF_DEFINE(draw_buf, 800, 450, LV_COLOR_FORMAT_NATIVE);
    ui->screen_canvas_camera = lv_canvas_create(ui->screen_tabview_tab_3);
    lv_obj_set_pos(ui->screen_canvas_camera, 41, 9);
    lv_obj_set_size(ui->screen_canvas_camera, 800, 450);
    lv_obj_set_scrollbar_mode(ui->screen_canvas_camera, LV_SCROLLBAR_MODE_OFF);
    lv_canvas_set_draw_buf(ui->screen_canvas_camera, &draw_buf);
    lv_canvas_fill_bg(ui->screen_canvas_camera, lv_color_hex(0xffffff), 255);

    lv_layer_t layer_screen_canvas_camera;
    lv_canvas_init_layer(ui->screen_canvas_camera, &layer_screen_canvas_camera);
    lv_canvas_finish_layer(ui->screen_canvas_camera, &layer_screen_canvas_camera);

    //Write codes screen_cont_vision
    ui->screen_cont_vision = lv_obj_create(ui->screen_tabview_tab_3);
    lv_obj_set_pos(ui->screen_cont_vision, 867, 7);
    lv_obj_set_size(ui->screen_cont_vision, 521, 224);
    lv_obj_set_scrollbar_mode(ui->screen_cont_vision, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_add_flag(ui->screen_cont_vision, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for screen_cont_vision, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_vision, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_vision, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_vision, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_vision, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_vision, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_vision, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_vision, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_vision, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_vision, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_vision, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_vision, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_vision, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_vision, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_vision, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_vision, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_108
    ui->screen_label_108 = lv_label_create(ui->screen_cont_vision);
    lv_obj_set_pos(ui->screen_label_108, 63, 91);
    lv_obj_set_size(ui->screen_label_108, 176, 30);
    lv_label_set_text(ui->screen_label_108, "曝光");
    lv_label_set_long_mode(ui->screen_label_108, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_108, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_108, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_108, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_108, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_108, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_107
    ui->screen_label_107 = lv_label_create(ui->screen_cont_vision);
    lv_obj_set_pos(ui->screen_label_107, 57, 29);
    lv_obj_set_size(ui->screen_label_107, 126, 36);
    lv_label_set_text(ui->screen_label_107, "视觉参数");
    lv_label_set_long_mode(ui->screen_label_107, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_107, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_107, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_107, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_107, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_107, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_vision_exposure_reset
    ui->screen_imgbtn_vision_exposure_reset = lv_imagebutton_create(ui->screen_cont_vision);
    lv_obj_set_pos(ui->screen_imgbtn_vision_exposure_reset, 416, 83);
    lv_obj_set_size(ui->screen_imgbtn_vision_exposure_reset, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_vision_exposure_reset, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_vision_exposure_reset, LV_IMAGEBUTTON_STATE_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_vision_exposure_reset, LV_IMAGEBUTTON_STATE_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_vision_exposure_reset, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_vision_exposure_reset, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_vision_exposure_reset_label = lv_label_create(ui->screen_imgbtn_vision_exposure_reset);
    lv_label_set_text(ui->screen_imgbtn_vision_exposure_reset_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_vision_exposure_reset_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_vision_exposure_reset_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_vision_exposure_reset, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_vision_exposure_reset, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_vision_exposure_reset, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_vision_exposure_reset, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_vision_exposure_reset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_vision_exposure_reset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_vision_exposure_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_vision_exposure_reset, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_vision_exposure_reset, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_vision_exposure_reset, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_vision_exposure_reset, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_vision_exposure_reset, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_vision_exposure_reset, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_vision_exposure_reset, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_vision_exposure_reset, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_vision_exposure_reset, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_vision_exposure_reset, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_vision_exposure_reset, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_vision_exposure_reset, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_vision_exposure_reset, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_vision_exposure_reset, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_vision_exposure_reset, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_vision_exposure_reset, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_vision_exposure_reset, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_line_10
    ui->screen_line_10 = lv_line_create(ui->screen_cont_vision);
    lv_obj_set_pos(ui->screen_line_10, 44, 24);
    lv_obj_set_size(ui->screen_line_10, 28, 26);
    static lv_point_precise_t screen_line_10[] = {{0, 0},{0, 403}};
    lv_line_set_points(ui->screen_line_10, screen_line_10, 2);

    //Write style for screen_line_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_line_10, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_line_10, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_line_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_spinbox_vision_exposure
    ui->screen_spinbox_vision_exposure = lv_spinbox_create(ui->screen_cont_vision);
    lv_obj_set_pos(ui->screen_spinbox_vision_exposure, 223, 84);
    lv_obj_set_pos(ui->screen_spinbox_vision_exposure, 223, 84);
    lv_obj_set_width(ui->screen_spinbox_vision_exposure, 108);
    lv_obj_set_height(ui->screen_spinbox_vision_exposure, 40);
    lv_spinbox_set_digit_format(ui->screen_spinbox_vision_exposure, 3, 1);
    lv_spinbox_set_range(ui->screen_spinbox_vision_exposure, -999, 999);
    int32_t screen_spinbox_vision_exposure_h = lv_obj_get_height(ui->screen_spinbox_vision_exposure);
    ui->screen_spinbox_vision_exposure_btn_plus = lv_button_create(ui->screen_cont_vision);
    lv_obj_set_pos(ui->screen_spinbox_vision_exposure, 223, 84);
    lv_obj_set_size(ui->screen_spinbox_vision_exposure_btn_plus, screen_spinbox_vision_exposure_h, screen_spinbox_vision_exposure_h);
    lv_obj_align_to(ui->screen_spinbox_vision_exposure_btn_plus, ui->screen_spinbox_vision_exposure, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_vision_exposure_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_vision_exposure_btn_plus, lv_screen_spinbox_vision_exposure_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_vision_exposure_btn_minus = lv_button_create(ui->screen_cont_vision);
    lv_obj_set_size(ui->screen_spinbox_vision_exposure_btn_minus, screen_spinbox_vision_exposure_h, screen_spinbox_vision_exposure_h);
    lv_obj_align_to(ui->screen_spinbox_vision_exposure_btn_minus, ui->screen_spinbox_vision_exposure, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_vision_exposure_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_vision_exposure_btn_minus, lv_screen_spinbox_vision_exposure_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_vision_exposure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_vision_exposure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_vision_exposure, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_vision_exposure, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_vision_exposure, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_vision_exposure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_vision_exposure, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_vision_exposure, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_vision_exposure, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_vision_exposure, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_vision_exposure, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_vision_exposure, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_vision_exposure, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_vision_exposure, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_vision_exposure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_vision_exposure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_vision_exposure, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_vision_exposure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_vision_exposure, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_vision_exposure, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_vision_exposure, &lv_font_misans_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_vision_exposure, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_vision_exposure, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_vision_exposure, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_vision_exposure, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_vision_exposure_extra_btns_main_default
    static lv_style_t style_screen_spinbox_vision_exposure_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_vision_exposure_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_vision_exposure_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_vision_exposure_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_vision_exposure_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_vision_exposure_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_vision_exposure_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_vision_exposure_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_vision_exposure_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_vision_exposure_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_vision_exposure_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_vision_exposure_btn_plus, &style_screen_spinbox_vision_exposure_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_vision_exposure_btn_minus, &style_screen_spinbox_vision_exposure_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_110
    ui->screen_label_110 = lv_label_create(ui->screen_cont_vision);
    lv_obj_set_pos(ui->screen_label_110, 63, 158);
    lv_obj_set_size(ui->screen_label_110, 158, 36);
    lv_label_set_text(ui->screen_label_110, "制导目标");
    lv_label_set_long_mode(ui->screen_label_110, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_110, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_110, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_110, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_110, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_110, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_vision_target
    ui->screen_label_vision_target = lv_label_create(ui->screen_cont_vision);
    lv_obj_set_pos(ui->screen_label_vision_target, 238, 159);
    lv_obj_set_size(ui->screen_label_vision_target, 266, 36);
    lv_label_set_text(ui->screen_label_vision_target, "N/A");
    lv_label_set_long_mode(ui->screen_label_vision_target, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_vision_target, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_vision_target, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_vision_target, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_vision_target, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_vision_target, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_vision_target, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_vision_target_edit
    ui->screen_imgbtn_vision_target_edit = lv_imagebutton_create(ui->screen_cont_vision);
    lv_obj_set_pos(ui->screen_imgbtn_vision_target_edit, 186, 151);
    lv_obj_set_size(ui->screen_imgbtn_vision_target_edit, 40, 40);
    lv_obj_add_flag(ui->screen_imgbtn_vision_target_edit, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_vision_target_edit, LV_IMAGEBUTTON_STATE_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_vision_target_edit, LV_IMAGEBUTTON_STATE_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_vision_target_edit, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_edit_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_vision_target_edit, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_edit_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40, NULL, NULL);
    ui->screen_imgbtn_vision_target_edit_label = lv_label_create(ui->screen_imgbtn_vision_target_edit);
    lv_label_set_text(ui->screen_imgbtn_vision_target_edit_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_vision_target_edit_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_vision_target_edit_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_vision_target_edit, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_vision_target_edit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_vision_target_edit, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_vision_target_edit, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_vision_target_edit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_vision_target_edit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_vision_target_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_vision_target_edit, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_vision_target_edit, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_vision_target_edit, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_vision_target_edit, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_vision_target_edit, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_vision_target_edit, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_vision_target_edit, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_vision_target_edit, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_vision_target_edit, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_vision_target_edit, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_vision_target_edit, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_vision_target_edit, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_vision_target_edit, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_vision_target_edit, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_vision_target_edit, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_vision_target_edit, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_vision_target_edit, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_cont_banner
    ui->screen_cont_banner = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_banner, 35, 23);
    lv_obj_set_size(ui->screen_cont_banner, 469, 108);
    lv_obj_set_scrollbar_mode(ui->screen_cont_banner, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_cont_banner, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_cont_banner, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_cont_banner, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_banner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_banner, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_banner, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_banner, lv_color_hex(0xf5ffb9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_banner, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_banner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_banner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_banner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_banner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_banner, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_banner, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_banner, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_banner, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_banner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_banner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_banner_title
    ui->screen_label_banner_title = lv_label_create(ui->screen_cont_banner);
    lv_obj_set_pos(ui->screen_label_banner_title, 59, 25);
    lv_obj_set_size(ui->screen_label_banner_title, 125, 22);
    lv_label_set_text(ui->screen_label_banner_title, "异常");
    lv_label_set_long_mode(ui->screen_label_banner_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_banner_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_banner_title, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_banner_title, &lv_font_misans_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_banner_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_banner_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_banner_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_line_3
    ui->screen_line_3 = lv_line_create(ui->screen_cont_banner);
    lv_obj_set_pos(ui->screen_line_3, 36, 14);
    lv_obj_set_size(ui->screen_line_3, 27, 61);
    static lv_point_precise_t screen_line_3[] = {{0, 0},{0, 80}};
    lv_line_set_points(ui->screen_line_3, screen_line_3, 2);

    //Write style for screen_line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_line_3, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_line_3, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_line_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_banner_info
    ui->screen_label_banner_info = lv_label_create(ui->screen_cont_banner);
    lv_obj_set_pos(ui->screen_label_banner_info, 59, 56);
    lv_obj_set_size(ui->screen_label_banner_info, 378, 25);
    lv_label_set_text(ui->screen_label_banner_info, "下位机/Yaw轴/Pitch轴/左装填/右装填/扳机轴电机/裁判系统/遥控器离线");
    lv_label_set_long_mode(ui->screen_label_banner_info, LV_LABEL_LONG_SCROLL);

    //Write style for screen_label_banner_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_banner_info, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_banner_info, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_banner_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_banner_info, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_banner_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_settings
    ui->screen_cont_settings = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_settings, 195, 80);
    lv_obj_set_size(ui->screen_cont_settings, 633, 411);
    lv_obj_set_scrollbar_mode(ui->screen_cont_settings, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_add_flag(ui->screen_cont_settings, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_cont_settings, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui->screen_cont_settings, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_cont_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_settings, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_settings, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_settings, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_settings, 127, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_settings, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_76
    ui->screen_label_76 = lv_label_create(ui->screen_cont_settings);
    lv_obj_set_pos(ui->screen_label_76, 53, 109);
    lv_obj_set_size(ui->screen_label_76, 173, 29);
    lv_label_set_text(ui->screen_label_76, "自动协议生成");
    lv_label_set_long_mode(ui->screen_label_76, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_76, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_76, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_76, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_76, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_76, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_73
    ui->screen_label_73 = lv_label_create(ui->screen_cont_settings);
    lv_obj_set_pos(ui->screen_label_73, 57, 29);
    lv_obj_set_size(ui->screen_label_73, 84, 36);
    lv_label_set_text(ui->screen_label_73, "设置");
    lv_label_set_long_mode(ui->screen_label_73, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_73, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_73, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_73, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_73, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_73, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_line_6
    ui->screen_line_6 = lv_line_create(ui->screen_cont_settings);
    lv_obj_set_pos(ui->screen_line_6, 44, 22);
    lv_obj_set_size(ui->screen_line_6, 28, 30);
    static lv_point_precise_t screen_line_6[] = {{0, 0},{0, 403}};
    lv_line_set_points(ui->screen_line_6, screen_line_6, 2);

    //Write style for screen_line_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_line_6, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_line_6, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_line_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_sw_settings_protocol_generate
    ui->screen_sw_settings_protocol_generate = lv_switch_create(ui->screen_cont_settings);
    lv_obj_set_pos(ui->screen_sw_settings_protocol_generate, 247, 111);
    lv_obj_set_size(ui->screen_sw_settings_protocol_generate, 46, 23);

    //Write style for screen_sw_settings_protocol_generate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_settings_protocol_generate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_settings_protocol_generate, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_settings_protocol_generate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_settings_protocol_generate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_settings_protocol_generate, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sw_settings_protocol_generate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_sw_settings_protocol_generate, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_sw_settings_protocol_generate, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_sw_settings_protocol_generate, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_settings_protocol_generate, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_sw_settings_protocol_generate, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_sw_settings_protocol_generate, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_settings_protocol_generate, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_settings_protocol_generate, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_settings_protocol_generate, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_settings_protocol_generate, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_settings_protocol_generate, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_btn_settings_exit
    ui->screen_btn_settings_exit = lv_button_create(ui->screen_cont_settings);
    lv_obj_set_pos(ui->screen_btn_settings_exit, 497, 19);
    lv_obj_set_size(ui->screen_btn_settings_exit, 100, 44);
    ui->screen_btn_settings_exit_label = lv_label_create(ui->screen_btn_settings_exit);
    lv_label_set_text(ui->screen_btn_settings_exit_label, "完成");
    lv_label_set_long_mode(ui->screen_btn_settings_exit_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_settings_exit_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_settings_exit, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_settings_exit_label, LV_PCT(100));

    //Write style for screen_btn_settings_exit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_settings_exit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_settings_exit, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_settings_exit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_settings_exit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_settings_exit, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_settings_exit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_settings_exit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_settings_exit, &lv_font_misans_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_settings_exit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_settings_exit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_settings_shortcuts
    ui->screen_cont_settings_shortcuts = lv_obj_create(ui->screen_cont_settings);
    lv_obj_set_pos(ui->screen_cont_settings_shortcuts, 51, 214);
    lv_obj_set_size(ui->screen_cont_settings_shortcuts, 537, 157);
    lv_obj_set_scrollbar_mode(ui->screen_cont_settings_shortcuts, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_cont_settings_shortcuts, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for screen_cont_settings_shortcuts, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_settings_shortcuts, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_settings_shortcuts, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_settings_shortcuts, lv_color_hex(0x4a4a4a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_settings_shortcuts, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_settings_shortcuts, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_settings_shortcuts, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_settings_shortcuts, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_settings_shortcuts, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_settings_shortcuts, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_settings_shortcuts, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_settings_shortcuts, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_settings_shortcuts, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_settings_shortcuts, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_settings_shortcuts_reboot
    ui->screen_imgbtn_settings_shortcuts_reboot = lv_imagebutton_create(ui->screen_cont_settings_shortcuts);
    lv_obj_set_pos(ui->screen_imgbtn_settings_shortcuts_reboot, 66, 28);
    lv_obj_set_size(ui->screen_imgbtn_settings_shortcuts_reboot, 60, 60);
    lv_obj_add_flag(ui->screen_imgbtn_settings_shortcuts_reboot, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_reboot, LV_IMAGEBUTTON_STATE_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_reboot, LV_IMAGEBUTTON_STATE_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_reboot, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_reboot, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    ui->screen_imgbtn_settings_shortcuts_reboot_label = lv_label_create(ui->screen_imgbtn_settings_shortcuts_reboot);
    lv_label_set_text(ui->screen_imgbtn_settings_shortcuts_reboot_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_settings_shortcuts_reboot_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_settings_shortcuts_reboot_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_settings_shortcuts_reboot, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_settings_shortcuts_reboot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_settings_shortcuts_reboot, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_settings_shortcuts_reboot, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_settings_shortcuts_reboot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_settings_shortcuts_reboot, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_settings_shortcuts_reboot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_settings_shortcuts_reboot, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_settings_shortcuts_reboot, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_settings_shortcuts_reboot, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_settings_shortcuts_reboot, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_settings_shortcuts_reboot, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_settings_shortcuts_reboot, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_settings_shortcuts_reboot, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_settings_shortcuts_reboot, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_settings_shortcuts_reboot, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_settings_shortcuts_reboot, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_settings_shortcuts_reboot, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_settings_shortcuts_reboot, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_settings_shortcuts_reboot, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_settings_shortcuts_reboot, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_settings_shortcuts_reboot, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_settings_shortcuts_reboot, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_settings_shortcuts_reboot, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_label_79
    ui->screen_label_79 = lv_label_create(ui->screen_cont_settings_shortcuts);
    lv_obj_set_pos(ui->screen_label_79, 28, 98);
    lv_obj_set_size(ui->screen_label_79, 134, 29);
    lv_label_set_text(ui->screen_label_79, "重启");
    lv_label_set_long_mode(ui->screen_label_79, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_79, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_79, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_79, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_79, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_79, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_78
    ui->screen_label_78 = lv_label_create(ui->screen_cont_settings_shortcuts);
    lv_obj_set_pos(ui->screen_label_78, 181, 99);
    lv_obj_set_size(ui->screen_label_78, 134, 29);
    lv_label_set_text(ui->screen_label_78, "连接热点");
    lv_label_set_long_mode(ui->screen_label_78, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_78, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_78, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_78, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_78, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_78, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_settings_shortcuts_ap
    ui->screen_imgbtn_settings_shortcuts_ap = lv_imagebutton_create(ui->screen_cont_settings_shortcuts);
    lv_obj_set_pos(ui->screen_imgbtn_settings_shortcuts_ap, 218, 28);
    lv_obj_set_size(ui->screen_imgbtn_settings_shortcuts_ap, 60, 60);
    lv_obj_add_flag(ui->screen_imgbtn_settings_shortcuts_ap, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_ap, LV_IMAGEBUTTON_STATE_RELEASED, &_cell_tower_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_ap, LV_IMAGEBUTTON_STATE_PRESSED, &_cell_tower_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_ap, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_cell_tower_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_ap, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_cell_tower_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    ui->screen_imgbtn_settings_shortcuts_ap_label = lv_label_create(ui->screen_imgbtn_settings_shortcuts_ap);
    lv_label_set_text(ui->screen_imgbtn_settings_shortcuts_ap_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_settings_shortcuts_ap_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_settings_shortcuts_ap_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_settings_shortcuts_ap, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_settings_shortcuts_ap, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_settings_shortcuts_ap, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_settings_shortcuts_ap, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_settings_shortcuts_ap, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_settings_shortcuts_ap, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_settings_shortcuts_ap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_settings_shortcuts_ap, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_settings_shortcuts_ap, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_settings_shortcuts_ap, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_settings_shortcuts_ap, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_settings_shortcuts_ap, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_settings_shortcuts_ap, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_settings_shortcuts_ap, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_settings_shortcuts_ap, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_settings_shortcuts_ap, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_settings_shortcuts_ap, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_settings_shortcuts_ap, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_settings_shortcuts_ap, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_settings_shortcuts_ap, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_settings_shortcuts_ap, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_settings_shortcuts_ap, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_settings_shortcuts_ap, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_settings_shortcuts_ap, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_label_77
    ui->screen_label_77 = lv_label_create(ui->screen_cont_settings_shortcuts);
    lv_obj_set_pos(ui->screen_label_77, 333, 99);
    lv_obj_set_size(ui->screen_label_77, 134, 29);
    lv_label_set_text(ui->screen_label_77, "图形界面");
    lv_label_set_long_mode(ui->screen_label_77, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_77, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_77, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_77, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_77, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_77, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_settings_shortcuts_graphic
    ui->screen_imgbtn_settings_shortcuts_graphic = lv_imagebutton_create(ui->screen_cont_settings_shortcuts);
    lv_obj_set_pos(ui->screen_imgbtn_settings_shortcuts_graphic, 370, 28);
    lv_obj_set_size(ui->screen_imgbtn_settings_shortcuts_graphic, 60, 60);
    lv_obj_add_flag(ui->screen_imgbtn_settings_shortcuts_graphic, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_graphic, LV_IMAGEBUTTON_STATE_RELEASED, &_desktop_windows_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_graphic, LV_IMAGEBUTTON_STATE_PRESSED, &_desktop_windows_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_graphic, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_desktop_windows_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_settings_shortcuts_graphic, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_desktop_windows_24dp_904E29_FILL0_wght400_GRAD0_opsz24_RGB565A8_60x60, NULL, NULL);
    ui->screen_imgbtn_settings_shortcuts_graphic_label = lv_label_create(ui->screen_imgbtn_settings_shortcuts_graphic);
    lv_label_set_text(ui->screen_imgbtn_settings_shortcuts_graphic_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_settings_shortcuts_graphic_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_settings_shortcuts_graphic_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_settings_shortcuts_graphic, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_settings_shortcuts_graphic, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_settings_shortcuts_graphic, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_settings_shortcuts_graphic, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_settings_shortcuts_graphic, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_settings_shortcuts_graphic, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_settings_shortcuts_graphic, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_settings_shortcuts_graphic, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_settings_shortcuts_graphic, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_settings_shortcuts_graphic, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_settings_shortcuts_graphic, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_settings_shortcuts_graphic, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_settings_shortcuts_graphic, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_settings_shortcuts_graphic, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_settings_shortcuts_graphic, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_settings_shortcuts_graphic, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_settings_shortcuts_graphic, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_settings_shortcuts_graphic, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_settings_shortcuts_graphic, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_settings_shortcuts_graphic, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_settings_shortcuts_graphic, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_settings_shortcuts_graphic, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_settings_shortcuts_graphic, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_settings_shortcuts_graphic, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_label_80
    ui->screen_label_80 = lv_label_create(ui->screen_cont_settings);
    lv_obj_set_pos(ui->screen_label_80, 52, 166);
    lv_obj_set_size(ui->screen_label_80, 173, 29);
    lv_label_set_text(ui->screen_label_80, "系统操作\n");
    lv_label_set_long_mode(ui->screen_label_80, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_80, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_80, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_80, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_80, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_80, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_settings_ip
    ui->screen_label_settings_ip = lv_label_create(ui->screen_cont_settings);
    lv_obj_set_pos(ui->screen_label_settings_ip, 154, 29);
    lv_obj_set_size(ui->screen_label_settings_ip, 173, 29);
    lv_label_set_text(ui->screen_label_settings_ip, "IP: N/A");
    lv_label_set_long_mode(ui->screen_label_settings_ip, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_settings_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_settings_ip, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_settings_ip, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_settings_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_settings_ip, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_settings_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_notification_1
    ui->screen_cont_notification_1 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_notification_1, 295, -90);
    lv_obj_set_size(ui->screen_cont_notification_1, 437, 70);
    lv_obj_set_scrollbar_mode(ui->screen_cont_notification_1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_cont_notification_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_cont_notification_1, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_cont_notification_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_notification_1, 57, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_notification_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_notification_1, lv_color_hex(0xf5ffb9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_notification_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_notification_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_notification_1, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_notification_1, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_notification_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_notification_1
    ui->screen_label_notification_1 = lv_label_create(ui->screen_cont_notification_1);
    lv_obj_set_pos(ui->screen_label_notification_1, 77, 22);
    lv_obj_set_size(ui->screen_label_notification_1, 329, 25);
    lv_label_set_text(ui->screen_label_notification_1, "协议已写入");
    lv_label_set_long_mode(ui->screen_label_notification_1, LV_LABEL_LONG_SCROLL);

    //Write style for screen_label_notification_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_notification_1, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_notification_1, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_notification_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_notification_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_notification_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_2
    ui->screen_img_2 = lv_image_create(ui->screen_cont_notification_1);
    lv_obj_set_pos(ui->screen_img_2, 25, 15);
    lv_obj_set_size(ui->screen_img_2, 40, 40);
    lv_obj_add_flag(ui->screen_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_2, &_info_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
    lv_image_set_pivot(ui->screen_img_2, 50,50);
    lv_image_set_rotation(ui->screen_img_2, 0);

    //Write style for screen_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_overview_hardware_edit
    ui->screen_cont_overview_hardware_edit = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_overview_hardware_edit, 201, 145);
    lv_obj_set_size(ui->screen_cont_overview_hardware_edit, 630, 287);
    lv_obj_set_scrollbar_mode(ui->screen_cont_overview_hardware_edit, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_add_flag(ui->screen_cont_overview_hardware_edit, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui->screen_cont_overview_hardware_edit, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_cont_overview_hardware_edit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_overview_hardware_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_overview_hardware_edit, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_overview_hardware_edit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_overview_hardware_edit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_overview_hardware_edit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_overview_hardware_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_overview_hardware_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_overview_hardware_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_overview_hardware_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_overview_hardware_edit, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_overview_hardware_edit, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_overview_hardware_edit, 127, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_overview_hardware_edit, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_overview_hardware_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_overview_hardware_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_102
    ui->screen_label_102 = lv_label_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_label_102, 62, 106);
    lv_obj_set_size(ui->screen_label_102, 173, 29);
    lv_label_set_text(ui->screen_label_102, "设定值");
    lv_label_set_long_mode(ui->screen_label_102, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_102, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_102, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_102, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_102, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_102, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_overview_hardware_edit_head
    ui->screen_label_overview_hardware_edit_head = lv_label_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_label_overview_hardware_edit_head, 62, 30);
    lv_obj_set_size(ui->screen_label_overview_hardware_edit_head, 262, 36);
    lv_label_set_text(ui->screen_label_overview_hardware_edit_head, "快速设置Yaw轴角度");
    lv_label_set_long_mode(ui->screen_label_overview_hardware_edit_head, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_overview_hardware_edit_head, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_overview_hardware_edit_head, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_overview_hardware_edit_head, &lv_font_misans_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_overview_hardware_edit_head, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_overview_hardware_edit_head, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_overview_hardware_edit_head, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_line_9
    ui->screen_line_9 = lv_line_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_line_9, 44, 22);
    lv_obj_set_size(ui->screen_line_9, 28, 30);
    static lv_point_precise_t screen_line_9[] = {{0, 0},{0, 403}};
    lv_line_set_points(ui->screen_line_9, screen_line_9, 2);

    //Write style for screen_line_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_line_9, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_line_9, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_line_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_overview_hardware_edit_save
    ui->screen_btn_overview_hardware_edit_save = lv_button_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_btn_overview_hardware_edit_save, 496, 23);
    lv_obj_set_size(ui->screen_btn_overview_hardware_edit_save, 100, 44);
    ui->screen_btn_overview_hardware_edit_save_label = lv_label_create(ui->screen_btn_overview_hardware_edit_save);
    lv_label_set_text(ui->screen_btn_overview_hardware_edit_save_label, "完成");
    lv_label_set_long_mode(ui->screen_btn_overview_hardware_edit_save_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_overview_hardware_edit_save_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_overview_hardware_edit_save, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_overview_hardware_edit_save_label, LV_PCT(100));

    //Write style for screen_btn_overview_hardware_edit_save, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_overview_hardware_edit_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_overview_hardware_edit_save, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_overview_hardware_edit_save, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_overview_hardware_edit_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_overview_hardware_edit_save, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_overview_hardware_edit_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_overview_hardware_edit_save, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_overview_hardware_edit_save, &lv_font_misans_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_overview_hardware_edit_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_overview_hardware_edit_save, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_overview_hardware_edit_rst
    ui->screen_imgbtn_overview_hardware_edit_rst = lv_imagebutton_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_imgbtn_overview_hardware_edit_rst, 158, 94);
    lv_obj_set_size(ui->screen_imgbtn_overview_hardware_edit_rst, 50, 50);
    lv_obj_add_flag(ui->screen_imgbtn_overview_hardware_edit_rst, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_hardware_edit_rst, LV_IMAGEBUTTON_STATE_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_hardware_edit_rst, LV_IMAGEBUTTON_STATE_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_hardware_edit_rst, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_restart_alt_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50, NULL, NULL);
    lv_imagebutton_set_src(ui->screen_imgbtn_overview_hardware_edit_rst, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_restart_alt_24dp_BB271A_FILL0_wght400_GRAD0_opsz24_RGB565A8_50x50, NULL, NULL);
    ui->screen_imgbtn_overview_hardware_edit_rst_label = lv_label_create(ui->screen_imgbtn_overview_hardware_edit_rst);
    lv_label_set_text(ui->screen_imgbtn_overview_hardware_edit_rst_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_overview_hardware_edit_rst_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_overview_hardware_edit_rst_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_overview_hardware_edit_rst, 0, LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_hardware_edit_rst, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_hardware_edit_rst, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_hardware_edit_rst, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_hardware_edit_rst, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_overview_hardware_edit_rst, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_hardware_edit_rst, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_overview_hardware_edit_rst, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_hardware_edit_rst, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_hardware_edit_rst, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_hardware_edit_rst, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_hardware_edit_rst, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_hardware_edit_rst, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_hardware_edit_rst, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_overview_hardware_edit_rst, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_hardware_edit_rst, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_hardware_edit_rst, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_overview_hardware_edit_rst, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_overview_hardware_edit_rst, &lv_font_misans_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_overview_hardware_edit_rst, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_overview_hardware_edit_rst, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_overview_hardware_edit_rst, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->screen_imgbtn_overview_hardware_edit_rst, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->screen_imgbtn_overview_hardware_edit_rst, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes screen_spinbox_overview_hardware_edit
    ui->screen_spinbox_overview_hardware_edit = lv_spinbox_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_spinbox_overview_hardware_edit, 181, 170);
    lv_obj_set_pos(ui->screen_spinbox_overview_hardware_edit, 181, 170);
    lv_obj_set_width(ui->screen_spinbox_overview_hardware_edit, 247);
    lv_obj_set_height(ui->screen_spinbox_overview_hardware_edit, 78);
    lv_spinbox_set_digit_format(ui->screen_spinbox_overview_hardware_edit, 8, 4);
    lv_spinbox_set_range(ui->screen_spinbox_overview_hardware_edit, -99999999, 99999999);
    int32_t screen_spinbox_overview_hardware_edit_h = lv_obj_get_height(ui->screen_spinbox_overview_hardware_edit);
    ui->screen_spinbox_overview_hardware_edit_btn_plus = lv_button_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_spinbox_overview_hardware_edit, 181, 170);
    lv_obj_set_size(ui->screen_spinbox_overview_hardware_edit_btn_plus, screen_spinbox_overview_hardware_edit_h, screen_spinbox_overview_hardware_edit_h);
    lv_obj_align_to(ui->screen_spinbox_overview_hardware_edit_btn_plus, ui->screen_spinbox_overview_hardware_edit, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_overview_hardware_edit_btn_plus, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_overview_hardware_edit_btn_plus, lv_screen_spinbox_overview_hardware_edit_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_spinbox_overview_hardware_edit_btn_minus = lv_button_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_size(ui->screen_spinbox_overview_hardware_edit_btn_minus, screen_spinbox_overview_hardware_edit_h, screen_spinbox_overview_hardware_edit_h);
    lv_obj_align_to(ui->screen_spinbox_overview_hardware_edit_btn_minus, ui->screen_spinbox_overview_hardware_edit, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(ui->screen_spinbox_overview_hardware_edit_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_spinbox_overview_hardware_edit_btn_minus, lv_screen_spinbox_overview_hardware_edit_decrement_event_cb, LV_EVENT_ALL, NULL);

    //Write style for screen_spinbox_overview_hardware_edit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_spinbox_overview_hardware_edit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_overview_hardware_edit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_overview_hardware_edit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_spinbox_overview_hardware_edit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_spinbox_overview_hardware_edit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_spinbox_overview_hardware_edit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_spinbox_overview_hardware_edit, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_spinbox_overview_hardware_edit, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_spinbox_overview_hardware_edit, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_spinbox_overview_hardware_edit, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_spinbox_overview_hardware_edit, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_spinbox_overview_hardware_edit, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_overview_hardware_edit, &lv_font_misans_36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_overview_hardware_edit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_spinbox_overview_hardware_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_spinbox_overview_hardware_edit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_spinbox_overview_hardware_edit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_spinbox_overview_hardware_edit, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_spinbox_overview_hardware_edit, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_spinbox_overview_hardware_edit, &lv_font_misans_36, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_spinbox_overview_hardware_edit, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_spinbox_overview_hardware_edit, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_spinbox_overview_hardware_edit, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_spinbox_overview_hardware_edit, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_spinbox_overview_hardware_edit_extra_btns_main_default
    static lv_style_t style_screen_spinbox_overview_hardware_edit_extra_btns_main_default;
    ui_init_style(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, &lv_font_misans_12);
    lv_style_set_text_opa(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, 0);
    lv_style_set_radius(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_spinbox_overview_hardware_edit_btn_plus, &style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_spinbox_overview_hardware_edit_btn_minus, &style_screen_spinbox_overview_hardware_edit_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cb_overview_hardware_edit_ptcl
    ui->screen_cb_overview_hardware_edit_ptcl = lv_checkbox_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_cb_overview_hardware_edit_ptcl, 378, 104);
    lv_checkbox_set_text(ui->screen_cb_overview_hardware_edit_ptcl, "更新到当前协议");

    //Write style for screen_cb_overview_hardware_edit_ptcl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_overview_hardware_edit_ptcl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_overview_hardware_edit_ptcl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_overview_hardware_edit_ptcl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_overview_hardware_edit_ptcl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_overview_hardware_edit_ptcl, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_overview_hardware_edit_ptcl, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_overview_hardware_edit_ptcl, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_overview_hardware_edit_ptcl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_overview_hardware_edit_ptcl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_overview_hardware_edit_ptcl, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_overview_hardware_edit_ptcl, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_overview_hardware_edit_ptcl, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_overview_hardware_edit_ptcl, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_overview_hardware_edit_ptcl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_overview_hardware_edit_ptcl, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_overview_hardware_edit_ptcl, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_overview_hardware_edit_ptcl, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_overview_hardware_edit_ptcl, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_overview_hardware_edit_ptcl, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_overview_hardware_edit_ptcl, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_overview_hardware_edit_ptcl, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_overview_hardware_edit_ptcl, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_overview_hardware_edit_ptcl, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_overview_hardware_edit_ptcl, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_btn_overview_hardware_edit_drop
    ui->screen_btn_overview_hardware_edit_drop = lv_button_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_btn_overview_hardware_edit_drop, 378, 23);
    lv_obj_set_size(ui->screen_btn_overview_hardware_edit_drop, 100, 44);
    ui->screen_btn_overview_hardware_edit_drop_label = lv_label_create(ui->screen_btn_overview_hardware_edit_drop);
    lv_label_set_text(ui->screen_btn_overview_hardware_edit_drop_label, "放弃更改");
    lv_label_set_long_mode(ui->screen_btn_overview_hardware_edit_drop_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_overview_hardware_edit_drop_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_overview_hardware_edit_drop, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_overview_hardware_edit_drop_label, LV_PCT(100));

    //Write style for screen_btn_overview_hardware_edit_drop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_overview_hardware_edit_drop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_overview_hardware_edit_drop, lv_color_hex(0x938810), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_overview_hardware_edit_drop, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_overview_hardware_edit_drop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_overview_hardware_edit_drop, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_overview_hardware_edit_drop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_overview_hardware_edit_drop, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_overview_hardware_edit_drop, &lv_font_misans_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_overview_hardware_edit_drop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_overview_hardware_edit_drop, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cb_overview_hardware_edit_visual
    ui->screen_cb_overview_hardware_edit_visual = lv_checkbox_create(ui->screen_cont_overview_hardware_edit);
    lv_obj_set_pos(ui->screen_cb_overview_hardware_edit_visual, 230, 104);
    lv_obj_add_flag(ui->screen_cb_overview_hardware_edit_visual, LV_OBJ_FLAG_HIDDEN);
    lv_checkbox_set_text(ui->screen_cb_overview_hardware_edit_visual, "视觉制导");

    //Write style for screen_cb_overview_hardware_edit_visual, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_cb_overview_hardware_edit_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cb_overview_hardware_edit_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cb_overview_hardware_edit_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cb_overview_hardware_edit_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cb_overview_hardware_edit_visual, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cb_overview_hardware_edit_visual, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cb_overview_hardware_edit_visual, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cb_overview_hardware_edit_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_overview_hardware_edit_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_overview_hardware_edit_visual, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_overview_hardware_edit_visual, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_overview_hardware_edit_visual, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_overview_hardware_edit_visual, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cb_overview_hardware_edit_visual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cb_overview_hardware_edit_visual, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->screen_cb_overview_hardware_edit_visual, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cb_overview_hardware_edit_visual, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cb_overview_hardware_edit_visual, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cb_overview_hardware_edit_visual, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cb_overview_hardware_edit_visual, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cb_overview_hardware_edit_visual, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cb_overview_hardware_edit_visual, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cb_overview_hardware_edit_visual, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cb_overview_hardware_edit_visual, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_cont_notification_2
    ui->screen_cont_notification_2 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_notification_2, 295, -90);
    lv_obj_set_size(ui->screen_cont_notification_2, 437, 70);
    lv_obj_set_scrollbar_mode(ui->screen_cont_notification_2, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_cont_notification_2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_cont_notification_2, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_cont_notification_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_notification_2, 57, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_notification_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_notification_2, lv_color_hex(0xf5ffb9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_notification_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_notification_2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_cont_notification_2, lv_color_hex(0x353535), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_cont_notification_2, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_cont_notification_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_cont_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_cont_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_notification_2
    ui->screen_label_notification_2 = lv_label_create(ui->screen_cont_notification_2);
    lv_obj_set_pos(ui->screen_label_notification_2, 77, 22);
    lv_obj_set_size(ui->screen_label_notification_2, 329, 25);
    lv_label_set_text(ui->screen_label_notification_2, "协议已写入");
    lv_label_set_long_mode(ui->screen_label_notification_2, LV_LABEL_LONG_SCROLL);

    //Write style for screen_label_notification_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_notification_2, lv_color_hex(0x1a1a1a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_notification_2, &lv_font_misans_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_notification_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_notification_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_notification_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_3
    ui->screen_img_3 = lv_image_create(ui->screen_cont_notification_2);
    lv_obj_set_pos(ui->screen_img_3, 25, 15);
    lv_obj_set_size(ui->screen_img_3, 40, 40);
    lv_obj_add_flag(ui->screen_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_3, &_info_24dp_1F1F1F_FILL0_wght400_GRAD0_opsz24_RGB565A8_40x40);
    lv_image_set_pivot(ui->screen_img_3, 50,50);
    lv_image_set_rotation(ui->screen_img_3, 0);

    //Write style for screen_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

    //Init events for screen.
    events_init_screen(ui);
}
