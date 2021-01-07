#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
 
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);
 
int potPin = 2; //potentiometer connected to anolog pin 2
int ledPin = 10;// LED connected to digital pin 13
int val = 0; //varaiable to store value coming from the sensor
 
 
void setup(){
	lcd.begin(16,2);
	lcd.setBacklightPin(3, POSITIVE);
	lcd.setBacklight(HIGH);
	lcd.print("Brightness");
	pinMode(ledPin, OUTPUT);
}
void loop(){
	lcd.setCursor(7, 1);
 
  val = analogRead(potPin);    // read the value from the sensor
  analogWrite(ledPin, val / 4);  //makes val 0-255
  lcd.print(val / 102.3, 0);
  lcd.print(" ");
}