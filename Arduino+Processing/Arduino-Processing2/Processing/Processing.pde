// Processing code
import processing.serial.*;
Serial port; // Create object from Serial class
int val; // Data received from the serial port
PImage balloon;
int offset1,offset2;
void setup() {
  size(800, 800);
  frameRate(10);
  // Open the port that the board is connected to and use the same speed (9600 bps)
  //println(Serial.list());
  String portName = Serial.list()[2];
  //where 0 is dependent on the "com" port number.
  
  port = new Serial(this, portName, 9600);
  balloon=loadImage("balloon.png");
  background(255); // Set background to white
  fill(255);
  stroke(5);
  line(400,0,400,800);
  offset1=100;
  offset2=100;
}
void draw() {
  background(255); // Set background to white
  fill(255);
  stroke(5);
  line(400,0,400,800);
  
  if (0 < port.available()) { // If data is available,
  val = port.read(); // read it and store it in val
  println(val);
}
  if(val==1){
    // j==0 i==1
    offset1+=10;
  }else if(val==2){
    // j==1 i==0 
    offset2+=10;
  }else if(val==3){
    //j==1 i==1
    offset1+=10;
    offset2+=10;
  }
  if(offset1>300){
    offset1=100;
  }
  if(offset2>300){
    offset2=100;
  }
  image(balloon,100,100,offset1,offset1);
  image(balloon,500,100,offset2,offset2);
  //println(offset1+" "+offset2);
}
