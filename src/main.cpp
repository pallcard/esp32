#include <Arduino.h>

// #include "lcd1602/lcd1602.h"
#include "blinkeriot/blinkeriot.h"
#include "keyboard/keyboard.h"
#include "buzzer/buzzer.h"
#include "tft/tft.h"
#include "led/led.h"
#include "net/net.h"
#include "ps2/ps2.h"
#include "tilt/tilt.h"
#include "servo/servo.h"
#include "shake/shake.h"
#include "ultrasound/ultrasound.h"
#include "step/step.h"
#include "wifi/wifi.h"


void setup() {
   // ledSetup();
   // lcdSetup();
    // tftSetup();
    // servoSetup();
    // wifiSetup();
    // stepSetup();
    // ps2Setup();
    // keyboardSetup();
    // buzzerSetup();
    // tiltSetup();
    // shakeSetup();
    // ultrasoundSetup();
    // netSetup();
    blinkeriotSetup();
}


void loop() {
    // ledLoop();
    // lcdLoop();
    // tftLoop();
    // servoLoop();
    // wifiLoop();
    // stepLoop();
    // ps2Loop();
    // keyboardLoop();
    // buzzerLoop();
    // tiltLoop();
    // shakeLoop();
   // ultrasoundLoop();
    // netLoop();
    blinkeriotLoop();
}