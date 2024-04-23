#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);   // RX | TX


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);  // Pour permettre la config du BlueTooth (retirer le cable Key sur la pin 9 quand config terminée)
  digitalWrite(9,HIGH);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);
  //wait 1s and flush the serial buffer
  delay(1000);
  Serial.flush();
  BTSerial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  if (Serial.available())
    BTSerial.write(Serial.read());
}
