#include <Arduino.h>

const int buzzerPin = 7;

const int buttonPin1 = 8;
const int buttonPin2 = 9;
const int buttonPin3 = 10;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;


void setup() {
	pinMode(buttonPin1,INPUT);
	pinMode(buttonPin2,INPUT);
	pinMode(buttonPin3,INPUT);
}

void loop() {
	buttonState1 = digitalRead(buttonPin1);
	buttonState2 = digitalRead(buttonPin2);
	buttonState3 = digitalRead(buttonPin3);


	if(buttonState1 == HIGH) {
		tone(buzzerPin,260,430);
	}
	else if(buttonPin2 == HIGH) {
		tone(buzzerPin,300,600);
	}
	else if(buttonState3 == HIGH) {
		tone(buzzerPin,500,750);
	}

}

