//www.elegoo.com
//2016.12.08

int buzzer = 8; // der Pins des angesteckten Summers
const int Schalter = 3; // Digitaler Pin zum schalten der LED's

void setup()
{
 pinMode(buzzer,OUTPUT);// initialsiert den buzzer als Output
 pinMode(Schalter, INPUT_PULLUP);
}
void loop()
{
  if(digitalRead(Schalter) == LOW){
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
  }  
} 
