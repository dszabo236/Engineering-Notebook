int potPin = 2; //connect potentiometer to Analog pin 2
int val = 0;
void setup(){
	Serial.begin(9600); 
}
void loop()
{
	val = map(analogRead(potPin), 0, 1023, 0, 180);
	Serial.println(val); //print the value of the potentiometer
 
		delay(100); //delay 
	}