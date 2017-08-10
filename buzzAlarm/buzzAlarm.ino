#include<Arduino.h>

// an alarm system that can be used with two different sensors
// a pir sensor or a distance sensor

const int buzzerPin = 7;

void setup() {}

void loop() {
	tone(buzzerPin,2000,700);
	delay(1000);
}
