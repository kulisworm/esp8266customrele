# Включение и выключение ПК используя esp8266 с реле.   
Поддерживается Яндекс Алиса и веб интерфейс  
Работает все тупо на http запросах, просто и сердито  
Запросы выполняются следующим образом для включения и выключения соответственно:  
> http://ipyouresp/LED=OFF  
> http://ipyouresp/LED=ON  

Из-за ошибок в коде "OFF" используется для включения и "ON" для выключения  
Для работы нам потребуется провода ,плата NodeMcu3 ESP8266 и модуль реле, схема подключения следующаяя:  
![image](https://github.com/kulisworm/esp8266pccontrol/assets/59212398/710b0a74-acc3-4de6-88f7-1ade025d7c8d)
