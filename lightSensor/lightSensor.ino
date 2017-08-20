#include<Arduino.h>

const int led = 7;
const int lightSensor = A0;
const int brightness = 300;

void setup() {
	pinMode(led,OUTPUT);
}

void loop() {
	int lightStatus = analogRead(lightSensor);

	if(lightStatus < brightness) {
		digitalWrite(led,HIGH);
	}else{
		digitalWrite(led,LOW);
	}
	delay(4000);
}
