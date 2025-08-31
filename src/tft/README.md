# tft-lcd液晶屏

## 型号
液晶屏 ST7789  240*240

| ESP32引脚 |  ST7789引脚 |  功能 |
|---------|---|---|
| GND     | GND  | 接地  |
| 3V3     |  VCC |  电源 |
| 22      | SCL  | SPI时钟  |
| 21      | SDA(MOSI)  |  SPI主出从入 |
| 13      |  RES | 复位引脚  |
| 12      |  DC |  数据/命令选择 |
| 14      | CS  |  SPI片选 |
| 27      | BLK  |  背光控制 |


## 步骤
1. 引入依赖
```ini
lib_deps =
    bodmer/TFT_eSPI @ ^2.5.43
```

2. 修改.pio/libdeps/esp32dev/TFT_eSPI/User_Setup.h
```c++
// 1型号
#define ST7789_DRIVER      // Full configuration option, define additional parameters below for this display
// 2颜色设置
#define TFT_RGB_ORDER TFT_BGR  // Colour order Blue-Green-Red
// 3屏幕尺寸
#define TFT_WIDTH  240 // ST7789 240 x 240 and 240 x 320
#define TFT_HEIGHT 240 // GC9A01 240 x 240

// 4引脚设置
// For ESP32 Dev board (only tested with GC9A01 display)
// The hardware SPI can be mapped to any pins
#define TFT_MOSI 21 // In some display driver board, it might be written as "SDA" and so on.
#define TFT_SCLK 22
#define TFT_CS   14  // Chip select control pin
#define TFT_DC   12  // Data Command control pin
#define TFT_RST  13  // Reset pin (could connect to Arduino RESET pin)
#define TFT_BL   27  // LED back-light

```
3. 编写代码

