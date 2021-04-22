int ledVermelho = 7; //Começa a oficina sem declarar variável e
                    //depois declara e substitui pra revisar variáveis

void setup() {
  //Define a porta do led como saida
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  //Acende o led
  digitalWrite(ledVermelho, HIGH);
   
  //Aguarda 1 segundo
  delay(1000);
   
  //Apaga o led
  digitalWrite(ledVermelho, LOW);
   
  //Aguarda 1 segundo
  delay(1000);
}
