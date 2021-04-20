int motorDC = 2;
int botao = 6;

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(motorDC, LOW);
  pinMode(6, INPUT_PULLUP);

}

void loop() {
  while(digitalRead(botao) == LOW) {
    //delay(20);
    digitalWrite(motorDC, HIGH);
  }

  digitalWrite(motorDC, LOW);

}
