int ligaDesliga = 5;
int motorDir = 4;
int motorEsq = 3;

int botaoDir = 10;
int botaoEsq = 11;

int velocidade = 100;

void setup(){
  pinMode(ligaDesliga, OUTPUT);
  pinMode(motorDir, OUTPUT);
  pinMode(motorEsq, OUTPUT);

  analogWrite(ligaDesliga,0);
  digitalWrite(motorDir,LOW);
  digitalWrite(motorEsq,LOW);

  pinMode(botaoDir, INPUT_PULLUP);
  pinMode(botaoEsq, INPUT_PULLUP);
}

void loop(){
  if(digitalRead(botaoDir) == HIGH && digitalRead(botaoEsq) == HIGH) {
    analogWrite(ligaDesliga,0);
    digitalWrite(motorDir,LOW);
    digitalWrite(motorEsq,LOW);
  } else if(digitalRead(botaoDir) == LOW) {
    analogWrite(ligaDesliga,velocidade);
    digitalWrite(motorDir,HIGH);
    digitalWrite(motorEsq,LOW);
  } else {
    analogWrite(ligaDesliga,velocidade);
    digitalWrite(motorDir,LOW);
    digitalWrite(motorEsq,HIGH);
  }
}
