#include <Arduino.h>
#include "lvgl.h"
#include <Arduino_GFX_Library.h>
#include <ChronosESP32.h>
#include <Preferences.h>
#include "webscreen_chronos/ui.h"

#define LVGL_LOCK() xSemaphoreTakeRecursive(lvgl_mutex, portMAX_DELAY)
#define LVGL_UNLOCK() xSemaphoreGiveRecursive(lvgl_mutex)

// Locking LVGL calls to prevent concurrent access
// This is important because LVGL is not thread-safe
// and we need to ensure that only one task is accessing it at a time
// This is done using a recursive mutex
#define LVGL_EXEC(code) \
  do                    \
  {                     \
    if (LVGL_LOCK())    \
    {                   \
      code;             \
      LVGL_UNLOCK();    \
    }                   \
  } while (0)

#define GFX_BL 1 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
Arduino_DataBus *bus = new Arduino_ESP32QSPI(
    6 /* CS */, 47 /* SCK */, 18 /* SDIO0 */, 7 /* SDIO1 */,
    48 /* SDIO2 */, 5 /* SDIO3 */);

Arduino_GFX *gfx = new Arduino_RM67162(bus, 17, 1, false);

ChronosESP32 watch("Webscreen");
Preferences prefs;

static const uint32_t screenWidth = 536;
static const uint32_t screenHeight = 240;

const unsigned int lv_buffer_size = (0x4000);
uint8_t lv_buffer[lv_buffer_size];

static lv_display_t *lv_display;

SemaphoreHandle_t lvgl_mutex;
Navigation nav;
uint32_t nav_icon_crc = 0xFFFFFFFF;

lv_timer_t *alert_timer = NULL;

void my_disp_flush(lv_display_t *disp, const lv_area_t *area, unsigned char *data)
{

  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)data, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1);

  lv_display_flush_ready(disp); /* tell lvgl that flushing is done */
}

static uint32_t my_tick(void)
{
  return millis();
}

void alert_callback(lv_timer_t *timer)
{
  lv_subject_set_int(&subject_notification, 0);
  // lv_subject_set_int(&subject_alert, 0);
  alert_timer = NULL; // We’re done with the timer
}

void set_nav_icon_px(uint16_t x, uint16_t y, bool on)
{
  if (on)
  {
    // lv_subject_get_color(&subject_text_color)
    lv_canvas_set_px(nav_canvas, x, y, lv_color_make(0, 0, 1), LV_OPA_COVER);
  }
  else
  {
    lv_canvas_set_px(nav_canvas, x, y, lv_color_make(0, 0, 0), LV_OPA_COVER);
  }
}

/* Callback for notifications */
void notification_callback(Notification notification)
{

  LVGL_EXEC({
    lv_subject_copy_string(&subject_notif_title, notification.title.c_str());
    lv_subject_copy_string(&subject_notif_message, notification.message.c_str());
    lv_subject_copy_string(&subject_notif_time, notification.time.c_str());

    lv_subject_set_int(&subject_notification, 1);
    // lv_subject_set_int(&subject_alert, 1);

    if (alert_timer)
    {
      lv_timer_delete(alert_timer);
      alert_timer = NULL;
    }

    alert_timer = lv_timer_create(alert_callback, 5000, NULL);
    lv_timer_set_repeat_count(alert_timer, 1);
  });
}

