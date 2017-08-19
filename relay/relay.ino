#include<Arduino.h>

const int c1 = 7;

void setup() {
	pinMode(c1,OUTPUT);
	digitalWrite(c1,LOW);
}

void loop() {

	digitalWrite(c1,LOW);
	delay(3000);
	digitalWrite(c1,HIGH);
	delay(3000);
}
