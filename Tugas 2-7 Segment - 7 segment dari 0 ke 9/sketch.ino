const int atas = 4;
const int kananatas = 5;
const int kananbawah = 6; 
const int bawah = 7;
const int kiribawah = 8;
const int kiriatas = 9;
const int tengah = 10;


void setup() {

 pinMode(atas, OUTPUT);
 pinMode(kananatas, OUTPUT);
 pinMode(kananbawah, OUTPUT);
 pinMode(bawah, OUTPUT);
 pinMode(kiribawah, OUTPUT);
 pinMode(kiriatas, OUTPUT);
 pinMode(tengah, OUTPUT);

}

void loop() {
nol();
delay(1000);
satu();
delay(1000);
dua();
delay(1000);
tiga();
delay(1000);
empat();
delay(1000);
lima();
delay(1000);
enam();
delay(1000);
tujuh();
delay(1000);
delapan();
delay(1000);
sembilan();
delay(1000);


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