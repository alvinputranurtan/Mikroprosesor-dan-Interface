int potensio = A0;    
int resistansi = 0;   
float voltage = 0;   
int led = 3;      

void setup() {
  
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
}

void loop() {

  resistansi = analogRead(potensio);

  voltage = resistansi * (5.0 / 1023.0);
  
  
  Serial.print("Tegangan: ");
  Serial.print(voltage); 
  Serial.println(" V"); 


  int pwmValue = map(resistansi, 0, 1023, 0, 255);
  
  analogWrite(led, pwmValue);

  delay(100);
}