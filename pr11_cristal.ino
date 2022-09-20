#include <LiquidCrystal.h>

LiquidCrystal lcd (12,11,5,4,3,2);

const int interruptor =6;
int estadointerruptor=0;
int estadoprevio=0;
int respuesta;

void setup() {
  
  lcd.begin (16,2);
  pinMode (interruptor, INPUT);

  lcd.print ("!Pregúntale a");

  lcd.setCursor (0,1);
  lcd.print ("la bola de cristal");

}

void loop() {

  estadointerruptor = digitalRead(interruptor);

  if (estadointerruptor != estadoprevio){

    if (estadointerruptor == LOW){
      respuesta = random(8);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("La bola dice: ");
      lcd.setCursor (0,1);

      switch (respuesta){
        case 0:
        lcd.print("sí");
        break;

        case 1:
        lcd.print("Probablemente");
        break;

        case 2:
        lcd.print("Desde luego");
        break;

        case 3:
        lcd.print("Tiene buena pinta");
        break;

        case 4:
        lcd.print ("No estoy segura");
        break;

        case 5:
        lcd.print("Vuelve a preguntar");
        break;

        case 6:
        lcd.print ("Tengo dudas");
        break;

        case 7:
        lcd.print ("No");
        break;
      }
    }
  }
  estadoprevio=estadointerruptorj;

}
