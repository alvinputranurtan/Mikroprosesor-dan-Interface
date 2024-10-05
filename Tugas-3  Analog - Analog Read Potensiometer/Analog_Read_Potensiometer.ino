int potensio = A0;    
int resistansi = 0;   
      

void setup() {
  Serial.begin(9600);
}

void loop() {

  resistansi = analogRead(potensio);
  
  Serial.print("Data: ");
  Serial.println(resistansi); 
  delay(100);
}