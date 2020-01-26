#include<Arduino.h>

const int channelsNum = 4;

const int channelsList [channelsNum] = {5, 6, 7, 8};

void setup() {
  for(int i = 0; i < channelsNum; i++) {
    pinMode(channelsList[i], OUTPUT);
  }

  for(int i = 0; i < channelsNum; i++) {
    digitalWrite(channelsList[i], HIGH);
  }

}

void loop() {
  // Test all channels first
  for(int i = 0; i < channelsNum; i++) {
    digitalWrite(channelsList[i], LOW);
    delay(5000);
    digitalWrite(channelsList[i], HIGH);
    delay(5000);
  }

  // Test two channels at the same time
  for(int i = 0; i < channelsNum; i++) {
    int j = i + 1;
    digitalWrite(channelsList[i], LOW);
    digitalWrite(channelsList[j], LOW);
    delay(3000);
  }

  for(int i = 0; i < channelsNum; i++) {
    int j = i + 1;
    digitalWrite(channelsList[i], HIGH);
    digitalWrite(channelsList[j], HIGH);
    delay(4000);
  }

    for(int i = 2; i < channelsNum; i++) {
      int j = i + 1;
    digitalWrite(channelsList[i], LOW);
    digitalWrite(channelsList[j], LOW);
    delay(4000);
  }

  for(int i = 2; i < channelsNum; i++) {
    int j = i + 1;
    digitalWrite(channelsList[i], HIGH);
    digitalWrite(channelsList[j], HIGH);
    delay(4000);
  }

}
