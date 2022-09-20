
int notas[] = {262,294,330,349};

void setup() {
  

  Serial.begin (9600);

}

void loop() {
  
  int valor = analogRead(A0);
  Serial.print(valor);

  if (valor ==1023){

    tone (8, notas[0]);
  }
  else if (valor <1023 && valor >1010){

    tone (8, notas[1]);
  }

    else if (valor <1010 && valor >505){

    tone (8, notas[2]);
  }

    else if (valor <400 && valor >5){

    tone (8, notas[3]);
  }

  else {
    noTone (8);
    
  }

}
