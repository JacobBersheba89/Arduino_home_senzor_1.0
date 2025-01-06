#include <ESP8266WiFi.h>

const char* ssid = "SSID";
const char* password = "Heslo";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..."); }
  Serial.println("Yes, připojeno!"); }
