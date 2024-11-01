const int inputSuhu = A0; 
const int LED = 3;
float Valueinput;
float teganganInput;
float suhu;

void setup() {
  pinMode(inputSuhu, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Valueinput = analogRead(inputSuhu);
  teganganInput = (Valueinput * 5000.0) / 1024.0;
  suhu = teganganInput / 10.0;

  Serial.print("Suhu(ºC): ");
  Serial.print(suhu);
  Serial.print("  Tegangan(mV): ");
  Serial.println(teganganInput);

  if (suhu >= 27) {
    digitalWrite(LED, HIGH);  
  } else {
    digitalWrite(LED, LOW);   
  }
  delay(500);
}
