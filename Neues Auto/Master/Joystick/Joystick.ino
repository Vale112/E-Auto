//www.elegoo.com
//2016.12.09

// Arduino-PIN- Nummern
const int SW_pin = 2; // Digitaler Pin zum Schaltausgang angeschlossen - SW
const int X_pin = 0; // Analog-Pin an X-Ausgang angeschlossen
const int Y_pin = 1; // Analog-Pin an Y-Ausgang angeschlossen
const int LichtSchalter = 3; // Digitaler Pin zum schalten der LED's
int X = LOW;  // Variable zum Speichern des Licht-Zustands
int XAchse = 0; // X-Achse des Joysticks
int YAchse = 0; // Y-Achse des Joysticks
int forward = 0; // vorwärtsfahren
int backward = 0; // rückwärts
int left = 0; // links
int right = 0; // rechts
const int LED = 4;  //Test LEDs
const int Hupe = 5; //Test Hupe

void setup() {
  pinMode(SW_pin, INPUT_PULLUP);
  pinMode(LichtSchalter, INPUT_PULLUP);
  pinMode(LED, OUTPUT); //Test LEDs
  pinMode(Hupe, OUTPUT); //Test Hupe
  Serial.begin(9600);
}

void loop() {
  // LED's steuern
  if (digitalRead(LichtSchalter) == LOW) // Lichtsteuerung
  {
    if(X == HIGH)
    {
      // LED's ausschalten
      digitalWrite(LED, LOW); //Test
      delay(200); //Test
      X = LOW;
    }
    else
    {
      // LED's einschalten
      digitalWrite(LED, HIGH); //Test
      delay(200); //Test
      X = HIGH;
    }
  }
  
  // hupen
  if(digitalRead(SW_pin)== LOW){
    // hupen
    digitalWrite(Hupe, HIGH); //Test
    delay(200); //Test
    digitalWrite(Hupe, LOW); //Test
  }

  // Joystick
  XAchse = analogRead(X_pin);
  YAchse = analogRead(Y_pin);

  if(XAchse < 495){forward = XAchse;} //ggf. val = map(val, 0, 495, 0, 255);
  if(XAchse > 505){backward = XAchse - 500;}
  if(YAchse < 495){right = YAchse;} 
  if(YAchse > 505){left = YAchse - 500;}
  // weitere Verarbeitung bzw sendung!
 }
