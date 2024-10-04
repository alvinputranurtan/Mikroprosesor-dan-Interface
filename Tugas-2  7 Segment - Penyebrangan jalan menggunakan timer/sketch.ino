const int atas = 4;
const int kananatas = 5;
const int kananbawah = 6; 
const int bawah = 7;
const int kiribawah = 8;
const int kiriatas = 9;
const int tengah = 10;
const int digitalkanan = 11;
const int digitalkiri = 12;
const int button1Pin = 3;
const int merah = 2;
const int kuning = 1;
const int hijau = 13;
int button1State = 0;



void setup() {

 pinMode(atas, OUTPUT);
 pinMode(kananatas, OUTPUT);
 pinMode(kananbawah, OUTPUT);
 pinMode(bawah, OUTPUT);
 pinMode(kiribawah, OUTPUT);
 pinMode(kiriatas, OUTPUT);
 pinMode(tengah, OUTPUT);
 pinMode(digitalkanan, OUTPUT);
 pinMode(digitalkiri, OUTPUT);
 pinMode(button1Pin, INPUT);

}



void loop() {
button1State = digitalRead(button1Pin);

if (button1State == LOW) {
kedip();

 }


else {
digitalWrite(kuning, HIGH);
delay(2000);
digitalWrite(kuning, LOW);
digitalWrite(merah, HIGH);

//20
for (int n = 0; n < 500; n++) {
kiri();
dua();
clear();
kanan();
nol();
clear();
}

//19
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
sembilan();
clear();
}

//18
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
delapan();
clear();
}

//17
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
tujuh();
clear();
}

//16
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
enam();
clear();
}

//15
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
lima();
clear();
}

//14
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
empat();
clear();
}

//13
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
tiga();
clear();
}

//12
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
dua();
clear();
}

//11
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
satu();
clear();
}

//10
for (int n = 0; n < 500; n++) {
kiri();
satu();
clear();
kanan();
nol();
clear();
}

//09
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
sembilan();
clear();
}

//08
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
delapan();
clear();
}

//07
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
tujuh();
clear();
}

//06
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
enam();
clear();
}

//05
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
lima();
clear();
}

//04
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
empat();
clear();
}

//03
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
tiga();
clear();
}

//02
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
dua();
clear();
}

//01
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
satu();
clear();
}

//00
for (int n = 0; n < 500; n++) {
kiri();
nol();
clear();
kanan();
nol();
clear();
}

digitalWrite(merah, LOW);
digitalWrite(kuning, HIGH);
delay(2000);
digitalWrite(kuning, LOW);

}
}



void nol() {
digitalWrite(tengah, LOW);
digitalWrite(atas, HIGH);
digitalWrite(bawah, HIGH);
digitalWrite(kiribawah, HIGH);
digitalWrite(kiriatas, HIGH);
digitalWrite(kananbawah, HIGH);
digitalWrite(kananatas, HIGH);
}

void satu() {
digitalWrite(atas, LOW);
digitalWrite(bawah, LOW);
digitalWrite(kiribawah, LOW);
digitalWrite(kiriatas, LOW);
digitalWrite(kananatas, HIGH);
digitalWrite(kananbawah, HIGH);
}

void dua() {
digitalWrite(kananbawah, LOW);
digitalWrite(atas, HIGH);
digitalWrite(kananatas, HIGH);
digitalWrite(tengah, HIGH);
digitalWrite(kiribawah, HIGH);
digitalWrite(bawah, HIGH);
}

void tiga() {
digitalWrite(kiribawah, LOW);
digitalWrite(atas, HIGH);
digitalWrite(kananatas, HIGH);
digitalWrite(tengah, HIGH);
digitalWrite(kananbawah, HIGH);
digitalWrite(bawah, HIGH);  
}

void empat() {
digitalWrite(atas, LOW);
digitalWrite(bawah, LOW); 
digitalWrite(kananatas, HIGH);
digitalWrite(kiriatas, HIGH);
digitalWrite(tengah, HIGH);
digitalWrite(kananbawah, HIGH);
}

void lima() {
digitalWrite(kananatas, LOW);
digitalWrite(atas, HIGH);
digitalWrite(kiriatas, HIGH);
digitalWrite(tengah, HIGH);
digitalWrite(kananbawah, HIGH);
digitalWrite(bawah, HIGH);
}

void enam() {
digitalWrite(atas, HIGH);
digitalWrite(kiriatas, HIGH);
digitalWrite(kiribawah, HIGH);
digitalWrite(tengah, HIGH);
digitalWrite(kananbawah, HIGH);
digitalWrite(bawah, HIGH);
}

void tujuh() {
digitalWrite(atas, HIGH);
digitalWrite(kiriatas, LOW);
digitalWrite(kiribawah, LOW);
digitalWrite(tengah, LOW);
digitalWrite(kananbawah, HIGH);
digitalWrite(bawah, LOW);  
digitalWrite(kananatas, HIGH);
}

void delapan() {
digitalWrite(tengah, HIGH);
digitalWrite(atas, HIGH);
digitalWrite(bawah, HIGH);
digitalWrite(kiribawah, HIGH);
digitalWrite(kiriatas, HIGH);
digitalWrite(kananbawah, HIGH);
digitalWrite(kananatas, HIGH);
}

void sembilan() {
digitalWrite(kiribawah, LOW);
digitalWrite(tengah, HIGH);
digitalWrite(atas, HIGH);
digitalWrite(bawah, HIGH);
digitalWrite(kiriatas, HIGH);
digitalWrite(kananbawah, HIGH);
digitalWrite(kananatas, HIGH);
}

void clear() {
digitalWrite(kiribawah, LOW);
digitalWrite(tengah, LOW);
digitalWrite(atas, LOW);
digitalWrite(bawah, LOW);
digitalWrite(kiriatas, LOW);
digitalWrite(kananbawah, LOW);
digitalWrite(kananatas, LOW);  
delay(1);
}

void kiri () {
digitalWrite(digitalkanan, LOW);
digitalWrite(digitalkiri, HIGH);
}

void kanan () {
digitalWrite(digitalkanan, HIGH);
digitalWrite(digitalkiri, LOW);
}

void kedip() {
digitalWrite(hijau, HIGH);
delay(500);
digitalWrite(hijau, LOW);
delay(500);
}