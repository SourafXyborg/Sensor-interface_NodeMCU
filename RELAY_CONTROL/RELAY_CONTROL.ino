  
  /*
  GND - Gnd
  INP - D1
  VCC - 3.3v 
  */
  
int relay = D1;

void setup() 
{
   pinMode(relay, OUTPUT);
}

void loop() 
{
   digitalWrite(relay, HIGH);  
     delay(1000);                      
     digitalWrite(relay, LOW);  
   delay(1000);                     
}
