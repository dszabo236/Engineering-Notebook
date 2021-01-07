const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW; // ensures that data is shared between ISR and main program
int n = 0;
 
void setup() {
  pinMode(ledPin, OUTPUT); //Sets LED to output
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE); 
  //reads interrupt pin- executes blink function if the photointerrupter state changes
  Serial.begin(9600);
}
 
void loop() {
  digitalWrite(ledPin, state); //makes LED HIGH or LOW depending on state of photointerrupter
 	 Serial.println(n); //prints when photointerrupter is being interrupted
}
 
void blink() {
  state = !state; //negates boolean 
  n = n+1; //count up one with each change of photointerrupter
}