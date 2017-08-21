#include<Arduino.h>
void serialControl(const int relayChannel) {
	if(Serial.available() > 0) {
		char command = Serial.read();

		switch(command) {
			case 'o':
				digitalWrite(relayChannel,LOW);
				delay(200);
				Serial.println("Relay is on");
				break;
			case 'c':
				digitalWrite(relayChannel,HIGH);
				delay(200);
				Serial.println("Relay is off");
				break;
		}
	}
}
