
const int greenledpin = 9;
const int redledpin = 10;
const int blueledpin =11;

const int redsensorpin =A0;
const int greensensorpin = A1;
const int bluesensorpin =A2;

int redsensorvalue =0;
int greensensorvalue=0;
int bluesensorvalue =0;

void setup() {
  Serial.begin (9600);

  pinMode (greenledpin, OUTPUT);
  pinMode(redledpin, OUTPUT);
  pinMode (blueledpin, OUTPUT);

}

void loop() {

  redsensorvalue = analogRead (redsensorpin);
  delay(100);
  bluesensorvalue = analogRead (bluesensorpin);
  delay(100);
  greensensorvalue = analogRead (greensensorpin);
  delay (100);

  Serial.print ("\t Rojo: ");
  Serial.print (redsensorvalue);
  Serial.print ("\t Azul: ");
  Serial.print (bluesensorvalue);
  Serial.print ("\t Verde");
  Serial.print ( greensensorvalue);

  analogWrite (greenledpin, greensensorvalue/4);
  analogWrite (redledpin, redsensorvalue/4);
  analogWrite (blueledpin, bluesensorvalue/4);
  

}
