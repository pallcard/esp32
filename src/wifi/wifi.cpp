//
// Created by 刘科 on 2025/8/30.
//

#include "wifi.h"
#include <WiFi.h>

#include <HardwareSerial.h>

// 定义 Wi-Fi 名与密码
// const char * ssid = "xxxx";
// const char * password = "123456";

// 设置要创建的热点名与密码
const char * ssid = "ESP32_AP";
const char * password = "12345678";

void wifiSetup() {
    Serial.begin(9600);

    // // 断开之前的连接
    // WiFi.disconnect(true);
    // // 连接 Wi-Fi
    // WiFi.begin(ssid, password);
    //
    // // 检测是否链接成功
    // while (WiFi.status() != WL_CONNECTED) {
    //     delay(500);
    //     Serial.print(".");
    // }
    // Serial.println("连接成功");
    // Serial.print("IP address: ");
    // Serial.println(WiFi.localIP());

    // 创建热点
    WiFi.softAP(ssid, password);

    //  打印热点 IP
    Serial.print("Wi-Fi 接入的 IP：");
    Serial.println(WiFi.softAPIP());
}



void wifiLoop()
{

}