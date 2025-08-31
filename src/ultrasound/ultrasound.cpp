//
// Created by 刘科 on 2025/8/31.
//

#include "ultrasound.h"

#include <Arduino.h>

// 定义超声波模块引脚
#define TRIG 27
#define ECHO 26

#define LED 23
#define BUZZER 22

int delay_time;

void ultrasoundSetup() {
    Serial.begin(115200);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    pinMode(LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    // 将 LED 与蜂鸣器设置为低电平
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, LOW);
}

void ultrasoundLoop()
{
    // 清除trigPin
    digitalWrite(TRIG, LOW);
    delay(5);
    // 将trigPin设置为HIGH状态10微秒
    digitalWrite(TRIG, HIGH);
    delay(10);
    digitalWrite(TRIG, LOW);
    // 读取echoPin，返回声波传播时间(微秒)
    float time = pulseIn(ECHO, HIGH);

    // 计算距离
    float distance = time * 0.3432 / 2;

    Serial.print("距离: ");
    Serial.print(distance);
    Serial.println("mm");
    delay(100);

    // 距离过近则报警
    if (distance < 200) {
        delay_time = int(distance);
        Serial.println(delay_time);
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, LOW );
        delay(delay_time);
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, HIGH);
        delay(delay_time);
    } else {
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, HIGH);
        delay(100);
    }
}