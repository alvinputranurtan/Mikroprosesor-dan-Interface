#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

// Ganti dengan kredensial WiFi Anda
const char* ssid = "Poco X3 Pro Alvin 3";
const char* password = "AlvinputranurtaN";

// Pin untuk LED
const int ledPin = D5;

void setup() {
  Serial.begin(115200);
  delay(10);

  // Menyiapkan pin LED
  pinMode(ledPin, OUTPUT);

  // Menyambung ke WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected.");

  // Menyiapkan OTA
  ArduinoOTA.setHostname("nodemcu"); // Ganti dengan nama perangkat Anda
  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle(); // Menangani OTA request
  
  // LED Blink
  digitalWrite(ledPin, HIGH); // Nyalakan LED
  delay(1000);                 // Tunggu 500 ms
  digitalWrite(ledPin, LOW);  // Matikan LED
  delay(1000);                 // Tunggu 500 ms
}
