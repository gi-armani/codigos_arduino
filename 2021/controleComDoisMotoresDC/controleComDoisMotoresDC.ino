#include <IRremote.h>
int RECV_PIN = 40;
IRrecv IRR(RECV_PIN);
decode_results results;

int dirLigaDesliga = 46;
int dirSentidoHorario = 49;
int dirSentidoAnti = 48;

int esqLigaDesliga = 47;
int esqSentidoHorario = 50;
int esqSentidoAnti = 51;

int velocidade = 255;

void setup()
{
  //Enable serial usage and IR signal in
  Serial.begin(9600);
  Serial.println("");
  IRR.enableIRIn();
  Serial.println("Enabled IRin");

  //Portas do motor
  pinMode(dirLigaDesliga, OUTPUT);
  pinMode(dirSentidoHorario, OUTPUT);
  pinMode(dirSentidoAnti, OUTPUT);
  pinMode(esqLigaDesliga, OUTPUT);
  pinMode(esqSentidoHorario, OUTPUT);
  pinMode(esqSentidoAnti, OUTPUT);

  analogWrite(dirLigaDesliga,0);
  digitalWrite(dirSentidoHorario,LOW);
  digitalWrite(dirSentidoAnti,LOW);
  
  analogWrite(esqLigaDesliga,0);
  digitalWrite(esqSentidoHorario,LOW);
  digitalWrite(esqSentidoAnti,LOW);
}

void loop() {
  if (IRR.decode()) { // devolve 0 ou 1 se esta apertando botao ou nao
    int botao = IRR.results.value; // passa o codigo do botao
    
    switch (botao) {
      case 16736925: 
        paraFrente();
        break;
      
      case 16754775:
        paraTras();
        break;
      
     case 16761405: 
        paraDireita();
        break;
      
      case 16720605:
        paraEsquerda();
        break;

      case 16712445:
        pararMotores();
        break;
    } 
    
    IRR.resume(); // Receive the next value
  }
}

void paraFrente(){
    analogWrite(dirLigaDesliga,velocidade);
    digitalWrite(dirSentidoHorario,HIGH);
    digitalWrite(dirSentidoAnti,LOW);
    analogWrite(esqLigaDesliga,velocidade);
    digitalWrite(esqSentidoHorario,LOW);
    digitalWrite(esqSentidoAnti,HIGH);
}
void paraTras(){
    analogWrite(dirLigaDesliga,velocidade);
    digitalWrite(dirSentidoHorario,LOW);
    digitalWrite(dirSentidoAnti,HIGH);
    analogWrite(esqLigaDesliga,velocidade);
    digitalWrite(esqSentidoHorario,HIGH);
    digitalWrite(esqSentidoAnti,LOW);
}
void paraDireita(){
    analogWrite(dirLigaDesliga,velocidade);
    digitalWrite(dirSentidoHorario,HIGH);
    digitalWrite(dirSentidoAnti,LOW);
    analogWrite(esqLigaDesliga,0);
    digitalWrite(esqSentidoHorario,LOW);
    digitalWrite(esqSentidoAnti,LOW);
}
void paraEsquerda(){
    analogWrite(dirLigaDesliga,0);
    digitalWrite(dirSentidoHorario,LOW);
    digitalWrite(dirSentidoAnti,LOW);
    analogWrite(esqLigaDesliga,velocidade);
    digitalWrite(esqSentidoHorario,HIGH);
    digitalWrite(esqSentidoAnti,LOW);
}
void pararMotores() {
   analogWrite(dirLigaDesliga,0);
   digitalWrite(dirSentidoHorario,LOW);
   digitalWrite(dirSentidoAnti,LOW);
   analogWrite(esqLigaDesliga,0);
   digitalWrite(esqSentidoHorario,LOW);
   digitalWrite(esqSentidoAnti,LOW);
}
