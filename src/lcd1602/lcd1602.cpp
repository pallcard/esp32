//
// Created by 刘科 on 2025/8/30.
//

#include "lcd1602.h"

#include <HardwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void lcdSetup() {
    Serial.begin(9600);
    lcd.init();                      // initialize the lcd
    lcd.backlight();
    lcd.print("Hello, world!");
}

void lcdLoop()
{
    // when characters arrive over the serial port...
    if (Serial.available()) {

        String data = Serial.readString();
        data.trim();
        // wait a bit for the entire message to arrive
        delay(100);
        // clear the screen
        lcd.clear();
        lcd.print(data);
        // // read all the available characters
        // while (Serial.available() > 0) {
        //     // display each character to the LCD
        //     lcd.write(data);
        // }
    }
}