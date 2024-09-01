#ifndef RELAYCONTROL_H
#define RELAYCONTROL_H

#include <HTTPClient.h>
#include <ArduinoJson.h>

extern const char* node1_ip;
extern const char* node2_ip;

extern bool node1_relay_state[4];
extern bool node2_relay_state[4];

void controlRelay(const char* node_ip, const char* relay, const char* state, bool* relay_state, int relay_index);
void publishRelayState(const char* node_state_topic, const JsonDocument& doc);

#endif
