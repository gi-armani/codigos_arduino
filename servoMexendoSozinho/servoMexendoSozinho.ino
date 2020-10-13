#include <Servo.h>

Servo meuServo;
int angulo;

void setup() {
  meuServo.attach(8);
  meuServo.write(0);
  angulo = meuServo.read(); 
}

void loop() {
  if(angulo < 180) {
     angulo = angulo + 1;
     meuServo.write(angulo);
     delay(20);
   }
}
