//
// Created by 刘科 on 2025/8/30.
//

#include "step.h"

#include <CheapStepper.h>
#define IN_1  13
#define IN_2  12
#define IN_3  14
#define IN_4  27

CheapStepper stepper (IN_1, IN_2, IN_3, IN_4);

bool clockwise = true;

void stepSetup() {
    // 设置输出模式
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);

}

void stepLoop()
{
    // 设置转速
    stepper.setRpm(20);
    // 通过步数旋转
    stepper.moveTo(clockwise, 2048);

    delay(1000);
    // 通过角度旋转
    stepper.moveDegrees(clockwise, 90);
}