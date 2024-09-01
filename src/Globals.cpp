#include "Globals.h"

//  credentials
const char* ssid = "Airtel_Zerotouch";
const char* password = "Airtel@123";

// mqtt broker settings
const char* mqtt_server = "mqtt.vidhu.co";
const int mqtt_port = 1883;

// esp node IPs
const char* node1_ip = "192.168.0.11";
const char* node2_ip = "192.168.0.13";

// mqtt topics
const char* node1_topic = "node1/relay";
const char* node2_topic = "node2/relay";
const char* node1_state_topic = "node1/relay_state";
const char* node2_state_topic = "node2/relay_state";

// Relay states
bool node1_relay_state[4] = {false, false, false, false};  // Initially all relays are OFF
bool node2_relay_state[4] = {false, false, false, false};  
