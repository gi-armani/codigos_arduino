int vel = 3;
int motorDir = 4;
int motorEsq = 5;
int temp = 1000;

int botaoDir = 10;
int botaoEsq = 11;

int velocidade = 55;

void setup(){
  pinMode(vel, OUTPUT);
  pinMode(motorDir, OUTPUT);
  pinMode(motorEsq, OUTPUT);

  analogWrite(vel,0);
  digitalWrite(motorDir,LOW);
  digitalWrite(motorEsq,LOW);

  pinMode(botaoDir, INPUT_PULLUP);
  pinMode(botaoEsq, INPUT_PULLUP);
}

void loop(){
  /*while(digitalRead(botaoDir) == LOW) {
    analogWrite(vel,velocidade);
    digitalWrite(motorDir,HIGH);
    digitalWrite(motorEsq,LOW);
  }

  while(digitalRead(botaoEsq) == LOW) {
    analogWrite(vel,velocidade);
    digitalWrite(motorDir,LOW);
    digitalWrite(motorEsq,HIGH);
  }

  analogWrite(vel,0);
  digitalWrite(motorDir,LOW);
  digitalWrite(motorEsq,LOW);*/

  if(digitalRead(botaoDir) == HIGH && digitalRead(botaoEsq) == HIGH) {
    analogWrite(vel,0);
    digitalWrite(motorDir,LOW);
    digitalWrite(motorEsq,LOW);
  } else if(digitalRead(botaoDir) == LOW) {
    analogWrite(vel,velocidade);
    digitalWrite(motorDir,HIGH);
    digitalWrite(motorEsq,LOW);
  } else {
    analogWrite(vel,velocidade);
    digitalWrite(motorDir,LOW);
    digitalWrite(motorEsq,HIGH);
  }
  
}
