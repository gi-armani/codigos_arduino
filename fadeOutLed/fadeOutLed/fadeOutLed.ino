void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9, HIGH);
  delay(1000);
  analogWrite(9, 180);
  delay(1000);
  analogWrite(9, 120);
  delay(1000);
  analogWrite(9, 80);
  delay(1000);
  analogWrite(9, 20);
  delay(1000);
  analogWrite(9, 0);
  delay(1000);
  digitalWrite(9, LOW);
}
