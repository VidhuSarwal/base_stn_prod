#ifndef SENSORPUBLISHER_H
#define SENSORPUBLISHER_H


#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "Globals.h"
#include <HTTPClient.h>  
#include "MQTTClient.h"
#include <WiFiClient.h>

void setupSensorPublisher(PubSubClient& client, const char* topic);
void sensorTask(void * parameter);
void setupSensorPublisherTask();

#endif
