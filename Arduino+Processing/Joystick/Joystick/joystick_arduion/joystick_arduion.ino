int xValue = 0 ; // read value of the X axis  
int yValue = 0 ; // read value of the Y axis  
int bValue = 0 ; // value of the button reading 

void setup()  
{ 
  Serial.begin(9600) ; // Open the serial port
  pinMode(8,INPUT) ; // Configure Pin 2 as input
  digitalWrite(8,HIGH); 
} 

void loop() 
{ 
  // Read analog port values A0 and A1  
  xValue = analogRead(A0);  
  yValue = analogRead(A1);  

  // Read the logic value on pin 2  
  bValue = digitalRead(8);  

  // We display our data separated by a comma 
  Serial.print(xValue,DEC);
  Serial.print(",");
  Serial.print(yValue,DEC);
  Serial.print(",");
  Serial.print(!bValue);

  // We end with a newline character to facilitate subsequent analysis  
  Serial.print("\n");

  // Small delay before the next measurement  
  delay(20);  
}