/* Callback for the configuration */
void config_callback(Config config, uint32_t a, uint32_t b)
{
  switch (config)
  {
  case CF_NAV_DATA:
    // Navigation data received
    LVGL_EXEC({
      if (a)
      {
        nav = watch.getNavigation();
        lv_subject_copy_string(&subject_nav_title, nav.title.c_str());           // title
        lv_subject_copy_string(&subject_nav_eta, nav.eta.c_str());               // eta
        lv_subject_copy_string(&subject_nav_directions, nav.directions.c_str()); // directions
        lv_subject_copy_string(&subject_nav_speed, nav.speed.c_str());           // directions

        char text[100];
        snprintf(text, sizeof(text), "%s %s", nav.duration.c_str(), nav.distance.c_str());
        lv_subject_copy_string(&subject_nav_duration, text); // duration & distance

        lv_subject_set_int(&subject_navigate, nav.active);

        if (nav.hasIcon)
        {
          lv_obj_remove_flag(nav_canvas, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
          lv_obj_add_flag(nav_canvas, LV_OBJ_FLAG_HIDDEN);
        }
      }
      else
      {
        nav_icon_crc = 0xFFFFFFFF;
      }
      lv_subject_set_int(&subject_navigate, a);
    });
    break;
  case CF_NAV_ICON:
    // Navigation icon received
    LVGL_EXEC({
      if (a == 2)
      {
        nav = watch.getNavigation();
        if (nav_icon_crc != nav.iconCRC)
        {
          nav_icon_crc = nav.iconCRC;
          for (int y = 0; y < 48; y++)
          {
            for (int x = 0; x < 48; x++)
            {
              int byte_index = (y * 48 + x) / 8;
              int bit_pos = 7 - (x % 8);
              bool px_on = (nav.icon[byte_index] >> bit_pos) & 0x01;
              set_nav_icon_px(x, y, px_on);
            }
          }
        }
      }
    });
    break;
  case CF_WEATHER:
    // Weather data received
    LVGL_EXEC({
      if (a)
      {
        Weather w = watch.getWeatherAt(0);
        lv_subject_set_int(&subject_temp, w.temp);
        lv_subject_copy_string(&subject_city, watch.getWeatherCity().c_str());
      }
    });
    break;
  case CF_FONT:
    // state not saved internally

    LVGL_EXEC({
      if (((b >> 16) & 0xFFFF) == 0x01)
      { // Style 1
        if ((b & 0xFFFF) == 0x01)
        { // TOP
          lv_subject_set_color(&subject_text_color, lv_color_hex(a));
          prefs.putUInt("text_color", a);
        }
        if ((b & 0xFFFF) == 0x02)
        { // CENTER
          lv_subject_set_color(&subject_border_color, lv_color_hex(a));
          prefs.putUInt("border_color", a);
        }
        if ((b & 0xFFFF) == 0x03)
        { // BOTTOM
          lv_subject_set_color(&subject_text_color, lv_color_hex(a));
          lv_subject_set_color(&subject_border_color, lv_color_hex(a));
          prefs.putUInt("text_color", a);
          prefs.putUInt("border_color", a);
        }
      }
    });
    break;
  }
}

void setup(void)
{

  Serial.begin(115200);

#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif

  // Init Display
  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(RGB565_BLACK);

  prefs.begin("my-app");

  lv_init(); // Initialize LVGL

  lv_tick_set_cb(my_tick);

  lv_display = lv_display_create(screenWidth, screenHeight);
  lv_display_set_color_format(lv_display, LV_COLOR_FORMAT_RGB565_SWAPPED);
  lv_display_set_flush_cb(lv_display, my_disp_flush);
  lv_display_set_buffers(lv_display, lv_buffer, NULL, lv_buffer_size, LV_DISPLAY_RENDER_MODE_PARTIAL);

  /* Create a mutex for LVGL */
  /* This mutex is used to protect the LVGL library from concurrent access */
  lvgl_mutex = xSemaphoreCreateRecursiveMutex();

  ui_init("");
  lv_screen_load(main_create());

  lv_subject_set_color(&subject_text_color, lv_color_hex(prefs.getUInt("text_color", 0xFFFFFF)));
  lv_subject_set_color(&subject_border_color, lv_color_hex(prefs.getUInt("border_color", 0xFFFFFF)));

  /* ChronosESP32 Library */
  // watch.setRingerCallback(ringer_callback);
  watch.setNotificationCallback(notification_callback);
  watch.setConfigurationCallback(config_callback);
  watch.begin();
  watch.setBattery(80);
  watch.set24Hour(true);
  watch.clearNotifications();
}

void loop()
{
  /* Handle LVGL tasks */
  /* This function must be called periodically to keep the LVGL library running */
  LVGL_EXEC({
    lv_timer_handler();
  });
  delay(5);

  /* Handle ChronosESP32 periodic tasks */
  watch.loop();

  LVGL_EXEC({
    lv_subject_set_int(&subject_hour, watch.getHourC());
    lv_subject_set_int(&subject_minute, watch.getMinute());
    lv_subject_copy_string(&subject_sys_time, watch.getTime("%R").c_str());
    lv_subject_copy_string(&subject_sys_date, watch.getTime("%a %d %b").c_str());

    lv_subject_set_int(&subject_connected, watch.isConnected());
    lv_subject_set_int(&subject_battery, watch.getPhoneBattery());
  });
}