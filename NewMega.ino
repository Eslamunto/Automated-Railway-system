
 #include <SoftwareSerial.h>
#include <Servo.h> 

SoftwareSerial mySerial(8, 9); // RX, TX
 
int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divider
int led = 13;

Servo myservo1;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo myservo2; 


void setup()
{
  pinMode(led, OUTPUT); 
  myservo1.attach(5);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(6);  // attaches the servo on pin 9 to the servo object 

  
  Serial.begin(9600);
  Serial.println("Hello I am the Mega");
  mySerial.begin(9600);

}

void loop() // run over and over
{
  if (mySerial.available()) {
     Serial.write(mySerial.read());
     Serial.println("recv Method");
     
     
  }

  if (Serial.available()) {

    
    int y = Serial.read();
    //Case 5: line, line
    if(y == 53) {
      myservo1.write(300);
     // myservo2.write(180);
    }
    
    
    
    //case 6: Circle , Circle
    if(y == 54) {
       myservo1.write(300);
      //myservo2.write(0);
    }
    
    
    //Serial.write(y);
    mySerial.write(y);
    Serial.println("I am the sending method");
     
  }
 
}
