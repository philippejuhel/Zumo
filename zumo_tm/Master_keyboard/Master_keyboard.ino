#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial BTSerial(10,11);   // RX | TX

void setup() 
{
  Serial.begin(9600);  // This is the serial communication between the PC and the Arduino
  BTSerial.begin(9600);
  Serial.flush();
  BTSerial.flush();
  delay(500); 
}

void loop()
{ 
  if (Serial.available()){
    char cmd = Serial.read();  // Lecture de la commande
    if ((cmd == 'g') || (cmd == 'd') || (cmd == 's') || (cmd == 'a') || (cmd == 'r') || (cmd == 'f')){
      Serial.println(cmd);
      BTSerial.write(cmd); // envoi de la commande par Bluetooth au Zumo si elle est reconnue
    }
  }
  delay(50);
}
