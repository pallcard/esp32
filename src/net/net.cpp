//
// Created by 刘科 on 2025/8/31.
//

#include "net.h"

#include <Arduino.h>
#include <WebServer.h>
#include <WiFi.h>

#define LED 15

WebServer server(80);

// 处理根目录访问
void handleRoot() {
    String html = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>局域网控制LED</title>
</head>
<body>
<h3>局域网控制LED</h3>>
<a href="/on">打开LED</a>
<a href="/off">关闭LED</a>
</body>
</html>
)rawliteral";
    server.send(200, "text/html", html);
}

void handleOn()
{
    digitalWrite(LED, HIGH);
    server.sendHeader("location", "/");
    server.send(303);
}

void handleOff()
{
    digitalWrite(LED, LOW);
    server.sendHeader("location", "/");
    server.send(303);
}
void handleNotFound()
{
    server.send(404, "text/html", "not found");
}

void netSetup() {
    Serial.begin(115200);
    Serial.println("net module");

    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    // 创建热点
    WiFi.mode(WIFI_AP);
    WiFi.softAP("local-net", "12345678");
    //  打印热点 IP
    Serial.print("AP IP address: ");
    Serial.println(WiFi.softAPIP());

    // ... 后续服务器设置与STA模式相同
    server.on("/", handleRoot);
    server.on("/on", handleOn);
    server.on("/off", handleOff);
    server.onNotFound(handleNotFound);
    server.begin();
}

void netLoop()
{
    server.handleClient(); // 持续处理来自客户端的请求[2,8](@ref)
}