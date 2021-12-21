// Processing code
import processing.serial.*;
Serial port; // Create object from Serial class
int val; // Data received from the serial port
void setup() {
  size(200, 200);
  frameRate(10);
  // Open the port that the board is connected to and use the same speed (9600 bps)
  println(Serial.list());
  String portName = Serial.list()[2];
  //where 0 is dependent on the "com" port number.
  
  port = new Serial(this, portName, 9600);
}
void draw() {
  if (0 < port.available()) { // If data is available,
  val = port.read(); // read it and store it in val
}
background(255); // Set background to white
  if (val == 0) { // If the serial value is 0,
  fill(0); // set fill to black
  } else { // If the serial value is not 0,
  fill(204); // set fill to light gray
  }
  rect(50, 50, 100, 100);
}
