#include <SoftwareSerial.h>
#include <ZumoShield.h>

ZumoMotors motors;
SoftwareSerial BTSerial(4,11);   // RX | TX

int SLOW = 100;
int FAST = 2*SLOW;

void setup() 
{
  Serial.begin(9600);  // This is the serial communication between the PC and the Arduino
  BTSerial.begin(9600);
  Serial.flush();
  BTSerial.flush();
  motors.setSpeeds(0,0);
}

void loop()
{ 
  int left_speed;
  int right_speed;
  if (BTSerial.available()){
    char cmd = BTSerial.read();
    Serial.println(cmd);
    switch (cmd){
      case 'f':  // Fast avance
        left_speed = FAST;
        right_speed = FAST;
        break;
      case 'g':  // Gauche
        left_speed = SLOW;
        right_speed = -SLOW;
        break;
      case 'd':  // Droite
        left_speed = -SLOW;
        right_speed = SLOW;
        break;    
      case 'a':  // Avance
        left_speed = SLOW;
        right_speed = SLOW;
        break;
      case 'r':  // Recule
        left_speed = -SLOW;
        right_speed = -SLOW;
        break;  
      default:   // Stop (ou commande non reconnue)
        left_speed = 0;
        right_speed = 0;
        break; 
    }
  }
  motors.setSpeeds(left_speed,right_speed);
  delay(50);
}
