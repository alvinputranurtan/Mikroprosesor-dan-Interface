#include <ESP8266WiFi.h>
#include <espnow.h>

// MAC address perangkat penerima
uint8_t broadcastAddress[] = {0xDC, 0x4F, 0x22, 0x7E, 0x2F, 0x8C};

// Pesan yang akan dikirim
String message = "Ini adalah pengetesan ESP NOW, Halo Faren... Ini Pesan dari Alvin";

// Fungsi callback saat data berhasil terkirim
void onDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Pengiriman ke alamat MAC: ");
  for (int i = 0; i < 6; i++) {
    Serial.print(mac_addr[i], HEX);
    if (i < 5) Serial.print(":");
  }
  Serial.print(" Status pengiriman: ");
  Serial.println(sendStatus == 0 ? "Berhasil" : "Gagal");
}

void setup() {
  Serial.begin(9600);  // Ubah baud rate ke 9600
  WiFi.mode(WIFI_STA);

  // Inisialisasi ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Gagal menginisialisasi ESP-NOW");
    return;
  }

  // Registrasi callback pengiriman
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(onDataSent);

  // Menambahkan perangkat penerima dengan MAC address yang ditentukan
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  // Konversi pesan ke byte array dan kirim data
  uint8_t dataToSend[message.length() + 1];
  message.getBytes(dataToSend, sizeof(dataToSend));
  esp_now_send(broadcastAddress, dataToSend, sizeof(dataToSend));

  Serial.println("Pesan terkirim");

  delay(2000); // Menunggu 2 detik sebelum pengiriman berikutnya
}