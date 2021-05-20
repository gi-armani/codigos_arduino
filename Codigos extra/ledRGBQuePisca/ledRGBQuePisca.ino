
const int ledAzul = 8;
const int ledVerde = 9;
const int ledVermelho = 10;
 
void setup() {
  pinMode(ledAzul,OUTPUT);   
  pinMode(ledVerde,OUTPUT);   
  pinMode(ledVermelho,OUTPUT);    
}
 
void loop() {   
  digitalWrite(ledAzul,0);
  digitalWrite(ledVerde,0);
  digitalWrite(ledVermelho,255);  
  delay(1500);  
  analogWrite(ledAzul,0);     
  analogWrite(ledVerde,100);
  analogWrite(ledVermelho,255);
  delay(1500);    
  digitalWrite(ledAzul,0);
  digitalWrite(ledVerde,255);
  digitalWrite(ledVermelho,0);  
  delay(1500);  
}
