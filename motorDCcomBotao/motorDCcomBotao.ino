int motorDC = 3;
int botao = 8;
int led = 10;

void setup() {
  pinMode(motorDC, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  
  if(digitalRead(botao) == LOW) {
    if(digitalRead(motorDC) == LOW) {
      digitalWrite(motorDC, HIGH);
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(motorDC, LOW);
      digitalWrite(led, LOW);
    }
    delay(1000);
  }
}
