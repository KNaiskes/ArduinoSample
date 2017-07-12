//keep the led off all the time but turn it on when the button is pressed
//and send a message in the serial monitor 

#include <Arduino.h>

const int buttonPin = 7;
const int ledPin = 8;

int buttonState = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(buttonPin,INPUT);
	pinMode(ledPin,OUTPUT);
}

void loop()
{
	buttonState = digitalRead(buttonPin);

	if(buttonState == HIGH){
		Serial.println("Button has been pressed");
		digitalWrite(ledPin,HIGH);
		delay(50);
		}
	else{
		digitalWrite(ledPin,LOW);
	}
	
}

