
int ledAzul = 8;
int ledVerde = 9;
int ledVermelho = 10;
 
void setup() {
  pinMode(ledAzul,OUTPUT);   
  pinMode(ledVerde,OUTPUT);   
  pinMode(ledVermelho,OUTPUT); 
  Serial.begin(9600);   
  Serial.println("Selecione um número e veja uma cor:");
  Serial.println("1 = Amarelo");
  Serial.println("2 = Verde");
  Serial.println("3 = Azul escuro");
  Serial.println("4 = Azul claro");
  Serial.println("5 = Roxo");
  Serial.println("6 = Vermelho");
}
 
void loop() { 
  if(Serial.available()){
    char led = Serial.read();
    if(led == '1') trocaCor(255, 255, 0); //deixa led amarelo
    if(led == '2') trocaCor(0, 255, 0); //deixa led verde
    if(led == '3') trocaCor(0, 0, 255); //deixa led azul escuro
    if(led == '4') trocaCor(0, 127, 255); //deixa led azul claro
    if(led == '5') trocaCor(148, 0, 211); //deixa led roxo
    if(led == '6') trocaCor(255, 0, 0); //deixa led vermelho
  }
}

void trocaCor(int vermelho, int verde, int azul){
  digitalWrite(ledAzul, azul);
  digitalWrite(ledVerde, verde);
  digitalWrite(ledVermelho, vermelho);
  delay(100);
}
