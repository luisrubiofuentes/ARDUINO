int valorfoto;
int sensorbajo =1023;
int sensoralto =0;

const int ledPin =13;


void setup() {

  pinMode (ledPin, OUTPUT);
  digitalWrite (ledPin, HIGH);

  while (millis()<5000){

    valorfoto = analogRead(A0);
    
    if ( valorfoto > sensorbajo){
      sensoralto = valorfoto;
    }
    if (valorfoto < sensorbajo){
      sensorbajo = valorfoto;
    }
  }
digitalWrite (ledPin, LOW);
}

void loop() {
  
  valorfoto = analogRead(A0);

  int pitch = map(valorfoto, sensorbajo, sensoralto, 50, 4000);

  tone(8, pitch, 20);
  delay (5);

}
