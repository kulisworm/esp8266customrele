#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "ваш_SSID"; //впишите ващ SSID 2.4G WiFi
const char *password = "ваш_пароль"; //ну и пароль

ESP8266WebServer server(80);

const int relayPin = 2; // D4 пин

void setup() {
  Serial.begin(115200);

  // Подключение к Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");

  // Определение пина реле как OUTPUT
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Изначально реле закрыто

  // Определение HTTP endpoint для управления реле
  server.on("/open", HTTP_GET, [](){
    digitalWrite(relayPin, LOW); // Открытие реле
    delay(500); // Подождать полсекунды
    digitalWrite(relayPin, HIGH); // Закрытие реле
    server.send(200, "text/plain", "Реле открыто и закрыто");
  });

  // Запуск веб-сервера
  server.begin();
}

void loop() {
  server.handleClient();
}
