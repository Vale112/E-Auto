#include <SoftwareSerial.h>

SoftwareSerial BTSerial(3, 4);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Arduino ist fertig");
BTSerial.begin(9600);
Serial.println("BT ist fertig");
}

void loop() {
  // put your main code here, to run repeatedly:
if (BTSerial.available())
  Serial.write(BTSerial.read());  
if (Serial.available())
  BTSerial.write(Serial.read());
}
