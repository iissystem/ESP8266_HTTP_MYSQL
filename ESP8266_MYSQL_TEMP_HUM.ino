#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
// sensor im using for this progect is DHT11
#include "DHT.h"

#define DPIN 4
#define DTYPE DHT11

DHT dht(DPIN,DTYPE);
// please change here your local wifi detail
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASWORD";
// you must chage to your domain name here
const char* SERVER_NAME = "http://YOUR_DOMAIN_NAME_/w_station/pushdata.php";
// api key must be the same here and your pushdata.php file to work it as well
String PROJECT_API_KEY = "pushdata_test_2025";

unsigned long lastMillis = 0;
long interval = 5000;

void setup() {
  Serial.begin(9600);
  Serial.println("esp8266 serial initialize");

  dht.begin();
  Serial.println("initialize DHT11 sensor");

  WiFi.begin(ssid, password);
  Serial.println("Connecting to the wifi");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable),");
  Serial.println("it will take 5 seconds before publishing the first reading.");
}

void loop() {
  
  if(WiFi.status()== WL_CONNECTED){
    if(millis() - lastMillis > interval) {
       
       upload_temperature();
       lastMillis = millis();
    }
  }
  
  else {
    Serial.println("WiFi Disconnected");
  }

  delay(1000);
  
}
void upload_temperature()
{

  float t = dht.readTemperature();
  
  float h = dht.readHumidity();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  float hic = dht.computeHeatIndex(t, h, false);
  //°C
  String humidity = String(h, 2);
  String temperature = String(t, 2);
  String heat_index = String(hic, 2);

  Serial.println("Temperature: "+temperature);
  Serial.println("Humidity: "+humidity);
  
  Serial.println("--------------------------");
  
  String temperature_data;
  temperature_data = "api_key="+PROJECT_API_KEY;
  temperature_data += "&temperature="+temperature;
  temperature_data += "&humidity="+humidity;

  Serial.print("temperature_data: ");
  Serial.println(temperature_data);
  
  WiFiClient client;
  HTTPClient http;

  http.begin(client, SERVER_NAME);
  
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int httpResponseCode = http.POST(temperature_data);
  
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
    
  http.end();
  }