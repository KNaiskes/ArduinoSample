#include <Arduino.h>

const int leds[7] = {2,3,4,5,6,7,8};
const int sizeOfArray = 7;


void setup()
{
	for(int i = 0; i < sizeOfArray; i++){
		pinMode(leds[i],OUTPUT);
	}
}
	

void loop()
{
	for(int i = 0; i < sizeOfArray; i++){
		digitalWrite(leds[i],HIGH);
	}
	delay(1000);
	for(int i = 0; i < sizeOfArray; i++){
		digitalWrite(leds[i],LOW);
	}
	delay(100);

	for(int i = 0; i < sizeOfArray; i++){
		digitalWrite(leds[i],HIGH);
		delay(500);
		digitalWrite(leds[i],LOW);
		delay(500);
	}
	
}
