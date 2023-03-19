/*
GND - Gnd
INP - A0
VCC - 3.3v
*/
int moisture_sensor = A0;
int value;
void setup()
{
pinMode(moisture_sensor, INPUT);
Serial.begin(9600);
}
void loop()
{
value = analogRead(moisture_sensor);
value = map(value, 0, 1023, 100, 0);
Serial.println(value);
}
