#include<Arduino.h>

void pirSensor(const int sensorPin,const int relayChannel) {
	int status = 0;

	status = digitalRead(sensorPin);

	if(status == LOW) {
		digitalWrite(relayChannel,HIGH);
	}
	while(status == HIGH) {
		status = digitalRead(sensorPin);
		digitalWrite(relayChannel,LOW);
		delay(10000);
	}

	delay(2000);


}
