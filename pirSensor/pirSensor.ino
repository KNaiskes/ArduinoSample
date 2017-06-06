#include <Arduino.h>

/*
   the blue led is high while sensor detects no movements but if it does then
   blue led is turned low and the red led is turned high while the pir sensor
   detects any movement

   Added a laser to fire up when movement is detected
   */

const int redLed = 8;
const int blueLed= 6;
const int pirPin = 7;
int status = 0;

//laser
const int laserPin = 2;

void setup()
{
	pinMode(redLed,OUTPUT);
	pinMode(blueLed,OUTPUT);
	pinMode(pirPin,INPUT);
	pinMode(laserPin,OUTPUT);
	digitalWrite(redLed,LOW);
	digitalWrite(laserPin,LOW);

}

void loop()
{
	status = digitalRead(pirPin);

	if(status == LOW){
		digitalWrite(redLed,LOW);
		digitalWrite(laserPin,LOW);
		digitalWrite(blueLed,HIGH);
	}

	while(status == HIGH){
		status = digitalRead(pirPin);
		digitalWrite(blueLed,LOW);
		digitalWrite(redLed,HIGH);
		digitalWrite(laserPin,HIGH);
		if(status == LOW){
			delay(2000); // do not turn low the red led immediately 
			break;
		}
	}

}
