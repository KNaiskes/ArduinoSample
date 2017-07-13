#include <Arduino.h>
#include <Servo.h>
#include "serialControl.h"

Servo miniServo;  

//const int servoPin = 9;
extern const int servoPin = 9;
const int laserPin = 2;

const int secondsD = 100; //delay

//buttons
const int buttonR = 5;
const int buttonL = 6;


int degrees = 0;   

void autopilot(){
	for(degrees = 0; degrees < 180; degrees++){
		miniServo.write(degrees);
		delay(secondsD);
	}
	for(degrees = 180; degrees > 0; degrees--){
		miniServo.write(degrees);
		delay(secondsD);
	}
}



void setup()
{
	pinMode(laserPin,OUTPUT);
	digitalWrite(laserPin,LOW);
	miniServo.write(0); // position
	miniServo.attach(servoPin);
	Serial.begin(9600);
	//serialControl.setup();
	//serialControl();
}

void loop()
{
	digitalWrite(laserPin,HIGH); // laser always on

	//serialControl();
	serialControl();	
}
