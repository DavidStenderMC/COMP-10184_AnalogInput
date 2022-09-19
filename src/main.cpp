#include <Arduino.h>

/*
  I, David Stender, 000828140 certify that this material is my original work.
  No other person's work has been used without due acknowledgement.
*/
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
void loop() { 
  int iVal;
  float conversionFactor = 50/(float)1024;
  float iValDigital;
  String judgement = "";

  iVal = analogRead(A0);
  iValDigital = iVal*conversionFactor;


  if(iValDigital > 35) {
    judgement = "Too Hot!";
  } else if(iValDigital >= 30) {
    judgement = "Hot";
  } else if(iValDigital > 25) {
    judgement = "Warm";
  } else if(iValDigital > 15) {
    judgement = "Perfect";
  } else if(iValDigital >= 10) {
    judgement = "Cool";
  } else {
    judgement = "Cold!";
  }
 
  Serial.println("Digitized output of " + String(iVal) + " is equivalent to a temperature input of "+String(iValDigital)+" dec C, which is "+judgement);
 
  delay(2000); 
}