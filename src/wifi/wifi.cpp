//
// Created by 刘科 on 2025/8/30.
//

#include "wifi.h"
#include <WiFi.h>

#include <HardwareSerial.h>
#include <WiFiManager.h>
#include "esp_wifi.h"

// 定义 Wi-Fi 名与密码
// const char * ssid = "xxxx";
// const char * password = "123456";

// 设置要创建的热点名与密码
const char * ssid = "ESP32_AP";
const char * password = "12345678";

#define SW 15


void resetWiFiConfig() {
    esp_wifi_disconnect();    // 断开当前连接
    esp_wifi_stop();          // 停止Wi-Fi
    esp_wifi_restore();       // 清除配置
    // 如需继续使用Wi-Fi，可能需要重新初始化并启动
    esp_wifi_start();
    Serial.println("wifi reset");
}

void setWiFiConfig()
{
    WiFiManager manager;
    manager.autoConnect(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print("waiting for connect wifi...");
    }
    Serial.println("连接成功");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void wifiSetup() {
    pinMode(SW, INPUT_PULLUP);
    Serial.begin(115200);
    Serial.println("wifi module");
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

    // // 创建热点
    // WiFi.softAP(ssid, password);
    //
    // //  打印热点 IP
    // Serial.print("Wi-Fi 接入的 IP：");
    // Serial.println(WiFi.softAPIP());

    setWiFiConfig();
}



void wifiLoop()
{

    if (digitalRead(SW) == LOW) {
        Serial.printf("wifi reset button");
        resetWiFiConfig();
        setWiFiConfig();
    }

    delay(100);
}