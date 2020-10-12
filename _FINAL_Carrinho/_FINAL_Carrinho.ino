#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************
 * DECLARAÇÃO DE VARIAVEIS
 **************************************************************/
//CONSTANTES DOS MOTORES [esquerdo, direito (e,d)
/*const int eh = 5;
const int dh = 11;
const int ea = 6;
const int da = 10;*/

const int eh = 10;
const int dh = 13;
const int ea = 11;
const int da = 12;

//VARIAVEIS DO MOTOR
float pot;
float tempo;

//VARIVEIS DO TEMPO
unsigned long tempoExecucao;
unsigned long tempoInicio;
unsigned long tempoFim;

//OUTRAS VARIAVEIS
String leituraSerial;
boolean completo;
boolean executa;
boolean cancela;
int rodaEsquerda;
int rodaDireita;
String moduloExecucao;
int tempoEspera;

//CONSTANTES DAS DIRECOES E MODULOS
const String frente = "f";
const String parado = "p";
const String tras = "t";
const String moduloConect = "s";
const String moduloDesc = "n";


/***************************************************************
 * SETUP DO PROGRAMA
 **************************************************************/
void setup() {
    tempoInicio = 0;
    tempoFim = 0;
    leituraSerial = "";
    completo = false;
    executa = false;
    cancela = false;

    pinMode(eh,OUTPUT);
    pinMode(ea,OUTPUT);
    pinMode(dh,OUTPUT);
    pinMode(da,OUTPUT);
    Serial.begin(9600);
}

/***************************************************************
 * LOOP & SERIAL EVENT DO PROGRAMA
 *
 * Ao receber algum dado novo pela serial executa SerialEvent()
 * Exceto isso, o loop() acontece infitamente
 **************************************************************/
 
void serialEvent() {
  
      //Enquanto houver dados entrando...
      while (Serial.available() > 0) {
         char caractere = (char)Serial.read();
        
        //caso a passagem de dados nao esteja completa
        if (completo == false){
            //Adiciona o caractere lido a lista de caracteres
            leituraSerial += caractere;
            //Caso seja o demarcador final, completou
            if (caractere == '!')
              completo = true;
        } 
        
        //caso seja pedida uma parada
        if (caractere == '#') {
               cancela = true;
               completo = false;
               leituraSerial = "";
               Serial.write("#");
         }      
      } 
}
 
//Trata do modulo de execucao, do tempo de desc, e de mandar fazer acontecer
void loop() {  
  
    //caso alguma isntrucao esteja em execucao, verifica o tempo
    if (executa == true && (millis() - tempoInicio > tempoExecucao)){
      //Depois de cumprir a execucao, para
      desligaCarrinho();
      executa = false;
    }  
  
     //depois de completar a leitura serial do programa
     if (completo == true) {
       
       //começa a cortar a string recebida, primeiro pelo modulo de execuço
       int esp = leituraSerial.indexOf(' ');       
       moduloExecucao = leituraSerial.substring(0, esp);      
       
       //depois guarda o resto
       int final = leituraSerial.indexOf('!');            
       leituraSerial = leituraSerial.substring(esp+1, final+1);
       
       //caso o modulo seja desconectado     
       if (moduloExecucao == moduloDesc){
          Serial.write("*"); 
         
         //pega a primeira coisa antes do espaço, nesse caso o tempo
         int tempoDesc = leituraSerial.indexOf(' '); 
         int v3 = leituraSerial.indexOf('!'); //pega o resto
                       
         String lendoEspera = leituraSerial.substring(0, tempoDesc);    
         leituraSerial = leituraSerial.substring(tempoDesc+1, v3+1);        
                  
         tempoEspera = lendoEspera.toInt();   
         int i = 0;
                  
          delay(tempoEspera * 1000L);
       }
       serialEvent(); 
           
        //Se a instruçao foi pega, age
        carregaDados();
        
        //Depois, zera tudo para o proximo uso
        leituraSerial = "";
        completo = false;  
        
        //se o modulo for conectado, manda um sinal que terminou tudo!
        if (moduloExecucao == moduloConect) {
            Serial.write("*");
        }         
     }   
}


  
  
/***************************************************************
 * carrega o programa
 *
 * separa em si as informaçoes da serial e as executa
 **************************************************************/
