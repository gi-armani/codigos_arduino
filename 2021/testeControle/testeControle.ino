#include <IRremote.h>
int RECV_PIN = 40;
IRrecv IRR(RECV_PIN);
decode_results results;

void setup()
{
  //Enable serial usage and IR signal in
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  IRR.enableIRIn();
  Serial.println("Enabled IRin");
}

void loop() {
  if (IRR.decode()) {
    int botao = IRR.results.value;
    //Serial.println(IRR.results.value);

    switch (botao) {
      case 16736925: 
        Serial.println("Para frente");
        break;
      
      case 16754775:
        Serial.println("Para tras");
        break;
      
     case 16761405: 
        Serial.println("Para direita");
        break;
      
      case 16720605:
        Serial.println("Para esquerda");
        break;

      case 4294967295:
        Serial.println("Repetindo");
        break;
    } 
    
    IRR.resume(); // Receive the next value
  }
}
