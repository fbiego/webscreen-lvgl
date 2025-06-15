# WebScreen LVGL + Chronos
This is an LVGL UI project for the WebScreen ESP32-S3 AMOLED Display.
It displays time, weather, phone battery level, notifications, and a navigation screen — all synced via ChronosESP32 and the Chronos App.

![webscreen](images/webscreen.png?raw=true "webscreen")

The UI was designed with LVGL’s UI editor, which lets you create UI screens using XML and export them directly to C code.

This project also includes a color customization feature.
Using the Chronos App, you can set the text and border colors to match your preferred style.

> Huge thanks to [`HW Media Lab`](https://www.linkedin.com/company/hwlab/) for providing the hardware.

## Screens

![home](images/home.png?raw=true "home")
![navigation](images/navigation.png?raw=true "navigation")
![notification](images/notification.png?raw=true "notification")

## WebScreen Platform
WebScreen is an ESP32-based platform that lets you run dynamic JavaScript applications with the Elk engine, rendered by LVGL, with storage for multiple apps on a microSD card.

[`Webscreen.cc`](https://webscreen.cc/)

## How to Change Colors
- Open the `Watchfaces` tab in the Chronos App.
- Select `Settings` under `Custom Watchface` in the `Background` tab.
- Choose `Style1`.
- Use the color picker to customize colors:
  - `Top` — Text color
  - `Center` — Border color
  - `Bottom` — Text and border color together

![setting](images/setting.png?raw=true "setting")