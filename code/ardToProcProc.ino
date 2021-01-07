float var;
String myStr;
float myNum=0;
 
void setup(){
  println("Available serial ports:"); //print the available serial ports
println(Serial.list());
myPort = new Serial(this, Serial.list()[1], 9600);
 
  size(400, 400);//size of the window
  background (127); //color of the background
}
 
void draw(){
 //reads the serial port
 {
  if ( myPort.available() > 0) 
  { 
    myStr = myPort.readStringUntil('\n');
    if(myStr != null) 
    {
      myStr = myStr.trim();
      myNum = Integer.parseInt(myStr);
 
 
  background (127); //color of the background
  noStroke();
  fill(255); //fill color
  arc(width/2, width/2, radius*2, radius*2, PI, 2*PI); //draw and arc 
 
  // Rotates circle around an arc
  px = width/2 + cos(radians(angle))*(radius);
  py = width/2 - sin(radians(angle))*(radius);
  fill(0);
  ellipse (px, py, 5, 5);
  stroke(100);
  line(width/2, width/2, px, py);
  stroke(200);
  // Keep reinitializing to 0, to avoid
  // flashing during redrawing
  angle2 = 0;
 
noStroke(); 
var = myNum;
  angle = var;
   }
  }
 }
}
