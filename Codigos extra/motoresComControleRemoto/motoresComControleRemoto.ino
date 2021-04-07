#include <Servo.h>
#include <IRremote.h>

int ligaDesligaDC = 5;
int esqDC = 4;
int dirDC = 3;

Servo meuServo;
int anguloServo;

int sensorIR = 22;
IRrecv IRR(sensorIR);
decode_results results;
unsigned long int botao = 0;

void setup() {
  pinMode(ligaDesligaDC, OUTPUT);
  pinMode(esqDC, OUTPUT);
  pinMode(dirDC, OUTPUT);
  
  meuServo.attach(8);
  meuServo.write(90);
  anguloServo = meuServo.read();

  Serial.begin(9600);
  Serial.println("");
  Serial.println("Enabling IRin");
  IRR.enableIRIn();
  Serial.println("Enabled IRin");
}

void loop() {
  if (IRR.decode()) {
    if(IRR.results.value != 4294967295) {
      botao = IRR.results.value;
    }
    //unsigned long int 
    Serial.println(botao);

    switch (botao) {
      case 16761405: 
        mexeServoParaDireita();
        break;
      
      case 16720605:
        mexeServoParaEsquerda();
        break;
      
     case 16736925:
        mexeDCParaFrente();
        break;

     case 16754775:
        mexeDCParaTras();
        break;
    }
   
    IRR.resume(); // Receive the next value
  }

}

void mexeServoParaDireita(){
   Serial.println("Servo para a direita");
   if(anguloServo > 45) {
     anguloServo = anguloServo - 3;
     meuServo.write(anguloServo);
     delay(30);
   }
}

void mexeServoParaEsquerda(){
  Serial.println("Servo para a esquerda");
   if(anguloServo < 135) {
     anguloServo = anguloServo + 3;
     meuServo.write(anguloServo);
     delay(30);
   }
}

void mexeDCParaFrente(){
  Serial.println("DC para frente");
}

void mexeDCParaTras(){
  Serial.println("DC para tras");
}
