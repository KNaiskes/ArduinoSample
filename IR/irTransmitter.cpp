#include <IRremote.h>

//gpio must be connected to pin 3 

IRsend irSend;

void setup() {
	Serial.begin(9600);
	delay(3000);
}

void loop() {
	if(Serial.available() > 0) {
		String command = Serial.readString();
		command.trim();
		if(command == "send") {
			irSend.sendNEC(0xF7C03F, 32); //example from led strip
			delay(10);
		}
	}
}


