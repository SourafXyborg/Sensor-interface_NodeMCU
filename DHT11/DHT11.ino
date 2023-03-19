  
  /*
  GND - Gnd
  DATA - D4
  VCC - 3.3v 
  */
#include "DHT.h"
#define DHTPIN D4 
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("% ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("C ");
}
