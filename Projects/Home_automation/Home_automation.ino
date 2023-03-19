
  
  /*
  GND - Gnd
  INP - D1
  VCC - 5v 
  */

// Ubidots through HTTP protocol.

/****************************************
 * Include Libraries
 ****************************************/


#include "Ubidots.h"

/****************************************
 * Define Instances and Constants
 ****************************************/

const char* UBIDOTS_TOKEN = "...";  // Put here your Ubidots TOKEN
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
 int relay = D1;

void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  pinMode(relay,OUTPUT);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
}

void loop() {

 float value = ubidots.get("light_contol","r1"); //device label, variable label
  Serial.println("value");
 Serial.println(value);
 if (value==1)
 {
  digitalWrite(relay,HIGH);
 }
 else
 {
  digitalWrite(relay,LOW);
 }
 delay(100);
}
