//includes the libraries
#include <Wire.h> 
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
 
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); //initializes the library with these pins
 
int button = 13;
int swtch = 12;
int buttonState;
int swtchState; 
int printVal = 0;
bool isOn = false;
 
void setup(){
	lcd.begin (16,2); //for 16 x 2 LCD module
	lcd.setBacklightPin (3, POSITIVE);
	lcd.setBacklight (HIGH);   //turns the backlight on
	lcd.print ("Hello World"); //Print Hello World
	pinMode(13, INPUT);
	pinMode(12, OUTPUT);
	Serial.begin(9600);
}
void loop(){ 
	lcd.setCursor(2,1); //set the cursor to row 1 colmn 2 
 
	buttonState = digitalRead(button);  
	Serial.println(buttonState);
	swtchState = digitalRead(swtch);
 
	if (swtchState && !buttonState && isOn == false){// check if button and switch are on/pressed
		printVal = printVal + 1;// print up one on LCD                 
		isOn = true; 
	}  
	else if (!swtchState && !buttonState && isOn == false){// check if button is on and switch is off
		printVal = printVal - 1;// print down one on LCD
		isOn = true;
	}
	if (buttonState){ 
		isOn = false;
	}
 
	lcd.print(printVal); 
	lcd.print(" ");// print a space so the LCD doesn't go by 10's
	delay(100);
}