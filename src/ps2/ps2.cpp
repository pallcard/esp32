//
// Created by 刘科 on 2025/8/30.
//
#include <Arduino.h>
#include "ps2.h"
#define PS2_X     15
#define PS2_Y     2
#define SW        4

void ps2Setup()
{
    // 配置输入模式
    pinMode(PS2_X, INPUT);
    pinMode(PS2_Y, INPUT);
    pinMode(SW, INPUT_PULLUP);

    // 配置串口通信波特率
    Serial.begin(9600);

    Serial.printf("x: 0, y: 0, z: 0\n");


}
void ps2Loop()
{
    // 读取数值
    Serial.printf("x: %d, y: %d, z: %d\n",
        analogRead(PS2_X),//读模拟信号
        analogRead(PS2_Y),
        digitalRead(SW));//读数字信号

    delay(100);

}
