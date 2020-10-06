int botao = 9;
int led = 7;
 
void setup()
{
  pinMode(botao, INPUT_PULLUP); // define o pino do botao como entrada "INPUT"
  pinMode(led, OUTPUT);
}
 
void loop()
{
  while(digitalRead(botao) == LOW) { // Se o botão for pressionado
    digitalWrite(led, HIGH); 
  }   
  digitalWrite(led, LOW); 
}
