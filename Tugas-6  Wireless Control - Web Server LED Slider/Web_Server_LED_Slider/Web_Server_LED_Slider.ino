#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>

// Informasi koneksi WiFi
const char* ssid = "predator 300";
const char* password = "ph31554-2021";

// Pin LED diubah ke D8 (GPIO15)
const int ledPin = D8;

// Web server berjalan pada port 80
ESP8266WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  if (type == WStype_TEXT) {
    // Terima data dari klien (nilai PWM)
    String pwmValueString = String((char*)payload);
    int pwmValue = pwmValueString.toInt();
    pwmValue = constrain(pwmValue, 0, 1023);
    analogWrite(ledPin, pwmValue); // Atur kecerahan LED
    Serial.println("Nilai PWM: " + String(pwmValue));
  }
}

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>Kontrol LED</title></head><body>";
  html += "<h1>Kontrol Kecerahan LED dengan Slider</h1>";
  html += "<p>Sesuaikan kecerahan LED:</p>";
  html += "<input type=\"range\" min=\"0\" max=\"1023\" value=\"0\" id=\"pwmSlider\" oninput=\"sendPWM(this.value)\">";
  html += "<script>";
  html += "var websocket = new WebSocket('ws://' + window.location.hostname + ':81/');";
  html += "websocket.onopen = function(event) { console.log('WebSocket terhubung'); };";
  html += "function sendPWM(val) {";
  html += "  websocket.send(val);"; // Kirim nilai langsung melalui WebSocket
  html += "}";
  html += "</script>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  // Memulai komunikasi serial
  Serial.begin(115200);

  // Mengatur pin LED sebagai output
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 0); // Mulai dengan LED mati

  // Menghubungkan ke WiFi
  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);

  // Menunggu hingga terhubung ke WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nKoneksi ke WiFi berhasil!");
  Serial.print("Alamat IP ESP: ");
  Serial.println(WiFi.localIP());

  // Memulai server HTTP
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Server HTTP dimulai");

  // Memulai WebSocket
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  Serial.println("WebSocket dimulai pada port 81");
}

void loop() {
  server.handleClient();
  webSocket.loop();
}
