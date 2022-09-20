#include <Servo.h>

Servo myservo;

const int pinpotenciometro = A0;

int entradavalor=0;
int anguloservo =0;

void setup() {

 myservo.attach(9);

 Serial.begin(9600);
}

void loop() {

  entradavalor = analogRead(pinpotenciometro);

  Serial.print ("\nEl valor del potenciometro es: ");
  Serial.print(entradavalor);

  anguloservo = map(entradavalor, 0, 1023, 0, 179);

  Serial.print ("\t Ángulo: ");
  Serial.print (anguloservo);
  
  myservo.write(anguloservo);
  delay(15);
  

}
