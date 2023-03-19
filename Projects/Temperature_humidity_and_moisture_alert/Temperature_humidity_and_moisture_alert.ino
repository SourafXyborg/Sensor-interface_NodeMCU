// Ubidots through HTTP protocol.

/****************************************
 * Include Libraries
 ****************************************/
#include "DHT.h"
#define DHTPIN D4
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

#include "Ubidots.h"

/****************************************
 * Define Instances and Constants
 ****************************************/
const char* UBIDOTS_TOKEN = "BBFF-CAtw2kVeiTyN73P1SaCLdXn3pxFMyW";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "...";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "...";      // Put here your Wi-Fi password
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/****************************************
 * Main Functions
 ****************************************/
#define BUZZER D0
int moisture_sensor = A0;
int value;

void setup() {
  Serial.begin(115200);
  dht.begin();
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
  pinMode(moisture_sensor, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {

    value = analogRead(moisture_sensor);
    value = map(value, 0, 1023, 100, 0);
    Serial.println(value);


    
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  ubidots.add("temperature", t);  // Change for your variable name
  ubidots.add("humidity", h);
  ubidots.add("moisture", value);

    

  bool bufferSent = false;
  bufferSent = ubidots.send("temp_hum");  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }
if(h>75)
{
   digitalWrite(BUZZER, HIGH);
   delay(1000);
   digitalWrite(BUZZER,LOW);
   delay(1000);
}
if(75<h>80)
{
   digitalWrite(BUZZER, HIGH);
   delay(500);
   digitalWrite(BUZZER,LOW);
   delay(500);
}
else
{
  digitalWrite(BUZZER,LOW);
}
 // delay(5000);


}
