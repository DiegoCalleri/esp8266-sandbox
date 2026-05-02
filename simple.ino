#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Ваша_сеть";
const char* password = "Ваш_пароль";
const int ledPin = D4;

ESP8266WebServer server(80);

void setup() {
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, HIGH); // Выключаем светодиод

Serial.begin(115200);

// Подключение к Wi-Fi
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.print("Подключено к WiFi. IP-адрес: ");
Serial.println(WiFi.localIP());

// Настройка маршрутов для веб-сервера
server.on("/", handleRoot);
server.on("/on", handleOn);
server.on("/off", handleOff);

server.begin();
Serial.println("HTTP сервер запущен");
}

void loop() {
server.handleClient();
}

void handleRoot() {
String html = "<!DOCTYPE html><html><body>";
html += "<meta charset=\"UTF-8\">";
html += "<h1>Управление светодиодом ESP8266</h1>";
html += "<p><a href=\"/on\"><button>Выключить</button></a></p>";
html += "<p><a href=\"/off\"><button>Включить</button></a></p>";
html += "</body></html>";
server.send(200, "text/html; charset=utf-8", html);
}

void handleOn() {
digitalWrite(ledPin, LOW); // Включаем светодиод
server.sendHeader("Location", "/");
server.send(303);
}

void handleOff() {
digitalWrite(ledPin, HIGH); // Выключаем светодиод
server.sendHeader("Location", "/");
server.send(303);
}