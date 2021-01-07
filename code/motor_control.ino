int motorPin = 3;
int potPin = 0;
int potValue = 0;
int motorValue = 0;
 
void setup(){
	pinMode(motorPin, OUTPUT); //motorPin is set to OUTPUT
	pinMode(potPin, INPUT);//potPin is set to INPUT 
	Serial.begin(9600);
}
 
void loop(){
	potValue = analogRead(potPin);//reads the value of potentiometer
	motorValue = map(potValue, 0, 1023, 0, 255); 
	//scale it to use with motor
	analogWrite(motorPin, motorValue); 
	//sets motor speed according to the value of the potentiometer
	Serial.print("potentiometer ="); 
	Serial.print("potValue");
	Serial.print("t motor =");
	Serial.println(motorValue); 
	delay(2);
}