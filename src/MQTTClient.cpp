#include "MQTTClient.h"
#include "RelayControl.h"
#include "Globals.h"

WiFiClient espClient;  // Create espClient object, use it for WiFi controlling
PubSubClient client(espClient);  // Pass the espClient object as MQTT client

void setup_mqtt() {
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback); // Define the callback function to handle MQTT messages
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP32Client")) {
            Serial.println("connected");
            client.subscribe(node1_topic);
            client.subscribe(node2_topic);
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void callback(char* topic, byte* payload, unsigned int length) {
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, payload, length);

    if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }

    const char* relay1 = doc["relay1"];
    const char* relay2 = doc["relay2"];
    const char* relay3 = doc["relay3"];
    const char* relay4 = doc["relay4"];

    if (strcmp(topic, node1_topic) == 0) {
        controlRelay(node1_ip, "relay1", relay1, node1_relay_state, 0);
        controlRelay(node1_ip, "relay2", relay2, node1_relay_state, 1);
        controlRelay(node1_ip, "relay3", relay3, node1_relay_state, 2);
        controlRelay(node1_ip, "relay4", relay4, node1_relay_state, 3);
        delay(10);
        publishRelayState(node1_state_topic, doc);
    } else if (strcmp(topic, node2_topic) == 0) {
        controlRelay(node2_ip, "relay1", relay1, node2_relay_state, 0);
        controlRelay(node2_ip, "relay2", relay2, node2_relay_state, 1);
        controlRelay(node2_ip, "relay3", relay3, node2_relay_state, 2);
        controlRelay(node2_ip, "relay4", relay4, node2_relay_state, 3);
        delay(10);
        publishRelayState(node2_state_topic, doc);
    }
}
