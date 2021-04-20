#include <Servo.h>

Servo meuServo;
int botaoDir=2;
int botaoEsq=3;
int angulo;

void setup() {
  meuServo.attach(8);
  meuServo.write(90);
  angulo = meuServo.read();
  
  pinMode(botaoDir, INPUT_PULLUP);  
  pinMode(botaoEsq, INPUT_PULLUP);  
}

void loop() {
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

}
