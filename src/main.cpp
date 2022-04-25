#include "Arduino.h"

float analog_value = 0;                                     // 用于存储电位器值的变量
const int ANALOG_PIN = 34;
int a[10];

void write(){
  int analog_value = 0;
  int acc = 0;
  for (int j = 0; ; j++) {
    for (int i = 0; i < 10; i++) {                      
      acc = acc - a[i] ;
      a[i] = analogRead(ANALOG_PIN);
      acc = acc + a[i] ;
      analog_value = (2959 - acc / 10) / 251; 
      Serial.println(analog_value);
      delay(300);
    }
    if (j == 100){
      j = 0;
    }

  }
}


void setup() {
  Serial.begin(115200);
  analogSetPinAttenuation(ANALOG_PIN, ADC_11db);
  Serial.println("Calibrating... Ensure that no current flows through the sensor at this moment");
  Serial.println("Done!");
}


void loop() {
  write();
  delay(300);
}
