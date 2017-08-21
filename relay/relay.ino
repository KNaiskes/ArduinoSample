#include<Arduino.h>

const int channel1 = 7;

void setup() {
	pinMode(channel1,OUTPUT);
	Serial.begin(9600);
	digitalWrite(channel1,HIGH);
}

void loop() {
	if(Serial.available() > 0) {
		char command = Serial.read();

		switch(command) {
			case 'o':
				digitalWrite(channel1,HIGH);
				break;
			case 'c':
				digitalWrite(channel1,LOW);
				break;
		}
	}
}
