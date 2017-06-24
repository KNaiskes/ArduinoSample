#include <Arduino.h>

const int echoPin = 7;
const int triggerPin = 8;

const int delayTime = 5000;

long duration;
int distance;

void setup(){
	pinMode(triggerPin,OUTPUT);
	pinMode(echoPin,INPUT);
	//Serial.begin(115200);
	Serial.begin(9600);
}

void loop(){
	digitalWrite(triggerPin,HIGH);
	digitalWrite(triggerPin,LOW);
	//delay(delayTime);
	duration = pulseIn(echoPin,HIGH);

	distance = duration*0.034/2;

	Serial.print("Object's distance:");
	Serial.println(distance);
	delay(delayTime);
}
