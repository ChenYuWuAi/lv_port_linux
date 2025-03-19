#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <gui_guider.h>
#include <custom.h>
#include <chrono>

lv_ui guider_ui;

static const char * getenv_default(const char * name, const char * dflt)
{
    return getenv(name) ?: dflt;
}

#if LV_USE_LINUX_FBDEV
static void lv_linux_disp_init(void)
{
    const char * device = getenv_default("LV_LINUX_FBDEV_DEVICE", "/dev/fb0");
    lv_display_t * disp = lv_linux_fbdev_create();

    lv_linux_fbdev_set_file(disp, device);
}
#elif LV_USE_LINUX_DRM
static void lv_linux_disp_init(void)
{
    const char * device = getenv_default("LV_LINUX_DRM_CARD", "/dev/dri/by-path/platform-axi:gpu-card");
    lv_display_t * disp = lv_linux_drm_create();

    lv_linux_drm_set_file(disp, device, -1);
}
#elif LV_USE_SDL
static void lv_linux_disp_init(void)
{
    const int width  = atoi(getenv("LV_SDL_VIDEO_WIDTH") ?: "1024");
    const int height = atoi(getenv("LV_SDL_VIDEO_HEIGHT") ?: "600");

    lv_sdl_window_create(width, height);
    lv_sdl_mouse_create();
}
#else
#error Unsupported configuration
#endif

#if LV_USE_EVDEV
static void lv_linux_input_create(void)
{
    const char * device =
        getenv_default("LV_LINUX_EVDEV_DEVICE", "/dev/input/event1");
    lv_indev_t * indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, device);
    lv_indev_enable(indev, true);
}
#endif



int screen_digital_clock_min_value;
int screen_digital_clock_hour_value;
int screen_digital_clock_sec_value;

int main(void)
{
    lv_init();

    
    /*Linux display device init*/
    lv_linux_disp_init();
    
    /* 设置时钟 */
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm *tm = std::localtime(&now_c);
    screen_digital_clock_hour_value = tm->tm_hour;
    screen_digital_clock_min_value = tm->tm_min;
    screen_digital_clock_sec_value = tm->tm_sec;

    /*Create a Demo*/
    setup_ui(&guider_ui);
    custom_init(&guider_ui);
    // lv_demo_benchmark();
    // lv_demo_widgets_start_slideshow();

    /*Handle LVGL tasks*/
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}
