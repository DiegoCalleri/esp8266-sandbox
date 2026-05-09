#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "";              // <-- замените
const char* password = "";          // <-- замените

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
 if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    String url = ""; // <-- замените
    http.begin(client, url);
    http.addHeader("Content-Type", "application/json");

    String json = "{\"key\":\"value\",\"num\":123}"; // тело POST

    int httpCode = http.POST(json);
    if (httpCode > 0) {
      Serial.printf("HTTP code: %d\n", httpCode);
      String resp = http.getString();
      Serial.println("Response:");
      Serial.println(resp);
    } else {
      Serial.printf("POST failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
  delay(10000);
}