#include <ESP8266WiFi.h>
#include <WiFiManager.h>

void setup() {
    Serial.begin(115200);
    WiFiManager wifiManager;

    Serial.println("Memulai portal konfigurasi...");
    wifiManager.startConfigPortal("ESP Alvin dan Rifqi");

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Terhubung ke WiFi!");
    } else {
        Serial.println("Gagal terhubung ke WiFi.");
    }
}

void loop() {
    // Kode aplikasi utama Anda di sini
}