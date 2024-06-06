#include <Arduino.h>
#include "WiFiSetup.h"
#include "MQTTSetup.h"

#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  setupWiFi();
  setupMQTT();
}

void loop() {
  if (!mqttClient.connected()) {
    reconnectMQTT();
  }
  mqttClient.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  if (message == "ON") {
    digitalWrite(LED_PIN, HIGH);
  } else if (message == "OFF") {
    digitalWrite(LED_PIN, LOW);
  }
}
