#include <Arduino.h>
#include <Servo.h>

Servo miniServo;  

const int servoPin = 9;
const int laserPin = 2;
const int secondsD = 1000;
int degrees = 0;   


void setup()
{
	pinMode(laserPin,OUTPUT);
	digitalWrite(laserPin,LOW);
	miniServo.attach(servoPin);
}

void loop()
{
	digitalWrite(laserPin,HIGH);
	for(degrees = 0; degrees < 180; degrees++){
		miniServo.write(degrees);
		delay(secondsD);
	}
	for(degrees = 180; degrees > 0; degrees--){
		miniServo.write(degrees);
		delay(secondsD);
	}
}
