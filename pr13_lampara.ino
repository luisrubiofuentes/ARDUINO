#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor (4,2);

int threshold = 1000;
int ledpin =12;


void setup() {

  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  

}

void loop() {
  
  long sensorvalue = capSensor.capacitiveSensor(30);
  Serial.print ("\n");
  Serial.print (sensorvalue);
  
  if (sensorvalue >threshold){
    digitalWrite(ledpin, HIGH);
  }
  else{
    digitalWrite (ledpin, LOW);
  }
  delay(10);

}
