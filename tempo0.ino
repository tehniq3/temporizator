/*
 * monostable (time relay)
 * original sketch by Nicu FLORICA
 * ver.0 - initial, 05.06.2019, Craiova
 */

#define pincursor A0
#define buton 2
#define releu 3

int timp1;
unsigned long timp2;


void setup() {
pinMode(pincursor, INPUT);
pinMode(buton, OUTPUT);
pinMode(releu, OUTPUT);

digitalWrite(buton, HIGH);
digitalWrite(releu, LOW);
}

void loop() {

timp1 = analogRead(pincursor);
//timp1 = map(timp1, 0, 1023, 300, 900);  // 5-15 minutes 
//timp2 = timp1 * 1000;  // ms
timp1 = map(timp1, 0, 1023, 1, 100);  // 0.1-10 seconds 
timp2 = timp1 * 100;  // ms

if(digitalRead(buton) == LOW)
{
  digitalWrite(releu, HIGH);
  delay(timp2);
  digitalWrite(releu, LOW);
}

delay(100);
}
