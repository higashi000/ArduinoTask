const int ledPin[4] = {13, 12, 11, 10};
const int swPin = 2;

int nowSwState = LOW;
int binaryCnt = 0;

void outputBinary(int nowCnt);


void setup() {
  for (int line = 0; line < 4; ++line) {
    pinMode(ledPin[line], OUTPUT);
  }
  pinMode( swPin, INPUT );
}


void loop() {
  nowSwState = digitalRead(swPin);

  if (nowSwState == HIGH) {
    binaryCnt = (binaryCnt + 1) % 16;
    delay(500);
  }

  outputBinary(binaryCnt);
}

void outputBinary(int nowCnt) {
  for (int line = 0; line < 4; ++line) {
    digitalWrite(ledPin[line], nowCnt&1);
    nowCnt >>= 1;
  }
}
