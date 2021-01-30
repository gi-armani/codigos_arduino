
int ledAzul = 8;
int ledVerde = 9;
int ledVermelho = 10;

int pinoSensorLuz = A0;               
int valorLuz; 
 
void setup() {
  pinMode(ledAzul,OUTPUT);   
  pinMode(ledVerde,OUTPUT);   
  pinMode(ledVermelho,OUTPUT);  

  Serial.begin(9600);
  Serial.println();
  Serial.println("Tudo certo");
  delay(3000);
}
 
void loop() {   
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledVermelho,HIGH); 
  lerLuz(); 
  delay(1500);  
  analogWrite(ledAzul,0);     
  analogWrite(ledVerde,255);
  analogWrite(ledVermelho,255);
  lerLuz(); 
  delay(1500);    
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,LOW);  
  lerLuz(); 
  delay(1500);  
}

void lerLuz(){
  valorLuz = analogRead(pinoSensorLuz);
  if(valorLuz > 885) {
    Serial.print("VERDE: ");
    Serial.println(valorLuz);
  } else if(valorLuz > 850) {
    Serial.print("AMARELO: ");
    Serial.println(valorLuz);
  } else {
    Serial.print("VERMELHO: ");
    Serial.println(valorLuz);
  }
}
