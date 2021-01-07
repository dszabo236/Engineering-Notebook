#include <LiquidCrystal.h>
 
 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  //initializes the library with these pins
 
void setup() {
 
	lcd.begin(16, 2);   //set up the number of LCD columns and rows
 
	lcd.print("Hello, World!");  //prints hello world to the LCD
}
 
void loop() {
	lcd.setCursor(5, 1);  //sets the cursor to column 5 line 1 
	                      // line 1 is second row (counting begings with zero)
 
	lcd.print(millis() / 1000); //print number of seconds since reset
}