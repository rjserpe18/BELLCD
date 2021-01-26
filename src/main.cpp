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


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int vBattery = A1;
int vPanel = A2;
int vCurrent = A3;

//int Vbat
//int T14 

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
  Serial.print(1);
  
  // real current and voltage calculated for board
  //float voltage =  analogRead(vBat)*5.0/1023.0*2/2.21*4.5/2.45;
  //float current  = (2.5 - (1.96/2.15)*(analogRead(vBat) - analogRead(T14)) *5.0/1023.0)/(0.27);

  float voltage = analogRead(vBattery)*5.0/1023.0*2/2.21*5/2.45;
  //float current = analogRead(vCurrent) * 5.0/1023.0*1.96/2.15;
  float current = (2.5 - (1.96/2.15)*analogRead(vCurrent) *5.0/1023.0)/(0.27);
  String voltageOutput= "Voltage is " + String(voltage) + "V.";
  String currentOutput = "Current is " + String(current) + "A.";
  lcd.print(voltageOutput);
  lcd.setCursor(0,1);
  lcd.print(currentOutput);
  lcd.backlight();
  delay(1000);
}