void carregaDados(){    
    String programa = leituraSerial;

//Primeiro, forma os dados do tempo de execuço e potencia do motor

     int v1 = programa.indexOf(' '); //pega indice do tempo
     String lendoTempo = programa.substring(0, v1);     
     
     int v3 = programa.indexOf('!'); //pega o resto
     programa = programa.substring(v1+1, v3+1);  //corta a string do programa
     
     int v2 = programa.indexOf('.'); //pega indice da potencia              
     String lendoPotencia = programa.substring(0, v2); //pega potencia
     
     v3 = programa.indexOf('!'); //pega o resto
     programa = programa.substring(v2+1, v3+1);  //corta a string do programa
         
   
     
     //Agora, transforma o tipo de tempo e potencia para outro tipo
     float t = lendoTempo.toFloat();
     float p = lendoPotencia.toFloat();
     
     tempoExecucao = t * 1000;
     pot = p;     


    int indice = 0;
   //Executa ate o programa chegar no fim
        while (programa != "!" && cancela == false) {      
           //ATENCAO! Modelo: 1,1.2,2.3,3.!         
           
           int v1 = programa.indexOf(','); //pega indice primeira instrucao
           int v2 = programa.indexOf('.'); //pega indice segunda instrucao
           int v3 = programa.indexOf('!'); //pega o resto
                         
           String rodaE = programa.substring(0, v1);     //pega primeira instrucao
           String rodaD = programa.substring(v1+1, v2); //pega segunda instrucao
           programa = programa.substring(v2+1, v3+1);  //corta a string do programa
         
           
           //chama executa e marca o tempo de inicio
           tempoInicio = millis();
           
           if (moduloExecucao == moduloConect) {
             indice = indice + 1;
             Serial.print(indice, DEC);
           }
           executaMovimento(rodaE, rodaD);       
           executa = true;  
           
           //enquanto o carrinho executa, para de carregar o resto das intruçoes
           delay(tempoExecucao);   
           serialEvent();  
         
        }    
        
        if (cancela == true) cancela = false;
      
}
  
   
  
  /************************************
   * Executa movimentacao do carrinho
   ***********************************/
  void executaMovimento(String esq, String dir){   
       //Se tudo der certo e ambas as rodas tiverem valores executa movimentos
         if (esq != NULL && dir !=NULL)
         if (esq == frente && dir == frente) 
           vaiFF();
         else if (esq == tras && dir == tras) 
           vaiTT();
         else if (esq == frente && dir == tras) 
           vaiFT();
         else if (esq == tras && dir == frente) 
           vaiTF();
         else if (esq == parado && dir == parado)
           vaiPP(); 
         else if (esq == frente && dir ==parado)
           vaiFP();
         else if (esq == parado && dir ==frente)
            vaiPF();
         else if (esq == parado && dir ==tras)
           vaiPT();
         else if (esq == tras && dir == parado)
           vaiTP();      
  }
  

   
  /****************************
   * desliga instrucao
   ***************************/
  void desligaCarrinho(){
    digitalWrite(eh, 0);
    digitalWrite(dh, 0);
    digitalWrite(ea, 0);
    digitalWrite(da, 0);
  }
  
   /****************************
   * Vai pra Frente
   ***************************/
  void vaiFF(){
      digitalWrite(eh, pot);
      digitalWrite(dh, pot);
      digitalWrite(ea, 0);
      digitalWrite(da, 0);
  }
  
  
   /****************************
   * Vai pra FT
   ***************************/
  void vaiFT(){
      digitalWrite(eh, pot);
      digitalWrite(dh, 0);
      digitalWrite(ea, 0);
      digitalWrite(da, pot);
  }
  
  
   /****************************
   * Vai pra TF
   ***************************/
  void vaiTF(){
      digitalWrite(eh, 0);
      digitalWrite(dh, pot);
      digitalWrite(ea, pot);
      digitalWrite(da, 0);
  }
  
  /****************************
   * Vai pra TT
   ***************************/
  void vaiTT(){
      digitalWrite(eh, 0);
      digitalWrite(dh, 0);
      digitalWrite(ea, pot);
      digitalWrite(da, pot);
  }  
  
  /****************************
   * Vai pra PP
   ***************************/
  void vaiPP(){
      digitalWrite(eh, 0);
      digitalWrite(dh, 0);
      digitalWrite(ea, 0);
      digitalWrite(da, 0);
  }
  
  /****************************
   * Vai pra FP
   ***************************/
  void vaiFP(){
      digitalWrite(eh, pot);
      digitalWrite(dh, 0);
      digitalWrite(ea, 0);
      digitalWrite(da, 0);
  }
  
    
  /****************************
   * Vai pra PF
   ***************************/
  void vaiPF(){
      digitalWrite(eh, 0);
      digitalWrite(dh, pot);
      digitalWrite(ea, 0);
      digitalWrite(da, 0);
  }
  
    
  /****************************
   * Vai pra PT
   ***************************/
  void vaiPT(){
      digitalWrite(eh, 0);
      digitalWrite(dh, 0);
      digitalWrite(ea, 0);
      digitalWrite(da, pot);
  }
  
    
  /****************************
   * Vai pra TP
   ***************************/
  void vaiTP(){
      digitalWrite(eh, 0);
      digitalWrite(dh, 0);
      digitalWrite(ea, pot);
      digitalWrite(da, 0);
  }
