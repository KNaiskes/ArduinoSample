#include<Arduino.h>

const int pin = 13;

void setup()
{
	pinMode(pin,OUTPUT);
}

void loop()
{
	// turns on the built-in led
	digitalWrite(pin,HIGH);
	delay(1000);
	digitalWrite(pin,LOW);
	delay(1000);

}

