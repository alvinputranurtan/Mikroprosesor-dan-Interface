const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int button1Pin = 5;

int button1State = 0;

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(button1Pin, INPUT);
}

void loop() {

  button1State = digitalRead(button1Pin);

  if (button1State == HIGH) {
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);

    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);

    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
  } 

  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}