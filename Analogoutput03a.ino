/*  ********************************************************************
 
  R&D on RCWL-0516

  file: Analogoutput03a.ino
  Capture data when radar goes high  because of motion detection

  Created by Glenn C. Gregory
  "The Ghetto Rocketeer"
  July 21, 2017

  this code is in the public domain at GitHib
  http://github.com/Ghetto-Rocketeer/rcwl-0516

  ******************************************************************
  */

int sensorPin = A7;    // select the input pin for the RCWL-0516
int ledPin = 11;      // select the pin for the super bright LED , (no resistor needed)
int sensorValue = 0;  // variable to store the value coming from the sensor
int outValue = 0;     // Mapped value from sensor to tenths of a volt up to 5 volts
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
   Serial.begin(115200);
   Serial.println("Begin RCWL-0516 tests");
   delay(5000); //wait for sensor to get ready
   Serial.println("Waiting for you to wave your hand");
}

void loop() {
  // read the value from the sensor:
  
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  if(sensorValue > 0){
     digitalWrite(ledPin, HIGH);
  }
  else
  {
      // turn the ledPin off:
    digitalWrite(ledPin, LOW);
  }
  outValue = map(sensorValue, 0, 1024, 0, 500);
  if(sensorValue > 20)
  {
    
    Serial.print(micros());
    Serial.print("\t ");
    Serial.println(outValue);
  }
  // set no delay for fastest readings
}
