//Sensor de distancia
#define echoPin 5 
#define trigPin 4 
long duration; //duration of sound wave travel
int distance; //distance measurement

//LEDs distancia
int ledVermelho = 7;
int ledVerde = 8;
int ledAzul = 9;

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
}

void moverParaTras(){
  analogWrite(dirLigaDesliga,velocidade);
  digitalWrite(dirSentidoHorario,LOW);
  digitalWrite(dirSentidoAnti,HIGH);
  analogWrite(esqLigaDesliga,velocidade);
  digitalWrite(esqSentidoHorario,HIGH);
  digitalWrite(esqSentidoAnti,LOW);
}

void moverParaDireita(){
  analogWrite(esqLigaDesliga,0);
  digitalWrite(esqSentidoHorario,LOW);
  digitalWrite(esqSentidoAnti,LOW);
  analogWrite(dirLigaDesliga,velocidade);
  digitalWrite(dirSentidoHorario,HIGH);
  digitalWrite(dirSentidoAnti,LOW);
}

void moverParaEsquerda(){
  analogWrite(dirLigaDesliga,0);
  digitalWrite(dirSentidoHorario,LOW);
  digitalWrite(dirSentidoAnti,LOW);
  analogWrite(esqLigaDesliga,velocidade);
  digitalWrite(esqSentidoHorario,HIGH);
  digitalWrite(esqSentidoAnti,LOW);
}

void pararMotores(){
  analogWrite(dirLigaDesliga,0);
  digitalWrite(dirSentidoHorario,LOW);
  digitalWrite(dirSentidoAnti,LOW);
  analogWrite(esqLigaDesliga,0);
  digitalWrite(esqSentidoHorario,LOW);
  digitalWrite(esqSentidoAnti,LOW);
}

void controleMotores(){
  if (IRR.decode()) { // devolve 0 ou 1 se esta apertando botao ou nao
    int botao = IRR.results.value; // passa o codigo do botao
    
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
    } 
    IRR.resume(); // Receive the next value
  }
}

void loop() {
  
  medirDistancia();
  controleMotores();

}
