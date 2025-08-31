//
// Created by 刘科 on 2025/8/30.
//
#include <Arduino.h>

#include "keyboard.h"
// 定义行引脚
int row_pins[4] = {13, 12, 14, 27};
// 定义列引脚
int col_pins[4] = {26, 25, 33, 32};

// 按下的按键
char key;

void keyboardSetup()
{
    // 设置通信波特率
    Serial.begin(9600);

    // 行引脚设置为输入
    for (int i=0;i<4;i++) {
        pinMode(row_pins[i], INPUT_PULLUP);
    }

    // 列引脚设置为输出
    for (int i=0;i<4;i++) {
        pinMode(col_pins[i], OUTPUT);
        // 初始化为高电平
        digitalWrite(col_pins[i], HIGH);
    }
}

char read_keypad() {
    // 定义键盘按键布局
    char keys[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };

    // 行列扫描法
    for (int j=0;j<4;j++) {
        // 将当前列设置为低电平
        digitalWrite(col_pins[j], LOW);
        for (int i=0;i<4;i++) {
            // 检测行输入引脚状态, 检测到低电平,说明按键被按下,则返回该按键值
            if (!digitalRead(row_pins[i])) {
                // 将该行恢复为高电平
                digitalWrite(col_pins[j], HIGH);
                return keys[i][j];
            }
        }
        // 将该行恢复为高电平
        digitalWrite(col_pins[j], HIGH);
    }

    return NULL;
}

void keyboardLoop()
{
    // 保存读取到的按键值
    key = read_keypad();

    if (key) {
        Serial.printf("检测到按键按下: %c\n", key);
    }
    delay(200);

}