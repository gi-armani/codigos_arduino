#include <Servo.h>

Servo meuServo;
int botaoDir=12;
int botaoEsq=11;
int angulo;

void setup() {
  meuServo.attach(8);
  meuServo.write(90);
  angulo = meuServo.read();
  
  pinMode(botaoDir, INPUT_PULLUP);  
  pinMode(botaoEsq, INPUT_PULLUP);  
}

void loop() {
  //meuServo.attach(8);
  while(digitalRead(botaoDir)==LOW) {
    if(angulo > 45) {
      angulo = angulo - 1;
      meuServo.write(angulo);
      delay(20);
    }
  }
  
  while(digitalRead(botaoEsq)==LOW) {
    if(angulo < 135) {
      angulo = angulo + 1;
      meuServo.write(angulo);
      delay(20);
    }
  }
  
  /*if(digitalRead(botao)==LOW){
    for(int angulo=0; angulo<=180;angulo++){
      meuServo.write(angulo);
      delay(10);
    }
    for(int angulo=180;angulo>=0;angulo--){
      meuServo.write(angulo);
      delay(10);
    }
  }*/
  //meuServo.detach();

}
