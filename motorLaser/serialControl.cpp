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

void serialControl(){
	if(Serial.available() > 0){
		char command = Serial.read();

		switch(command){
			case 'f':
				digitalWrite(laserPin,HIGH);
				break;
			case 'r':
				if(degrees >= 0 && degrees < 180){
				       degrees += 15;	
				       miniServo.write(degrees);
				       Serial.println(degrees);
				       delay(2);
				}else{
					Serial.print("You have reached: ");
					Serial.print(degrees);
					Serial.print(" degress");
					Serial.println();
					delay(2);
				}
				break;
			case 'l':
				if(degrees >= 15 && degrees <= 180){
					degrees -= 15;
					miniServo.write(degrees);
					Serial.println(degrees);
					delay(2);
				}else{

					Serial.print("You have reached: ");
					Serial.print(degrees);
					Serial.print(" degress");
					Serial.println();
					delay(2);
				}
				break;
			case 'd':
				// detach to save battery
				miniServo.detach();
				delay(2);
				break;
			case 'a':
				// attach when it is needed
				miniServo.attach(servoPin);
				delay(2);
				break;
			case 'A':
				autopilot();
				delay(2);
				break;
		}
	}
}

