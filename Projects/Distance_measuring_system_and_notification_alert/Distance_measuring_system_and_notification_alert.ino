  /*
  GND - Gnd
  ECHO - D6
  TRIG - D5
  VCC - 5v 
  LED - D1
  */

// Ubidots through HTTP protocol.

/****************************************
 * Include Libraries
 ****************************************/


#define echo D6 
#define trig D5 
#define LED D1
#define BUZZER D0
long duration;
int distance;
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

void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);   
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print(distance);
  Serial.println(" cm");
  
  ubidots.add("distance_a", distance);  // Change for your variable name

    

  bool bufferSent = false;
  bufferSent = ubidots.send("dist_mes");  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }

if(distance<15)
{
 digitalWrite(BUZZER, HIGH);
 digitalWrite(LED, HIGH);
 delay(1000);
 digitalWrite(BUZZER,LOW);
 digitalWrite(LED, LOW);
 delay(1000);
}
else
{
 digitalWrite(BUZZER,LOW);
 digitalWrite(LED, LOW);
}
  

 // delay(5000);
}
