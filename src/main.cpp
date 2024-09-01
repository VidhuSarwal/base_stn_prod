#include "WiFiSetup.h"
#include "MQTTClient.h"
#include "RelayControl.h"
#include "Globals.h"
#include "SensorPublisher.h"  // Include the new header

const char* topic = "node1/sensor"; // Define your topic here

void setup() {
    Serial.begin(115200);
    setup_wifi();
    setup_mqtt(); // Ensure this sets up the client correctly

    // Start the sensor publishing task on the second core
    setupSensorPublisher(client, topic);
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
}
