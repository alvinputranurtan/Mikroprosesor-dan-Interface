#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Ganti dengan SSID dan password WiFi yang digunakan
const char* ssid = "Poco X3 Pro Alvin 3";
const char* password = "AlvinputranurtaN";

// Inisialisasi server pada port 80
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // Menghubungkan ke WiFi
  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Terhubung ke WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Menyusun halaman web
  server.on("/", [](){
    server.send(200, "text/html", "<html><body><h1>ESP8266 LOCAL WEB SERVER</h1>"
                                  "<p>Alvin Putra Nurtan dan Rifqi Maulana</p>"
                                  "<p>4.31.23.0.02 &nbsp;&nbsp;&nbsp;&nbsp; 4.31.23.0.20</p>"
                                  "<p>POLITEKNIK NEGERI SEMARANG 2024/2025</p>"
                                  "</body></html>");
  });
  
  // Memulai server
  server.begin();
  Serial.println("Server dimulai...");
}

void loop() {
  // Menangani permintaan klien
  server.handleClient();

  // Print IP Address setiap 1 detik
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  delay(1000);  // Jeda 1 detik
}
