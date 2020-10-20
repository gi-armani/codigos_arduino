int motorDC = 2;

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(motorDC, LOW);

}
void loop() {
  digitalWrite(motorDC, HIGH);
  /*delay(1000);
  digitalWrite(motorDC, LOW);
  delay(1000);*/
}
