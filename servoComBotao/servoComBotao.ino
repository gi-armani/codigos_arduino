#include <Servo.h>

Servo meuServo;
int botao=11;

void setup() {
  pinMode(botao, INPUT_PULLUP);  
}

void loop() {
  meuServo.attach(8);
  if(digitalRead(botao)==LOW){
    for(int angulo=0; angulo<=180;angulo++){
      meuServo.write(angulo);
      delay(10);
    }
    for(int angulo=180;angulo>=0;angulo--){
      meuServo.write(angulo);
      delay(10);
    }
  }
  meuServo.detach();

}
