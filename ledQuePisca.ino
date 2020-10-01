void setup() {
  //Define a porta do led como saida
  pinMode(7, OUTPUT);
}

void loop() {
  //Acende o led
  digitalWrite(7, HIGH);
   
  //Aguarda 1 segundo
  delay(1000);
   
  //Apaga o led
  digitalWrite(7, LOW);
   
  //Aguarda 1 segundo
  delay(1000);
}
