//
// Created by 刘科 on 2025/8/30.
//

#include "servo.h"
#include <ESP32Servo.h>
Servo myServo;  // 建立 Servo 物件

int APin = 13;

int freq = 1000;
void servoSetup() {
    ESP32PWM::allocateTimer(0);
    myServo.attach(APin); // 將伺服馬達綁定到 GPIO 13 腳位
    // pwm.attachPin(APin, freq, 10); // 1KHz 10 bits
    myServo.write(0);
}

void servoLoop()
{

    for (int angle = 0; angle <= 180; angle += 1) {
        myServo.write(angle); // 慢慢轉向 180 度
        delay(15);            // 延遲一點時間，讓馬達有足夠時間移動
    }

    for (int angle = 180; angle >= 0; angle -= 1) {
        myServo.write(angle); // 慢慢轉回 0 度
        delay(15);            // 延遲一點時間
    }
}