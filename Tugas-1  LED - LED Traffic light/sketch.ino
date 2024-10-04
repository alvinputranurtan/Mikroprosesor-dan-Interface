const int kananhijau = 4;
const int kanankuning = 3;
const int kananmerah = 2;
const int tengahhijau = 5;
const int tengahkuning = 6;
const int tengahmerah = 7;
const int kirihijau = 8;
const int kirikuning = 9;
const int kirimerah = 10;


void setup() {

  pinMode(kananhijau, OUTPUT);
  pinMode(kanankuning, OUTPUT);
  pinMode(kananmerah, OUTPUT);
  pinMode(tengahhijau, OUTPUT);
  pinMode(tengahkuning, OUTPUT);
  pinMode(tengahmerah, OUTPUT);
  pinMode(kirihijau, OUTPUT);
  pinMode(kirikuning, OUTPUT);
  pinMode(kirimerah, OUTPUT);

}


void loop() {


//nyalakan semua, kanan hijau
 digitalWrite(kanankuning, LOW);
 digitalWrite(kananmerah, LOW);
 digitalWrite(tengahhijau, LOW);
 digitalWrite(tengahkuning, LOW);
 digitalWrite(kirihijau, LOW);
 digitalWrite(kirikuning, LOW);
 digitalWrite (kananhijau, HIGH);
 digitalWrite (tengahmerah, HIGH);
 digitalWrite (kirimerah, HIGH);
  delay(1000);

//lampu kuning di kanan dan tengah
 digitalWrite (kananhijau, LOW);
 digitalWrite (tengahmerah, LOW);
 digitalWrite (kirimerah, HIGH);
 digitalWrite (kanankuning, HIGH);
 digitalWrite (tengahkuning, HIGH);
  delay(500);

//tengah hijau
 digitalWrite (kanankuning, LOW);
 digitalWrite (tengahkuning, LOW);
 digitalWrite (kananmerah, HIGH);
 digitalWrite (tengahhijau, HIGH);
  delay(1000);

//lampu kuning di tengah dan kiri
 digitalWrite (kananmerah, LOW);
 digitalWrite (tengahhijau, LOW);
 digitalWrite(kirimerah, LOW);
 digitalWrite(kananmerah, HIGH);
 digitalWrite (tengahkuning, HIGH);
 digitalWrite (kirikuning, HIGH);
  delay(500);

//kiri hijau
 digitalWrite (tengahkuning, LOW);
 digitalWrite (kirikuning, LOW);
 digitalWrite(kirimerah, LOW);
 digitalWrite (kirihijau, HIGH);
 digitalWrite (tengahmerah, HIGH);
 digitalWrite(kananmerah, HIGH);
  delay(1000);

//kuning di kiri dan tengah
 digitalWrite (kirihijau, LOW);
 digitalWrite (tengahmerah, LOW);
 digitalWrite (kirikuning, HIGH);
 digitalWrite (tengahkuning, HIGH);
  delay(500);

//tengah hijau
 digitalWrite (kirikuning, LOW);
 digitalWrite (tengahkuning, LOW);
 digitalWrite(tengahhijau, HIGH);
 digitalWrite(kirimerah, HIGH);
 delay(1000);

//lampu kuning di tengah dan kanan
 digitalWrite (tengahhijau, LOW);
 digitalWrite(kananmerah, LOW);
 digitalWrite (kanankuning, HIGH);
 digitalWrite (tengahkuning, HIGH);
  delay(500);

}



