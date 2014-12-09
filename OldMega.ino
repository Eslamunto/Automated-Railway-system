#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello I am the Mega");
   mySerial.begin(9600);
}

void loop() // run over and over
{
  if (mySerial.available()) {
     Serial.write(mySerial.read());
     Serial.println("recv Method");
     
     
  }

  if (Serial.available()) {
  
     mySerial.write(Serial.read());
     Serial.println("I am the sending method");
     
  }

}
