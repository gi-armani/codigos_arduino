#define vel 3
#define motorDir 4
#define motorEsq 5
#define tmp 1000

int velocidade = 255;

void setup(){
  pinMode(vel, OUTPUT);
  pinMode(motorDir, OUTPUT);
  pinMode(motorEsq, OUTPUT);

  analogWrite(vel,0);
  digitalWrite(motorDir,LOW);
  digitalWrite(motorEsq,LOW);
}

void loop(){
  //M1
  analogWrite(vel,velocidade);
  digitalWrite(motorDir,HIGH);
  digitalWrite(motorEsq,LOW);
  /*delay(tmp);
  
  analogWrite(vel,0);
  digitalWrite(motorDir,LOW);
  digitalWrite(motorEsq,LOW);
  delay(100);
  
  //M1
  analogWrite(vel,velocidade);
  digitalWrite(motorDir,LOW);
  digitalWrite(motorEsq,HIGH);
  
  delay(tmp);*/
}
