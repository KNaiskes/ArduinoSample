#include <Arduino.h>
#include <Servo.h>

const int secondsD = 50;

extern Servo miniServo;
extern int degrees;

void autopilot(){
	for(degrees = 0; degrees < 180; degrees++){
		miniServo.write(degrees);
		delay(secondsD);
	}
	for(degrees = 180; degrees > 0; degrees--){
		miniServo.write(degrees);
		delay(secondsD);
	}
}
