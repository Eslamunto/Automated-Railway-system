#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9); // RX, TX

//Define Pins
int enableA = 12; int pinA1 = 11; int pinA2 = 10;
boolean run;

void setup()
{

	pinMode(enableA, OUTPUT);
	pinMode(pinA1, OUTPUT);
	pinMode(pinA2, OUTPUT);
	run = true;
	Serial.begin(9600);
	Serial.println("Hello I am the nano of Train B");
	mySerial.begin(9600);
}

void loop() // run over and over
{
	if (mySerial.available()) {


		int receivedByNano = mySerial.read();
		//Serial.write(receivedByNano);
		// Serial.println("recv method");
		//Serial.println("Greetings from nano, i received the following");
		Serial.println(receivedByNano);



		//Case 3 (51)

		if(receivedByNano == 51) {
			enableMotors();
			forward(10);

		}
		else if(receivedByNano == 52) {
			disableMotors();
		}

		//       if(run) {
		//   
		//   enableMotors();
		//   forward(10000);
		//       }


		if (Serial.available()) {

			mySerial.write(Serial.read());


		}

	}
}

void motorAOn() {
	digitalWrite(enableA, HIGH);
}
//void motorBOn() {
// digitalWrite(enableB, HIGH);
//}
//disable motors
void motorAOff()
{
	digitalWrite(enableA, LOW);
}
//void motorBOff() {
// digitalWrite(enableA, LOW);
//}
//motor A controls
void motorAForward() {
	digitalWrite(pinA1, HIGH);
	digitalWrite(pinA2, LOW);
}
void motorABackward() {
	digitalWrite(pinA1, LOW);
	digitalWrite(pinA2, HIGH);
}
//motor B contorls
//void motorBForward() {
// digitalWrite(pinB1, HIGH);
// digitalWrite(pinB2, LOW);
//}
//void motorBBackward() {
// digitalWrite(pinB1, LOW);
// digitalWrite(pinB2, HIGH);
//}
//coasting and braking
void motorACoast() {
	digitalWrite(pinA1, LOW);
	digitalWrite(pinA2, LOW);
}
void motorABrake() {
	digitalWrite(pinA1, HIGH);
	digitalWrite(pinA2, HIGH);
}
//void motorBCoast() {
// digitalWrite(pinB1, LOW);
// digitalWrite(pinB2, LOW);
//}
//void motorBBrake() {
// digitalWrite(pinB1, HIGH);
// digitalWrite(pinB2, HIGH);
//}
//Define High Level Commands
void enableMotors() {
	motorAOn();
	// motorBOn();
}
void disableMotors()
{
	motorAOff();
	// motorBOff();
}
void forward(int time) {
	motorAForward(); 
	//motorBForward();
	delay(time);
}
void backward(int time) {
	motorABackward(); 
	//motorBBackward();
	delay(time);
}
void turnLeft(int time) {
	motorABackward();
	// motorBForward();
	delay(time);
}
void turnRight(int time) {
	motorAForward(); 
	//motorBBackward();
	delay(time);
}
void coast(int time) {
	motorACoast();
	//motorBCoast();
	delay(time);
}
void brake(int time) {
	motorABrake(); 
	//motorBBrake(); 
	delay(time);
}
