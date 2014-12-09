#include <Servo.h>
#include <SoftwareSerial.h>
 

SoftwareSerial mySerial(11, 12); // RX, TX
 
int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divider
int led = 13;

Servo myservoRight;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo myservoLeft; 


void setup()
{
  pinMode(led, OUTPUT); 
  myservoRight.attach(5);  // attaches the servo on pin 9 to the servo object 
  myservoLeft.attach(3);  // attaches the servo on pin 9 to the servo object 

  
  Serial.begin(9600);
  Serial.println("Hello I am the Mega");
  mySerial.begin(9600);

}

void loop() // run over and over
{
  

  if (Serial.available()) {

    
    int y = Serial.read();
    //Case 5: line, line
    if(y == 53) {
      myservoRight.write(180);
      myservoLeft.write(0);
    }
    
    
    
    //case 6: Circle , Circle
    if(y == 54) {
       myservoRight.write(0);
      myservoLeft.write(180);
    }
    
    
    //Serial.write(y);
    mySerial.write(y);
    Serial.println("I am the sending method");
     
  }
 
}
