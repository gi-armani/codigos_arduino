int ligaDesliga = 5;
int motorDir = 4;
int motorEsq = 3;

int velocidade = 100;

void setup(){
  pinMode(ligaDesliga, OUTPUT);
  pinMode(motorDir, OUTPUT);
  pinMode(motorEsq, OUTPUT);

  analogWrite(ligaDesliga,0);
  digitalWrite(motorDir,LOW);
  digitalWrite(motorEsq,LOW);
}

void loop(){
  analogWrite(ligaDesliga,velocidade);
  digitalWrite(motorDir,HIGH);
  digitalWrite(motorEsq,LOW);
}
