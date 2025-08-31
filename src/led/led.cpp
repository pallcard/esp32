//
// Created by 刘科 on 2025/8/30.
//

#include "led.h"
#include <Arduino.h>

#define LED_PIN 13

int pinList[4]= {12,14,26,27};

void ledSetup() {
    Serial.begin(9600);
    for (int i : pinList)
    {
        pinMode(i, OUTPUT);
    }
    pinMode(LED_PIN, OUTPUT);
}

void ledLoop() {

    Serial.println("----流水灯-----");
    for (int i : pinList)
    {
        Serial.println(i);
        digitalWrite(i, HIGH);
        delay(500);
        digitalWrite(i, LOW);
        delay(500);
    }

    Serial.println("----呼吸灯-----");

    for (int i=0; i < 256; i ++)
    {
        analogWrite(LED_PIN, i);
        delay(10);
    }

    for (int i=255; i >= 0; i --)
    {
        analogWrite(LED_PIN, i);
        delay(10);
    }

}