//
// Created by 刘科 on 2025/8/31.
//

#include "shake.h"
#include <Arduino.h>
#define SHAKE_SENSOR_PIN 15 // 传感器数据引脚连接到GPIO15

void shakeSetup() {
    Serial.begin(115200);          // 初始化串口通信，用于打印信息
    pinMode(SHAKE_SENSOR_PIN, INPUT_PULLUP); // 设置传感器引脚为上拉输入模式
}

void shakeLoop()
{
    int sensorState = digitalRead(SHAKE_SENSOR_PIN); // 读取传感器状态

    if (sensorState == HIGH) {  // 如果读到高电平
        Serial.println("警告：检测到震动！");
    } else {                  // 如果读到低电平
        Serial.println("状态正常。");
    }

    delay(200); // 延迟200毫秒，避免打印过于频繁
}