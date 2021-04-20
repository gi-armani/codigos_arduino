void setup() {
  //Define a porta do led como saida
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  //Acende o led
  digitalWrite(9, LOW);
  digitalWrite(5, HIGH);
   
  //Aguarda 1 segundo
  delay(1000);
   
  //Apaga o led
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
   
  //Aguarda 1 segundo
  delay(1000);

  //Apaga o led
  digitalWrite(7, LOW);
  digitalWrite(9, HIGH);
   
  //Aguarda 1 segundo
  delay(1000);
}
