/**
 * Bounce. 
 * 
 * When the shape hits the edge of the window, it reverses its direction. 
 */
 
int rad = 15;        // Width of the shape
float xpos, ypos;    // Starting position of shape    
 
float xspeed = 2.8;  // Speed of the shape
float yspeed = 2.2;  // Speed of the shape
 
int xdirection = 1;  // Left or Right
int ydirection = 1;  // Top to Bottom
 
 
void setup() 
{
  size(300, 300); //size of the screen
  stroke(0, 255, 0); //makes the edge green
  frameRate(150); //runs it 150 tps
  ellipseMode(RADIUS);
  fill(150, 0, 150); //fills the circle purple 
  xpos = width/2; //sets the x starting position
  ypos = height/2; //sets the y starting position
  println("Hello World"); //print hello world
}
 
void draw() 
{
  background(0, 0, 255); //makes the background blue
 
  // Update the position of the shape
  xpos = xpos + ( xspeed * xdirection );
  ypos = ypos + ( yspeed * ydirection );
 
  // Test to see if the shape exceeds the boundaries of the screen
  // If it does, reverse its direction by multiplying by -1
  if (xpos > width-rad || xpos < rad) {
    xdirection *= -1;
  }
  if (ypos > height-rad || ypos < rad) {
    ydirection *= -1;
  }
 
  // Draw the shape
  ellipse(xpos, ypos, rad, rad);
}