#include <Servo.h>
Servo myServo;

const int piezo =A0;
const int ledrojo = 5;
const int ledverde =4;
const int ledamarillo=3;
const int boton=2;

int interruptorvalor;
int piezovalor;

const int golpemax=100;
const int golpemin =10;

boolean cerrado=false;
int numerodellamadasbuenas =0;

void setup() {
  
  myServo.attach (9);
  for(int i=3;i<=5;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(boton,INPUT);
  
  Serial.begin(9600);

  digitalWrite(ledverde, HIGH);
  myServo.write(0);
  Serial.print("La caja está abierta");
}

void loop() {

  if (cerrado == false){
    interruptorvalor = digitalRead(boton);
  
  if (interruptorvalor == HIGH){
    cerrado = true;
    digitalWrite(ledverde, LOW);
    digitalWrite(ledrojo, HIGH);
    myServo.write(90);
    Serial.print("\nLa caja está cerrada");
    delay(1000);
    }
  }
  if (cerrado == true){
    piezovalor = analogRead(piezo);
  
  if (numerodellamadasbuenas < 3 &&  piezovalor >0){
    if (chequeollamadas (piezovalor) == true){
      numerodellamadasbuenas++;
    }
    Serial.print ("\n");
    Serial.print(3 - numerodellamadasbuenas);
    Serial.print(" necesitas golpes para abrir");
  }

  if (numerodellamadasbuenas >=3){
    cerrado =false;
    myServo.write (0);
    delay(20);
    digitalWrite(ledverde, HIGH);
    digitalWrite(ledrojo, LOW);
    Serial.print("\nLa caja está abierta");
    }
  
  }

}

boolean chequeollamadas(int valor){

  if (valor > golpemin && valor <golpemax){

    delay(50);
    digitalWrite(ledamarillo, LOW);
    Serial.print ("\nGolpe válido ");
    Serial.print (valor);
      return true;
  }
  else{

    Serial.print ("\nGolpe no válido ");
    Serial.print (valor);
      return false;
    
  }
}
