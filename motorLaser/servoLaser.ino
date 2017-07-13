#include <Arduino.h>
#include <Servo.h>
#include "serialControl.h"
#include "autoPilot.h"

Servo miniServo;  

//const int servoPin = 9;
extern const int servoPin = 9;
const int laserPin = 2;

const int secondsD = 100; //delay

int degrees = 0;   


void setup()
{
	pinMode(laserPin,OUTPUT);
	digitalWrite(laserPin,LOW);
	miniServo.write(0); // position
	miniServo.attach(servoPin);
	Serial.begin(9600);
}

void loop()
{
	digitalWrite(laserPin,HIGH); // laser always on

	serialControl();	
}
