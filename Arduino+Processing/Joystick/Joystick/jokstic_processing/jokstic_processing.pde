import processing.serial.*;
Serial myPort;
void setup() {
  size(512, 512);
  //println(Serial.list());
  String portName = Serial.list()[2];
  //where 0 is dependent on the "com" port number.
  //println(portName);
  
  myPort = new Serial(this, portName, 9600);

}
int X, Y, Button;

void draw() {
  getData();
  background(255);
  if (Button == 0)
     fill(255, 0, 0);
  else
     fill(0, 255, 0);
  ellipse(Y/2, X/2, 50, 50);
}

void getData() {
  String msg;
  if (myPort.available() > 0) {
    msg = myPort.readStringUntil('\n');
  
  if (msg != null)
  {
        msg = trim(msg);
        println(msg);
        String[] token = msg.split(",");
        X=int(token[0]);
        Y=int(token[1]);
        Button=int(token[2]);
        println(X, Y, Button);
  }
  }
}
