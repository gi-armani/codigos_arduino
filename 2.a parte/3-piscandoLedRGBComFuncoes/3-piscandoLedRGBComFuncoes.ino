
int ledAzul = 8;
int ledVerde = 9;
int ledVermelho = 10;
 
void setup() {
  pinMode(ledAzul,OUTPUT);   
  pinMode(ledVerde,OUTPUT);   
  pinMode(ledVermelho,OUTPUT);    
}
 
void loop() { 
  trocaCor(255, 0, 0);
  trocaCor(255, 255, 0);
  trocaCor(0, 255, 0);  
}

void trocaCor(int vermelho, int verde, int azul){
  digitalWrite(ledAzul, azul);
  digitalWrite(ledVerde, verde);
  digitalWrite(ledVermelho, vermelho);
  delay(1000);
}
