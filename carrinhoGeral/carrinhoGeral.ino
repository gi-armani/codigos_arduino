#include <Servo.h>

Servo meuServo;

int ligaDesligaDC = 5;
int DirDC = 4;
int EsqDC = 3;
int velocidadeDC = 100;

int botaoDirDC = 9;
int botaoEsqDC = 10;
int botaoDirServo = 12;
int botaoEsqServo = 13;
int angulo;

void setup() {
  meuServo.attach(7);
  meuServo.write(95);
  angulo = meuServo.read();

  pinMode(ligaDesligaDC, OUTPUT);
  pinMode(DirDC, OUTPUT);
  pinMode(EsqDC, OUTPUT);

  analogWrite(ligaDesligaDC,0);
  digitalWrite(DirDC,LOW);
  digitalWrite(EsqDC,LOW);

  pinMode(botaoDirDC, INPUT_PULLUP);
  pinMode(botaoEsqDC, INPUT_PULLUP);
  pinMode(botaoDirServo, INPUT_PULLUP);  
  pinMode(botaoEsqServo, INPUT_PULLUP);  
}

void loop() {

  while(digitalRead(botaoDirDC) == LOW){
    analogWrite(ligaDesligaDC,velocidadeDC);
    digitalWrite(DirDC,HIGH);
    digitalWrite(EsqDC,LOW);
  }
  while(digitalRead(botaoEsqDC) == LOW){
    analogWrite(ligaDesligaDC,velocidadeDC);
    digitalWrite(DirDC,LOW);
    digitalWrite(EsqDC,HIGH);
  }

  while(digitalRead(botaoDirServo)==LOW) {
    if(angulo > 50) {
      angulo = angulo - 1;
      meuServo.write(angulo);
      delay(20);
    }
  }
  
  while(digitalRead(botaoEsqServo)==LOW) {
    if(angulo < 140) {
      angulo = angulo + 1;
      meuServo.write(angulo);
      delay(20);
    }
  }

  analogWrite(ligaDesligaDC,0);
  digitalWrite(DirDC,LOW);
  digitalWrite(EsqDC,LOW);

}
