#include<Arduino.h>

// an alarm system that can be used with two different sensors
// a pir sensor or a distance sensor

const int buzzerPin = 7;

// pir sensor
const int pirPin = 8;
int status;

// distance sensor
const int echoPin = 5;
const int triggerPin = 6;


void simpleTest(const int buzzer) {
	tone(buzzerPin,200,700);
	delay(60000);
}

void pirSensor(int pir ) {
	pir = digitalRead(pirPin);
	while(pir == HIGH) {
		pir = digitalRead(pirPin);
		tone(buzzerPin,400,700);
		delay(2000);
		tone(buzzerPin,450,650);
		delay(2000);
		tone(buzzerPin,300,500);
		delay(2000);
	}
}

void distanceSensor(int trig, int echo) {
	long duration;
	int distance;

	duration = pulseIn(echo,HIGH);
	digitalWrite(trig,HIGH);
	digitalWrite(trig,LOW);

	distance = duration * 0.034 / 2;
	if(distance < 5) {
		tone(buzzerPin,500,500);
	}

}

void setup() {
	// pir sensor
	//pinMode(pirPin,INPUT);
	// distance sensor
	pinMode(triggerPin,OUTPUT);
	pinMode(echoPin,INPUT);

}
	
void loop() {
	//pirSensor(status);
	//distanceSensor(triggerPin,echoPin);
	simpleTest(buzzerPin);
}
