#include<Arduino.h>
#include<Servo.h>

extern int degrees;
extern int laserPin;
extern Servo miniServo;

const int btnR = 8;
const int btnF = 7;
const int btnL = 6;

int btnStateR = 0;
int btnStateF = 0;
int btnStateL = 0;

const int secondsD = 70;

void btnSetup()
{
	pinMode(btnR,INPUT);
	pinMode(btnF,INPUT);
	pinMode(btnL,INPUT);

}

void btnControl()
{
	btnStateR = digitalRead(btnR);
	btnStateF = digitalRead(btnF);
	btnStateL = digitalRead(btnL);

	if(btnStateR == HIGH){
		if(degrees >= 0 && degrees < 180){
			degrees += 15;
			miniServo.write(degrees);
			delay(secondsD);
		}
	}
	else if(btnStateF == HIGH){
		digitalWrite(laserPin,HIGH);
		delay(secondsD);
	}
	else if(btnStateL == HIGH){
		if(degrees >= 15 && degrees <= 180){
			degrees -= 15;
			miniServo.write(degrees);
			delay(secondsD);
		}
	}
}




