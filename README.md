# Engineering-Notebook
Collection of 11 smaller embedded systems assignments. Completed November 6th, 2016. Original [wiki documentation](http://wiki.chssigma.com/index.php?title=Dani%27s_Engineering_Notebook)
# Table of Contents
* [LCD Hello World](#lcd-hello-world)
* [LCD Backpack](#lcd-backpack)
* [Photo Interrupter](#photo-interrupter)
* [Reading Potentiometers](#reading-potentiometers)
* [Potentiometer Servo Control](#potentiometer-servo-control)
* [Potentiometer Motor Control](#potentiometer-motor-control)
* [Processing Hello World](#processing-hello-world)
* [Solidworks: Advanced Motion Study](#solidworks:-advanced-motion-study)
* [Arduino to Processing](#arduino-to-processing)
* [Processing to Arduino](#processing-to-arduino)

# LCD Hello World
This project was about learning how to wire and code for the liquid crystal LCD display. There was some trouble understanding exactly how to wire the arduino. Besides that, it was just figuring out how exactly the liquid crystal LCD worked and how to manipulate it to my needs.
```
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
```
- [code](code/code.py)
- [picture](media/lcdhw.png)
# LCD Backpack
This sub-project was to make the LCD function with an LCD backpack, which makes it much easier to wire. When the button is pressed, the LCD counts up one. If the switch is then flipped and the button is pressed the LCD counts back one. There was some trouble ensuring that the LCD didn't count up more than one when the button was held down, so I used a boolean to make sure that it only counted up or down 1.
```
