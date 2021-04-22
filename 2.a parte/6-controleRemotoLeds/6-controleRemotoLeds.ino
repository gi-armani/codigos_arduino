#include <IRremote.h>
//Define Pins
int ledVermelho = 3;
int ledAzul = 4;
int ledVerde = 5;

int RECV_PIN = 11;
IRrecv IRR(RECV_PIN);
decode_results results;

void setup()
{
  //Set Led Pins
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  //Enable serial usage and IR signal in
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  IRR.enableIRIn();
  Serial.println("Enabled IRin");
}

void loop() {
  if (IRR.decode()) {
    int botao = IRR.results.value;
    Serial.println(IRR.results.value);

    switch (botao) {
      case 16724175: 
        digitalWrite(ledVermelho, HIGH);
        delay(500);
        digitalWrite(ledVermelho, LOW);
        break;
      
      case 16718055:
        digitalWrite(ledAzul, HIGH);
        delay(500);
        digitalWrite(ledAzul, LOW);
        break;
      
     case 16743045:
        digitalWrite(ledVerde, HIGH);
        delay(500);
        digitalWrite(ledVerde, LOW);
        break;
    }
    
    
    IRR.resume(); // Receive the next value
  }
}
