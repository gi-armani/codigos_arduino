int dirLigaDesliga = 46;
int dirSentidoHorario = 49;
int dirSentidoAnti = 48;

int esqLigaDesliga = 47;
int esqSentidoHorario = 50;
int esqSentidoAnti = 51;

int velocidade = 255;

void setup(){
  pinMode(dirLigaDesliga, OUTPUT);
  pinMode(dirSentidoHorario, OUTPUT);
  pinMode(dirSentidoAnti, OUTPUT);
  pinMode(esqLigaDesliga, OUTPUT);
  pinMode(esqSentidoHorario, OUTPUT);
  pinMode(esqSentidoAnti, OUTPUT);

  analogWrite(dirLigaDesliga,0);
  digitalWrite(dirSentidoHorario,LOW);
  digitalWrite(dirSentidoAnti,LOW);
  
  analogWrite(esqLigaDesliga,0);
  digitalWrite(esqSentidoHorario,LOW);
  digitalWrite(esqSentidoAnti,LOW);
}

void loop(){
  // Liga os dois sentido horario
  analogWrite(dirLigaDesliga,velocidade);
  digitalWrite(dirSentidoHorario,HIGH);
  
  analogWrite(esqLigaDesliga,velocidade);
  digitalWrite(esqSentidoHorario,HIGH);

  delay(2000);

  // Desliga os dois
  analogWrite(dirLigaDesliga,0);
  digitalWrite(dirSentidoHorario,LOW);
  analogWrite(esqLigaDesliga,0);
  digitalWrite(esqSentidoHorario,LOW);

  delay(2000);

  // Liga o da direita no sentido horario
  analogWrite(dirLigaDesliga,velocidade);
  digitalWrite(dirSentidoHorario,HIGH);

  delay(2000);

  // Desliga o da direita
  analogWrite(dirLigaDesliga,0);
  digitalWrite(dirSentidoHorario,LOW);

  delay(2000);

  // Liga o da esquerda no sentido horario
  analogWrite(esqLigaDesliga,velocidade);
  digitalWrite(esqSentidoHorario,HIGH);

  delay(2000);

  // Desliga o da esquerda
  analogWrite(esqLigaDesliga,0);
  digitalWrite(esqSentidoHorario,LOW);

  delay(2000);
}
