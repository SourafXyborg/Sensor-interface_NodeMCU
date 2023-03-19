// This example sends data to multiple variables to
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
const char* WIFI_SSID = "Rog_scar";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "Souraf@123";      // Put here your Wi-Fi password
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
  dht.begin();
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
}

void loop() {

    
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  ubidots.add("temp", t);  // Change for your variable name
  ubidots.add("hum", h);

    

  bool bufferSent = false;
  bufferSent = ubidots.send("abcd");  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }

  

 delay(5000);
}
