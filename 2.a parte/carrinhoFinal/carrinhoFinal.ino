#include <IRremote.h>

//Sensor de distancia
#define echoPin 13 
#define trigPin 12 
long duration; //duration of sound wave travel
int distance; //distance measurement

//LEDs distancia
int ledVermelho = 22;
int ledVerde = 23;
int ledAzul = 24;

//Controle
int RECV_PIN = 11;
IRrecv IRR(RECV_PIN);
decode_results results;

//Motores DC
int dirLigaDesliga = 46;
int dirSentidoHorario = 49;
int dirSentidoAnti = 48;
int esqLigaDesliga = 47;
int esqSentidoHorario = 50;
int esqSentidoAnti = 51;
int velocidade = 255;

//Display 7 segmentos
byte seven_seg_digits[4][7] =  { { 1,1,1,1,1,1,0 },  // = Digito 0
                                 { 0,1,1,0,0,0,0 },  // = Digito 1
                                 { 1,1,0,1,1,0,1 },  // = Digito 2
                                 { 1,1,1,1,0,0,1 },  // = Digito 3
                                };
//Marcha
int marchaGlobal = 0;

void setup() {
  //Sensor de distancia
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //Inicializacao serial
  Serial.begin(9600);
  
  //LEDs distancia
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  //Controle
  IRR.enableIRIn();
  IRR.blink13(true);

  //Motores DC
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

  //Display
  pinMode(2, OUTPUT); //Pino 2 do Arduino ligado ao segmento A  
  pinMode(3, OUTPUT); //Pino 3 do Arduino ligado ao segmento B
  pinMode(4, OUTPUT); //Pino 4 do Arduino ligado ao segmento C
  pinMode(5, OUTPUT); //Pino 5 do Arduino ligado ao segmento D
  pinMode(6, OUTPUT); //Pino 6 do Arduino ligado ao segmento E
  pinMode(7, OUTPUT); //Pino 7 do Arduino ligado ao segmento F
  pinMode(8, OUTPUT); //Pino 8 do Arduino ligado ao segmento G
  pinMode(9, OUTPUT); //Pino 9 do Arduino ligado ao segmento PONTO

  printaMarcha(0);
}

void medirDistancia(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance < 50 && distance > 20){
    trocaCorLed(255, 255, 0); //Amarelo
  }
  else if(distance < 20){
    trocaCorLed(255, 0, 0); //Vermelho
  }
  else{
    trocaCorLed(0, 255, 0); //Verde
  }
}

void trocaCorLed(int red, int green, int blue){
  analogWrite(ledVermelho, red);
  analogWrite(ledVerde, green);
  analogWrite(ledAzul, blue);  
}

void moverParaFrente(){
  analogWrite(dirLigaDesliga,velocidade);
  digitalWrite(dirSentidoHorario,HIGH);
  digitalWrite(dirSentidoAnti,LOW);
  analogWrite(esqLigaDesliga,velocidade);
  digitalWrite(esqSentidoHorario,LOW);
  digitalWrite(esqSentidoAnti,HIGH);

  if(marchaGlobal == 0) printaMarcha(1);
}

void moverParaTras(){
  analogWrite(dirLigaDesliga,velocidade);
  digitalWrite(dirSentidoHorario,LOW);
  digitalWrite(dirSentidoAnti,HIGH);
  analogWrite(esqLigaDesliga,velocidade);
  digitalWrite(esqSentidoHorario,HIGH);
  digitalWrite(esqSentidoAnti,LOW);

  if(marchaGlobal == 0) printaMarcha(1);
}

void moverParaDireita(){
  analogWrite(esqLigaDesliga,0);
  digitalWrite(esqSentidoHorario,LOW);
  digitalWrite(esqSentidoAnti,LOW);
  analogWrite(dirLigaDesliga,velocidade);
  digitalWrite(dirSentidoHorario,HIGH);
  digitalWrite(dirSentidoAnti,LOW);

  if(marchaGlobal == 0) printaMarcha(1);
}

void moverParaEsquerda(){
  analogWrite(dirLigaDesliga,0);
  digitalWrite(dirSentidoHorario,LOW);
  digitalWrite(dirSentidoAnti,LOW);
  analogWrite(esqLigaDesliga,velocidade);
  digitalWrite(esqSentidoHorario,HIGH);
  digitalWrite(esqSentidoAnti,LOW);

  if(marchaGlobal == 0) printaMarcha(1);
}

void pararMotores(){
  analogWrite(dirLigaDesliga,0);
  digitalWrite(dirSentidoHorario,LOW);
  digitalWrite(dirSentidoAnti,LOW);
  analogWrite(esqLigaDesliga,0);
  digitalWrite(esqSentidoHorario,LOW);
  digitalWrite(esqSentidoAnti,LOW);

  printaMarcha(0);
}

void printaMarcha(int marcha){
  marchaGlobal = marcha;
  int portaSegmento = 2;
  for (int segmento = 0; segmento < 7; segmento++){ 
    digitalWrite(portaSegmento, seven_seg_digits[marcha][segmento]);
    portaSegmento++;
  }
}

void controle(){
  if (IRR.decode(&results)) { // devolve 0 ou 1 se esta apertando botao ou nao
    int botao = results.value; // passa o codigo do botao
    
    switch (botao) {
      case 16736925: 
        moverParaFrente();
        break;
      
      case 16754775:
        moverParaTras();
        break;
      
     case 16761405: 
        moverParaDireita();
        break;
      
      case 16720605:
        moverParaEsquerda();
        break;

      case 16712445:
        pararMotores();
        break;

      /*
      case CODIGO DO BOTAO 1:
        printaMarcha(1);
        break;
      
      case CODIGO DO BOTAO 2:
        printaMarcha(2);
        break;

      case CODIGO DO BOTAO 3:
        printaMarcha(3);
        break;
      */
    } 
    Serial.println(results.value, HEX);
    IRR.resume(); // Receive the next value
  }
}

void loop() {
  
  //medirDistancia();
  controle();

}
