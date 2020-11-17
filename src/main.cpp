  /*
      ------- WIRING ------- 

      LCD  ---> (SCL,A5)  (SDA, A4) (VCC and Ground to their pins)

      Rotary Encoder  ----> (with button pins on bottom) (Top Left, D3 w/ 330ohm pullup to 5v), (Middle to Ground), (Top Right, D2 w/ 330ohm pullup to 5V )
                ----> (Button wired on one end to 5V, on the other end to D4 w/ 2k pulldown to ground)

      DS3231 ---> SCL to A5, SDA to A4, 5V and ground wired appropriately

      ULN2003 ---> IN1->D5, IN2->D6, ... ,IN4->D8

      Red Button ---> One side to 5V, the other to d10 w/ pulldown to ground 
         --- (LCD Power)

      Blue Button ---> One side to 5V, the other side to d9 w/ pulldown to ground 
         --- (Mode Select)
  */

#include <Arduino.h>
#include <Wire.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>
#include <Encoder.h>
#include <Stepper.h>
#include <ds3231.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int bluePin = 5;
int pinkPin = 6;
int yellowPin = 7;
int orangePin = 8;

void setup() {

  // Serial.begin(9600);
  Wire.begin();

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.clear();
}

void loop() {
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello, world");
  //lcd.setCursor(0,1);
  lcd.backlight();
}
