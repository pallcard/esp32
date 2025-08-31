//
// Created by 刘科 on 2025/8/30.
//
#include <Arduino.h>
#include "buzzer.h"

#define BUZZER  15

// 定义行引脚
int row_pins2[4] = {13, 12, 14, 27};
// 定义列引脚
int col_pins2[4] = {26, 25, 33, 32};

// 定义音符频率数组
int tone_array[7] = {262, 294, 330, 350, 393, 441, 495};
// 初始化发声频率
int tone_value = 0;

// 按下的按键
char button_key;

char read_keypad2() {
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
        digitalWrite(col_pins2[j], LOW);
        for (int i=0;i<4;i++) {
            // 检测行输入引脚状态, 检测到低电平,说明按键被按下,则返回该按键值
            if (!digitalRead(row_pins2[i])) {
                // 将该行恢复为高电平
                digitalWrite(col_pins2[j], HIGH);
                return keys[i][j];
            }
        }
        // 将该行恢复为高电平
        digitalWrite(col_pins2[j], HIGH);
    }

    return NULL;
}

void buzzerSetup()
{
    // 设置通信波特率
    Serial.begin(9600);

    // 行引脚设置为输入
    for (int i=0;i<4;i++) {
        pinMode(row_pins2[i], INPUT_PULLUP);
    }

    // 列引脚设置为输出
    for (int i=0;i<4;i++) {
        pinMode(col_pins2[i], OUTPUT);
        // 初始化为高电平
        digitalWrite(col_pins2[i], HIGH);
    }

    pinMode(BUZZER, OUTPUT);
    // digitalWrite(BUZZER, HIGH);
    // LEDC 外设
    ledcSetup(0, 20000, 8);
    ledcAttachPin(BUZZER, 0);
}

// 乐谱
int music[] = {1, 1, 5, 5, 6, 6, 5, 0,
               4, 4, 3, 3, 2, 2, 1, 0,
               5, 5, 4, 4, 3, 3, 2, 0,
               5, 5, 4, 4, 3, 3, 2, 0,
               1, 1, 5, 5, 6, 6, 5, 0,
               4, 4, 3, 3, 2, 2, 1, 0};

void buzzerLoop()
{
    // 保存读取到的按键值
    button_key = read_keypad2();

    if (button_key) {
        Serial.printf("检测到按键按下: %c\n", button_key);

        if (button_key == '#')
        {
            for (int i = 0; i < 48; i++)
            {
                if (music[i] == 0)
                {
                    delay(500);
                } else
                {
                    tone_value = tone_array[music[i]];
                    ledcWriteTone(0, tone_value);
                    delay(500);
                }
            }
        } else
        {
            int temp = button_key-'1';
            if (temp >=0 && temp < 7)
            {
                //digitalWrite(BUZZER, LOW);
                tone_value = tone_array[button_key-'1'];
            }
        }
    }
    ledcWriteTone(0, tone_value);
    tone_value = 0;
    delay(100);
    // digitalWrite(BUZZER, HIGH);
}