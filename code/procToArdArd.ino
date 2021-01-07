#include <Servo.h> 
#include <Wire.h> 
#include <LCD.h> 
Servo servo; 
int num =0; 
int val; 
int servoPin = 9; 
int angle = 0;
 
void setup() {
	pinMode(servoPin, OUTPUT);
	servo.attach(servoPin);
	Serial.begin(9600);
}
 
void loop() {
	if (Serial.available()) {
		val = Serial.read(); 
		val =map(val,0,200,0,180); 
    	servo.write(val); 
	}
}