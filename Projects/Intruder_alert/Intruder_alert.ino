

  /*
  GND - Gnd
  DATA - D7
  VCC - 3.3v 
  LED - D1
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

 int IR = D7;
 int LED = D1;
int value;

void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
    pinMode(IR, INPUT);
}

void loop() {

    Serial.println(value);
    
    value = digitalRead(IR);
  Serial.println(value);
  ubidots.add("ir_value", value);  // Change for your variable name

    

  bool bufferSent = false;
  bufferSent = ubidots.send("Intrud");  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }
if(value==0){

  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
  
}
else
{
    digitalWrite(LED,LOW);
}
  

 // delay(5000);
}
