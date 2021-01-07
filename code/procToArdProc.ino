import processing.serial.*; //establish serial communication between arduino and processing
Serial myPort; //establish serial communication
int val = 0;

void setup(){
  println("Available serial ports:"); //print all available serial ports
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[1], 9600);
 
  size(200, 200); //size of the window 
  line(100, 0, 100, 200); //draw a line  
  stroke(250); //line thickness
}  

void draw(){
  print(mouseX); //print the x position of the mouse
  print(" "); //print a space
}

void mouseMoved(){
  myPort.write(mouseX); //changes the value that is written based on position of mouse
  val = val + 5;

  if(val > 255){
    val = 0;
 }
}