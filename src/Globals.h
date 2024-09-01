#ifndef GLOBALS_H
#define GLOBALS_H

// Wi-Fi credentials
extern const char* ssid;
extern const char* password;

// MQTT broker settings
extern const char* mqtt_server;
extern const int mqtt_port;

// ESP8266 node IPs
extern const char* node1_ip;
extern const char* node2_ip;

// MQTT topics
extern const char* node1_topic;
extern const char* node2_topic;
extern const char* node1_state_topic;
extern const char* node2_state_topic;
extern const char* node1_sensor;
extern const char* node2_sensor;


// Relay states
extern bool node1_relay_state[4];
extern bool node2_relay_state[4];

#endif
