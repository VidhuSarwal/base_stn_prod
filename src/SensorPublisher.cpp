#include "SensorPublisher.h"
#include <HTTPClient.h>

// Declare global variables if needed
extern const char* node1_ip;
extern const char* node2_ip;

// HTTP GET request function
String httpGETRequest(const String& url) {
    HTTPClient http;
    Serial.print("Requesting URL: ");
    Serial.println(url);  // Debugging line to check the URL
    http.begin(url);
    int httpResponseCode = http.GET();

    String payload = "{}"; // Default to empty JSON object
    if (httpResponseCode > 0) {
        payload = http.getString();
    } else {
        Serial.print("Error on HTTP request: ");
        Serial.println(httpResponseCode);  // Print the error code
    }
    http.end();
    return payload;
}

// Setup function to initialize the sensor publisher task
void setupSensorPublisher(PubSubClient& client, const char* topic) {
    // Create a task on the APP_CORE
    xTaskCreatePinnedToCore(
        [](void* parameter) {
            PubSubClient* client = static_cast<PubSubClient*>(parameter);
            while (true) {
                // Construct the URLs
                String node1URL = String("http://") + node1_ip + "/sensor";
                String node2URL = String("http://") + node2_ip + "/sensor";

                // Request sensor data
                String node1SensorData = httpGETRequest(node1URL);
                String node2SensorData = httpGETRequest(node2URL);

                // Publish data to MQTT topics
                client->publish("node1/sensor", node1SensorData.c_str());
                Serial.println(node1SensorData.c_str());
                client->publish("node2/sensor", node2SensorData.c_str());
                Serial.println(node2SensorData.c_str());

                // Delay before the next iteration
                vTaskDelay(2000 / portTICK_PERIOD_MS);
            }
        },
        "SensorTask",
        4096,
        &client, // Pass the client to the task
        1,
        NULL,
        1
    );
}
