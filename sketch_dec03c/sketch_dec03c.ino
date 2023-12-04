#define BLYNK_TEMPLATE_ID "TMPL438mN5e40"
#define BLYNK_TEMPLATE_NAME "kitchen light"
#define BLYNK_AUTH_TOKEN "Your Auth Token"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "*****"; // Ваш токен Blynk

char ssid[] = "*****"; // Название вашей точки доступа
char pass[] = "*****"; // Пароль к точке доступа

int RelayPin = 13; // Пин, на который подключено реле

BLYNK_WRITE(V0) // Вызовется при обновлении виртуального порта V0 
{
  int pinValue = param.asInt(); // Считываем новое значение порта
  digitalWrite(RelayPin, pinValue); // Устанавливаем значение на пин
}

void setup()
{
  Serial.begin(9600);
  pinMode(RelayPin, OUTPUT); // Настройка порта RelayPin на выход
  
  Blynk.begin(auth, ssid, pass); // Инициализация и подключение к Blynk
}

void loop()
{
  Blynk.run(); // Вызов в цикле необходим для работы Blynk
}
