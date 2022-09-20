int estadoboton =0;

void setup() {
  pinMode(2,INPUT);
  pinMode(3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);

}

void loop() {
  estadoboton = digitalRead(2);
  
  if (estadoboton == LOW) {
    digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
  }
  

}
