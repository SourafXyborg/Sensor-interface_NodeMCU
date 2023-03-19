// Ubidots through HTTP protocol.

/****************************************
 * Include Libraries
 ****************************************/


#include "Ubidots.h"

/****************************************
 * Define Instances and Constants
 ****************************************/

const char* UBIDOTS_TOKEN = "BBFF-CAtw2kVeiTyN73P1SaCLdXn3pxFMyW";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "SDPK -LBS POOJAPPURA";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "Sdpk@123";      // Put here your Wi-Fi password
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  pinMode(D1,OUTPUT);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
}

void loop() {

 float value = ubidots.get("led_blink","leda"); //device label, variable label
  Serial.println("value");
 Serial.println(value);
 if (value==1)
 {
  digitalWrite(D1,HIGH);
 }
 else
 {
  digitalWrite(D1,LOW);
 }


;
}
