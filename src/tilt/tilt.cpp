//
// Created by 刘科 on 2025/8/31.
//

#include "tilt.h"
#include <Arduino.h>
#define TILT_SENSOR_PIN 15 // 倾斜传感器数据引脚连接到GPIO15

void tiltSetup() {
    Serial.begin(115200);          // 初始化串口通信，用于打印信息
    pinMode(TILT_SENSOR_PIN, INPUT_PULLUP); // 设置传感器引脚为上拉输入模式
}

void tiltLoop()
{
    int sensorState = digitalRead(TILT_SENSOR_PIN); // 读取传感器状态

    if (sensorState == LOW) {  // 如果读到低电平
        Serial.println("警告：检测到倾斜！");
    } else {                  // 如果读到高电平
        Serial.println("状态正常。");
    }

    delay(200); // 延迟200毫秒，避免打印过于频繁
}