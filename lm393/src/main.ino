// Sample code for LM393 microphone - sound sensor 

const int sensorPin = 8;
int value = 0;


void setup() {
	pinMode(sensorPin, INPUT);
	Serial.begin(9600);
}

void loop() {
	value = digitalRead(sensorPin);
	Serial.println(value);
	Serial.println("--------------------");
}
