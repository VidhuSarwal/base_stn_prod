#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <WiFi.h>

// Declare external variables
extern WiFiClient espClient;
extern PubSubClient client;

extern const char* mqtt_server;
extern const int mqtt_port;
extern const char* node1_topic;
extern const char* node2_topic;

// Function declarations
void setup_mqtt();
void reconnect();
void callback(char* topic, byte* payload, unsigned int length);

#endif
