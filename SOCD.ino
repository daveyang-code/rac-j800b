#define PIN_LEFT_IN 0
#define PIN_RIGHT_IN 1
#define PIN_DOWN_IN 2
#define PIN_UP_IN 3
#define PIN_SOCD 4
#define PIN_LEFT_OUT 7
#define PIN_RIGHT_OUT 8
#define PIN_DOWN_OUT 9
#define PIN_UP_OUT 10

uint8_t up_in;
uint8_t down_in;
uint8_t left_in;
uint8_t right_in;

void setup() {
  pinMode(PIN_UP_IN, INPUT_PULLUP);
  pinMode(PIN_DOWN_IN, INPUT_PULLUP);
  pinMode(PIN_LEFT_IN, INPUT_PULLUP);
  pinMode(PIN_RIGHT_IN, INPUT_PULLUP);
  pinMode(PIN_SOCD, INPUT_PULLUP);
  pinMode(PIN_UP_OUT, OUTPUT);
  pinMode(PIN_DOWN_OUT, OUTPUT);
  pinMode(PIN_LEFT_OUT, OUTPUT);
  pinMode(PIN_RIGHT_OUT, OUTPUT);
}

void loop() {
  up_in = digitalRead(PIN_UP_IN);
  down_in = digitalRead(PIN_DOWN_IN);
  left_in = digitalRead(PIN_LEFT_IN);
  right_in = digitalRead(PIN_RIGHT_IN);

  if (up_in == LOW && down_in == LOW) {
    if (digitalRead(PIN_SOCD) == LOW) {
      digitalWrite(PIN_UP_OUT, HIGH);
      digitalWrite(PIN_DOWN_OUT, HIGH);
    } else {
      digitalWrite(PIN_UP_OUT, LOW);
      digitalWrite(PIN_DOWN_OUT, HIGH);
    }
  } else if (up_in == LOW) {
    digitalWrite(PIN_UP_OUT, LOW);
    digitalWrite(PIN_DOWN_OUT, HIGH);
  } else if (down_in == LOW) {
    digitalWrite(PIN_UP_OUT, HIGH);
    digitalWrite(PIN_DOWN_OUT, LOW);
  } else {
    digitalWrite(PIN_UP_OUT, HIGH);
    digitalWrite(PIN_DOWN_OUT, HIGH);
  }

  if (left_in == LOW && right_in == LOW) {
    digitalWrite(PIN_LEFT_OUT, HIGH);
    digitalWrite(PIN_RIGHT_OUT, HIGH);
  } else if (left_in == LOW) {
    digitalWrite(PIN_LEFT_OUT, LOW);
    digitalWrite(PIN_RIGHT_OUT, HIGH);
  } else if (right_in == LOW) {
    digitalWrite(PIN_LEFT_OUT, HIGH);
    digitalWrite(PIN_RIGHT_OUT, LOW);
  } else {
    digitalWrite(PIN_LEFT_OUT, HIGH);
    digitalWrite(PIN_RIGHT_OUT, HIGH);
  }
}
