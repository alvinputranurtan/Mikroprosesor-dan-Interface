#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int inputSuhu = A0; 
const int LED = 3;
float Valueinput;
float teganganInput;
float suhu;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
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

  lcd.setCursor(0, 0);        
  lcd.print("Suhu: ");
  lcd.setCursor(6, 0);
  lcd.print(suhu, 2);            
  lcd.print(" C");

  delay(500);
}
