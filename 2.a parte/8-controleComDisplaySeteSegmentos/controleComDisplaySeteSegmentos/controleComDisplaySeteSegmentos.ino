#include <IRremote.h>

//Controle
int RECV_PIN = 12;
IRrecv IRR(RECV_PIN);
decode_results results;

//Display
byte seven_seg_digits[4][7] =  { { 1,1,1,1,1,1,0 },  // = Digito 0
                                 { 0,1,1,0,0,0,0 },  // = Digito 1
                                 { 1,1,0,1,1,0,1 },  // = Digito 2
                                 { 1,1,1,1,0,0,1 },  // = Digito 3
                                 };

//Marcha
int marcha = 0;

void setup(){ 
  //Enable serial usage and IR signal in
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  IRR.enableIRIn();
  Serial.println("Enabled IRin");

  //Display
  pinMode(2, OUTPUT); //Pino 2 do Arduino ligado ao segmento A  
  pinMode(3, OUTPUT); //Pino 3 do Arduino ligado ao segmento B
  pinMode(4, OUTPUT); //Pino 4 do Arduino ligado ao segmento C
  pinMode(5, OUTPUT); //Pino 5 do Arduino ligado ao segmento D
  pinMode(6, OUTPUT); //Pino 6 do Arduino ligado ao segmento E
  pinMode(7, OUTPUT); //Pino 7 do Arduino ligado ao segmento F
  pinMode(8, OUTPUT); //Pino 8 do Arduino ligado ao segmento G
  pinMode(9, OUTPUT); //Pino 9 do Arduino ligado ao segmento PONTO

  printaMarcha(0);
}

void loop() {
  if (IRR.decode()) {
    int botao = IRR.results.value;
    Serial.println(IRR.results.value);

    switch (botao) {
      case 16736925: 
        mudaMarcha();
        break;
    } 
    
    IRR.resume(); // Receive the next value
  }
}

void mudaMarcha(){
  if(marcha == 3){
    marcha = 0;
  } else {
    marcha++;
  }
  Serial.print("Marcha: ");
  Serial.println(marcha);
  printaMarcha(marcha);
}

void printaMarcha(int marcha){
  int porta = 2;
  for (int segmento = 0; segmento < 7; segmento++){ 
    digitalWrite(porta, seven_seg_digits[marcha][segmento]);
    porta++;
  }
  
}
