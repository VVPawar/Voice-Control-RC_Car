#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); //TX, RX respetively
String readvoice;
void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);

}
//-----------------------------------------------------------------------//  
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  }  
  if (readvoice.length() > 0) {
    Serial.println(readvoice); 
    Serial.println(readvoice.length());
    readvoice.trim();
    Serial.println(readvoice.length());

  if(readvoice == "go") 
  {
    Serial.println("Forward");
    digitalWrite(8, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite(3,LOW);
    digitalWrite(7,LOW);
    delay(100);
  } 
  
  else if(readvoice == "back") 
  {
    Serial.println("Backward");
    digitalWrite(8, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(7,HIGH);
    delay(100);
  }
  
  else if (readvoice == "up")
  {
    Serial.println("Right");
    digitalWrite (8,HIGH);
    digitalWrite (4,LOW);
    digitalWrite (3,LOW);
    digitalWrite (7,LOW);
    delay (100);
    
  }
    
 else if ( readvoice == "on")
 {
  Serial.println("Left");
   digitalWrite (8, LOW);
   digitalWrite (4, HIGH);
   digitalWrite (3, LOW);
   digitalWrite (7, LOW);
   delay (100);
 }
 
 else if (readvoice == "hello")
 {
  Serial.println("Stop");
   digitalWrite (8, LOW);
   digitalWrite (4, LOW);
   digitalWrite (3, LOW);
   digitalWrite (7, LOW);
   delay (100);
 }

readvoice="";}} //Reset the variable
