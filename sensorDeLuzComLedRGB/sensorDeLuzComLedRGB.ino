
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
  Serial.println("Tudo certo");
  delay(3000);
}
 
void loop() {   
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledVermelho,HIGH); 
  lerLuz(); 
  delay(3000);  
  analogWrite(ledAzul,0);     
  analogWrite(ledVerde,85);
  analogWrite(ledVermelho,255);
  lerLuz(); 
  delay(3000);    
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,LOW);  
  lerLuz(); 
  delay(3000);  
}

void lerLuz(){
  valorLuz = analogRead(pinoSensorLuz);
  Serial.println(valorLuz);
}
