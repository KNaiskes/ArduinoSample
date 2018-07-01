const int soundSensor = 7;
int sound = 0;

void setup() {
  pinMode(soundSensor, INPUT);
  Serial.begin (9600);
}
  
void loop () {
	sound = digitalRead(soundSensor);
	Serial.println(sound);
	delay(50);
}
