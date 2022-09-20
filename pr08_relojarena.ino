
const int pinsensor = 8;

unsigned long tiempocambioled = 0;

int estadointerruptor =0;
int estadopreviointerruptor =0;

int led = 2; 

long intervalo = 60000;


void setup() {

  for (int x=2 ; x <8; x++){

    pinMode (xb, OUTPUT);
  }
  pinMode (pinsensor, INPUT);

}

void loop() {

  unsigned long tiempoactual = millis();

  if (tiempoactual-tiempocambioled > intervalo){

    tiempocambioled = tiempoactual;

  digitalWrite (led, HIGH);
  led++;

  if (led==7){
  }
  }

  estadointerruptor = digitalRead (pinsensor);

  if (estadointerruptor != estadopreviointerruptor){
    
    for (int x=2 ; x <8; x++){
    digitalWrite (x, LOW);
  }
    
    led=2;
    tiempocambioled = tiempoactual;
  }

  estadopreviointerruptor = estadointerruptor;

}
