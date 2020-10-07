void setup()
{
  pinMode(9, INPUT_PULLUP); // define o pino do botao como entrada "INPUT"
  pinMode(7, OUTPUT);
}
 
void loop()
{
  while(digitalRead(9) == LOW) { // Se o botão for pressionado
    digitalWrite(7, HIGH); 
  }   
  digitalWrite(7, LOW); 
}
