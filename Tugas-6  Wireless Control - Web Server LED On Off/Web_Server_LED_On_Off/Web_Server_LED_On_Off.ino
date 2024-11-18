#include <ESP8266WiFi.h>

// Informasi koneksi WiFi
const char* ssid = "predator 300";
const char* password = "ph31554-2021";

// Pin LED diubah ke D2 (GPIO4)
const int ledPin = D8;

// Web server berjalan pada port 80
WiFiServer server(80);

// Status LED
bool ledState = false;

unsigned long previousMillis = 0;  // Untuk interval 1 detik

void setup() {
  // Memulai komunikasi serial
  Serial.begin(115200);

  // Mengatur pin LED sebagai output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);  // Mematikan LED eksternal di awal (logika terbalik)

  // Menghubungkan ke WiFi
  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);

  // Menunggu hingga terhubung ke WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nKoneksi ke WiFi berhasil!");
  } else {
    Serial.println("\nKoneksi ke WiFi gagal!");
  }

  // Tampilkan alamat IP pada Serial Monitor
  Serial.print("Alamat IP ESP: ");
  Serial.println(WiFi.localIP());

  // Memulai server
  server.begin();
  Serial.println("Server dimulai");
}

void loop() {
  // Mendapatkan waktu saat ini
  unsigned long currentMillis = millis();
  
  // Tampilkan alamat IP setiap 1 detik
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    
    if (WiFi.status() == WL_CONNECTED) {
      Serial.print("Alamat IP ESP (update): ");
      Serial.println(WiFi.localIP());
    } else {
      Serial.println("Koneksi ke WiFi terputus!");
    }
  }

  // Menerima koneksi client
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Koneksi baru diterima");
    String request = client.readStringUntil('\r');
    Serial.println("Permintaan diterima: " + request);
    client.flush();

    // Periksa apakah tombol untuk menghidupkan atau mematikan LED ditekan
    if (request.indexOf("/LED=ON") != -1) {
      ledState = true;
      digitalWrite(ledPin, HIGH);  // Logika terbalik untuk menyalakan LED
      Serial.println("LED dihidupkan");
    } else if (request.indexOf("/LED=OFF") != -1) {
      ledState = false;
      digitalWrite(ledPin, LOW);  // Logika terbalik untuk mematikan LED
      Serial.println("LED dimatikan");
    }

    // HTML untuk halaman web dengan tombol
    String html = "<!DOCTYPE html><html><head><title>ESP8266 Web Server</title></head><body>";
    html += "<h1>Kontrol LED dengan ESP8266</h1>";
    html += "<p>LED sekarang: " + String(ledState ? "ON" : "OFF") + "</p>";
    html += "<p><a href=\"/LED=ON\"><button>Hidupkan LED</button></a></p>";
    html += "<p><a href=\"/LED=OFF\"><button>Matikan LED</button></a></p>";
    html += "</body></html>";

    // Kirim respons ke client
    client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    client.print(html);
    delay(1);
    Serial.println("Koneksi berakhir");
  }
}
