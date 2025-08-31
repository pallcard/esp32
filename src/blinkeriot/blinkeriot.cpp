//
// Created by 刘科 on 2025/8/31.
//
#define BLINKER_WIFI
#define BLINKER_MIOT_LIGHT

#include "blinkeriot.h"
#include <Arduino.h>
#include <Blinker.h>

#define LED_BUILTIN 15

char auth[] = "xx";
char ssid2[] = "201";
char pswd2[] = "xx";

BlinkerButton btn("btn");

void handleBtn(const String &state) {
    if (state == "on") {
        digitalWrite(LED_BUILTIN, HIGH);
        btn.print("on");
    } else {
        digitalWrite(LED_BUILTIN, LOW);
        btn.print("off");
    }
}

void miotPowerState(const String & state)
{
    if (state == BLINKER_CMD_ON) {
        handleBtn("on");
    }
    else if (state == BLINKER_CMD_OFF) {
        handleBtn("off");
    }
}

void blinkeriotSetup() {
    // 初始化串口
    Serial.begin(115200);

    // 初始化有LED的IO
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Blinker.begin(auth, ssid2, pswd2);
    btn.attach(handleBtn);
    digitalWrite(LED_BUILTIN, HIGH);
    BlinkerMIOT.attachPowerState(miotPowerState);
}

void blinkeriotLoop()
{
    Blinker.run();
}