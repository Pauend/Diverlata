#include <Arduino.h>
#include <SoftwareSerial.h>
#define HC12SET 4

SoftwareSerial HC12(2,3);

void setup(){
  pinMode(HC12SET, OUTPUT);
  digitalWrite(HC12SET, LOW);
  Serial.begin(9600);
  HC12.begin(9600);
  delay(500);

  HC12.write("wasaaa");
  digitalWrite(HC12SET, HIGH);

}

void loop(){
  while(HC12.available()){
    Serial.write(HC12.read());
  }
  while(Serial.available()){
    HC12.write(Serial.read());
  }
}