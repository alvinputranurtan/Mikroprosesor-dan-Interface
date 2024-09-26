const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int button1Pin = 5;
const int button2Pin = 6;
const int button3Pin = 7;

int button1State = 0;
int button2State = 0;
int button3State = 0;

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
}

void loop() {

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);

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

  else if (button2State == HIGH) {
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);

    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);

    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
  }

else if (button3State == HIGH) {
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);

    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);

    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);

    delay(500);
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);

    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);

    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
  }

  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}