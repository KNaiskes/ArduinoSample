#include <Arduino.h>
#include <Servo.h>
#include "autoPilot.h"

extern Servo miniServo;
//const int servoPin = 9;
extern const int servoPin;
extern const int laserPin;
extern const int secondsD;

extern int degrees;

extern void autopilot();
const int secondsD = 20;

void serialControl(){
	if(Serial.available() > 0){
		char command = Serial.read();

		switch(command){
			// fire
			case 'f':
				digitalWrite(laserPin,HIGH);
				delay(secondsD);
				Serial.println("Fire");
				break;
				// ceasefire
			case 'c':
				digitalWrite(laserPin,LOW);
				delay(secondsD);
				Serial.println("Ceasefire");
				break;
			case 'r':
				if(degrees >= 0 && degrees < 180){
				       degrees += 15;	
				       miniServo.write(degrees);
				       Serial.println(degrees);
				       delay(secondsD);
				}else{
					Serial.print("You have reached: ");
					Serial.print(degrees);
					Serial.print(" degress");
					Serial.println();
					delay(secondsD);
				}
				break;
			case 'l':
				if(degrees >= 15 && degrees <= 180){
					degrees -= 15;
					miniServo.write(degrees);
					Serial.println(degrees);
					delay(secondsD);
				}else{

					Serial.print("You have reached: ");
					Serial.print(degrees);
					Serial.print(" degress");
					Serial.println();
					delay(secondsD);
				}
				break;
			case 'd':
				// detach to save battery
				miniServo.detach();
				delay(secondsD);
				break;
			case 'a':
				// attach when it is needed
				miniServo.attach(servoPin);
				delay(secondsD);
				break;
			case 'A':
				autopilot();
				delay(secondsD);
				break;
		}
	}
}

