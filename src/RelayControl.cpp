#include "RelayControl.h"
#include "MQTTClient.h"
//std fx to control relay status. 
void controlRelay(const char* node_ip, const char* relay, const char* state, bool* relay_state, int relay_index) {
    bool desired_state = (strcmp(state, "ON") == 0);

    if (relay_state[relay_index] != desired_state) {
        String url = "http://" + String(node_ip) + "/" + String(relay) + "/toggle";
        HTTPClient http;

        http.begin(url);
        int httpCode = http.GET();

        if (httpCode > 0) {
            Serial.printf("Relay %s on node %s toggled to %s\n", relay, node_ip, state);
            relay_state[relay_index] = desired_state;  // Update relay state
        } else {
            Serial.printf("Error toggling relay %s on node %s: %s\n", relay, node_ip, http.errorToString(httpCode).c_str());
        }

        http.end();
    } else {
        Serial.printf("Relay %s on node %s is already %s, no action taken.\n", relay, node_ip, state);
    }
}

void publishRelayState(const char* node_state_topic, const JsonDocument& doc) {
    char buffer[256];
    if(node_state_topic == "node1/relay_state") {
        Serial.println("Node 1 sent it");
        Serial.println(buffer);
    } else if (node_state_topic == "node2/relay_state" ) {
        Serial.println(" Node 2 sent It");
        Serial.println(buffer);

    } else {
        Serial.println("idk who the hell sent it");
        Serial.println(node_state_topic);
        Serial.println(buffer);
    }
    size_t n = serializeJson(doc, buffer);
    client.publish(node_state_topic, buffer, n);
}

