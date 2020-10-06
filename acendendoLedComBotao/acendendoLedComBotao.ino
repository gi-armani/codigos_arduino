int botao = 9;
int led = 7;
 
void setup()
{
  pinMode(botao, INPUT_PULLUP); // define o pino do botao como entrada "INPUT"
  pinMode(led, OUTPUT);
}
 
void loop()
{
  if(digitalRead(botao) == LOW) { // Se o botão for pressionado
    bool estadoLed = digitalRead(7);
    if(estadoLed == HIGH) {
      digitalWrite(led, LOW);
    } else {
      digitalWrite(led, HIGH);
    }
    delay(1000); 
  }    
}
