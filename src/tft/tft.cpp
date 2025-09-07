#include "tft.h"
#include <TFT_eSPI.h>
#include <SPI.h>

#define TFT_GREY 0x5AEB // New colour

TFT_eSPI tft = TFT_eSPI();  // Invoke library
TFT_eSprite sprite = TFT_eSprite(&tft);  // 缓冲1


void tftSetup() {
    Serial.begin(115200);
    // tft.begin();
    // tft.setRotation(0);
    // tft.invertDisplay(0);
    // tft.setSwapBytes(true);
    tft.init();                      // 初始化屏幕
    tft.setRotation(0);              // 设置屏幕方向（0-3）
    tft.fillScreen(TFT_BLACK);       // 清屏为黑色

    // 创建 Sprite（尺寸小于屏幕时可节省内存）
    if (sprite.createSprite(150, 100) == nullptr) { // 检查Sprite是否创建成功
        Serial.println("Sprite创建失败！内存不足！");
        while (1) delay(100); //  halt
    }
    Serial.println("Sprite创建成功");
    // sprite.createSprite(210, 210);   // 宽度=200像素，高度=100像素
    sprite.setTextColor(TFT_WHITE);  // 设置文本颜色
    sprite.setTextSize(2);           // 设置文本大小
}


void tftLoop2()
{
    static int counter = 0;

    // 1. 清空 Sprite（填充黑色背景）
    sprite.fillSprite(TFT_BLUE);

    // 2. 在 Sprite 上绘制内容
    sprite.drawString("Counter:", 10, 10);  // 文本
    sprite.drawNumber(counter, 10, 30);    // 数字
    sprite.drawRect(5, 5, 140, 90, TFT_GREEN); // 边框

    // 3. 将 Sprite 推送到屏幕的指定位置（避免闪屏的关键）
    sprite.pushSprite(0, 0);       // 推送到屏幕坐标 (20,20)

    // tft.setCursor(50,50);
    // tft.setTextColor(TFT_WHITE);
    // tft.printf("xxxxx");

    counter++;
    delay(100); // 延迟以控制更新速度
}

void tftLoop()
{
    // Fill screen with grey so we can see the effect of printing with and without
    // a background colour defined
    // tft.fillScreen(TFT_GREY);
    tft.fillScreen(TFT_GREY);

    // Set "cursor" at top left corner of display (0,0) and select font 2
    // (cursor will move to next line automatically during printing with 'tft.println'
    //  or stay on the line is there is room for the text with tft.print)
    tft.setCursor(0, 0, 2);
    // Set the font colour to be white with a black background, set text size multiplier to 1
    tft.setTextColor(TFT_WHITE,TFT_BLACK);  tft.setTextSize(1);
    // We can now plot text on screen using the "print" class
    tft.println("Hello World!");

    // Set the font colour to be yellow with no background, set to font 7
    tft.setTextColor(TFT_YELLOW,TFT_BLACK); tft.setTextFont(7);
    tft.println(1234.56);

    // Set the font colour to be green with black background, set to font 4
    tft.setTextColor(TFT_GREEN,TFT_BLACK);
    tft.setTextFont(4);
    tft.println("Groop");
    tft.println("I implore thee,");

    // Change to font 2
    tft.setTextFont(2);
    tft.println("my foonting turlingdromes.");
    tft.println("And hooptiously drangle me");
    tft.println("with crinkly bindlewurdles,");
    // This next line is deliberately made too long for the display width to test
    // automatic text wrapping onto the next line
    tft.println("Or I will rend thee in the gobberwarts with my blurglecruncheon, see if I don't!");

    // Test some print formatting functions
    float fnumber = 123.45;
    // Set the font colour to be blue with no background, set to font 4
    tft.setTextColor(TFT_BLUE);    tft.setTextFont(4);
    tft.print("Float = "); tft.println(fnumber);           // Print floating point number
    tft.print("Binary = "); tft.println((int)fnumber, BIN); // Print as integer value in binary
    tft.print("Hexadecimal = "); tft.println((int)fnumber, HEX); // Print as integer number in Hexadecimal
    delay(10000);
}