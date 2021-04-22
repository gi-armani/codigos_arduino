int ledVermelho = 7;
int ledAmarelo = 8;
int ledVerde = 9;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char led = Serial.read();
    if(led == '1') piscaLed(ledVermelho);
    if(led == '2') piscaLed(ledAmarelo);
    if(led == '3') piscaLed(ledVerde);
  }
}

void piscaLed(int led){
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
