  const int sensorpin = A0;
  const float temperaturabase = 22.0;

void setup() {

  Serial.begin (9600);

  for (int i=2; i<=4; i++){

    pinMode (i, OUTPUT);
    digitalWrite (i, LOW);
  }

}

void loop() {

  int sensorvalor = analogRead (sensorpin);
  Serial.print ("\n Valor del sensor ");
  Serial.print (sensorvalor);

  float voltaje = (sensorvalor * 5.0) / 1024.0;

  Serial.print (" El voltaje es: ");
  Serial.print (voltaje);

  Serial.print ( " En grados serían: ");
  float temperaturareal = (voltaje/0.01) -50.0;
  Serial.print (temperaturareal);
   Serial.print (" ºC ");
  


  if (temperaturareal < temperaturabase){

    digitalWrite (2,LOW);
    digitalWrite(3, LOW);
    digitalWrite(4,LOW);
  }
    else if (temperaturareal > temperaturabase+2 && temperaturareal < temperaturabase+4){

     digitalWrite (2,HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4,LOW);
    }

    else if (temperaturareal > temperaturabase+4 && temperaturareal < temperaturabase+6){

       digitalWrite (2,HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4,LOW);
    }
else if (temperaturareal >temperaturabase+6){

       digitalWrite (2,HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4,HIGH);
    }

    delay(1000);
}
