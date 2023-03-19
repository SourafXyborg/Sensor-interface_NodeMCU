  
  /*
  GND - Gnd
  ECHO - D6
  TRIG - D5
  VCC - 5v 
  */



int ledhigh = 1;  

int ledlow = 7;
int buzzerPin = 3;
#define echo D6 
#define trig D5 
long duration;
int distance;


void buzzer()
{
    for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(250);
    digitalWrite(buzzerPin, LOW);
    delay(250);
  }
}

void buzzeroff()
{
    digitalWrite(buzzerPin, LOW);
  }


void setup() 
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  pinMode(ledhigh, OUTPUT);
  pinMode(ledlow, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
}
void loop() 
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034/2;
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 2) {
    buzzer();
    digitalWrite(ledlow, HIGH);
    digitalWrite(ledhigh, LOW);
    
  }
      digitalWrite(ledlow, LOW);
      digitalWrite(ledhigh, HIGH);
      buzzeroff();
}
