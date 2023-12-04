#include <ESP8266WiFi.h>
const char* ssid = "wifissid";    
const char* password = "wifipass";   
int LED = 2;   // rele connected to GPIO2 (D4)
WiFiServer server(80);
void setup()
{
Serial.begin(115200); 
pinMode(LED, OUTPUT);
digitalWrite(LED, HIGH);
Serial.print("Connecting to the Newtork");
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("WiFi connected"); 
server.begin();  // Starts the Server
Serial.println("Server started");
Serial.print("IP Address of network: "); 
Serial.println(WiFi.localIP());
Serial.print("Copy and paste the following URL: https://"); 
Serial.print(WiFi.localIP());
Serial.println("/");
}
void loop()
{
WiFiClient client = server.available();
if (!client)
{
return;
}
Serial.println("Waiting for new client");
while(!client.available())
{
delay(1);
 }
String request = client.readStringUntil('\r');
Serial.println(request);
client.flush();
int value = LOW;
if(request.indexOf("/LED=ON") != -1)
{
  digitalWrite(LED, LOW); // Turn LED ON
  delay(500);
  digitalWrite(LED, HIGH);
value = HIGH;
  }
  if(request.indexOf("/LED=OFF") != -1)
 {
  digitalWrite(LED, LOW); 
  delay(500);
  digitalWrite(LED, HIGH);
   value = LOW;
 }
 
//*------------------HTML Page Code-------------------
client.println("HTTP/1.1 200 OK"); 
client.println("Content-Type: text/html");
client.println("");
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.print("<center>");
client.println("<body><h1>WebControl</h1>");
client.println("");
client.println("<body><h1>ON=off OFF=on</h1>");
client.println("Rele:");
  if(value == HIGH)
  {
    client.print("ON");
  }
 else
  {
    client.print("OFF");
 }
 client.println("<br><br>");
 client.println("<a href=\"/LED=ON\"\"><button\">ON</button></a>");
 client.println("<a href=\"/LED=OFF\"\"><button\">OFF</button></a><br />");
client.print("</center>");
  client.println("</html>");
 delay(1);
 Serial.println("Client disonnected");
 Serial.println("");
}
