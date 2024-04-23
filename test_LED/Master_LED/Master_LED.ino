#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);   // RX | TX

void setup() 
{
  Serial.begin(9600);                       // This is the serial communication between the PC and the Arduino
  BTSerial.begin(9600);
  Serial.flush();
  BTSerial.flush();
  delay(500); 
}

void envoyer(char lettre)
{
  BTSerial.write(lettre); //signal for start sending
  Serial.print(lettre);
  delay(4000);  
}

void loop()
{ 
  while(1){
    envoyer('s');
    delay(8000);
    envoyer('f');
    delay(8000);
  }
}
