#include <ESP8266WiFi.h>
#include <DHT.h>
#include <DHT_U.h>
#include <ThingSpeak.h>

#define DHTPIN D5       // Pin D5 untuk data dari DHT
#define DHTTYPE DHT11   // Gunakan DHT11 atau DHT22 tergantung tipe sensor yang digunakan
DHT dht(DHTPIN, DHTTYPE);

// Pin potensiometer
#define POT_PIN A0

// Informasi WiFi
const char* ssid = "Poco X3 Pro Alvin 3";       
const char* password = "AlvinputranurtaN";      

// Informasi ThingSpeak
const char* server = "api.thingspeak.com";
unsigned long channelID = 2735339;  
const char* apiKey = "82M1XTQKWNLNZI9G";        

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Koneksi ke WiFi
  Serial.print("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Terhubung!");

  // Inisialisasi ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Membaca suhu dan kelembaban dari sensor DHT
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();

  // Membaca nilai potensiometer
  int potensiometerValue = analogRead(POT_PIN); 
  float teganganPot = (potensiometerValue / 1023.0) * 3.3; // Konversi ke tegangan (3.3V maksimum)

  // Cek jika pembacaan gagal
  if (isnan(suhu) || isnan(kelembaban)) {
    Serial.println("Gagal membaca dari sensor DHT");
    return;
  }

  // Terapkan offset pada suhu jika diperlukan
  float suhu_disesuaikan = suhu + 21.2; // Contoh offset untuk menjadikan suhu 23°C

  // Tampilkan hasil ke Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(suhu_disesuaikan);
  Serial.println("°C");

  Serial.print("Kelembaban: ");
  Serial.print(kelembaban);
  Serial.println("%");

  Serial.print("Potensiometer: ");
  Serial.print(teganganPot);
  Serial.println(" V");

  // Mengirim data ke ThingSpeak
  ThingSpeak.setField(1, suhu_disesuaikan);  // Field 1 untuk suhu
  ThingSpeak.setField(2, kelembaban);        // Field 2 untuk kelembaban
  ThingSpeak.setField(3, teganganPot);       // Field 3 untuk nilai potensiometer (tegangan)

  int x = ThingSpeak.writeFields(channelID, apiKey);
  if (x == 200) {
      Serial.println("Data berhasil dikirim ke ThingSpeak");
  } else {
      Serial.println("Gagal mengirim data ke ThingSpeak. Error code: " + String(x));
  }

  delay(1000); // Tunggu 1 detik sebelum mengirim data lagi
}
