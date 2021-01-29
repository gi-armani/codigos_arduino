
const int ledAzul = 8;
const int ledVerde = 9;
const int ledVermelho = 10;
 
void setup() {
  pinMode(ledAzul,OUTPUT);   
  pinMode(ledVerde,OUTPUT);   
  pinMode(ledVermelho,OUTPUT);    
}
 
void loop() {   
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledVermelho,HIGH);  
  delay(1500);  
  analogWrite(ledAzul,0);     
  analogWrite(ledVerde,100);
  analogWrite(ledVermelho,255);
  delay(1500);    
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,LOW);  
  delay(1500);  
}
