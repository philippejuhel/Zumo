#include <SoftwareSerial.h>
#include <ZumoShield.h>

ZumoMotors motors;
SoftwareSerial BTSerial(10,11);   // RX | TX
int DELAY = 500;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 
  BTSerial.begin(9600);
  // This is the serial communication between the PC and the Arduino
  //wait 1s and flush the serial buffer
  delay(1000);
  Serial.flush();
  BTSerial.flush();
  //motors.setSpeeds(0,0);
}

void blink(int nb)
{
  for (int i=0;i<nb;i++){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(DELAY);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(DELAY);                       // wait for a second
  }
}

void loop()
{
  if (BTSerial.available()){
    char cmd = BTSerial.read();
    //Serial.println('r');
    Serial.println("La commande");
    Serial.print(cmd);
    if (cmd == 's'){
      blink(2);
      //motors.setSpeeds(200,200);
    }
    if (cmd == 'f'){
      //motors.setSpeeds(400,0);
      blink(4);
    }
  }
  delay(50);

}
