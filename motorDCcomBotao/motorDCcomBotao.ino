int motorDC = 3;
int botao = 8;
int led = 10;
bool estadoMotor = digitalRead(motorDC);
bool estadoLed = digitalRead(led);

void setup() {
  pinMode(motorDC, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  
  if(digitalRead(botao) == LOW) {
    if(digitalRead(led) == LOW) {
      digitalWrite(motorDC, HIGH);
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(motorDC, LOW);
      digitalWrite(led, LOW);
    }
    //delay(2000);
  }


  
  /*digitalWrite(motorDC, estadoMotor);
    
  if(digitalRead(botao) == LOW) {
  if(digitalRead(led) == LOW) {
      estadoMotor = HIGH;
      estadoLed = HIGH;
      digitalWrite(motorDC, estadoMotor);
      //digitalWrite(led, HIGH);
  } else {
      estadoMotor = LOW;
      estadoLed = LOW;
      digitalWrite(motorDC, estadoMotor);
      //digitalWrite(led, LOW);
  }
    delay(1000);
  }

  digitalWrite(motorDC, estadoMotor);*/

  

  
  /*if(digitalRead(botao) == LOW && digitalRead(motorDC) == LOW) {
    digitalWrite(motorDC, HIGH);
    digitalWrite(led, HIGH);
  }

  if(digitalRead(botao) == LOW && digitalRead(motorDC) == HIGH) {
    digitalWrite(motorDC, LOW);
    digitalWrite(led, LOW);
  }*/
  
}
