#include "WiFiSetup.h"

void setup_wifi() {
    delay(10);
    Serial.println(); //for debugging
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password); //connect to ssid

    while (WiFi.status() != WL_CONNECTED) { //check for connection status. if connected, break else ....
        delay(500); 
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP()); //print ip and exit function
}
