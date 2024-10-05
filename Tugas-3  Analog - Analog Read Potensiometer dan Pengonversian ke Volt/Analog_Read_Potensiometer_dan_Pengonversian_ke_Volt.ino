int potensio = A0;    
int resistansi = 0;   
float voltage = 0;      

void setup() {
  Serial.begin(9600);
}

void loop() {

  resistansi = analogRead(potensio);
  voltage = resistansi * (5.0 / 1023.0);

  Serial.print("Tegangan: ");
  Serial.print(voltage);
  Serial.println(" V"); 
  
  delay(100);
}