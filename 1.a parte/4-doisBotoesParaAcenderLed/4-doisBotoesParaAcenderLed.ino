int primeiroBotao = 9;
int primeiroLed = 7;
int segundoBotao = 3;
int segundoLed = 5;
 
void setup()
{
  pinMode(primeiroBotao, INPUT_PULLUP); // define o pino do botao como entrada "INPUT"
  pinMode(primeiroLed, OUTPUT);
  pinMode(segundoBotao, INPUT_PULLUP); // define o pino do botao como entrada "INPUT"
  pinMode(segundoLed, OUTPUT);
}
 
void loop()
{
  while(digitalRead(segundoBotao) == LOW) { // Se o botão for pressionado
    digitalWrite(segundoLed, HIGH); 
  }   
  digitalWrite(segundoLed, LOW); 
  
  if(digitalRead(primeiroBotao) == LOW) { // Se o botão for pressionado
    bool estadoLed = digitalRead(7);
    if(estadoLed == HIGH) {
      digitalWrite(primeiroLed, LOW);
    } else {
      digitalWrite(primeiroLed, HIGH);
    }
    delay(1000);
  } 

  
}
