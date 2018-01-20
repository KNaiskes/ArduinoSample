#include <IRremote.h>

const int recvPin = 7;

IRrecv irRecv(recvPin);
decode_results result;

void setup() {
	Serial.begin(9600);
	irRecv.enableIRIn();
}

void loop() {
	if(irRecv.decode(&result)) {
		Serial.println(result.value, HEX);
		irRecv.resume(); //get the next value
	}
}
