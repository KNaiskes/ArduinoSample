#include <Arduino.h>

/*
   the blue led is high while sensor detects no movements but if it does then
   blue led is turned low and the red led is turned high while the pir sensor
   detects any movement
   */

const int redLed = 8;
const int blueLed= 6;
const int pirPin = 7;
int status = 0;

void setup()
{
	pinMode(redLed,OUTPUT);
	pinMode(blueLed,OUTPUT);
	pinMode(pirPin,INPUT);
	digitalWrite(redLed,LOW);
}

void loop()
{
	status = digitalRead(pirPin);

	if(status == LOW){
		digitalWrite(redLed,LOW);
		digitalWrite(blueLed,HIGH);
	}

	while(status == HIGH){
		status = digitalRead(pirPin);
		digitalWrite(blueLed,LOW);
		digitalWrite(redLed,HIGH);
		if(status == LOW){
			delay(1000); // do not turn low the red led immediately 
			break;
		}
	}

}
