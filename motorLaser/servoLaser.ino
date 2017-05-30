#include <Arduino.h>
#include <Servo.h>

Servo miniServo;  

const int servoPin = 9;
const int laserPin = 2;
const int secondsD = 100;
int degrees = 0;   

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

void setup()
{
	pinMode(laserPin,OUTPUT);
	digitalWrite(laserPin,LOW);
	miniServo.write(0); // position
	miniServo.attach(servoPin);
	Serial.begin(9600);
}

void loop()
{
	digitalWrite(laserPin,HIGH); // laser always on

	if(Serial.available() > 0){
		char command = Serial.read();

		switch(command){
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
