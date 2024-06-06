#ifndef MQTT_SETUP_H
#define MQTT_SETUP_H

#include <PubSubClient.h>

extern WiFiClient espClient;
extern PubSubClient mqttClient;

void setupMQTT();
void reconnectMQTT();

#endif
