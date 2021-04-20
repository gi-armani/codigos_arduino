void setup()
{
  pinMode(9, INPUT_PULLUP); // define o pino do botao como entrada "INPUT"
  pinMode(7, OUTPUT);
}
 
void loop()
{
  if(digitalRead(9) == LOW) { // Se o botão for pressionado
    
    if(digitalRead(7) == HIGH) {
      digitalWrite(7, LOW);
    } else {
      digitalWrite(7, HIGH);
    }
    delay(1000); 
  }    
}
