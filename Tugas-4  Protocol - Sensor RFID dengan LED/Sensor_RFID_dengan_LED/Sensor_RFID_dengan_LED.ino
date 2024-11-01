#include <SPI.h>
#include <MFRC522.h>  // Menggunakan library MFRC522

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 3  // Pin LED untuk indikator

MFRC522 rfid(SS_PIN, RST_PIN);  // Inisialisasi modul RFID

// UID yang diinginkan (57, 185, 249, 162)
byte allowedUID[4] = {5, 135, 203, 8};

String rfidCard;

// Fungsi untuk membandingkan UID yang terbaca dengan UID yang diizinkan
bool checkUID(byte *readUID, byte *allowedUID) {
  for (byte i = 0; i < 4; i++) {
    if (readUID[i] != allowedUID[i]) {
      return false;  // Jika ada byte yang tidak cocok, kembalikan false
    }
  }
  return true;  // Jika semua byte cocok, kembalikan true
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);  // Atur pin LED sebagai output
  digitalWrite(LED_PIN, LOW);  // Matikan LED di awal
  
  Serial.println("Starting the RFID Reader...");

  SPI.begin();  // Memulai komunikasi SPI
  rfid.PCD_Init();  // Inisialisasi modul RFID
  
  // Debugging untuk memastikan RFID diinisialisasi
  if (rfid.PCD_PerformSelfTest()) {
    Serial.println("RFID module initialized successfully!");
  } else {
    Serial.println("RFID module initialization failed. Please check connections.");
  }
}

void loop() {
  // Cek apakah ada kartu yang terdeteksi
  if (rfid.PICC_IsNewCardPresent()) {
    // Cek apakah bisa membaca kartu
    if (rfid.PICC_ReadCardSerial()) {
      // Konversi serial number kartu menjadi string untuk debugging
      rfidCard = String(rfid.uid.uidByte[0]) + " " + String(rfid.uid.uidByte[1]) + " " + 
                 String(rfid.uid.uidByte[2]) + " " + String(rfid.uid.uidByte[3]);
      
      // Tampilkan nomor serial kartu ke Serial Monitor
      Serial.println("Card detected: " + rfidCard);
      
      // Cek apakah kartu yang terdeteksi sesuai dengan UID yang diizinkan
      if (checkUID(rfid.uid.uidByte, allowedUID)) {
        Serial.println("Allowed card detected!");
        // Nyalakan LED selama 2 detik sebagai indikator kartu valid
        digitalWrite(LED_PIN, HIGH);
        delay(5000);
        digitalWrite(LED_PIN, LOW);
      } else {
        Serial.println("Card not allowed.");
        // Flash LED for unauthorized card
        for (int i = 0; i < 8; i++) {
          digitalWrite(LED_PIN, HIGH);  // Nyalakan LED
          delay(250);                   // Tunggu 250ms
          digitalWrite(LED_PIN, LOW);   // Matikan LED
          delay(250);                   // Tunggu 250ms
        }
      }

      // Hentikan komunikasi untuk menunggu kartu baru
      rfid.PICC_HaltA();
    }
  }
}
