  
  /*
  GND - Gnd
  DATA - D7
  VCC - 3.3v 
  */

int IR = D7;
int value;

void setup() 
{
  pinMode(IR, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  value = digitalRead(IR);
  Serial.println(value);
}
