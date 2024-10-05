#include <Servo.h>

int potensio = A0;   
int resistansi = 0;    
float voltage = 0;

Servo alvin;

void setup() {
  alvin.attach(5);
}

void loop() {

  resistansi = analogRead(potensio);
  

  int angle = map(resistansi, 0, 1023, 0, 180);
  
  alvin.write(angle);
 
  delay(100);
}