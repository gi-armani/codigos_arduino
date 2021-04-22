int ledVermelho = 7;
int ledAmarelo = 8;
int ledVerde = 9;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  piscaLed(ledVermelho);
  piscaLed(ledAmarelo);
  piscaLed(ledVerde);
}

void piscaLed(int led){
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
