#include <IRremote.h>

//Sensor de distancia
#define echoPin 11
#define trigPin 10 
long duration; //duration of sound wave travel
int distance; //distance measurement

//LEDs distancia
int ledVermelho = 7;
int ledVerde = 6;
int ledAzul = 5;

//Controle
int RECV_PIN = 22;

//Motores DC
int dirLigaDesliga = 47;
int dirSentidoHorario = 50;
int dirSentidoAnti = 51;
int esqLigaDesliga = 46;
int esqSentidoHorario = 49;
int esqSentidoAnti = 48;
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
  //IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

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
  digitalWrite(dirSentidoHorario,LOW);
  digitalWrite(dirSentidoAnti,HIGH);
  analogWrite(esqLigaDesliga,velocidade);
  digitalWrite(esqSentidoHorario,HIGH);
  digitalWrite(esqSentidoAnti,LOW);

  if(marchaGlobal == 0) printaMarcha(1);
}

void moverParaTras(){
  analogWrite(dirLigaDesliga,velocidade);
  digitalWrite(dirSentidoHorario,HIGH);
  digitalWrite(dirSentidoAnti,LOW);
  analogWrite(esqLigaDesliga,velocidade);
  digitalWrite(esqSentidoHorario,LOW);
  digitalWrite(esqSentidoAnti,HIGH);

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
  /*if (IrReceiver.decode()) { // devolve 0 ou 1 se esta apertando botao ou nao
     // passa o codigo do botao
    
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 3108437760:
        Serial.println("duda");
        moverParaFrente();
        break;
      
      case 3927310080:
        moverParaTras();
        break;
      
     case 3158572800:
        moverParaDireita();
        break;
      
     case 3141861120:
        moverParaEsquerda();
        break;

     case 3208707840:
        pararMotores();
        break;

     case 4077715200:
        printaMarcha(1);
        break;
      
     case 3877175040:
        printaMarcha(2);
        break;

     case 2707357440:
        printaMarcha(3);
        break;
      
    } 
    IrReceiver.resume(); // Receive the next value
  }*/
}

void loop() {
  
  medirDistancia();
  controle();
}
