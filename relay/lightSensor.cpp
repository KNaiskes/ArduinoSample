#include<Arduino.h>

void lightSensor(const int sensorPin,const int relayChannel) {
	int lightStatus = 0;

	lightStatus = analogRead(sensorPin);

	if(lightStatus < 300) {
		digitalWrite(relayChannel,LOW);
		delay(10000);
	}
	else {
		digitalWrite(relayChannel,HIGH);
		delay(2000);
	}
	delay(2000);
}

